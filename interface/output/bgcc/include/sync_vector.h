/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SYNC_VECTOR_H_
#define _BGCC_SYNC_VECTOR_H_

#include <queue>
#include "mutex.h"
#include "sema.h"
#include "guard.h"
#include "bgcc_error.h"
#include "shareable.h"
#include "libs/rwlock.h"
#include "log.h"

/**
 * @brief 线程安全vector
 * @see
 * @note
 * @author  liuxupeng(liuxupeng@baidu.com)
 * @date    2012年05月30日 16时42分56秒
 */
namespace bgcc {

    template <typename ElemType>
        class SyncVector : public Shareable {
        public:
            SyncVector() 
            {
                _psem = new Semaphore();
            }
            
            ~SyncVector()
            {
                if(_psem != NULL)
                {
                    delete _psem;
                }
            }
            typedef Guard<Mutex> ScopedGuard;

            /**
             * @brief put 向同步vector中添加元素（允许重复）。同时触发信号量
             *
             * @param elem 新元素
             *
             * @return 添加成功返回0；否则返回错误码
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时11分24秒
             */
            int32_t put(ElemType elem) {
                {
                    ScopedGuard guard(&_mutex);
                    if (guard.is_locked()) {
                        try {
                            _queue.push(elem);
                        }
                        catch(std::bad_alloc &) {
                            return E_BGCC_NOMEM;
                        }
                    }
                    else {
                        return E_BGCC_SYSERROR;
                    }
                }
                _psem->signal();
                return 0;
            }

            /**
             * @brief get 从同步vector中取元素。如果同步vector为空，将阻塞指定时长
             * BGCC_SEMA_WAIT_INFINITE表示无限阻塞。
             *
             * @param elem 取得的元素
             * @param millisecond 超时时长（毫秒）
             *
             * @return 成功返回0；否则返回错误码: E_BGCC_TIMEOUT表示超时.
             * @see
             * @note
             * @author  liuxupeng(liuxupeng@baidu.com)
             * @date    2012年05月30日 19时12分19秒
             */
            int32_t get(ElemType& elem, int millisecond) {
                _rwlock_clear.get_rdlock();
                int32_t ret = _psem->wait(millisecond);

                if (0 == ret) {
                    {   
                        ScopedGuard guard(&_mutex);
                        if (guard.is_locked()) {
                            elem = _queue.front();
                            _queue.pop();
                        }   
                        else {
                            _rwlock_clear.unlock();
                            return E_BGCC_SYSERROR;
                        }   
                    }
                    _rwlock_clear.unlock();   
                    return 0;
                }   
                else {
                    _rwlock_clear.unlock();
                    return ret;
                }
            }

            int32_t size() {
                return (int32_t)_queue.size();
            }

            /**
             * @brief 清空
             *
             * @return  void
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2013/01/05 15:12:51
            **/
            void clear() {
                BGCC_DEBUG("bgcc","SyncVector Clear()");
                _rwlock_clear.get_wrlock();
                ScopedGuard guard(&_mutex);
                std::vector<ElemType> tmp;
				while(_queue.size()){
					_queue.pop();
				}
                delete _psem;
                _psem = new Semaphore();
                _rwlock_clear.unlock();
            }

        protected:
            SyncVector(const SyncVector&);
            SyncVector& operator=(const SyncVector&);

        private:
            std::queue<ElemType> _queue;
            Mutex _mutex;
            RWLock _rwlock_clear;
            Semaphore * _psem;

        }; // end of class SyncVector
}

#endif // _BGCC_SYNC_VECTOR_H_
