/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifdef _WIN32
#include <stdlib.h>
#include <windows.h>
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
    RWLock::RWLock():_reader_num(0),_writer_num(0),_writer_waiting_num(0)
    {
        _mutex = CreateMutex(NULL, FALSE, NULL);
        _evt_reader = CreateEvent(NULL, TRUE, TRUE, NULL);  
        _evt_writer = CreateEvent(NULL, TRUE, TRUE, NULL);  
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
        CloseHandle(_mutex);
        CloseHandle(_evt_reader);
        CloseHandle(_evt_writer);
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
        HANDLE h[2];
        h[0] = _mutex;
        h[1] = _evt_reader;
        //同时等待互斥锁和读者信号
        switch (WaitForMultipleObjects(2, h, TRUE, INFINITE))
        {
            case WAIT_OBJECT_0:
            case WAIT_OBJECT_0 + 1:
                //if(_writer_num == 0)
                //{
                    _reader_num++;
                    ResetEvent(_evt_writer);
                //}
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                return -1;
        }
        return 0;
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
        HANDLE h[2];
        h[0] = _mutex;
        h[1] = _evt_reader;
        //同时等待互斥锁和读者信号，仅等待1毫秒
        switch (WaitForMultipleObjects(2, h, TRUE, 1))
        {
            case WAIT_OBJECT_0:
            case WAIT_OBJECT_0 + 1:
                //if(_writer_num == 0)
                //{
                    _reader_num++;
                    ResetEvent(_evt_writer);
                //}
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                return -1;
        }
        return 0;
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
        //增加写者记录
        add_writer();
        HANDLE h[2];
        h[0] = _mutex;
        h[1] = _evt_writer;
        //同时等待互斥锁和写者信号，仅等待1毫秒
        switch (WaitForMultipleObjects(2, h, TRUE, INFINITE))
        {
            case WAIT_OBJECT_0:
            case WAIT_OBJECT_0 + 1:
                //记录写者数目，关闭读者写者信号
                _writer_num++;
                _writer_waiting_num--;
                ResetEvent(_evt_reader);
                ResetEvent(_evt_writer);
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                //加锁不成功，需要删除等待写者记录
                remove_writer();
                return -1;
        }
        return 0;
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
        //增加写者记录
        add_writer();
        HANDLE h[2];
        h[0] = _mutex;
        h[1] = _evt_writer;
        //同时等待互斥锁和写者信号，仅等待1毫秒
        switch (WaitForMultipleObjects(2, h, TRUE, 1))
        {
            case WAIT_OBJECT_0:
            case WAIT_OBJECT_0 + 1:
                //记录写者数目，关闭读者写者信号
                _writer_num++;
                _writer_waiting_num--;
                ResetEvent(_evt_reader);
                ResetEvent(_evt_writer);
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                //加锁不成功，需要删除等待写者记录
                remove_writer();
                return -1;
        }
        return 0;
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
        //获取互斥锁即可
        switch (WaitForSingleObject(_mutex, INFINITE))
        {
            case WAIT_OBJECT_0:
                if(_writer_num == 0)
                {
                    //可能释放的是读锁
                    if(_reader_num > 0)
                    {
                        //只有读锁被占有，释放的是读锁。否则认为释放错误
                        _reader_num--;
                        if(_reader_num == 0)
                        {
                            SetEvent(_evt_writer);
                        }
                    }
                    else
                    {
                        //没有人获得读锁或写锁，认为失败
                        return -1;
                    }
                }
                else
                {
                    //释放的一定是写锁
                    _writer_num = 0;
                    if(_writer_waiting_num == 0)
                    {
                        //没有等待的写者，开启读者和写者信号
                        SetEvent(_evt_reader);
                        SetEvent(_evt_writer);
                    }
                    else
                    {
                        //有等待的写者，优先进行写操作
                        SetEvent(_evt_writer);
                    }
                }
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                return -1;
        }
        return 0;
    }

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
    void RWLock::add_writer()
    {
        //获取互斥锁即可
        switch (WaitForSingleObject(_mutex, INFINITE))
        {
            case WAIT_OBJECT_0:
                _writer_waiting_num++;
                //若有人等待写锁，关闭读者信号，不允许有读者抢先
                if(_writer_waiting_num > 0)
                {
                    ResetEvent(_evt_reader);
                }
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                break;
        }
    }

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
    void RWLock::remove_writer()
    {
        //获取互斥锁即可
        switch (WaitForSingleObject(_mutex, INFINITE))
        {
            case WAIT_OBJECT_0:
                _writer_waiting_num--;
                //若已经没有等待的写者，开启读者信号
                if(_writer_waiting_num == 0)
                {
                    SetEvent(_evt_reader);
                }
                ReleaseMutex(_mutex);
                break;
            default:
                ReleaseMutex(_mutex);
                break;
        }
    }
}
#endif//ifdef _WIN32
