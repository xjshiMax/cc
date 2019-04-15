/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_TRANSACTION_H_
#define _BGCC_TRANSACTION_H_

#include <time.h>
#include <string>               // for std::string
#include <map>                  // for std::map

#include "shareable.h"          // for super class
#include "shared_pointer.h"      // for member _data
#include "mutex.h"              // for member Mutex
#include "thread.h"
#include "protocol.h"
#include "nb_data_buffer.h"

namespace bgcc {

    typedef int32_t TicketIdType;
    typedef int32_t ThreadIdType;
    typedef int32_t PortType;

    /**
     * @class TicketMapKeyType
     * @brief 事务map键类型
     */
    struct TicketMapKeyType {
        /** 客户端ip */
        std::string ip;
        /** 客户端port */
        PortType port;
        /** 客户端程序线程id */
        ThreadIdType threadId;
        /** 客户端程序调用函数名 */
        std::string funcName;
    };

    typedef SharedPointer<IProtocol> ProtocolSharedPointer;

    /**
     * @brief   事务map键类型比较函数
     * @param   lhs 左比较数
     * @param   rhs 右比较数
     * @return  当lhs<rhs时，返回true;否则返回false。
     */
    bool operator<(const TicketMapKeyType& lhs, const TicketMapKeyType& rhs);

    /**
     * @class TicketMapValueType
     * @brief 事务map值类型
     */
    struct TicketMapValueType {
        /** 事务号 */
        TicketIdType ticketId;
        /** 值存放时间点 */
        time_t storeTime;
    };


    class Transaction : public Shareable {
        private:
            Transaction();
        public:
            static Transaction* get_instance();
            virtual ~Transaction();
            /**
             * @brief   获取一个新的事务号
             * @param   
             * @return  
             */
            TicketIdType getTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName);

            /**
             * @brief   获取上一次的事务号
             * @param   
             * @return  
             */
            TicketIdType getCurrentTicketId(ProtocolSharedPointer protocol, ThreadIdType threadId, std::string funcName);

            
        private:
            /**
             * @brief   根据protocol获取ip和port
             * @param   
             * @return  
             */
            int32_t getIpAndPort(ProtocolSharedPointer protocol, std::string& ip, PortType& port);
#ifdef _DEBUG
        public:
#endif
            TicketIdType _getTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);
            TicketIdType _getCurrentTicketId(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);
        private:

            /**
             * @brief   根据客户端ip和port及客户端程序线程id及函数名构造事务map的键
             * @param   ip 客户端ip
             * @param   port 客户端port
             * @param   threadId 客户端线程id
             * @param   funcName 客户端程序名
             * @return  事务map键
             */
            TicketMapKeyType makeKey(const std::string& ip, PortType port, ThreadIdType threadId, const std::string& funcName);

            /**
             * @brief   获取下一个可用的事务号
             * @param   
             * @return  可用的事务号
             */
            TicketIdType getNextTicketId();

        private:
            typedef std::map<TicketMapKeyType, TicketMapValueType> TicketKey2TicketValueMap;
            TicketKey2TicketValueMap _tickets;

            TicketIdType _counter;
            Mutex _mutex;
    };

}
#endif
