/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC_NET_UTIL_H_
#define _BGCC_NET_UTIL_H_

#include "bgcc_common.h"

namespace bgcc {

class NetUtil {
public:
    /**
     * @brief is_valid_ipv4 判断ipstr是否为合法的ipv4地址
     *
     * @param ipstr ipv4地址
     *
     * @return
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 18时54分26秒
     */
    static bool is_valid_ipv4(const char* ipstr);

    /**
     * @brief is_valid_port 判断portstr是否为合法的端口号
     *
     * @param portstr port字符串
     *
     * @return
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 18时54分57秒
     */
    static bool is_valid_port(const char* portstr);

    /**
     * @brief get_valid_port 将字符串portstr转化为整数值
     *
     * @param portstr
     *
     * @return
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 18时55分41秒
     */
    static uint16_t get_valid_port(const char* portstr);
};

}

#endif // _BGCC_NET_UTIL_H_

