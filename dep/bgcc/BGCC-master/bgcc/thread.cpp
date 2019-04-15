/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include "thread.h"
#include "time_util.h"

namespace bgcc {

    Thread::Thread(const RunnableSP& runner, bool detached)
        : _use_functor(true),
        _functor(runner),
        _func_ptr(NULL),
        _func_arg(NULL),
        _detached(detached),
        _state(INIT),
        _isstopped(false)
#ifdef _WIN32
          ,_handle(NULL)
#endif
    { }

    Thread::Thread(run_func_t func, void* arg, bool detached)
        : _use_functor(false),
        _func_ptr(func),
        _func_arg(arg),
        _detached(detached),
        _state(INIT),
        _isstopped(false)
#ifdef _WIN32
          ,_handle(NULL)
#endif
    { }

    Thread::~Thread() {
        join();
        _state = STOP;
    }

    bool Thread::start() {
        if (INIT != _state) {
            return false;
        }
#ifdef _WIN32
        _handle = ::CreateThread(NULL, 0, 
                (LPTHREAD_START_ROUTINE)thread_start_func, this, 0, &_thread_id);

        if (NULL != _handle) {
            _sema.wait();
			if(_detached)
			{
				CloseHandle(_handle);
			}
        }
        _isstopped = false;
        _state = START;

        return (NULL != _handle);
#else
        int ret;
        pthread_attr_t attr;

        ret = pthread_attr_init(&attr);
        if (0 != ret) {
            return false;
        }

        ret = pthread_attr_setdetachstate(&attr,
                _detached ? PTHREAD_CREATE_DETACHED : PTHREAD_CREATE_JOINABLE);
        if (0 != ret) {
            pthread_attr_destroy(&attr);
            return false;
        }

        ret = pthread_create(&_thread, &attr, thread_start_func, (void*)this);

        if (0 == ret) {
            _sema.wait();
        }

        pthread_attr_destroy(&attr);

        if (0 != ret) {
            return false;
        }

        _isstopped = false;
        _state = START;
        return true;
#endif
    }

    bool Thread::join() {
        if (START != _state && STOP != _state) {
            return false;
        }
#ifdef _WIN32
        bool ret = false;
        if (!_detached) {
            if (NULL != _handle) {
                DWORD dw = ::WaitForSingleObject(_handle, INFINITE);
                if (WAIT_OBJECT_0 == dw || WAIT_ABANDONED == dw) {
					CloseHandle(_handle);
                    ret = true;
                    _handle = NULL;
                }
            }
            _state = JOINED;
        }
        return ret;
#else
        bool ret = false;

        if (!pthread_equal(pthread_self(), _thread)) {
            if (!_detached) {
                int r = pthread_join(_thread, NULL);
                if (0 == r) {
                    _state = JOINED;
                }
                ret = (0 == r);
            }
        } else {
            ret = false;
        }
        return ret;
#endif 
    }

    bool Thread::stop() {
		bool ret = false;
        if (_state != STOP && _state >= START)
        {
            _isstopped = true;
            _state = STOP;
            ret = true;
        }
        return ret;
    }

#ifdef _WIN32
    DWORD Thread::get_thread_id() const {
        return _thread_id;
    }

    Thread::operator HANDLE() {
        return _handle;
    }

    DWORD __stdcall Thread::thread_start_func(LPVOID lpParam) {
        Thread *me = (Thread*)lpParam;
        RunnableSharedPointer runner = me->_functor;
        bool use_functor = me->_use_functor;
        run_func_t func = me->_func_ptr;
        void* arg = me->_func_arg;
        me->_sema.signal();

        DWORD ret = 0;
        if (use_functor) {
            if (runner.is_valid()) {
                ret = (*runner)(&me->_isstopped, arg);
            }
        }
        else {
            if (func) {
                func(&me->_isstopped, arg);
            }
        }

        return ret;
    }
#else
    pthread_t Thread::get_thread_id() const {
        return _thread;
    }

    void* Thread::thread_start_func(void *arg) {
        Thread* me = (Thread*)arg;
        RunnableSharedPointer runner = me->_functor;
        bool use_functor = me->_use_functor;
        run_func_t func = me->_func_ptr;
        void* func_arg = me->_func_arg;
        me->_sema.signal();

        if (use_functor) {
                if (runner.is_valid()) {
                (*runner)(&me->_isstopped);
            }
        }
        else {
            if (func) {
                func(&me->_isstopped, func_arg);
            }
        }
        return NULL;
    } 
#endif
}

