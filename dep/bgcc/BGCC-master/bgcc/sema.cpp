/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "sema.h"
#include "time_util.h"
#include "bgcc_error.h"

namespace bgcc {

    Semaphore::Semaphore(int ninit) {
        if (ninit < 0) {
            ninit = 0;
        }
#ifdef _WIN32
        _sem = CreateSemaphore(NULL, ninit, LONG_MAX, NULL);
#else
        sem_init(&_sem, 0, ninit);
#endif
    }

    Semaphore::~Semaphore() {
#ifdef _WIN32
        if (NULL != _sem) {
            BOOL ret = CloseHandle(_sem);
            if (0 != ret) {
                _sem = NULL;
            }
        }
#else
        sem_destroy(&_sem);
#endif
    }

    int32_t Semaphore::wait(uint32_t millisecond) {
#ifdef _WIN32
        if (NULL == _sem) {
            return E_BGCC_NULL_POINTER;
        }

        DWORD ret = WaitForSingleObject(_sem, millisecond);
        if (WAIT_OBJECT_0 == ret || WAIT_ABANDONED == ret) {
            return 0;
        }
        else if (WAIT_TIMEOUT == ret) {
            return E_BGCC_TIMEOUT;
        }
        else {
            return E_BGCC_SYSERROR;
        }
#else
        int32_t ret = 0;

        if (BGCC_SEMA_WAIT_INFINITE == millisecond) {
			while((ret=sem_wait(&_sem))==-1 && EINTR==errno);
		}
		else{
            struct timespec ts = {0, 0};
            TimeUtil::get_abs_timespec(&ts, millisecond);
            while( (ret=sem_timedwait(&_sem, &ts))==-1 && EINTR==errno );
		}
		
		if(0!=ret){
			if(BgccGetLastError()==ETIMEDOUT){
				return E_BGCC_TIMEOUT;
			}
			else{
				return E_BGCC_SYSERROR;
			}
		}

		return 0;
#endif
    }

	bool Semaphore::try_wait(){
#ifdef _WIN32
		if (NULL == _sem) {
            return false;
        }

        DWORD ret = WaitForSingleObject(_sem, 0);
        if (WAIT_OBJECT_0 == ret || WAIT_ABANDONED == ret) {
            return true;
        }

		return false;
#else
		int32_t ret=0;
		while((ret=sem_trywait(&_sem))==-1 && EINTR==errno);
		return (0==ret);
#endif

	}

    int32_t Semaphore::signal() {
#ifdef _WIN32
        BOOL ret = FALSE;

        if (NULL != _sem) {
            ret = ReleaseSemaphore(_sem, 1, NULL);
        }
        return (0 != ret ? 0 : E_BGCC_SYSERROR);
#else

		int32_t ret=0;
		while((ret=sem_post(&_sem))==-1 && EINTR==errno);
		return (0==ret?0:E_BGCC_SYSERROR);

#endif
    }
}

