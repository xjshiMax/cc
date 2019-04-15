/*
 * Copyright 2002-2014 the original author or authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      CC/LICENSE
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DB_POOL_H_
#define _DB_POOL_H_

#include "common.h"
#include <string>
#include <vector>
#include <set>
// #include "mysql_connection.h"
// #include "mysql_driver.h"
// #include "statement.h"
#include <mysql.h>
using namespace std;
/*using namespace sql;*/

class DBContainer {
public:
	DBContainer();
    virtual ~DBContainer();

    int32_t create_container( string& host, string& user,
                             string& passwd, uint32_t conn_num,string dbname);

    MYSQL* get_connection();
    void free_connection(MYSQL* conn);

private:
	std::string m_host;
	std::string m_user;
	std::string m_passwd;
	uint32_t m_connnum;
	std::string m_dbname;
    vector<MYSQL*> _idle_conn_vec;
    set<MYSQL*> _busy_conn_set;

   // sql::ConnectOptionsMap _connection_properties;

    pthread_mutex_t _mutex;
    sem_t _sem_conn;
    uint32_t _conn_num;
};





class SqlInstan
{
public:
	SqlInstan()
	{

	}
	static DBContainer m_DBpool;
	static bool m_bisCreeatedb;
	static int Initsqlconn(string& host, string& user, string& passwd,uint32_t conn_num,string dbname)
	{
		return Createpool(host,user,passwd,conn_num,"master_outdial");
	}
	static int Createpool(string& host, string& user, string& passwd,uint32_t conn_num,string dbname)
	{
		//static mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		if(!m_bisCreeatedb)
		{
			//m_bisCreeatedb=true;
			return 	m_DBpool.create_container(host,user,passwd,conn_num,dbname);
		}
		return -1;
	}
	static int InsertCall(string callmsg)
	{
		MYSQL* conn=NULL;
		conn=m_DBpool.get_connection();
		if(!conn)
			return -1;
		try
		{
			mysql_query(conn,"START TRANSACTION");
			mysql_query(conn, callmsg.c_str());
			mysql_query(conn,"COMMIT");
//			bool is_ret_rs = state->execute(callmsg.c_str());

		} catch (exception& e) {
			//IVR_WARN("数据库查询失败(%s,%s)", ex.getSQLStateCStr(), ex.what());
			//goto FREE;
			//g_dbpool->free_connection(_connectid, conn);
			m_DBpool.free_connection( conn);
			return -1;
		} catch (...) {
			//IVR_WARN("数据库查询失败 抛出异常");
			//goto FREE;
			//g_dbpool->free_connection(_connectid, conn);
			m_DBpool.free_connection( conn);
			return -1;
		}


		m_DBpool.free_connection( conn);
		return 0;
	}
	
};



#endif
