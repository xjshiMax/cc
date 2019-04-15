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


#include "acd_info.h"
#include "acd_tool.h"
#include "time_util.h"
#include "db_pool.h"

CallDirectT::CallDirectT(int32_t value) : m_value(value) {
}

CallDirectT::~CallDirectT() {
}

void CallDirectT::set_value(int32_t value) {
    m_value = value;
}

int32_t CallDirectT::get_value() {
    return m_value;
}

bool CallDirectT::isValid() {
    return m_value != UNKNOWN;
}

ReleaseCauseT::ReleaseCauseT(int32_t value) : m_value(value) {
}

ReleaseCauseT::~ReleaseCauseT() {
}

void ReleaseCauseT::set_value(int32_t value) {
    m_value = value;
}

int32_t ReleaseCauseT::get_value() {
    return m_value;
}

bool ReleaseCauseT::isValid() {
    return m_value != UNKNOWN;
}

callinfo::callinfo() : m_sessionId(0), m_callId(""), m_agentId(""), m_agentDn(""), m_caller(""),
    m_callee(""), m_waitbegin(0), m_waitend(0),
    m_ackbegin(0), m_ackend(0), m_callbegin(0), m_callend(0),
    m_callType(ims::PartyAttributeT::P_Unknown), m_callDirect(CallDirectT::UNKNOWN),
    m_releaseCause(ReleaseCauseT::UNKNOWN),
    m_recordFilename(""), m_routecall(false) {
}

callinfo::~callinfo() {
}

void callinfo::Initial(ims::SessionIdT sessionId, const ims::CallIdT& callId, const string& agentId,
                       const string& agentDn, const string& skill, const string& caller, const string& callee,
                       time_t waitbegin, time_t waitend) {
    m_sessionId = sessionId;
    m_callId = callId;
    m_agentId = agentId;
    m_agentDn = agentDn;
    m_skill = skill;
    m_caller = caller;
    m_callee = callee;
    m_waitbegin = waitbegin;
    m_waitend = waitend;
}

void callinfo::SetAniDnis(const string& caller, const string& callee) {
    m_caller = caller;
    m_callee = callee;
}

void callinfo::SetAckBegin(time_t t) {
    m_ackbegin = t;
}

void callinfo::SetAckEnd(time_t t) {
    if (0 != m_ackbegin && 0 == m_ackend) {
        m_ackend = t;
    }
}

void callinfo::SetCallBegin(time_t t) {
    m_callbegin = t;
    m_callend = t;
}

void callinfo::SetCallEnd(time_t t) {
    if (0 != m_callbegin) {
        m_callend = t;
    }
}

void callinfo::SetCallType(const ims::PartyAttributeT& callType) {
    m_callType = callType;
}

void callinfo::SetCallDirect(int32_t callDirect) {
    m_callDirect.set_value(callDirect);
}

void callinfo::SetReleaseCause(int32_t releaseCause) {
    m_releaseCause.set_value(releaseCause);
}

void callinfo::SetRecordFilename(const string& recordFilename) {
    m_recordFilename = recordFilename;
}

void callinfo::SetRoutecall() {
    m_routecall = true;
}

bool callinfo::GetRoutecall() {
    return m_routecall;
}

bool callinfo::isValid() {
    return m_sessionId != 0 && m_callId != "";
}

void callinfo::reset() {
    m_sessionId = 0;
    m_callId.clear();
    m_agentId.clear();
    m_agentDn.clear();
    m_caller.clear();
    m_callee.clear();

    m_waitbegin = 0;
    m_waitend = 0;
    m_ackbegin = 0;
    m_ackend = 0;
    m_callbegin = 0;
    m_callend = 0;

    m_callType = ims::PartyAttributeT::P_Unknown;
    m_callDirect = CallDirectT::UNKNOWN;
    m_releaseCause = ReleaseCauseT::UNKNOWN;
    m_recordFilename.clear();

    m_routecall = false;
}

void callinfo::WriteCallLog() {
//     ostringstream strbuf;
//     strbuf << '1'
//            << ',' << m_sessionId
//            << ',' << m_callId
//            << ',' << m_agentId
//            << ',' << m_agentDn
//            << ',' << m_skill
//            << ',' << m_caller
//            << ',' << m_callee
//            << ',' << static_cast<int64_t>(m_waitbegin)
//            << ',' << static_cast<int64_t>(m_waitend)
//            << ',' << static_cast<int64_t>(m_ackbegin)
//            << ',' << static_cast<int64_t>(m_ackend)
//            << ',' << static_cast<int64_t>(m_callbegin)
//            << ',' << static_cast<int64_t>(m_callend)
//            << ',' << m_callType.get_value()
//            << ',' << m_callDirect.get_value()
//            << ',' << m_releaseCause.get_value()
//            << ',' << m_recordFilename;
  //  acd_tool::m_calllogger.WriteLog(strbuf.str().c_str());
	if(m_callbegin==0)
		m_callbegin+=1;
	string starttime = bgcc::TimeUtil::format_time(m_callbegin,"%Y-%m-%d %H:%M:%S");
	if(m_callend==0)
		m_callend+=1;
	string stoptime = bgcc::TimeUtil::format_time(m_callend,"%Y-%m-%d %H:%M:%S");
	string createtime = bgcc::TimeUtil::format_time("%Y-%m-%d %H:%M:%S");
	string strsql="Insert into master_outdial.t_call_info_tbl (user_id, customer_number,call_id,call_start_time,call_end_time,call_state,user_number,call_type,record_file,create_at,skill_id) values ";
	char charsql[512]={0};
	string Numbercalled=m_callee;
	Numbercalled=Numbercalled.erase(0,Numbercalled.find_last_of('/')+1);
	sprintf(charsql,"%s ( %d,'%s','%s','%s','%s', %d,'%s',%d,'%s','%s','%s')",strsql.c_str(),atoi(m_agentId.c_str()),Numbercalled.c_str(),m_callId.c_str(),starttime.c_str(),stoptime.c_str()
		, m_callType.get_value(),m_agentDn.c_str(),m_callDirect.get_value(),m_recordFilename.c_str(),createtime.c_str(),m_skill.c_str());
	SqlInstan::InsertCall(charsql);
}
