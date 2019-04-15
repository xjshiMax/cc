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
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "statement.h"

using namespace sql;

class DBContainer {
public:
    DBContainer();
    virtual ~DBContainer();

    int32_t create_container(mysql::MySQL_Driver* driver, string& host, string& user,
                             string& passwd, uint32_t conn_num);

    Connection* get_connection();
    void free_connection(Connection* conn);

private:
    vector<Connection*> _idle_conn_vec;
    set<Connection*> _busy_conn_set;

    sql::ConnectOptionsMap _connection_properties;

    pthread_mutex_t _mutex;
    sem_t _sem_conn;
    uint32_t _conn_num;
};


// class DBPool {
// public:
//     DBPool();
//     virtual ~DBPool();
// 
// public:
//     int32_t create_container_to_pool(uint32_t id, string& host, string& user, string& passwd,
//                                      uint32_t conn_num, uint32_t timeout);
// 
//     Connection* get_connection(uint32_t id, uint32_t timeout = 0);
//     void free_connection(uint32_t id, Connection* conn);
// 
// private:
//     map<int32_t, DBContainer*> _id_conn_map;
// };


class SqlInstan
{
public:
	SqlInstan()
	{

	}
	static DBContainer m_DBpool;
	static bool m_bisCreeatedb;
	static int Createpool(string& host, string& user, string& passwd,uint32_t conn_num)
	{
		static mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
		if(!m_bisCreeatedb)
		{
			//m_bisCreeatedb=true;
			return 	m_DBpoolcreate_container(driver,  host, user,passwd, conn_num);
		}
		return -1;
	}
	static int InsertCall(string callmsg)
	{
		try
		{
			Connection* conn = NULL;
			Statement* state = NULL;
			ResultSet* rs = NULL;
			const char* exit = EXIT_FAIL;

			conn = m_DBpool->get_connection();

			if (conn) {
				state = conn->createStatement();
			} else {

				return -1;
			}
			bool is_ret_rs = state->execute(callmsg.c_str());

		} catch (sql::SQLException ex) {
			//IVR_WARN("数据库查询失败(%s,%s)", ex.getSQLStateCStr(), ex.what());
			//goto FREE;
			//g_dbpool->free_connection(_connectid, conn);
		} catch (...) {
			//IVR_WARN("数据库查询失败 抛出异常");
			//goto FREE;
			//g_dbpool->free_connection(_connectid, conn);
		}


		m_DBpool->free_connection( conn);
	}
	
};



#endif
