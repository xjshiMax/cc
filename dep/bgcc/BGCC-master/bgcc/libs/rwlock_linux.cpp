/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _WIN32
#include <stdlib.h>
#include <stdio.h>
#include "rwlock.h"

namespace bgcc {

    /**
     * @brief 构造函数
     *
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:08:31
     **/
    RWLock::RWLock()
    {
//        _rwlock = PTHREAD_RWLOCK_INITIALIZER;
        pthread_rwlock_init(&_rwlock, NULL);
    }

    /**
     * @brief 析构函数
     *
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:08:44
     **/
    RWLock::~RWLock()
    {
        pthread_rwlock_unlock(&_rwlock);
    }

    /**
     * @brief 获取读锁
     *
     * @return  int32_t 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:08:51
     **/
    int32_t RWLock::get_rdlock()
    {
        return pthread_rwlock_rdlock(&_rwlock);
    }

    /**
     * @brief 尝试获取写锁
     *
     * @return  int32_t 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:08:57
     **/
    int32_t RWLock::try_rdlock()
    {
        return pthread_rwlock_tryrdlock(&_rwlock);
    }

    /**
     * @brief 获取写锁
     *
     * @return  int32_t 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:09:03
     **/
    int32_t RWLock::get_wrlock()
    {
        return pthread_rwlock_wrlock(&_rwlock);
    }

    /**
     * @brief 尝试获取写锁
     *
     * @return  int32_t 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:09:09
     **/
    int32_t RWLock::try_wrlock()
    {
        return pthread_rwlock_trywrlock(&_rwlock);
    }

    /**
     * @brief 解锁
     *
     * @return  int32_t 
     * @retval   
     * @see 
     * @note 
     * @author zhangyue
     * @date 2012/12/21 15:09:13
     **/
    int32_t RWLock::unlock()
    {
        return pthread_rwlock_unlock(&_rwlock);
    }
}
#endif//ifdef _WIN32
