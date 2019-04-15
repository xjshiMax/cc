/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#include <fstream>
#include "./internal/bgcc_configure_parser.h"
#include "exception.h"
#include "string_util.h"
#include "conf_unit.h"

namespace bgcc2 {

const int32_t ConfigureParser::MAX_LINE_LEN = 512;

void ConfigureParser::parse(const std::string& conf_filename, ConfUnit& conf_unit)
{
    _filename = conf_filename;
    std::ifstream conf_file(conf_filename.c_str());

    if (!conf_file) {
        throw bgcc::ConfigurationException("failed to open conf file: " + conf_filename);
    }

    parse(conf_file, conf_unit);
    conf_file.close();
}

void ConfigureParser::parse(std::ifstream& conf_file, ConfUnit& conf_unit)
{
    if (conf_file.fail()) {
        throw bgcc::ConfigurationException("failed to parse conf file: " + _filename);
    }

    char line[MAX_LINE_LEN];
    ConfUnit* current = &conf_unit;

    while (conf_file.good()) {
        conf_file.getline(line, MAX_LINE_LEN);

        if (is_white_line(line) || is_comment_line(line)) {
            continue;
        }

        if (0 != handle_line(line, conf_unit, current)) {
            break;
        }
    }
}

bool ConfigureParser::is_white_line(const char* line)
{
    if (NULL == line) {
        return false;
    } else {
        return bgcc::StringUtil::trim(line).empty();
    }
}

bool ConfigureParser::is_comment_line(const char* line)
{
    if (NULL == line) {
        return false;
    } else {
        std::string line_trimed = bgcc::StringUtil::ltrim(line);
        return !line_trimed.empty() && ('#' == line_trimed[0]);
    }
}

int32_t ConfigureParser::handle_line(const char* line, ConfUnit& root, ConfUnit*& current)
{
    if (NULL == current) {
        return -1;
    }

    std::vector<std::string> paths;
    std::string key;
    std::string value;

    if (0 == handle_as_section(line, paths)) {
        if (0 == paths.size()) {
            return -1;
        }
        current = push_section(root, paths);
        if (NULL == current) {
            return -1;
        }
    } else if (0 == handle_as_item(line, key, value)) {
        if (0 != push_item(current, key, value)) {
            return -1;
        }
    } else {
        return -1;
    }

    return 0;
}

int32_t ConfigureParser::handle_as_section(const char* line, std::vector<std::string>& paths)
{
    paths.clear();
    std::string line_trimed = bgcc::StringUtil::trim(line);
    int32_t size = (int32_t)line_trimed.size();

    if (size < 2
            || '[' != line_trimed[0]
            || ']' != line_trimed[size - 1]) {
        return -1;
    }

    line_trimed = line_trimed.substr(1, size - 2);
    size -= 2;

    std::vector<std::string> v;
    bgcc::StringUtil::split_string(line_trimed, ".", v, /*filter_empty = */false);
    if (0 == v.size()) {
        return -1;
    }

    std::vector<std::string>::iterator itr;
    for (itr = v.begin(); itr != v.end(); ++itr) {
        std::string s = bgcc::StringUtil::trim(*itr);

        if (s.empty()) {
            return -1;
        } else {
            paths.push_back(s);
        }
    }

    std::vector<std::string>::reverse_iterator ritr;
    ritr = paths.rbegin();
    if (ritr != paths.rend()) {
        ++ritr;
        while (ritr != paths.rend()) {
            if ('@' == (*ritr)[0]) {
                paths.clear();
                return -1;
            }
            ++ritr;
        }
    }
    return 0;
}

int32_t ConfigureParser::handle_as_item(const char* line, std::string& key, std::string& value)
{
    std::string line_trimed = bgcc::StringUtil::trim(line);
    std::string::size_type pos = line_trimed.find_first_of('=');
    if (std::string::npos == pos) {
        return -1;
    } else {
        key = bgcc::StringUtil::trim(line_trimed.substr(0, pos));
        if (key.empty()) {
            return -1;
        }

        if (pos != line_trimed.size() - 1) {
            value = bgcc::StringUtil::trim(line_trimed.substr(pos + 1));
        } else {
            value = "";
        }

        return 0;
    }
}

ConfUnit* ConfigureParser::push_section(ConfUnit& root, const std::vector<std::string>& paths)
{
    int32_t size = (int32_t)paths.size();
    if (0 == size) {
        return NULL;
    }

    ConfUnit* current = &root;
    ConfUnit* son = NULL;
    for (int32_t i = 0; i < size - 1; ++i) {
        if (!current->is_group() || '@' == paths[i][0]) {
            return NULL;
        }
        son = &(*current)[paths[i]];

        if (son->is_null()) { //不存在，则插入
            current->insert(paths[i], new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
            son = &(*current)[paths[i]];
            if (son->is_null()) {
                return NULL;
            }
        }
        current = son;
    }

    if (!current->is_group()) {
        return NULL;
    }

    if ('@' == paths[size - 1][0]) { //array
        std::string p = paths[size - 1].substr(1);
        son = &(*current)[p];
        if (!son->is_null()) { //array已存在
            if (!son->is_array()) { //array不是UT_ARRAY
                return NULL;
            }
            return son->push_back(new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
        }

        current->insert(p, new(std::nothrow) ConfUnit(ConfUnit::UT_ARRAY));
        son = &(*current)[p];
        if (!son->is_array()) {
            return NULL;
        }
        return son->push_back(new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
    } else {
        son = &(*current)[paths[size - 1]];
        if (!son->is_null()) { //居然存在?
            return NULL;
        }
        current->insert(paths[size - 1], new(std::nothrow) ConfUnit(ConfUnit::UT_GROUP));
        son = &(*current)[paths[size - 1]];
        return son;
    }
}

int32_t ConfigureParser::push_item(ConfUnit* current, const std::string& key,
        const std::string& value)
{
    if (NULL == current) {
        return -1;
    }

    ConfUnit& tmp = (*current)[bgcc::StringUtil::trim(key)];
    if (!tmp.is_null()) {
        return -1;
    }

    current->insert(bgcc::StringUtil::trim(key), new(std::nothrow) ConfUnit(bgcc::StringUtil::trim(value)));
    return 0;
}

}

