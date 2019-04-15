/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_SOCKET_BASE_H_
#define _BGCC_SOCKET_BASE_H_

#include "shareable.h"
#include "transport.h"
#include "mutex.h"
#include "guard.h"

#include "socket_util.h"

namespace bgcc {

    /**
     * @class Socket 
     * @brief Socket部分公共接口实现
     */
    class Socket :  public ITransport {
    public:

        virtual ~Socket();

        /**
         * @brief   打开连接，虚函数，在client、server类中具体实现
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t open();
		
		virtual int32_t close();

        /**
         * @brief   读取数据
         * @param   buffer 进行recv数据的存储空间
         * @param   length 接受数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t read(void * buffer, int32_t length);

        /**
         * @brief   写数据
         * @param   buffer 进行write数据的存储空间
         * @param   length 写数据的长度
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual int32_t write(const void* buffer, int32_t length);

        /**
         * @brief   判断socket是否打开，用于流程合法判断，虚函数，client、server分别实现
         * @return  成功返回ture，失败返回false
         */
        virtual bool is_open() const;

        /**
         * @brief   用来查看是否有可用数据
         * @return  操作成功返回0；否则返回错误码。
         */
        virtual bool peek() const;

		TRANSPORTID id() const{
			return _socket;
		}

		protected:
        Socket();
        /**全局socket编号*/
        SOCKET _socket;
        int32_t _send_timeout;
        int32_t _recv_timeout;
    };
}

#endif

