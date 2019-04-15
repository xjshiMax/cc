/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef _BGCC2_CONFIGURE_PARSER_H_
#define _BGCC2_CONFIGURE_PARSER_H_

#include <string>
#include <vector>
#include "bgcc_common.h"

namespace bgcc2 {

// 类前置声明
class ConfUnit;

/**
 * @brief 配置解析器，用于解析配置文件或配置字符串
 * @see
 * @note
 * @author  liuxupeng(liuxupeng@baidu.com)
 * @date    2013年10月11日 19时37分32秒
 */
class ConfigureParser {
public:
    /**
     * @brief parse 从配置文件中解析配置
     *
     * @param conf_filename 配置文件名
     * @param conf_unit 配置单元
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 19时39分35秒
     */
    void parse(const std::string& conf_filename, ConfUnit& conf_unit);

    /**
     * @brief parse 从配置文件中解析配置
     *
     * @param file 配置文件对象
     * @param conf_unit 配置单元
     * @see
     * @note
     * @author  liuxupeng(liuxupeng@baidu.com)
     * @date    2013年10月11日 19时40分08秒
     */
    void parse(std::ifstream& conf_file, ConfUnit& conf_unit);

private:
    static const int32_t MAX_LINE_LEN;

    static bool is_white_line(const char* line);
    static bool is_comment_line(const char* line);
    static int32_t handle_line(const char* line, ConfUnit& root, ConfUnit*& current);
    static int32_t handle_as_section(const char* line, std::vector<std::string>& paths);
    static int32_t handle_as_item(const char* line, std::string& key, std::string& value);
    static ConfUnit* push_section(ConfUnit& root, const std::vector<std::string>& paths);
    static int32_t push_item(ConfUnit* current, const std::string& key, const std::string& value);

private:
    std::string _filename;
};

}

#endif // _BGCC2_CONFIGURE_PARSER_H_

