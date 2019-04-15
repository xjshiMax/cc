/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  *
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  *
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONF_LOADER_H_
#define _BGCC2_CONF_LOADER_H_

#include "bgcc_common.h"
#include <vector>

namespace bgcc {

class ConfUnit;
class ConfLoader;

/**
 * @brief 配置文件加载器
 * @see
 * @note
 * @author  liuxupeng(liuxupeng@baidu.com)
 * @date    2012年06月01日 10时48分10秒
 */
class ConfLoader {
public:
    /**
     * @brief 行最大长度
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月01日 10时46分17秒
     */
    static const int32_t MAX_LINE_LEN;

    /**
     * @brief load_conf 加载配置文件
     *
     * @param conf_filename 配置文件名
     *
     * @return 配置内容的Root;当加载出错时返回NULL
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月01日 10时46分48秒
     */
    static DEPRECATED(ConfUnit* load_conf(const char* conf_filename));

private:
    /**
     * @brief is_white_line 判断line是否为空白行----以空白符组成的行
     *
     * @param line C风格字符串
     *
     * @return true表示line为空白行；否则返回false
     * @see
     * @note 当(line == NULL)时返回false
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月01日 10时45分17秒
     */
    static bool is_white_line(const char* line);

    /**
     * @brief is_comment_line 判断line是否为注释行----以'#'开关的行
     *
     * @param line C风格字符串
     *
     * @return true表示line为注释行；否则返回false
     * @see
     * @note 当(line == NULL)时返回false
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2012年06月01日 10时43分22秒
     */
    static bool is_comment_line(const char* line);

    static int32_t handle_line(const char* line, ConfUnit* root, ConfUnit*& current);

    static int32_t handle_as_section(const char* line, std::vector<std::string>& paths);

    static int32_t handle_as_item(const char* line, std::string& key, std::string& value);

    static ConfUnit* push_section(ConfUnit* root, const std::vector<std::string>& paths);

    static int32_t push_item(ConfUnit* current, const std::string& key,
            const std::string& value);

};
} // bgcc

namespace bgcc2 {
// 类前置声明
class ConfUnit;

class ConfLoader {
public:
    /**
     * @brief load_conf 从配置文件conf_file中加载配置到conf_unit中。
     *
     * @param conf_file 配置文件名称
     * @param conf_unit 配置单元
     *
     * @return 成功返回true；否则返回false。返回false的同时，可能会向标准错误输出打印出错信息。
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 14时10分43秒
     */
    static bool load_conf(const std::string& conf_file, ConfUnit& conf_unit);
};

} // bgcc2


#endif  //_BGCC2_CONF_LOADER_H_
