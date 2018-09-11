/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  *
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_FILE_UTIL_H_
#define _BGCC2_FILE_UTIL_H_

#include "bgcc_common.h"

namespace bgcc {

class FileUtil {
public:
    /**
     * @brief close_r 确保close在遇到中断信号后继续被调用
     *
     * @param fd 文件描述符
     *
     * @return
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月12日 14时34分26秒
     */
    static int32_t close_r(int32_t fd);

    /**
     * @brief create_directories 创建级联目录
     *
     * @param path 级联目录名称
     *
     * @return 0表示创建成功
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月31日 15时36分09秒
     */
    static int32_t create_directories(const char* path);

	static const char SEP; /* 路径分隔符 */

};

}
#endif // _BGCC2_FILE_UTIL_H_

