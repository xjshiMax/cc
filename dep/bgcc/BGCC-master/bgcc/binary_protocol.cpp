/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  *
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      license.txt
  *********************************************************************/

#include "binary_protocol.h"
#include "log.h"
#include "service_framework.h"
#include "socket_util.h"
#include "server_task.h"

namespace bgcc {

BinaryProtocol::BinaryProtocol(TransportSharedPointer transport)
    : _transport(transport) { }

int32_t BinaryProtocol::writeBool(const bool value)
{
    return _data.append_bool(value);
}

int32_t BinaryProtocol::readBool(char* request, int32_t request_len, bool& value)
{
    char data[sizeof(uint8_t)];
    int32_t ret = readBasic(data, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        value = (UINT8(data) != 0);
    }

    return ret;
}

int32_t BinaryProtocol::writeByte(const int8_t value)
{
    return _data.append_int8(value);
}

int32_t BinaryProtocol::readByte(char* request, int32_t request_len, int8_t& value)
{
    char data[sizeof(int8_t)];
    int32_t ret = readBasic(data, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        value = (INT8(data) != 0);
    }

    return ret;
}

int32_t BinaryProtocol::writeInt16(const int16_t value)
{
    return _data.append_int16(value);
}

int32_t BinaryProtocol::readInt16(char* request, int32_t request_len, int16_t& value)
{
    char data[sizeof(int16_t)];
    int32_t ret = readBasic(data, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        value = INT16(data);
    }

    return ret;
}

int32_t BinaryProtocol::writeInt32(const int32_t value)
{
    return _data.append_int32(value);
}

int32_t BinaryProtocol::readInt32(char* request, int32_t request_len, int32_t& value)
{
    char data[sizeof(int32_t)];
    int32_t ret = readBasic(data, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        value = INT32(data);
    }

    return ret;
}

int32_t BinaryProtocol::writeInt64(const int64_t value)
{
    return _data.append_int64(value);
}

int32_t BinaryProtocol::readInt64(char* request, int32_t request_len, int64_t& value)
{
    char data[sizeof(int64_t)];
    int32_t ret = readBasic(data, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        value = INT64(data);
    }

    return ret;
}

int32_t BinaryProtocol::writeFloat(const float value)
{
    return _data.append_float(value);
}

int32_t BinaryProtocol::readFloat(char* request, int32_t request_len, float& value)
{
    union bytes {
        char b[sizeof(float)];
        int32_t w;
        float f;
    } data;
    int32_t ret = readBasic(data.b, sizeof(data), request, request_len);

    if (sizeof(data) == ret) {
        data.w = INT32(data.b);
        value = data.f;
    }

    return ret;
}

int32_t BinaryProtocol::writeString(const std::string& value)
{
    return _data.append_string(value);
}

int32_t BinaryProtocol::readString(char* request, int32_t request_len, std::string& value)
{
    int32_t len = 0;
    int32_t ret = 0;
    int32_t nread = 0;

    ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, len);
    if (sizeof(int32_t) != ret) {
        return ret;
    }
    nread += ret;

    if (len < 0) {
        return -1;
    } else if (0 == len) {
        value = "";
        return sizeof(int32_t);
    }

    char *buffer = (char*)malloc(len);
    if (buffer) {
        ret = readBasic(buffer, len, OFFSET_PTR(request, nread), request_len - nread);
        if (len == ret) {
            value = std::string(buffer, len);
        }
        free(buffer);
        nread += ret;
        return nread;
    } else {
        BGCC_FATAL("bgcc", "readString Failed(malloc failed)");
        return -1;
    }
}

int32_t BinaryProtocol::writeBinary(const void* data, const int32_t size)
{
    return _data.append_binary(data, size);
}

int32_t BinaryProtocol::readBinary(char *request, int32_t request_len, std::string& value)
{
    return readString(request, request_len, value);
}

int32_t BinaryProtocol::writeMessageBegin(
        const std::string& processor_name,
        const std::string& function_name,
        const MsgTypeID msg_type,
        const SequenceNOType seq_no)
{

    // msg header
    int32_t ret;

    // protocol name: bgcP
    if ((ret = writeByte('b')) != 0) {   //protocol name
        return ret;
    }
    if ((ret = writeByte('g')) != 0) {   //protocol name
        return ret;
    }
    if ((ret = writeByte('c')) != 0) {   //protocol name
        return ret;
    }
    if ((ret = writeByte('P')) != 0) {   //protocol name
        return ret;
    }

    // version 1.0
    if ((ret = writeByte(0x01)) != 0) {   //main version
        return ret;
    }
    if ((ret = writeByte(0x00)) != 0) {   //sub version
        return ret;
    }

    if ((ret = writeByte(0x01)) != 0) {   //proto type
        return ret;
    }

    if ((ret = writeByte(0x00)) != 0) {   //reserved
        return ret;
    }

    if ((ret = writeInt32(0)) != 0) {     //logid
        return ret;
    }

    if ((ret = writeInt32(seq_no)) != 0) { //ticketid
        return ret;
    }

    if ((ret = writeInt32(0)) != 0) {     //body size
        return ret;
    }

    //msg body

    if ((ret = writeString(processor_name)) != 0) { //processor name
        return ret;
    }

    if ((ret = writeInt16(msg_type)) != 0) { //msg type
        return ret;
    }

    if ((ret = writeInt32(seq_no)) != 0) { //ticketid  故意重复
        return ret;
    }

    if ((ret = writeInt16(0)) != 0) {     //function version
        return ret;
    }

    if ((ret = writeString(function_name)) != 0) { //function name
        return ret;
    }

    return 0;
}

//not tosend , no free, no send
//tosend free && clear
int32_t BinaryProtocol::writeMessageEnd(bool tosend)
{
    void *pdata = NULL;
    int32_t size = 0;
    int32_t body_size = 0;
    int32_t ret = _data.get_data(&pdata, size);

    body_size = (int32_t)htonl(size - HEAD_SIZE); /** 除去头的20个字节长度*/

    if (0 == ret && pdata) {
        memcpy(BODY_LEN_PTR(pdata), &body_size, LENGTH_SIZE);

        if (tosend) {
            if (_transport.is_valid()) {
                ret = _transport->write(pdata, size);
            } else {
                ret = -1;
            }

            _data.clear();
        }
    }

    return ret;
}

int32_t BinaryProtocol::readMessageBegin(
    char **req,
    int32_t &request_len,
    std::string& msgName,
    MsgTypeID& msgType,
    SequenceNOType& seqNO,
    ReadItem *pItem)
{

    int32_t ret = 0;
    int16_t t16 = 0;
    int32_t t32 = 0;
    std::string tstr;
    int32_t nread = 0;
    char *request = NULL;
#ifndef _WIN32
    if (pItem && pItem->pTask) { // proxy read
        TaskAsso *pTask = (TaskAsso*)(pItem->pTask);
        BGCC_TRACE("bgcc", "Read Message Begin(fd=%d) construct buffer", pTask->event.fd);
        //while(pItem->psem->try_wait());	//consume all sem value
        pItem->isWait=true;
        if (!pTask->pLoop || pTask->pLoop->add_event(&(pTask->event)) != 0) {
            BGCC_WARN("bgcc", "Read Message Begin(fd=%d) Add to Epoll Failed", pTask->event.fd);
            pItem->isWait=false;
            SocketTool::close(pTask->event.fd);
            return -1;
        }
        if (pItem->psem->wait(DEFAULT_SERVER_TIMEOUT * 2) != 0 || pItem->err) {	//err occur
            pItem->isWait=false;
            BGCC_WARN("bgcc", "Read Message Begin(fd=%d) Wait Timeout Or Err Occur", pTask->event.fd);
            return -1;
        } else {
            pItem->isWait=false;
            request = pItem->item.data;
            *req = pItem->item.data;
            request_len = pItem->item.nread;
        }
    } else
#endif
        if (req) {
            request = *req;
        }

    if (!request) {
        BGCC_WARN("bgcc", "Read Message Begin(fd=%d) request is NULL", _transport->id());
        //ignore head
        for (int32_t i = 0; i < 5; ++i) {
            ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, t32);
            if (ret <= 0 || ret != sizeof(int32_t)) {
                return -1;
            }
            nread += ret;
        }
    }

    //ignore processor name
    ret = readString(OFFSET_PTR(request, nread), request_len - nread, tstr);
    if (ret <= 0 || ret < sizeof(int32_t)) {
        return -1;
    }
    nread += ret;


    // read useful info
    // msgType
    ret = readInt16(OFFSET_PTR(request, nread), request_len - nread, t16);
    if (ret <= 0 || ret != sizeof(int16_t)) {
        return -1;
    }
    nread += ret;
    msgType = (MsgTypeID)t16;

    //ticketid
    ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, t32);
    if (ret <= 0 || ret != sizeof(int32_t)) {
        return -1;
    }
    nread += ret;
    seqNO = (SequenceNOType)t32;

    //version
    ret = readInt16(OFFSET_PTR(request, nread), request_len - nread, t16);
    if (ret <= 0 || ret != sizeof(int16_t)) {
        return -1;
    }
    nread += ret;

    //function_name
    ret = readString(OFFSET_PTR(request, nread), request_len - nread, msgName);
    if (ret <= 0 || ret < sizeof(int32_t)) {
        return -1;
    }
    nread += ret;

    return nread;
}

int32_t BinaryProtocol::readMessageEnd()
{
    return 0;
}

int32_t BinaryProtocol::writeStructBegin(const std::string& name)
{
    return writeString(name);
}

int32_t BinaryProtocol::writeStructEnd()
{
    return 0;
}

int32_t BinaryProtocol::readStructBegin(char *request, int32_t request_len, std::string& name)
{
    int32_t ret = 0;
    if ((ret = readString(OFFSET_PTR(request, 0), request_len, name)) < sizeof(int32_t)) {
        return -1;
    }
    return ret;
}

int32_t BinaryProtocol::readStructEnd()
{
    return 0;
}

int32_t BinaryProtocol::writeFieldBegin(const std::string& name,
        const DataTypeID fieldType,
        const FieldIDType fieldId)
{

    int32_t ret;

    // 先写入fieldType
    ret = writeInt32(fieldType);
    if (0 != ret) {
        return ret;
    }

    ret = writeString(name);
    if (0 != ret) {
        return ret;
    }

    ret = writeInt32(fieldId);
    if (0 != ret) {
    } else {
    }

    return ret;
}

int32_t BinaryProtocol::writeFieldEnd()
{
    return 0;
}

int32_t BinaryProtocol::readFieldBegin(
        char *request,
        int32_t request_len,
        std::string& name,
        DataTypeID& fieldType,
        FieldIDType& fieldID)
{
    int32_t ret = 0;
    int32_t tmp = 0;
    int32_t nread = 0;

    // 先读取fieldType
    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    }
    fieldType = (DataTypeID)tmp;
    nread += ret;

    if (IDSTOP == fieldType) {
        return nread;
    }

    if ((ret = readString(OFFSET_PTR(request, nread), request_len - nread, name)) < sizeof(int32_t)) {
        return -1;
    }
    nread += ret;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    } else {
        fieldID = (FieldIDType)tmp;
    }
    nread += ret;

    return nread;
}

int32_t BinaryProtocol::readFieldEnd()
{
    return 0;
}

int32_t BinaryProtocol::writeFieldStop()
{
    return writeInt32(IDSTOP);
}

int32_t BinaryProtocol::writeMapBegin(const DataTypeID keyType,
        const DataTypeID valueType,
        const int32_t size)
{
    int32_t ret;

    ret = writeInt32(keyType);
    if (0 != ret) {
        return ret;
    }

    ret = writeInt32(valueType);
    if (0 != ret) {
        return ret;
    }

    ret = writeInt32(size);
    if (0 != ret) {
    } else {
    }
    return ret;
}

int32_t BinaryProtocol::writeMapEnd()
{
    return 0;
}

int32_t BinaryProtocol::readMapBegin(
        char *request,
        int32_t request_len,
        DataTypeID& keyType,
        DataTypeID& valueType,
        int32_t& size)
{
    int32_t ret;
    int32_t tmp;
    int32_t nread = 0;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    }
    keyType = (DataTypeID)tmp;
    nread += ret;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    }
    valueType = (DataTypeID)tmp;
    nread += ret;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, size)) != sizeof(int32_t)) {
        return -1;
    }
    nread += ret;

    return nread;
}

int32_t BinaryProtocol::readMapEnd()
{
    return 0;
}

int32_t BinaryProtocol::writeListBegin(const DataTypeID elemType,
        const int32_t size)
{
    int32_t ret;

    ret = writeInt32(elemType);
    if (0 != ret) {
        return ret;
    }

    ret = writeInt32(size);
    if (0 != ret) {
    } else {
    }
    return ret;
}

int32_t BinaryProtocol::writeListEnd()
{
    return 0;
}

int32_t BinaryProtocol::readListBegin(char *request, int32_t request_len, DataTypeID& elemType, int32_t& size)
{
    int32_t ret = 0;
    int32_t tmp = 0;
    int32_t nread = 0;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    }
    elemType = (DataTypeID)tmp;
    nread += ret;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, size)) != sizeof(int32_t)) {
        return -1;
    }
    nread += ret;

    return nread;
}

int32_t BinaryProtocol::readListEnd()
{
    return 0;
}

int32_t BinaryProtocol::writeSetBegin(const DataTypeID elemType,
        const int32_t size)
{
    int32_t ret;

    ret = writeInt32(elemType);
    if (0 != ret) {
        return ret;
    }

    ret = writeInt32(size);
    if (0 != ret) {
    } else {
    }
    return ret;
}

int32_t BinaryProtocol::writeSetEnd()
{
    return 0;
}

int32_t BinaryProtocol::readSetBegin(char *request, int32_t request_len, DataTypeID& elemType, int32_t& size)
{
    int32_t ret = 0;
    int32_t tmp = 0;
    int32_t nread = 0;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, tmp)) != sizeof(int32_t)) {
        return -1;
    }
    elemType = (DataTypeID)tmp;
    nread += ret;

    if ((ret = readInt32(OFFSET_PTR(request, nread), request_len - nread, size)) != sizeof(int32_t)) {
        return -1;
    }
    nread += ret;

    return nread;
}

int32_t BinaryProtocol::readSetEnd()
{
    return 0;
}

int32_t BinaryProtocol::setTransport(TransportSharedPointer transport)
{
    _transport = transport;
    return 0;
}

BinaryProtocol::TransportSharedPointer BinaryProtocol::getTransport()
{
    return _transport;
}

int32_t BinaryProtocol::getDataCopy(void** ppdata, int32_t& size)
{
    if (NULL == ppdata) {
        return -1;
    } else {
        return _data.get_data_copy(ppdata, size);
    }
}

int32_t BinaryProtocol::readBasic(char *dstbuf, int32_t dstbuf_len, const char *srcbuf, int32_t srcbuf_len)
{
    int32_t ret = dstbuf_len;

    if (!srcbuf) { //sock
        if (_transport->read(dstbuf, dstbuf_len) != 0) {
            ret = -1;
        }
    } else {
        if (srcbuf_len < dstbuf_len) {
            ret = -1;
        } else {
            memcpy(dstbuf, srcbuf, dstbuf_len);
        }
    }

    return ret;
}

const unsigned char bp_magic [] = {0x62, 0x67, 0x63, 0x50};//bgcP

const unsigned char bp_hb_hdr[] = {
    bp_magic[0], bp_magic[1], bp_magic[2], bp_magic[3],
    0x01, 0x00, 0x01, 0xff,	//ver(2), proto(1), reverd(1)
    0x00, 0x00, 0x00, 0x00,	//logid
    0x00, 0x00, 0x00, 0x00,	//ticketid
    0x00, 0x00, 0x00, 0x00	//body size
};
}

