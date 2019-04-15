/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_SHARED_PTR_H_
#define _BGCC2_SHARED_PTR_H_

#include "mutex.h"
#include "guard.h"
#include <stdlib.h>

namespace bgcc {
    typedef Guard<Mutex> ScopedGuard;

    /**
     * @brief 计数器类
     *
     * @see
     * @note
     * @author  zhangyue
     * @date    2012/12/11 11:21:49
     */
    class SharedCount
    {
        public:
            /**
             * @brief 构造函数
             *
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:28:38
             **/
            SharedCount():_count(1)
            {
            }

            /**
             * @brief 析构函数
             *
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:28:47
             **/
            ~SharedCount()
            {
            }

            /**
             * @brief 计数器 + 1
             *
             * @return  int32_t 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:29:00
             **/
            int32_t inc()
            {
                //Mutex
                bgcc::ScopedGuard guard(&_mutex);
                //if(_count > 0)//外部使用不会出现小于等于0且调用inc的情况，此部分仅为容错
                //{
                //    _count++;
                //}
                _count++;
                return _count;
            }

            /**
             * @brief 计数器 - 1
             *
             * @return  int32_t
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:29:13
             **/
            int32_t dec()
            {
                //Mutex
                ScopedGuard guard(&_mutex);
                _count--;
                return _count;
            }

            /**
             * @brief 获取当前计数
             *
             * @return  int32_t 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:29:37
             **/
            int32_t get_count()
            {
                return _count;
            }

        private:
            int32_t _count;           /**< 计数器 */
            Mutex _mutex;         /**< 计数器操作时的互斥锁 */
    };

    /**
     * @brief 智能指针类
     *
     * @see
     * @note
     * @author  zhangyue
     * @date    2012/12/11 11:21:49
     */
    template <typename ElementType> class SharedPtr {
        public:
            /**
             * @brief 构造函数
             *
             * @param [in/out] ptr   : ElementType*
             * @return  explicit 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:21:49
             **/
            explicit SharedPtr(ElementType* ptr = NULL) : _instance(ptr)
            {
                if(NULL != _instance)
                {
                    _counter = new SharedCount();
                }
            }

            /**
             * @brief 拷贝构造函数
             *
             * @param [in/out] other   : const SharedPtr&
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:31:14
             **/
            SharedPtr(const SharedPtr& other) :_instance(other._instance)
            {
                if(NULL != _instance)
                {
                    _counter = other._counter;
                    _counter->inc();
                }
            }

            /**
             * @brief 拷贝构造函数
             *
             * @param [in/out] other   : const SharedPtr <U>&
             * @return  template <typename U> 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:32:16
             **/
            template <typename U> SharedPtr (const SharedPtr <U> &other) :_instance(NULL)
            {
                _instance = other.get();
                if(NULL != _instance)
                {
                    _counter = other._counter;//get_counter();
                    _counter->inc();
                }
            }

            /**
             * @brief 析构函数
             *
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:32:38
             **/
            ~SharedPtr()
            {
                if(NULL != _instance)
                {
                    if(0 == _counter->dec())
                    {
                        delete _instance;
                        _instance = NULL;
                        delete _counter;
                        _counter = NULL;
                    }
                }
            }

            /**
             * @brief 重载等号右面的操作
             *
             * @param [in/out] r   : const SharedPtr&
             * @return  SharedPtr& 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:39:06
             **/
            SharedPtr & operator=(const SharedPtr& r)
            {
                if(_instance != r._instance)
                {
                    //先将计数器+1，防止其他人删除(目前未想到这种场景，以防万一)
                    if(NULL != r._instance)
                    {
                        r._counter->inc();
                    }
                    //删除原来指针
                    if(NULL != _instance)
                    {
                        if(0 == _counter->dec())
                        {
                            delete _instance;
                            delete _counter;
                        }
                    }

                    _instance = r._instance;
                    _counter = r._counter;
                }
                return *this;
            }


            /**
             * @brief 获取指针
             *
             * @return  ElementType* 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:39:25
             **/
            ElementType * get() const
            {
                return _instance;
            }

            /**
             * @brief 获取指针中的内容
             *
             * @return  ElementType* 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:39:54
             **/
            ElementType* operator->() const
            {
                return _instance;
            }

            /**
             * @brief 获取指针中的引用
             *
             * @return  ElementType* 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 11:39:54
             **/
            ElementType& operator*() const
            {
                return *_instance;
            }

            /**
             * @brief 获取当前计数
             *
             * @return  int32_t 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/12 19:28:07
             **/
            int32_t get_count() const
            {
                if(_counter!= NULL)
                {
                    return _counter->get_count();
                }
                return 0;
            }

            /**
             * @brief 判断指针是否可用
             *
             * @return  bool 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 14:13:58
             **/
            bool is_valid() const
            {
                return (_instance != NULL)?true:false;
            }

            /**
             * @brief 清空当前指针
             *
             * @return  void 
             * @retval   
             * @see 
             * @note 
             * @author zhangyue
             * @date 2012/12/11 14:14:37
             **/
            void reset()
            {
                if(NULL != _instance)
                {
                    if(0 == _counter->dec())
                    {
                        delete _instance;
                        delete _counter;
                    }
                }
                _instance = NULL;
                _counter = NULL;
            }

        private:
            template<class Y> friend class SharedPtr;

            ElementType * _instance;      /**< 实际元素的指针  */
            SharedCount * _counter;        /**< 内部计数器 */

    };

    /**
     * @brief 重载等于等于
     *
     * @param [in/out] a   : SharedPtr<T> const&
     * @param [in/out] b   : SharedPtr<U> const&
     * @return  template<class T, class U> inline bool 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/12 19:45:34
     **/
    template<class T, class U> inline bool operator==(SharedPtr<T> const & a, SharedPtr<U> const & b)
    {
        return (a.get() == b.get());
    }

    /**
     * @brief 重载不等于 
     *
     * @param [in/out] a   : SharedPtr<T> const&
     * @param [in/out] b   : SharedPtr<U> const&
     * @return  template<class T, class U> inline bool 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/12 19:45:34
     **/
    template<class T, class U> inline bool operator!=(SharedPtr<T> const & a, SharedPtr<U> const & b)
    {
        return (a.get() != b.get());
    }

    /**
     * @brief 重载不等于 
     *
     * @param [in/out] a   : SharedPtr<T> const&
     * @param [in/out] b   : SharedPtr<T> const&
     * @return  template<class T> inline bool 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/12 19:45:34
     **/
    template<class T> inline bool operator!=(SharedPtr<T> const & a, SharedPtr<T> const & b)
    {
        return (a.get() != b.get());
    }
}
#endif // _BGCC2_SHARED_PTR_H_
