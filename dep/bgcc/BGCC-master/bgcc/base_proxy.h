/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef __BASE_PROXY_HH__
#define __BASE_PROXY_HH__

#include "protocol.h"
#include "sync_vector.h"
#include "server_info.h"
#include "binary_protocol.h"
#include "exception.h"
#include "service_manager.h"
#include "time_util.h"
#include "thread.h"
#include "sema.h"
#include "selector.h"

#include "connection_manager.h"

namespace bgcc {

    typedef SharedPointer<BinaryProtocol> BinaryProtocolSharedPtr;
    
    class BaseProxy : public Exception {
    public:
        int32_t __get_ticket_id(
                const std::string& fun,
                int32_t& ticket_id,
                bool belast,
                SharedPointer<IProtocol> __iprot,
                SharedPointer<IProtocol> __oprot);

        BaseProxy(
                ServerInfo serverinfo,
                int32_t maxConn,
                bool initConsNow,
                ServiceManager* service_manager = NULL,
                int32_t tryCount = 3,
                int32_t tryInterval = 3000);

        virtual ~BaseProxy();

        /**
         * @brief 手动关闭连接
         *
         * @return  void 
         * @retval   
         * @see 
         * @note 
         * @author zhangyue
         * @date 2013/01/05 14:47:58
        **/
        void close();

        std::string get_name() const;
        void set_name(const std::string& name);

        std::string get_whoami() const;
        void set_whoami(const std::string& whoami);

		bool set_property(const std::string &key, int32_t val);
		bool set_property(const std::string &key, const std::string& val);

		bool get_property(const std::string &key, int32_t &val) const;
		bool get_property(const std::string &key, std::string &val) const;
    protected:
		enum INIT_TYPE{
			INIT_CALL		=1,
			INIT_CALLBACK	=2,
			INIT_ALL		=3
		};
        /**
         * @brief init 初始化代理
         *
         * @return 返回成功建立的连接个数
         * @see
         * @note
         * @author  liuxupeng(liuxupeng@baidu.com)
         * @date    2012年06月19日 23时27分05秒
         */
        int32_t init(INIT_TYPE type=INIT_ALL);
        int32_t uninit();

        std::string _name;
        std::string _whoami;
		Selector _selector;

    public:
        SyncVector<SharedPointer<BinaryProtocol> > _protocols;
    protected:
        int32_t _nMaxConn;
        ServerInfo _serverinfo;
        int32_t _tryCount;
        int32_t _tryInterval;
        int32_t _seqid;
        SharedPointer<Thread> _callback_thread;
        ServiceManager* _service_manager;
        bool _use_existing_socket;
            
		void free_Conn(SharedPointer<ConnInfo> conn, int32_t err);
        SharedPointer<ConnInfo> get_Conn();
        SharedPointer<ConnInfo> create_Conn();
	public:
		const static char * PROXY_SEND_TIMEOUT;
		const static char * PROXY_RECV_TIMEOUT;
		const static char * PROXY_HB_TIMEOUT;

	private:
		std::map<std::string, std::string> _property;
		bool is_support(const std::string& key) const;
    };

} // namespace


#endif //__BASE_SERVICES_HH__

