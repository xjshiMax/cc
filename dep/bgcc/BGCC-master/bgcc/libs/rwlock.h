/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_RWLOCK_H_
#define _BGCC2_RWLOCK_H_

#include "bgcc_common.h"

namespace bgcc {

    class RWLock
    {
    public:
        /**
         * @brief 构造函数
         *
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/21 15:08:31
        **/
        RWLock();

        /**
         * @brief 析构函数
         *
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/21 15:08:44
        **/
        ~RWLock();

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
        int32_t get_rdlock();
        
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
        int32_t try_rdlock();

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
        int32_t get_wrlock();
        
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
        int32_t try_wrlock();

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
        int32_t unlock();
    private:
#ifdef _WIN32
        /**
         * @brief 增加一个写者，windows下的核心
         *
         * @return  void 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/21 15:09:20
        **/
        void add_writer();
        
        /**
         * @brief 删除一个写者
         *
         * @return  void 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2012/12/21 15:09:25
        **/
        void remove_writer();
        
        HANDLE _mutex;                  /**< 互斥锁       */
        HANDLE _evt_reader;             /**< 读者事件     */
        HANDLE _evt_writer;             /**< 写者事件     */

        int32_t _reader_num;            /**< 当前拿到锁的读者   */
        int32_t _writer_num;            /**< 当前拿到锁的写者   */
        int32_t _writer_waiting_num;    /**< 当前排队拿写锁的人数  */
#else
        pthread_rwlock_t _rwlock;       /**< Linux的读写锁      */
#endif
    };
}
#endif // _BGCC2_RWLOCK_H_
