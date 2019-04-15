/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  *
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      license.txt
  *********************************************************************/

#include <iostream>

#ifdef _WIN32
#include <io.h>
#include <direct.h>
#define close _close
#define access _access
#define MKDIR(a) _mkdir(a)
#else
#include <sys/stat.h>
#define MKDIR(a) mkdir((a), 0755)
#endif

#include "file_util.h"

namespace bgcc {

int32_t FileUtil::close_r(int32_t fd)
{
    int32_t ret;

    do {
        ret = close(fd);
    } while (-1 == ret && EINTR == errno);
    return ret;
}

int32_t FileUtil::create_directories(const char* path)
{
    int i = 0;
    int ret;
    int len;
    char* path_copy;

    if (NULL == path) {
        return 0;
    }

    path_copy = strdup(path);
    len = strlen(path_copy);

    for (i = 0; i < len; i ++) {
        if ('\\' == path_copy[i] || '/' == path_copy[i]) {
            path_copy[i] = '\0';

            ret = access(path_copy, 0);
            if (ret != 0) {
                ret = MKDIR(path_copy);
                if (ret != 0) {
                    return -1;
                }
            }

            path_copy[i] = '/';
        }
    }

    ret = access(path_copy, 0);
    if (ret != 0) {
        ret = MKDIR(path_copy);
    }

    free(path_copy);
    return ret;
}

#ifdef _WIN32
const char FileUtil::SEP = '\\';
#else
const char FileUtil::SEP = '/';
#endif

}

