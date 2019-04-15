/***********************************************************************
  * Copyright (c) 2012, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

/**
 * @file     cpp_source_wirter.cpp
 * @brief    
 * @author   liuxupeng(liuxupeng@baidu.com)
 * @version  
 * @date     2012年08月17日 15时13分34秒
 *  
 **/

#include <sys/stat.h>
#include <sys/types.h>
#include <iomanip>
#include "util.h"
#include "cpp_source_writer.h"
#include "bidl_type.h"

CppSourceWriter::CppSourceWriter(const std::string& bidl) :
    _bidl(bidl) {
    }

CppSourceWriter::~CppSourceWriter() {
}

std::string CppSourceWriter::get_bidl_base() const {
    return _bidl.substr(0, _bidl.find_last_of("."));
}

void CppSourceWriter::write_header(const BidlType* bt) {
    if (!bt) {
        return;
    }
    //以下几行可以抽取出来
    if (!GlobalParser::is_dir_exist(g_parser.get_outdir())) {
        MKDIR(g_parser.get_outdir().c_str());
    }

    std::string target = g_parser.get_outdir() + get_bidl_base() + ".h";
    _f.open(target.c_str());
    if (!_f.is_open()) {
        myerror("open %s failed", target.c_str());
        return;
    }

    write_header_include();

    int32_t level = -1;
    write_header_recursive(bt, level);

    write_header_include_end();
    _f.close();
}

void CppSourceWriter::output_implement_const(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }

    const BidlConst* c = dynamic_cast<const BidlConst*>(bt);
    if (!c) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = g_parser.get_desent();

    const BidlType* field_type = c->get_field_type();
    if (!field_type) {
        return;
    }

    const BidlType* value = c->get_value();
    if (!value) {
        return;
    }

    if (field_type->is_container()) {
        _f << level_str << "static " << field_type->get_tag(this) << " create_" << c->get_name() << "() {\n";
        std::string tmp_name;
        output_container_const_value(field_type->get_real_type(), value, level + 1, tmp_name);
        _f << level_str << step << "return " << tmp_name << ";\n";
        _f << level_str << "}\n";
    }

    _f << level_str << c->get_tag(this) << " " << field_type->get_tag(this)
        << " " << c->get_name() << " = ";

    if (field_type->is_container()) {
        _f << "create_" << c->get_name() << "();" << "\n";
    }
    else {
        _f << value->get_tag() << ";" << "\n";
    }
   
}

void CppSourceWriter::output_container_const_value(const BidlType* field_type, const BidlType* value, int32_t level, std::string& name) {
    if (!field_type || !value) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = g_parser.get_desent();
    name = "tmp_" + g_parser.get_tmp_var();

    _f << level_str << field_type->get_tag(this) << " " << name << ";\n\n";

    if (field_type->get_type_id() == BidlType::SEQUENCE) {
        const BidlType* sub_type = dynamic_cast<const BidlSequence*>(field_type)->get_sub_type();
        if (!sub_type) {
            return;
        }
        sub_type = sub_type->get_real_type();
        if (!sub_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator citr;
        if (!sub_type->is_container()) {
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                _f << level_str << name << ".push_back(" << (*citr)->get_tag() << ");\n";
            }
        }
        else {
            std::string child_name;
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                output_container_const_value(sub_type, *citr, level, child_name);
                _f << level_str << name << ".push_back(" << child_name << ");\n";
            }
        }
        _f << "\n";
    }
    else if (field_type->get_type_id() == BidlType::SET) {
        const BidlType* sub_type = dynamic_cast<const BidlSet*>(field_type)->get_sub_type();
        if (!sub_type) {
            return;
        }
        sub_type = sub_type->get_real_type();
        if (!sub_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator citr;
        if (!sub_type->is_container()) {
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                _f << level_str << name << ".insert(" << (*citr)->get_tag() << ");\n";
            }
        }
        else {
            std::string child_name;
            for (citr = children_value.begin(); citr != children_value.end(); ++citr) {
                output_container_const_value(sub_type, *citr, level, child_name);
                _f << level_str << name << ".insert(" << child_name << ");\n";
            }
        }
        _f << "\n";
    }
    else if (field_type->get_type_id() == BidlType::MAP) {
        const BidlType* key_type = dynamic_cast<const BidlMap*>(field_type)->get_key_type();
        if (!key_type) {
            return;
        }
        key_type = key_type->get_real_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = dynamic_cast<const BidlMap*>(field_type)->get_value_type();
        if (!value_type) {
            return;
        }
        value_type = value_type->get_real_type();
        if (!value_type) {
            return;
        }
        
        const std::vector<BidlType*>& children_value = value->get_children();
        std::vector<BidlType*>::const_iterator itr;
        if (!key_type->is_container() && !value_type->is_container()) {
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                _f << level_str << name << ".insert(std::make_pair(" 
                    << tmp_map->get_key_type()->get_tag() << ", " << tmp_map->get_value_type()->get_tag() << "));\n";
            }
        }
        else if (!key_type->is_container() && value_type->is_container()) {
            std::string child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(value_type, tmp_map->get_value_type(), level, child_name);
                _f << level_str << name << ".insert(std::make_pair(" 
                    << tmp_map->get_key_type()->get_tag() << ", " << child_name << "));\n";
            }
        }
        else if (key_type->is_container() && !value_type->is_container()) {
            std::string child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(key_type, tmp_map->get_key_type(), level, child_name);
                _f << level_str << name << ".insert(std::make_pair(" 
                    << child_name << ", " << tmp_map->get_value_type()->get_tag() << "));\n";
            }
        }
        else if (key_type->is_container() && value_type->is_container()) {
            std::string key_child_name;
            std::string value_child_name;
            for (itr = children_value.begin(); itr != children_value.end(); ++itr) {
                BidlMap* tmp_map = dynamic_cast<BidlMap*>(*itr);
                if (!tmp_map) {
                    continue;
                }
                output_container_const_value(key_type, tmp_map->get_key_type(), level, key_child_name);
                output_container_const_value(value_type, tmp_map->get_value_type(), level, value_child_name);
                _f << level_str << name << ".insert(std::make_pair(" 
                    << key_child_name << ", " << value_child_name << "));\n";
            }
        }
        _f << "\n";
    }

}

void CppSourceWriter::output_implement_enum(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }

    const BidlEnum* e = dynamic_cast<const BidlEnum*>(bt);
    if (!e) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    _f << "\n"
        << level_str << "const struct " << class_name << "::desc_t "
        << class_name << "::descs[] = {\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlEnumField* f = dynamic_cast<const BidlEnumField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << "{" << class_name << "::" << f->get_name() 
            << ", \"" << class_name << "::" << f->get_name() << "\"},\n";
    }
    _f << level_str << step << "{" << 0 << ", NULL}\n";
    _f << level_str << "};\n\n";

    _f << level_str << class_name << "::" << class_name << "() ";
    if (children.size() > 0) {
        _f << ": _value(" << (*children.begin())->get_name() << ") {\n";
    }
    else {
        _f << level_str << "{\n";
    }
    _f << level_str << "}\n\n";

    _f << level_str << class_name << "::" << class_name << "(int32_t value) : _value(value) {\n";
    _f << level_str << "}\n\n";

    _f << level_str << "int32_t " << class_name << "::" << "get_value() const {\n";
    _f << level_str << step << "return _value;\n";
    _f << level_str << "}\n\n";

    _f << level_str << "std::string " << class_name << "::get_desc() const {\n";
    _f << level_str << step << "const struct desc_t* ptr = " << class_name << "::descs;\n";
    _f << level_str << step << "while (ptr->desc) {\n";
    _f << level_str << step << step << "if (ptr->value == _value) {\n";
    _f << level_str << step << step << step << "return ptr->desc;\n";
    _f << level_str << step << step << "}\n";
    _f << level_str << step << step << "++ptr;\n";
    _f << level_str << step << "}\n";
    _f << level_str << step << "return \"Unknown value\";\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator==(int32_t value) const {\n";
    _f << level_str << step << "return _value == value;\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator!=(int32_t value) const {\n";
    _f << level_str << step << "return _value != value;\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator< (int32_t value) const {\n";
    _f << level_str << step << "return _value < value;\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator==(const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "return _value == rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator!=(const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "return _value != rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name << "::operator< (const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "return _value < rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool operator==(int32_t value, const " << class_name << "& rhs) {\n";
    _f << level_str << step << "return value == rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool operator!=(int32_t value, const " << class_name << "& rhs) {\n";
    _f << level_str << step << "return value != rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool operator< (int32_t value, const " << class_name << "& rhs) {\n";
    _f << level_str << step << "return value < rhs.get_value();\n";
    _f << level_str << "}\n\n";

    _f << level_str << "std::ostream& operator<<(std::ostream& o, const " << class_name << "& e) {\n";
    _f << level_str << step << "o << e.get_value();\n";
    _f << level_str << step << "return o;\n";
    _f << level_str << "}\n\n";
}

void CppSourceWriter::output_implement_struct_constructor_destructor_operators(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    _f << level_str << class_name << "::" << class_name << "() {\n"
        << level_str << "}\n\n";
    _f << level_str << class_name << "::~" << class_name << "() {\n"
        << level_str << "}\n\n";

    _f << level_str << "bool " << class_name 
        << "::operator==(const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "if (this == &rhs) {\n";
    _f << level_str << step << step << "return true;\n";
    _f << level_str << step << "}\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << "if (" << f->get_name() << " != rhs."
            << f->get_name() << ") {\n"
            << level_str << step << step << "return false;\n"
            << level_str << step << "}\n";
    }
    _f << level_str << step << "return true;\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name 
        << "::operator!=(const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "return !(*this == rhs);\n";
    _f << level_str << "}\n\n";

    _f << level_str << "bool " << class_name 
        << "::operator< (const " << class_name << "& rhs) const {\n";
    _f << level_str << step << "if (this == &rhs) {\n"
        << level_str << step << step << "return false;\n"
        << level_str << step << "}\n\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << "if (" << f->get_name() << " < rhs."
            << f->get_name() << ") {\n"
            << level_str << step << step << "return true;\n"
            << level_str << step << "}\n";
        _f << level_str << step << "else if (rhs." << f->get_name() << " < "
            << f->get_name() << ") {\n"
            << level_str << step << step << "return false;\n"
            << level_str << step << "}\n\n";
    }
    _f << level_str << step << "return false;\n";
    _f << level_str << "}\n\n";
}

void CppSourceWriter::output_implement_struct_read_clause(const BidlType* bt, int32_t level,
        const std::string& field_name) {
    if (!bt) {
        return ;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        _f << level_str << step << step << step << "ret = proto->readBool(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int32_t>(sizeof(uint8_t))) { return ret; }\n";
        _f << level_str << step << step << step << "nread+=ret;\n";
        break;
    case BidlType::INT8:
        _f << level_str << step << step << step << "ret = proto->readByte(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int32_t>(sizeof(int8_t))) { return ret; }\n";
        break;
    case BidlType::INT16:
        _f << level_str << step << step << step << "ret = proto->readInt16(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int16_t>(sizeof(int16_t))) { return ret; }\n";
        break;
    case BidlType::INT32:
        _f << level_str << step << step << step << "ret = proto->readInt32(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int32_t>(sizeof(int32_t))) { return ret; }\n";
        break;
    case BidlType::ENUM:
        {
        std::string tmp_enum_var_name = "ele_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << "int32_t " << tmp_enum_var_name << ";\n";
        _f << level_str << step << step << step << "ret = proto->readInt32(OFFSET_PTR(request, nread), "
            << tmp_enum_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int32_t>(sizeof(int32_t))) { return ret; }\n";
        _f << level_str << step << step << step << field_name << " = " << tmp_enum_var_name << ";\n";
        }
        break;
    case BidlType::INT64:
        _f << level_str << step << step << step << "ret = proto->readInt64(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<int64_t>(sizeof(int64_t))) { return ret; }\n";
        break;
    case BidlType::FLOAT:
        _f << level_str << step << step << step << "ret = proto->readFloat(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret!=static_cast<float>(sizeof(float))) { return ret; }\n";
        break;
    case BidlType::STRING:
        _f << level_str << step << step << step << "ret = proto->readString(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret<static_cast<int32_t>(sizeof(int32_t))) { return ret; }\n";
        break;
    case BidlType::BINARY:
        _f << level_str << step << step << step << "ret = proto->readBinary(OFFSET_PTR(request, nread), "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret<static_cast<int32_t>(sizeof(int32_t))) { return ret; }\n";
        break;
    case BidlType::STRUCT:
        _f << level_str << step << step << step << "ret = " << field_name << ".read(OFFSET_PTR(request, nread), proto);\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";

        std::string size_var_name = "size_" + g_parser.get_tmp_var();
        std::string key_var_name = "ktype_" + g_parser.get_tmp_var();
        std::string value_var_name = "vtype_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << "int32_t " << size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << key_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << value_var_name << ";\n\n";

        _f << level_str << step << step << step << "ret = proto->readMapBegin(OFFSET_PTR(request, nread), "
            << key_var_name << ", " << value_var_name << ", " << size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread+=ret;\n\n";

        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << size_var_name << "; ++i) {\n";
        std::string key_key_var_name = "key_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << key_type->get_tag(this) << " " << key_key_var_name << ";\n\n";
        output_implement_struct_read_clause(key_type->get_real_type(), level + 1, key_key_var_name);
        _f << "\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << value_type->get_tag(this) << "& " << value_value_var_name << " = " << field_name 
            << "[" << key_key_var_name << "];\n";
        output_implement_struct_read_clause(value_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readMapEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
    }
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* sub_type = bidl_set->get_sub_type();
        if (!sub_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";
        std::string size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        _f << level_str << step << step << step << "int32_t " << size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << ele_var_name << ";\n\n";
        _f << level_str << step << step << step << "ret = proto->readSetBegin(OFFSET_PTR(request, nread), "
            << ele_var_name << ", " << size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n\n";
        _f << level_str << step << step << step << "nread+=ret;\n\n";

        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << size_var_name << "; ++i) {\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << sub_type->get_tag(this) << " " << value_value_var_name << ";\n";
        output_implement_struct_read_clause(sub_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << step
            << field_name << ".insert(" << value_value_var_name << ");\n";
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readSetEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        }
    case BidlType::SEQUENCE:
        {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sub_type = bidl_sequence->get_sub_type();
        if (!sub_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";
        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        _f << level_str << step << step << step << "int32_t " << set_size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << ele_var_name << ";\n\n";
        _f << level_str << step << step << step << "ret = proto->readListBegin(OFFSET_PTR(request, nread), "
            << ele_var_name << ", " << set_size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n\n";
        _f << level_str << step << step << step << "nread+=ret;\n\n";

        _f << level_str << step << step << step << field_name << ".reserve(" << set_size_var_name << ");\n";
        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << set_size_var_name << "; ++i) {\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << sub_type->get_tag(this) << " " << value_value_var_name << ";\n";
        output_implement_struct_read_clause(sub_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << step
            << field_name << ".push_back(" << value_value_var_name << ");\n";
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readListEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        }
        break;
	default:
		break;
    }
}

void CppSourceWriter::output_implement_struct_read_clause_from_buffer(
        const BidlType* bt,
        int32_t level,
        const std::string& field_name) {
    if (!bt) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        _f << level_str << step << step << step << "ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::INT8:
        _f << level_str << step << step << step << "ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::INT16:
        _f << level_str << step << step << step << "ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::INT32:
        _f << level_str << step << step << step << "ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::ENUM:
        {
        std::string tmp_enum_var_name = "ele_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << "int32_t " << tmp_enum_var_name << ";\n";
        _f << level_str << step << step << step << "ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, "
            << tmp_enum_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        _f << level_str << step << step << step << field_name << " = " << tmp_enum_var_name << ";\n";
        }
        break;
    case BidlType::STRUCT:
        _f << level_str << step << step << step << "ret = " << field_name << ".read(OFFSET_PTR(request, nread), request_len - nread, proto);\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::INT64:
        _f << level_str << step << step << step << "ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::FLOAT:
        _f << level_str << step << step << step << "ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::STRING:
        _f << level_str << step << step << step << "ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::BINARY:
        _f << level_str << step << step << step << "ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, "
            << field_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n";
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";

        std::string size_var_name = "size_" + g_parser.get_tmp_var();
        std::string key_var_name = "ktype_" + g_parser.get_tmp_var();
        std::string value_var_name = "vtype_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << "int32_t " << size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << key_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << value_var_name << ";\n\n";

        _f << level_str << step << step << step << "ret = proto->readMapBegin("
            << "OFFSET_PTR(request, nread), request_len - nread, "
            << key_var_name << ", " << value_var_name << ", " << size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n\n";

        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << size_var_name << "; ++i) {\n";
        std::string key_key_var_name = "key_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << key_type->get_tag(this) << " " << key_key_var_name << ";\n\n";
        output_implement_struct_read_clause_from_buffer(key_type->get_real_type(), level + 1, key_key_var_name);
        _f << "\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << value_type->get_tag(this) << "& " << value_value_var_name << " = " << field_name 
            << "[" << key_key_var_name << "];\n";
        output_implement_struct_read_clause_from_buffer(value_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readMapEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        }
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* sub_type = bidl_set->get_sub_type();
        if (!sub_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";
        std::string size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        _f << level_str << step << step << step << "int32_t " << size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << ele_var_name << ";\n";
        _f << level_str << step << step << step << "ret = proto->readSetBegin("
            << "OFFSET_PTR(request, nread), request_len - nread, "
            << ele_var_name << ", " << size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n\n";

        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << size_var_name << "; ++i) {\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << sub_type->get_tag(this) << " " << value_value_var_name << ";\n";
        output_implement_struct_read_clause_from_buffer(sub_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << step
            << field_name << ".insert(" << value_value_var_name << ");\n";
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readSetEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        }
    case BidlType::SEQUENCE:
        {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sub_type = bidl_sequence->get_sub_type();
        if (!sub_type) {
            return;
        }

        _f << level_str << step << step << step << field_name << ".clear();\n\n";
        std::string set_size_var_name = "size_" + g_parser.get_tmp_var();
        std::string ele_var_name = "etype_" + g_parser.get_tmp_var();

        _f << level_str << step << step << step << "int32_t " << set_size_var_name << ";\n";
        _f << level_str << step << step << step << "bgcc::DataTypeID " << ele_var_name << ";\n\n";

        _f << level_str << step << step << step << "ret = proto->readListBegin("
            << "OFFSET_PTR(request, nread), request_len - nread, "
            << ele_var_name << ", " << set_size_var_name << ");\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << step << "nread += ret;\n\n";

        _f << level_str << step << step << step << field_name << ".reserve(" << set_size_var_name << ");\n";
        _f << level_str << step << step << step << "for(int32_t i = 0; i < "
            << set_size_var_name << "; ++i) {\n";
        std::string value_value_var_name = "value_" + g_parser.get_tmp_var();
        _f << level_str << step << step << step << step
            << sub_type->get_tag(this) << " " << value_value_var_name << ";\n";
        output_implement_struct_read_clause_from_buffer(sub_type->get_real_type(), level + 1, value_value_var_name);
        _f << level_str << step << step << step << step
            << field_name << ".push_back(" << value_value_var_name << ");\n";
        _f << level_str << step << step << step << "}\n\n";

        _f << level_str << step << step << step << "ret = proto->readListEnd();\n";
        _f << level_str << step << step << step << "if (ret < 0) { return ret; }\n";
        }
        break;
    }
}

void CppSourceWriter::output_implement_struct_function_read_from_buffer(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;

    _f << level_str << "int32_t " << class_name
        << "::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){\n";
    _f << level_str << step << "int32_t ret = 0;\n";
    _f << level_str << step << "std::string fname;\n";
    _f << level_str << step << "int32_t nread = 0;\n";
    _f << level_str << step << "bgcc::DataTypeID ftype;\n";
    _f << level_str << step << "bgcc::FieldIDType fid;\n\n";
    _f << level_str << step << "ret = proto->readStructBegin("
        "OFFSET_PTR(request, nread), request_len - nread, fname);\n";
    _f << level_str << step << "if (ret < 0) { return ret; }\n";
    _f << level_str << step << "nread += ret;\n\n";
    _f << level_str << step << "while(true) {\n";
    _f << level_str << step << step << "ret = proto->readFieldBegin("
        "OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);\n";
    _f << level_str << step << step << "if(ret < 0) { return ret; }\n";
    _f << level_str << step << step << "nread += ret;\n\n";
    _f << level_str << step << step << "if(ftype == bgcc::IDSTOP){\n";
    _f << level_str << step << step << step << "break;\n";
    _f << level_str << step << step << "}\n\n";
    _f << level_str << step << step << "switch(fid) {\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << step << "case " << f->get_field_id() << ":\n";
        
        output_implement_struct_read_clause_from_buffer(f->get_field_type()->get_real_type(), level, f->get_name());
        _f << level_str << step << step << step << "break;\n";
    }

    _f << level_str << step << step << "}\n";
    _f << level_str << step << step << "ret = proto->readFieldEnd();\n";
    _f << level_str << step << step << "if (ret < 0) { return ret; }\n";
    _f << level_str << step << "}\n\n";
    _f << level_str << step << "ret = proto->readStructEnd();\n";
    _f << level_str << step << "if (ret < 0) { return ret; }\n";
    _f << level_str << step << "return nread;\n";
    _f << level_str << "}\n\n";
}

void CppSourceWriter::output_implement_struct_write_clause(
        const BidlType* bt,
        int32_t level,
        const std::string& field_name) {
    if (!bt) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();

    switch(bt->get_type_id()) {
    case BidlType::BOOLEAN:
        _f << level_str << step << "ret = proto->writeBool("
            << field_name << ");\n";
        break;
    case BidlType::INT8:
        _f << level_str << step << "ret = proto->writeByte("
            << field_name << ");\n";
        break;
    case BidlType::INT16:
        _f << level_str << step << "ret = proto->writeInt16("
            << field_name << ");\n";
        break;
    case BidlType::INT32:
        _f << level_str << step << "ret = proto->writeInt32("
            << field_name << ");\n";
        break;
    case BidlType::ENUM:
        _f << level_str << step << "ret = proto->writeInt32("
            << field_name << ".get_value());\n";
        break;
    case BidlType::INT64:
        _f << level_str << step << "ret = proto->writeInt64("
            << field_name << ");\n";
        break;
    case BidlType::FLOAT:
        _f << level_str << step << "ret = proto->writeFloat("
            << field_name << ");\n";
        break;
    case BidlType::STRING:
        _f << level_str << step << "ret = proto->writeString("
            << field_name << ");\n";
        break;
    case BidlType::BINARY:
        _f << level_str << step << "ret = proto->writeBinary("
            << field_name << ".c_str(), " << field_name << ".size()" << ");\n";
        break;
    case BidlType::STRUCT:
        _f << level_str << step << "ret = " << field_name << ".write(proto);\n";
        break;
    case BidlType::MAP:
        {
        const BidlMap* bidl_map = dynamic_cast<const BidlMap*>(bt);
        if (!bidl_map) {
            return;
        }

        const BidlType* key_type = bidl_map->get_key_type();
        if (!key_type) {
            return;
        }

        const BidlType* value_type = bidl_map->get_value_type();
        if (!value_type) {
            return;
        }

        _f << level_str << step << "ret = proto->writeMapBegin("
            << key_type->get_real_type()->get_bgcc_type_name()
            << ", " << value_type->get_real_type()->get_bgcc_type_name()
            << ", " << field_name << ".size());\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";

        std::string citr_name = "citr_" + g_parser.get_tmp_var();

        _f << level_str << step << bidl_map->get_tag(this) << "::const_iterator "
            << citr_name << ";\n";
        _f << level_str << step << "for ("
            << citr_name << " = " << field_name << ".begin(); "
            << citr_name << " != " << field_name << ".end(); ++" << citr_name << ") {\n";
        output_implement_struct_write_clause(key_type->get_real_type(), level + 1, citr_name + "->first");
        output_implement_struct_write_clause(value_type->get_real_type(), level + 1, citr_name + "->second");
        _f << level_str << step << "}\n";
        
        _f << level_str << step << "ret = proto->writeMapEnd();\n";

        }
        break;
    case BidlType::SET:
        {
        const BidlSet* bidl_set = dynamic_cast<const BidlSet*>(bt);
        if (!bidl_set) {
            return;
        }

        const BidlType* set_value_type = bidl_set->get_sub_type();
        if (!set_value_type) {
            return;
        }

        _f << level_str << step << "ret = proto->writeSetBegin("
            << set_value_type->get_real_type()->get_bgcc_type_name() << ", "
            << field_name << ".size());\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        std::string citr_name = "citr_" + g_parser.get_tmp_var();
        _f << level_str << step << bidl_set->get_tag(this) << "::const_iterator "
            << citr_name << ";\n";
        _f << level_str << step << "for ("
            << citr_name << " = " << field_name << ".begin(); "
            << citr_name << " != " << field_name << ".end(); ++" << citr_name << ") {\n";

        output_implement_struct_write_clause(set_value_type->get_real_type(), level + 1, "(*" + citr_name + ")");
        _f << level_str << step << "}\n";
        _f << level_str << step << "ret = proto->writeSetEnd();\n";
        }
        break;
    case BidlType::SEQUENCE:
        {
        const BidlSequence* bidl_sequence = dynamic_cast<const BidlSequence*>(bt);
        if (!bidl_sequence) {
            return;
        }

        const BidlType* sequence_value_type = bidl_sequence->get_sub_type();
        if (!sequence_value_type) {
            return;
        }

        _f << level_str << step << "ret = proto->writeListBegin("
            << sequence_value_type->get_real_type()->get_bgcc_type_name() << ", "
            << field_name << ".size());\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        std::string citr_name = "citr_" + g_parser.get_tmp_var();
        _f << level_str << step << bidl_sequence->get_tag(this) << "::const_iterator "
            << citr_name << ";\n";
        _f << level_str << step << "for ("
            << citr_name << " = " << field_name << ".begin(); "
            << citr_name << " != " << field_name << ".end(); ++" << citr_name << ") {\n";

        output_implement_struct_write_clause(sequence_value_type->get_real_type(), level + 1, "(*" + citr_name + ")");
        _f << level_str << step << "}\n";
        _f << level_str << step << "ret = proto->writeListEnd();\n";
        }
        break;
    }
    _f << level_str << step << "if (ret < 0) { return ret; }\n";
}

void CppSourceWriter::output_implement_struct_function_write(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }

    const BidlStruct* e = dynamic_cast<const BidlStruct*>(bt);
    if (!e) {
        return;
    }

    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();
    std::string class_name = bt->get_name();

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    _f << level_str << "int32_t " << class_name
        << "::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {\n";
    _f << level_str << step << "int32_t ret = 0;\n\n";
    _f << level_str << step << "ret = proto->writeStructBegin(\"" << class_name << "\");\n";
    _f << level_str << step << "if (ret < 0) { return ret; }\n\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << "ret = proto->writeFieldBegin(\"" << f->get_name() << "\", ";

        const BidlType* field_type = f->get_field_type();
        if (!field_type) {
            return;
        }

        _f << field_type->get_real_type()->get_bgcc_type_name();

        _f << ", " << f->get_field_id() << ");\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";

        output_implement_struct_write_clause(field_type->get_real_type(), level, f->get_name());

        _f << level_str << step << "ret = proto->writeFieldEnd();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
    }

    _f << level_str << step << "ret = proto->writeFieldStop();\n";
    _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
    _f << level_str << step << "return proto->writeStructEnd();\n";
    _f << level_str << "}\n";
}

void CppSourceWriter::output_implement_struct(const BidlType* bt, int32_t level) {
    output_implement_struct_constructor_destructor_operators(bt, level);
    output_implement_struct_function_read_from_buffer(bt, level);
    output_implement_struct_function_write(bt, level);
}

void CppSourceWriter::write_header_recursive(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }
    std::string level_str = get_indent(level);

    const BidlNamespace* ns = dynamic_cast<const BidlNamespace*>(bt);
    if (!ns) {
        return;
    }

    if (-1 != level) {
        _f << level_str << "namespace " << bt->get_name() << " {\n";
    }

    const std::vector<BidlType*>&children = ns->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        switch((*citr)->get_type_id()) {
        case BidlType::CONST:
            output_header_const(*citr, level + 1);
            break;
        case BidlType::INCLUDE:
            output_header_include(*citr, level + 1);
            break;
        case BidlType::TYPEDEF:
            output_header_typedef(*citr, level + 1);
            break;
        case BidlType::ENUM:
            output_header_enum(*citr, level + 1);
            break;
        case BidlType::STRUCT:
            output_header_struct(*citr, level + 1);
            break;
        case BidlType::NAMESPACE:
            write_header_recursive(*citr, level + 1);
            break;
        case BidlType::CLASS:
            output_header_class(*citr, level + 1);
            break;
        default:
            break;
        }
    }

    if (-1 != level) {
        _f << level_str << "}\n";
    }
    _f << "\n";
}

void CppSourceWriter::output_header_class_service(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    _f << level_str << t->get_tag(this) << " " << class_name << " : public bgcc::Shareable {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << "virtual ~" << class_name << "() { }\n\n";

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }
        _f << level_str << step << "virtual " << return_type->get_tag(this) << " "<< f->get_name() << "(\n";


        if (f->get_name() == class_name) {
            myerror("%s: %d: error: function name and service name can not be the same: %s\n",
                    f->get_filename().c_str(),
                    f->get_line(),
                    f->get_name().c_str());
        }

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            _f << level_str << step << step;

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            std::string arg_type;
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())) {
                arg_type += "const ";
            }

            arg_type += ftype->get_tag(this);
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())
                    || !b_in) {
                arg_type += " &";
            }

            arg_type += " ";
            _f << arg_type << ff->get_name() << ",\n";
        }

        _f << level_str << step << step << "const std::map<std::string, std::string>& ctx";
        _f << ") = 0;\n\n";
    }

    _f << level_str << "};\n";
    _f << "\n";

}

void CppSourceWriter::output_header_class_args(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_args";

        _f << level_str << "class " << new_class_name << " {\n";
        _f << level_str << "public:\n";
        _f << level_str << step << new_class_name << "();\n";
        _f << level_str << step << "virtual ~" << new_class_name << "();\n";
        _f << "\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << ftype->get_tag(this) << " " << ff->get_name() << ";\n";
            }
        }

        if (children.size() != 0) {
            _f << "\n";
        }
        _f << level_str << step << "bool operator==(const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "bool operator!=(const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "bool operator< (const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "int32_t read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);\n";
        _f << level_str << "};\n\n";
    }
}

void CppSourceWriter::output_header_class_pargs(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_pargs";

        _f << level_str << "class " << new_class_name << " {\n";
        _f << level_str << "public:\n";
        _f << level_str << step << "virtual ~" << new_class_name << "();\n";
        _f << "\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << "const " << ftype->get_tag(this) << "* " << ff->get_name() << ";\n";
            }
        }

        if (children.size() != 0) {
            _f << "\n";
        }
        _f << level_str << step << "int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;\n";
        _f << level_str << "};\n\n";
    }
}

void CppSourceWriter::output_header_class_result(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_result";

        _f << level_str << "class " << new_class_name << " {\n";
        _f << level_str << "public:\n";
        _f << level_str << step << new_class_name << "();\n";
        _f << level_str << step << "virtual ~" << new_class_name << "();\n";
        _f << "\n";

        if (!f->get_return_type()->is_void()) {
            _f << level_str << step << f->get_return_type()->get_tag(this) << " return_value;\n";
        }

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << ftype->get_tag(this) << " " << ff->get_name() << ";\n";
            }
        }

        if (children.size() != 0) {
            _f << "\n";
        }
        _f << level_str << step << "bool operator==(const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "bool operator!=(const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "bool operator< (const " << new_class_name << "& rhs) const;\n";
        _f << level_str << step << "int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;\n";
        _f << level_str << "};\n\n";
    }
}

void CppSourceWriter::output_header_class_presult(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_presult";

        _f << level_str << "class " << new_class_name << " {\n";
        _f << level_str << "public:\n";
        _f << level_str << step << "virtual ~" << new_class_name << "();\n";
        _f << "\n";

        if (!f->get_return_type()->is_void()) {
            _f << level_str << step << f->get_return_type()->get_tag(this) << "* return_value;\n";
        }

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << ftype->get_tag(this) << "* " << ff->get_name() << ";\n";
            }
        }

        if (children.size() != 0) {
            _f << "\n";
        }
        _f << level_str << step << "int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const;\n";
        _f << level_str << "};\n\n";
    }
}

void CppSourceWriter::output_header_class_proxy(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    std::string proxy_name = class_name + "Proxy";
    _f << level_str << "class " << proxy_name << " : public bgcc::BaseProxy {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "bgcc::ServerInfo serverinfo,\n";
    //Modify by Stars 2013-1-7
    _f << level_str << step << step << "int32_t maxConn,\n";
    //End Add
    _f << level_str << step << step << "bgcc::ServiceManager* mgr = NULL,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //Add by Stars 2013-1-7
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << step << "bgcc::ServiceManager* mgr = NULL,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //End Add

    //Modify by Stars 2013-1-22
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "const std::string& proxy_name,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //End Modify

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }
        _f << level_str << step << return_type->get_tag(this) << " "<< f->get_name() << "(\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            _f << level_str << step << step;
            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())) {
                _f << "const ";
            }

            _f << ftype->get_tag(this);
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())
                    || !b_in) {
                _f << "&";
            }

            _f << " " << ff->get_name() << ",\n";
        }

        _f << level_str << step << step << "bool last = false";
        _f << ");\n\n";
    }

    // send and recv
    _f << level_str << "private:\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }
        std::string func_name = f->get_name();

        //send
        _f << level_str << step << "void send_"<< f->get_name() << "(\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << level_str << step << step << "const " << ftype->get_tag(this) << "& " << ff->get_name() << ",\n";
        }

        _f << level_str << step << step << "int32_t seqid,\n";
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn);\n\n";

        //recv
        _f << level_str << step << return_type->get_tag(this) << " recv_" << f->get_name() << "(\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << step << ftype->get_tag(this) << "& " << ff->get_name() << ",\n";
            }

        }
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn);\n\n";
    }

    _f << level_str << "};\n\n";
}

void CppSourceWriter::output_header_class_ssl_proxy(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    std::string proxy_name = "SSL" + class_name + "Proxy";
    _f << level_str << "class " << proxy_name << " : public bgcc::SSLBaseProxy {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "bgcc::ServerInfo serverinfo,\n";
    //Modify by Stars 2013-1-7
    _f << level_str << step << step << "int32_t maxConn,\n";
    //End Add
    _f << level_str << step << step << "bgcc::ServiceManager* mgr = NULL,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //Add by Stars 2013-1-7
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << step << "bgcc::ServiceManager* mgr = NULL,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //End Add

    //Modify by Stars 2013-1-22
    _f << level_str << step << proxy_name << "(\n";
    _f << level_str << step << step << "const std::string& proxy_name,\n";
    _f << level_str << step << step << "int32_t tryCount = 5,\n";
    _f << level_str << step << step << "int32_t tryInterval = 500);\n\n";
    //End Modify

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }
        _f << level_str << step << return_type->get_tag(this) << " "<< f->get_name() << "(\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            _f << level_str << step << step;
            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())) {
                _f << "const ";
            }

            _f << ftype->get_tag(this);
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())
                    || !b_in) {
                _f << "&";
            }

            _f << " " << ff->get_name() << ",\n";
        }

        _f << level_str << step << step << "bool last = false";
        _f << ");\n\n";
    }

    // send and recv
    _f << level_str << "private:\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }
        std::string func_name = f->get_name();

        //send
        _f << level_str << step << "void send_"<< f->get_name() << "(\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << level_str << step << step << "const " << ftype->get_tag(this) << "& " << ff->get_name() << ",\n";
        }

        _f << level_str << step << step << "int32_t seqid,\n";
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn);\n\n";

        //recv
        _f << level_str << step << return_type->get_tag(this) << " recv_" << f->get_name() << "(\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << step << ftype->get_tag(this) << "& " << ff->get_name() << ",\n";
            }

        }
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn);\n\n";
    }

    _f << level_str << "};\n\n";
}


void CppSourceWriter::output_header_class_processor(const BidlClass* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;

    std::string processor_name = class_name + "Processor";
    _f << level_str << "class " << processor_name << " : public bgcc::BaseProcessor {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << processor_name << "(bgcc::SharedPointer<" << class_name << "> intf);\n\n";

    _f << level_str << step << "virtual ~" << processor_name << "(){ }\n\n";

    _f << level_str << step << "virtual int32_t process(\n";
    _f << level_str << step << step << "char* request,\n";
    _f << level_str << step << step << "int32_t request_len,\n";
    _f << level_str << step << step << "bgcc::SharedPointer<bgcc::IProtocol> proto);\n\n";

    _f << level_str << step << "virtual std::string get_name() const;\n\n";
    _f << level_str << "protected:\n";
    _f << level_str << step << "virtual int32_t do_function__(\n";
    _f << level_str << step << step << "char* request,\n";
    _f << level_str << step << step << "int32_t request_len,\n";
    _f << level_str << step << step << "bgcc::SharedPointer<bgcc::IProtocol> proto,\n";
    _f << level_str << step << step << "const std::string& fname, int32_t seqid);\n\n";
    _f << level_str << step << "bgcc::SharedPointer<" << class_name << "> __intf;\n\n";
    _f << level_str << "private:\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        _f << level_str << step << "int32_t do_" << func_name << "(\n";
        _f << level_str << step << step << "char* request,\n";
        _f << level_str << step << step << "int32_t request_len,\n";
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::IProtocol> proto,\n";
        _f << level_str << step << step << "int32_t seqid);\n\n";
    }

    _f << level_str << step << "typedef int32_t (" << processor_name << "::* do_function_ptr)(\n";
    _f << level_str << step << step << "char* request,\n";
    _f << level_str << step << step << "int32_t request_len,\n";
    _f << level_str << step << step << "bgcc::SharedPointer<bgcc::IProtocol> proto,\n";
    _f << level_str << step << step << "int32_t seqid);\n\n";
    _f << level_str << step << "std::map<std::string, do_function_ptr> __fun_map;\n";


    _f << level_str << "};\n";
}

void CppSourceWriter::output_implement_class(const BidlType* bt, int32_t level) {
    const BidlClass* t = dynamic_cast<const BidlClass*>(bt);
    if (!t) {
        return;
    }

    output_implement_class_args(t, level);
    output_implement_class_pargs(t, level);
    output_implement_class_result(t, level);
    output_implement_class_presult(t, level);
    output_implement_class_proxy(t, level);
    output_implement_class_ssl_proxy(t, level);
    output_implement_class_processor(t, level);
}

void CppSourceWriter::output_implement_class_processor(
        const BidlType* t,
        int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    std::string processor_name = class_name + "Processor";

    _f << level_str << processor_name << "::" << processor_name
        << "(bgcc::SharedPointer<" << class_name << "> intf) :\n";
    _f << level_str << step << "bgcc::BaseProcessor(), __intf(intf) {\n";
    for (citr = children.begin(); citr != children.end(); ++citr) {
        BidlFunction* f = dynamic_cast<BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        _f << level_str << step << "__fun_map[\""
            << func_name << "\"] = &" << processor_name 
            << "::do_" << func_name << ";\n";
    }
    _f << level_str << "}\n\n";

    _f << level_str << "int32_t " << processor_name << "::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {\n";
    _f << level_str << step << "int32_t ret = 0;\n";
    _f << level_str << step << "bgcc::MsgTypeID mtype;\n";
    _f << level_str << step << "int32_t seqid;\n";
    _f << level_str << step << "std::string fname;\n";
    _f << level_str << step << "int32_t nread = 0;\n";
    _f << level_str << step << "ret = proto->readMessageBegin(&request, request_len, fname, mtype, seqid);\n";
    _f << level_str << step << "if (ret < 0) { return ret;}\n";
    _f << level_str << step << "nread += ret;\n";
    _f << level_str << step << "if (mtype != ::bgcc::CALL){\n";
    _f << level_str << step << step << "return -1;\n";
    _f << level_str << step << "}\n";
    _f << level_str << step << "return do_function__(OFFSET_PTR(request, nread), request_len-nread, proto, fname, seqid);\n";
    _f << level_str << "}\n\n";

    _f << level_str << "std::string " << processor_name 
        << "::get_name() const {\n";
    _f << level_str << step << "return \""
        << t->_symtab_name << "\";\n";
    _f << level_str << "}\n\n";

    _f << level_str << "int32_t " << processor_name << "::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, \n";
    _f << level_str << step << "const std::string& fname, int32_t seqid) {\n";
    _f << level_str << step << "std::map<std::string, do_function_ptr>::iterator it;\n";
    _f << level_str << step << "it = __fun_map.find(fname);\n";
    _f << level_str << step << "if (it == __fun_map.end()) {\n";
    _f << level_str << step << step << "return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);\n";
    _f << level_str << step << "}\n\n";

    _f << level_str << step << "return (this->*(it->second))(request, request_len, proto, seqid);\n";
    _f << level_str << "}\n\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        _f << level_str << "int32_t " << processor_name 
            << "::do_" << func_name 
            << "(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {\n";

        _f << level_str << step << "int32_t ret = 0;\n";
        _f << level_str << step << "std::map<std::string, std::string> map;\n\n";

        _f << level_str << step << "int32_t proxy_name_len = INT32(request);\n";
        _f << level_str << step << "std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);\n";
        _f << level_str << step << "request+=(LENGTH_SIZE+proxy_name_len);\n";
        _f << level_str << step << "request_len-=(proxy_name_len+LENGTH_SIZE);\n";
        _f << level_str << step << "typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;\n\n";
        _f << level_str << step << "ITransSharedPointer ITransptr= proto->getTransport();\n";
        _f << level_str << step << "bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());\n";
        _f << level_str << step << "if (pServer) {\n";
        _f << level_str << step << step << "typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;\n";
        _f << level_str << step << step << "PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();\n";
        _f << level_str << step << step << "map[PEER_IP] =  peerptr->GetHost();\n";
        _f << level_str << step << step << "std::string strPort;\n";
        _f << level_str << step << step << "std::stringstream stream;\n";
        _f << level_str << step << step << "stream<<peerptr->GetPort();\n";
        _f << level_str << step << step << "stream>>strPort;\n";
        _f << level_str << step << step << "map[PEER_PORT]= strPort;\n";
        _f << level_str << step << "}\n";
        _f << level_str << step << "map[PROXY_NAME] = proxy_name;\n\n";

        _f << level_str << step << class_name << "_" << f->get_name() << "_args args;\n";
        _f << level_str << step << "ret = args.read(request, request_len, proto);\n";
        _f << level_str << step << "if (ret < 0) { return ret;}\n\n";
        _f << level_str << step << "request += ret;\n";
        _f << level_str << step << "request_len -= ret;\n\n";
        _f << level_str << step << "ret = proto->readMessageEnd();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
        _f << level_str << step << class_name << "_" << f->get_name() << "_result result;\n";
        _f << level_str << step;
        if (!f->get_return_type()->is_void()) {
            _f << "result.return_value = ";
        }
        _f << "__intf->"
            << f->get_name() << "(";


        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << "args." << ff->get_name() << ", ";
            }
            else if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << "result." << ff->get_name() << ", ";
            }
        }

        _f << "map);\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << "result." << ff->get_name() << " = args." << ff->get_name() << ";\n";
            }
        }
        _f << level_str << step << "ret = proto->writeMessageBegin(\""
            << t->_symtab_name << "\", \""
            << f->get_name() << "\", ::bgcc::REPLY, seqid);\n";
        _f << level_str << step << "if (ret < 0) { return ret;}\n";
        _f << level_str << step << "ret = result.write(proto);\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
        _f << level_str << step << "ret = proto->writeMessageEnd();\n";
        _f << level_str << step << "return ret;\n";

        _f << level_str << "}\n\n";
    }
}

void CppSourceWriter::output_implement_class_proxy(const BidlType* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    std::string proxy_name = class_name + "Proxy";

    _f << level_str << proxy_name << "::" << proxy_name << "(\n";

    _f << level_str << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << "int32_t maxConn,\n";
    _f << level_str << step << "bgcc::ServiceManager* mgr,\n";
    _f << level_str << step << "int32_t tryCount,\n";
    _f << level_str << step << "int32_t tryInterval) :\n";
    //Modify by Stars 2013-1-6
    _f << level_str << step << "bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){\n";
    //End Modify
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << "}\n\n";

    //Add By Stars 2013-1-7
    _f << level_str << proxy_name << "::" << proxy_name << "(\n";
    _f << level_str << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << "bgcc::ServiceManager* mgr,\n";
    _f << level_str << step << "int32_t tryCount,\n";
    _f << level_str << step << "int32_t tryInterval) :\n";
    _f << level_str << step << "bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){\n";
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << "}\n\n";
    //End Add

    //Modify by Stars 2013-1-22
    _f << level_str << proxy_name << "::" << proxy_name <<
        "(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :\n";
    _f << level_str << step << "bgcc::BaseProxy(bgcc::ServerInfo(\"\", 0), 0, true, NULL, tryCount, tryInterval){\n";
    //End Modify
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << step << step << "_use_existing_socket  = true;\n";
    _f << level_str << step << step << "_name=proxy_name;\n";
    _f << level_str << "}\n\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        _f << level_str << return_type->get_tag(this) << " "
            << proxy_name << "::" << f->get_name() << "(";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())) {
                _f << "const ";
            }

            _f << ftype->get_tag(this);
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())
                    || !b_in) {
                _f << "&";
            }

            _f << " " << ff->get_name() << ", ";
        }

        _f << "bool /*last*/";
        _f << ") {\n";
        if (!f->get_return_type()->is_void()) {
            _f << level_str << step <<
                f->get_return_type()->get_tag(this) << " return_value";
            if(f->get_return_type()->is_basic())
            {
                if(f->get_return_type()->get_type_id() == BidlType::BOOLEAN)
                {
                    _f << " = false";
                }
                else if(f->get_return_type()->get_type_id() == BidlType::STRING)
                {
                    _f << " = \"\"";
                }
                else if(f->get_return_type()->get_type_id() == BidlType::BINARY)
                {
                    _f << " = \"\"";
                }
                else
                {
                    _f << " = 0";
                }
            }
            _f << ";\n";
        }
        _f << level_str << step << "int tryCount = 0;\n";

        _f << level_str << step << "do{\n";
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();\n";
        _f << level_str << step << step << "if(conn.is_valid()&&conn->proto.is_valid()){\n";
        _f << level_str << step << step << step << "send_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << ff->get_name() << ", ";
        }
        _f << "_seqid, conn);\n";
        _f << level_str << step << step << step << "if(get_errno()==0){\n";
        _f << level_str << step << step << step << step;
        if (!f->get_return_type()->is_void()) {
            _f << "return_value = ";
        }
        _f << "recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << ff->get_name() << ", ";
            }
        }
        _f << "conn);\n";
        _f << level_str << step << step << step << step << "free_Conn(conn, get_errno());\n";
        _f << level_str << step << step << step << "}\n";
        _f << level_str << step << step << "}\n";
        _f << level_str << step << step << "else{\n";
        _f << level_str << step << step << step << "set_errno(-1);\n";
        _f << level_str << step << step << "}\n";
        _f << level_str << step << "}while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);\n\n";

        _f << level_str << step << "return ";
        if (!f->get_return_type()->is_void()) {
            _f << "return_value";
        }
        _f << ";\n";
        _f << level_str << "}\n\n";


        //send_XXX method
        _f << level_str << "void "<< proxy_name << "::send_"<< f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << "const " << ftype->get_tag(this) << "& " << ff->get_name() << ", ";
        }

        _f << "int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {\n";
        _f << level_str << step << "bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;\n";
        _f << level_str << step << "int32_t ret_code = 0;\n";
        _f << level_str << step << "set_errno(ret_code);\n\n";
        _f << level_str << step << "ret_code = proto->writeMessageBegin(_whoami.c_str(), \""
            << f->get_name() << "\", bgcc::CALL, seqid);\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << "ret_code = proto->writeString(get_name());\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << class_name << "_" << f->get_name() << "_pargs pargs;\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << "pargs." << ff->get_name() << " = &" << ff->get_name() << ";\n";
            }
        }
        _f << level_str << step << "ret_code = pargs.write(proto);\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << "proto->writeMessageEnd();\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n";
        _f << level_str << "}\n\n";

        //recv_XXX method
        _f << level_str << return_type->get_tag(this)
            << " " << proxy_name << "::recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << ftype->get_tag(this) << "& " << ff->get_name() << ", ";
            }

        }
        _f << "bgcc::SharedPointer<bgcc::ConnInfo> conn) {\n";

        if (!return_type->is_void()) {
            _f << level_str << step
                << return_type->get_tag(this) << " ret_val";
            if(return_type->is_pod())
            {
                if(return_type->get_type_id() == BidlType::BOOLEAN)
                {
                    _f << " = false";
                }
                else if(return_type->get_type_id() == BidlType::STRING)
                {
                    _f << " = \"\"";
                }
                else if(return_type->get_type_id() == BidlType::BINARY)
                {
                    _f << " = \"\"";
                }
                else
                {
                    _f << " = 0";
                }
            }
            _f << ";\n";
        }
        _f << level_str << step << "bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;\n";
        _f << level_str << step << "int32_t ret_code=0;\n";
        _f << level_str << step << "std::string fname;\n";
        _f << level_str << step << "bgcc::MsgTypeID  msg_type=bgcc::CALL;\n";
        _f << level_str << step << "int32_t msg_seqid=0;\n";
        _f << level_str << step << "char *read_buf=NULL;\n";
        _f << level_str << step << "int32_t read_buf_len = 0;\n";
        _f << level_str << step << class_name << "_" << f->get_name() << "_presult presult;\n";
        _f << level_str << step << "set_errno(ret_code);\n\n";

        _f << level_str << step << "if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE\n";
		_f << level_str << step << step << "&&msg_type==bgcc::REPLY\n" ;
		_f << level_str << step << step << "&&fname==\""<< f->get_name() << "\"){\n";
        if (!return_type->is_void()) {
            _f << level_str << step << step << "presult.return_value = &ret_val;\n";
        }
		for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
			const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
	            continue;
		    }
			const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
	            continue;
		    }

			if (ff->get_field_direction() && (
						(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
						|| (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
				_f << level_str << step << step << "presult."
					<< ff->get_name() << " = &" << ff->get_name() << ";\n";
			}
		}
        _f << level_str << step << step << "ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);\n";
        _f << level_str << step << step << "if(ret_code>0) { ret_code=proto->readMessageEnd();}\n";
        _f << level_str << step << "}\n";
        _f << level_str << step << "else{\n";
        _f << level_str << step << step << "ret_code=-1;\n";
        _f << level_str << step << "}\n";

        _f << level_str << step << "set_errno(ret_code);\n";
        _f << level_str << step << "return";
        if (!f->get_return_type()->is_void()) {
            _f << " ret_val";
        }
        _f << ";\n";

        _f << level_str << "}\n\n";
    }
}

void CppSourceWriter::output_implement_class_ssl_proxy(const BidlType* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    std::string proxy_name = "SSL" + class_name + "Proxy";

    _f << level_str << proxy_name << "::" << proxy_name << "(\n";

    _f << level_str << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << "int32_t maxConn,\n";
    _f << level_str << step << "bgcc::ServiceManager* mgr,\n";
    _f << level_str << step << "int32_t tryCount,\n";
    _f << level_str << step << "int32_t tryInterval) :\n";
    //Modify by Stars 2013-1-6
    _f << level_str << step << "bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){\n";
    //End Modify
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << "}\n\n";

    //Add By Stars 2013-1-7
    _f << level_str << proxy_name << "::" << proxy_name << "(\n";
    _f << level_str << step << "bgcc::ServerInfo serverinfo,\n";
    _f << level_str << step << "bgcc::ServiceManager* mgr,\n";
    _f << level_str << step << "int32_t tryCount,\n";
    _f << level_str << step << "int32_t tryInterval) :\n";
    _f << level_str << step << "bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){\n";
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << "}\n\n";
    //End Add

    //Modify by Stars 2013-1-22
    _f << level_str << proxy_name << "::" << proxy_name <<
        "(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :\n";
    _f << level_str << step << "bgcc::SSLBaseProxy(bgcc::ServerInfo(\"\", 0), 0, true, NULL, tryCount, tryInterval){\n";
    //End Modify
    _f << level_str << step << step << "_whoami = \"" << t->_symtab_name << "\";\n";
    _f << level_str << step << step << "_use_existing_socket  = true;\n";
    _f << level_str << step << step << "_name=proxy_name;\n";
    _f << level_str << "}\n\n";

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        const BidlType* return_type = f->get_return_type();
        if (!return_type) {
            continue;
        }

        _f << level_str << return_type->get_tag(this) << " "
            << proxy_name << "::" << f->get_name() << "(";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            bool b_in = false;
            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()) {
                b_in = true;
            }

            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())) {
                _f << "const ";
            }

            _f << ftype->get_tag(this);
            if ((b_in && !ftype->is_pod() && !ftype->is_identifier())
                    || (b_in && ftype->is_identifier() && !ftype->get_real_type()->is_pod())
                    || !b_in) {
                _f << "&";
            }

            _f << " " << ff->get_name() << ", ";
        }

        _f << "bool /*last*/";
        _f << ") {\n";
        if (!f->get_return_type()->is_void()) {
            _f << level_str << step <<
                f->get_return_type()->get_tag(this) << " return_value";
            if(f->get_return_type()->is_basic())
            {
                if(f->get_return_type()->get_type_id() == BidlType::BOOLEAN)
                {
                    _f << " = false";
                }
                else if(f->get_return_type()->get_type_id() == BidlType::STRING)
                {
                    _f << " = \"\"";
                }
                else if(f->get_return_type()->get_type_id() == BidlType::BINARY)
                {
                    _f << " = \"\"";
                }
                else
                {
                    _f << " = 0";
                }
            }
            _f << ";\n";
        }
        _f << level_str << step << "int tryCount = 0;\n";

        _f << level_str << step << "do{\n";
        _f << level_str << step << step << "bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();\n";
        _f << level_str << step << step << "if(conn.is_valid()&&conn->proto.is_valid()){\n";
        _f << level_str << step << step << step << "send_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << ff->get_name() << ", ";
        }
        _f << "_seqid, conn);\n";
        _f << level_str << step << step << step << "if(get_errno()==0){\n";
        _f << level_str << step << step << step << step;
        if (!f->get_return_type()->is_void()) {
            _f << "return_value = ";
        }
        _f << "recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << ff->get_name() << ", ";
            }
        }
        _f << "conn);\n";
        _f << level_str << step << step << step << step << "free_Conn(conn, get_errno());\n";
        _f << level_str << step << step << step << "}\n";
        _f << level_str << step << step << "}\n";
        _f << level_str << step << step << "else{\n";
        _f << level_str << step << step << step << "set_errno(-1);\n";
        _f << level_str << step << step << "}\n";
        _f << level_str << step << "}while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);\n\n";

        _f << level_str << step << "return ";
        if (!f->get_return_type()->is_void()) {
            _f << "return_value";
        }
        _f << ";\n";
        _f << level_str << "}\n\n";


        //send_XXX method
        _f << level_str << "void "<< proxy_name << "::send_"<< f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction()
                    &&(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()) {
                continue;
            }

            _f << "const " << ftype->get_tag(this) << "& " << ff->get_name() << ", ";
        }

        _f << "int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {\n";
        _f << level_str << step << "bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;\n";
        _f << level_str << step << "int32_t ret_code = 0;\n";
        _f << level_str << step << "set_errno(ret_code);\n\n";
        _f << level_str << step << "ret_code = proto->writeMessageBegin(_whoami.c_str(), \""
            << f->get_name() << "\", bgcc::CALL, seqid);\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << "ret_code = proto->writeString(get_name());\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << class_name << "_" << f->get_name() << "_pargs pargs;\n";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << "pargs." << ff->get_name() << " = &" << ff->get_name() << ";\n";
            }
        }
        _f << level_str << step << "ret_code = pargs.write(proto);\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n\n";
        _f << level_str << step << "proto->writeMessageEnd();\n";
        _f << level_str << step << "if (ret_code < 0) { set_errno(ret_code); return;}\n";
        _f << level_str << "}\n\n";

        //recv_XXX method
        _f << level_str << return_type->get_tag(this)
            << " " << proxy_name << "::recv_" << f->get_name() << "(";
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && (
                        (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << ftype->get_tag(this) << "& " << ff->get_name() << ", ";
            }

        }
        _f << "bgcc::SharedPointer<bgcc::ConnInfo> conn) {\n";

        if (!return_type->is_void()) {
            _f << level_str << step
                << return_type->get_tag(this) << " ret_val";
            if(return_type->is_pod())
            {
                if(return_type->get_type_id() == BidlType::BOOLEAN)
                {
                    _f << " = false";
                }
                else if(return_type->get_type_id() == BidlType::STRING)
                {
                    _f << " = \"\"";
                }
                else if(return_type->get_type_id() == BidlType::BINARY)
                {
                    _f << " = \"\"";
                }
                else
                {
                    _f << " = 0";
                }
            }
            _f << ";\n";
        }
        _f << level_str << step << "bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;\n";
        _f << level_str << step << "int32_t ret_code=0;\n";
        _f << level_str << step << "std::string fname;\n";
        _f << level_str << step << "bgcc::MsgTypeID  msg_type=bgcc::CALL;\n";
        _f << level_str << step << "int32_t msg_seqid=0;\n";
        _f << level_str << step << "char *read_buf=NULL;\n";
        _f << level_str << step << "int32_t read_buf_len = 0;\n";
        _f << level_str << step << class_name << "_" << f->get_name() << "_presult presult;\n";
        _f << level_str << step << "set_errno(ret_code);\n\n";

        _f << level_str << step << "if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE\n";
		_f << level_str << step << step << "&&msg_type==bgcc::REPLY\n" ;
		_f << level_str << step << step << "&&fname==\""<< f->get_name() << "\"){\n";
        if (!return_type->is_void()) {
            _f << level_str << step << step << "presult.return_value = &ret_val;\n";
        }
		for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
			const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
	            continue;
		    }
			const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
	            continue;
		    }

			if (ff->get_field_direction() && (
						(dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
						|| (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
				_f << level_str << step << step << "presult."
					<< ff->get_name() << " = &" << ff->get_name() << ";\n";
			}
		}
        _f << level_str << step << step << "ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);\n";
        _f << level_str << step << step << "if(ret_code>0) { ret_code=proto->readMessageEnd();}\n";
        _f << level_str << step << "}\n";
        _f << level_str << step << "else{\n";
        _f << level_str << step << step << "ret_code=-1;\n";
        _f << level_str << step << "}\n";

        _f << level_str << step << "set_errno(ret_code);\n";
        _f << level_str << step << "return";
        if (!f->get_return_type()->is_void()) {
            _f << " ret_val";
        }
        _f << ";\n";

        _f << level_str << "}\n\n";
    }
}


void CppSourceWriter::output_implement_class_result_write(
        const BidlType* bt,
        int32_t level, 
        const std::string& field_name) {
    output_implement_struct_write_clause(bt, level, field_name);
}

void CppSourceWriter::output_implement_class_presult_read(
        const BidlType* bt,
        int32_t level, 
        const std::string& field_name) {
    output_implement_struct_read_clause_from_buffer(bt, level, field_name);
}

void CppSourceWriter::output_implement_class_presult(
        const BidlType* t,
        int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_presult";

        _f << level_str << new_class_name << "::~"
            << new_class_name << "() {\n";
        _f << level_str << "}\n\n";

        _f << level_str << "int32_t " << new_class_name
            << "::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {\n";

        _f << level_str << step << "int32_t ret=0;\n";
        _f << level_str << step << "int32_t nread=0;\n";
        _f << level_str << step << "std::string fname;\n";
        _f << level_str << step << "bgcc::DataTypeID ftype;\n";
        _f << level_str << step << "bgcc::FieldIDType fid; \n\n";

        _f << level_str << step << "ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "nread+=ret;\n\n";

        _f << level_str << step << "while(true) {\n";
        _f << level_str << step << step << "ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);\n";
        _f << level_str << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << "nread+=ret;\n\n";
        _f << level_str << step << step << "if (ftype == bgcc::IDSTOP) {\n";
        _f << level_str << step << step << step << "break;\n";
        _f << level_str << step << step << "}\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;

        int field_count = 0;
        bool is_return_void = f->get_return_type()->is_void();
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                    ++field_count;
            }
        }

        if (0 != field_count || !is_return_void) {
            _f << level_str << step << step << "switch(fid) {\n";

            if (!is_return_void) {
                _f << level_str << step << step << "case 0:\n";
                output_implement_class_presult_read(
                    f->get_return_type()->get_real_type(), level, "(*(return_value))");
                _f << level_str << step << step << step << "break;\n";
            }

            if (0 != field_count) {
                for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
                    const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
                    if (!ff) {
                        continue;
                    }
                    const BidlType* ftype = ff->get_field_type();
                    if (!ftype) {
                        continue;
                    }

                    if (ff->get_field_direction() && 
                        ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                        || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                            _f << level_str << step << step << "case " << (citr2 - children.begin() + 1) << ":\n";
                            output_implement_class_presult_read(
                                ftype->get_real_type(), level, "(*(" + ff->get_name() + "))");
                            _f << level_str << step << step << step << "break;\n";
                    }
                }
            }

            _f << level_str << step << step << "default:\n";
            _f << level_str << step << step << step << "break;\n";
            _f << level_str << step << step << "}\n\n";
        }

        _f << level_str << step << step << "ret = proto->readFieldEnd();\n";
        _f << level_str << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << "nread+=ret; \n";
        _f << level_str << step << "}\n\n";

        _f << level_str << step << "ret=proto->readStructEnd();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "nread+=ret; \n\n";
        _f << level_str << step << "return nread;\n";
        _f << level_str << "}\n\n";
    }
}

void CppSourceWriter::output_implement_class_result(const BidlType* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_result";

        _f << level_str << new_class_name << "::" << new_class_name << "() {\n";
        _f << level_str << "}\n\n";
        _f << level_str << new_class_name << "::~" << new_class_name << "() {\n";
        _f << level_str << "}\n\n";

        //operator==
        _f << level_str << "bool " << new_class_name
            << "::operator==(const " << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "if (this == &rhs) {\n";
        _f << level_str << step << step << "return true;\n";
        _f << level_str << step << "}\n";

        if (!f->get_return_type()->is_void()) {
            _f << level_str << step << "if (return_value != rhs.return_value) {\n";
            _f << level_str << step << step << "return false;\n";
            _f << level_str << step << "}\n";

        }

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << "if (" << ff->get_name() << " != " << "rhs."
                    << ff->get_name() << ") {\n";
                _f << level_str << step << step << "return false;\n";
                _f << level_str << step << "}\n";
            }
        }

        _f << level_str << step << "return true;\n";

        _f << level_str << "}\n\n";

        //operator!=
        _f << level_str << "bool " << new_class_name
            << "::operator!=(const " << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "return !(*this == rhs);\n";
        _f << level_str << "}\n\n";
        
        //operator<
        _f << level_str << "bool " << new_class_name
            << "::operator< (const " << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "if (this == &rhs) {\n";
        _f << level_str << step << step << "return false;\n";
        _f << level_str << step << "}\n";

        if (!f->get_return_type()->is_void()) {
            _f << level_str << step << "if (!(return_value < rhs.return_value)) {\n";
            _f << level_str << step << step << "return false;\n";
            _f << level_str << step << "}\n";

        }

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << "if (!(" << ff->get_name() << " < " << "rhs."
                    << ff->get_name() << ")) {\n";
                _f << level_str << step << step << "return false;\n";
                _f << level_str << step << "}\n";
            }
        }

        _f << level_str << step << "return true;\n";
        _f << level_str << "}\n\n";

        //write
        _f << level_str << "int32_t " << new_class_name 
            << "::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {\n";
        _f << level_str << step << "int32_t ret = 0;\n";
        _f << level_str << step << "ret = proto->writeStructBegin(\""
            << new_class_name << "\");\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";

        if (!f->get_return_type()->is_void()) {
            _f << level_str << step << "ret = proto->writeFieldBegin(\"return_value\", "
                << f->get_return_type()->get_real_type()->get_bgcc_type_name() << ", 0);\n";
            _f << level_str << step << "if (ret < 0) { return ret; }\n";
            output_implement_class_result_write(f->get_return_type()->get_real_type(), level, "return_value");
            _f << level_str << step << "ret = proto->writeFieldEnd();\n";
            _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
        }

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (ff->get_field_direction() && 
                    ( (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_out()
                      || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all())) {
                _f << level_str << step << "ret = proto->writeFieldBegin(\""<< ff->get_name() << "\", "
                    << ftype->get_real_type()->get_bgcc_type_name() << ", " << (citr2 - children.begin() + 1) << ");\n";
                _f << level_str << step << "if (ret < 0) { return ret; }\n";
                output_implement_class_result_write(ftype->get_real_type(), level, ff->get_name());
                _f << level_str << step << "ret = proto->writeFieldEnd();\n";
                _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
            }
        }
        _f << level_str << step << "ret = proto->writeFieldStop();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
        _f << level_str << step << "return proto->writeStructEnd();\n";
        _f << level_str << "}\n\n";
    }
}

void CppSourceWriter::output_implement_class_pargs_write(
        const BidlType* bt,
        int32_t level,
        const std::string& field_name) {
    if (!bt) {
        return;
    }

    output_implement_struct_write_clause(bt, level, field_name);
}

void CppSourceWriter::output_implement_class_pargs(const BidlType* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;

    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_pargs";

        _f << level_str << new_class_name << "::~" << new_class_name << "() {\n";
        _f << level_str << "}\n\n";

        _f << level_str << "int32_t " << new_class_name
            << "::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {\n";
        _f << level_str << step << "int32_t ret = 0;\n";
        _f << level_str << step << "ret = proto->writeStructBegin(\""
            << new_class_name << "\");\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step
                    << "ret = proto->writeFieldBegin(\""
                    << ff->get_name() << "\", " << ftype->get_real_type()->get_bgcc_type_name()
                    << ", " << (citr2 - children.begin() + 1)<< ");\n";
                _f << level_str << step << "if (ret < 0) { return ret; }\n";
                output_implement_class_pargs_write(ftype->get_real_type(), level, "(*(" + ff->get_name() + "))");
                _f << level_str << step
                    << "ret = proto->writeFieldEnd();\n";
                _f << level_str << step << "if (ret < 0) { return ret; }\n\n";
            }
        }

        _f << level_str << step << "ret = proto->writeFieldStop();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "ret = proto->writeStructEnd();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "return ret;\n";
        _f << level_str << "};\n\n";
    }
}

void CppSourceWriter::output_implement_class_args_read(
        const BidlType* bt,
        int32_t level,
        const std::string& field_name) {
    output_implement_struct_read_clause_from_buffer(bt, level, field_name);
}

void CppSourceWriter::output_implement_class_args(const BidlType* t, int32_t level) {
    if (!t) {
        return;
    }
    std::string level_str = get_indent(level);
    std::string class_name = t->get_name();
    std::string step = GlobalParser::get_desent();

    const std::vector<BidlType*>& children = t->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlFunction* f = dynamic_cast<const BidlFunction*>(*citr);
        if (!f) {
            continue;
        }
        std::string func_name = f->get_name();
        std::string new_class_name = class_name + "_" + func_name + "_args";

        _f << level_str << new_class_name << "::" << new_class_name
            << "() {\n";
        _f << level_str << "}\n\n";

        _f << level_str << new_class_name << "::~" << new_class_name
            << "() {\n";
        _f << level_str << "}\n\n";

        _f << level_str << "bool " << new_class_name << "::operator==(const "
            << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "if (this == &rhs) {\n";
        _f << level_str << step << step << "return true;\n";
        _f << level_str << step << "}\n";

        const std::vector<BidlType*>& children = f->get_children();
        std::vector<BidlType*>::const_iterator citr2;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << "if (" << ff->get_name() << " != rhs." << ff->get_name() << ") {\n";
                _f << level_str << step << step << "return false;\n";
                _f << level_str << step << "}\n";
            }
        }
        _f << level_str << step << "return true;\n";
        _f << level_str << "}\n\n";

        _f << level_str << "bool " << new_class_name << "::operator!=(const "
            << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "return !(*this == rhs);\n";
        _f << level_str << "}\n\n";

        _f << level_str << "bool " << new_class_name << "::operator< (const "
            << new_class_name << "& rhs) const {\n";
        _f << level_str << step << "if (this == &rhs) {\n";
        _f << level_str << step << step << "return false;\n";
        _f << level_str << step << "}\n";

        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                _f << level_str << step << "if (!(" << ff->get_name() << " < rhs." << ff->get_name() << ")) {\n";
                _f << level_str << step << step << "return false;\n";
                _f << level_str << step << "}\n";
            }
        }
        _f << level_str << step << "return true;\n";
        _f << level_str << "}\n\n";

        _f << level_str << "int32_t " << new_class_name
            << "::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {\n";
        _f << level_str << step << "int32_t ret = 0; \n";
        _f << level_str << step << "std::string fname;\n";
        _f << level_str << step << "int32_t nread = 0;\n";
        _f << level_str << step << "bgcc::DataTypeID ftype;\n";
        _f << level_str << step << "bgcc::FieldIDType fid; \n\n";
        _f << level_str << step << "ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "nread += ret;\n\n";

        _f << level_str << step << "while (true) {\n";
        _f << level_str << step << step << "ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);\n";
        _f << level_str << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << step << "nread += ret;\n\n";

        _f << level_str << step << step << "if (ftype == bgcc::IDSTOP) {\n";
        _f << level_str << step << step << step << "break;\n";
        _f << level_str << step << step << "}\n\n";

        int field_count = 0;
        for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
            const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
            if (!ff) {
                continue;
            }
            const BidlType* ftype = ff->get_field_type();
            if (!ftype) {
                continue;
            }

            if (!ff->get_field_direction()
                || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                    ++field_count;
            }
        }

        if (0 != field_count) {
            _f << level_str << step << step << "switch (fid) {\n";

            for (citr2 = children.begin(); citr2 != children.end(); ++citr2) {
                const BidlFunctionField* ff = dynamic_cast<const BidlFunctionField*>(*citr2);
                if (!ff) {
                    continue;
                }
                const BidlType* ftype = ff->get_field_type();
                if (!ftype) {
                    continue;
                }

                if (!ff->get_field_direction()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_in()
                    || (dynamic_cast<const BidlFieldDirection*>(ff->get_field_direction()))->is_all()) {
                        _f << level_str << step << step << "case " << (citr2 - children.begin() + 1) << ":\n";
                        _f << level_str << step << step << step << "{\n";
                        output_implement_class_args_read(ftype->get_real_type(), level + 1, ff->get_name());
                        _f << level_str << step << step << step << "}\n";
                        _f << level_str << step << step << step << "break;\n";
                }
            }

            _f << level_str << step << step << "default:\n";
            _f << level_str << step << step << step << "break;\n";

            _f << level_str << step << step << "}\n";
        }

        _f << level_str << step << step << "ret = proto->readFieldEnd();\n";
        _f << level_str << step << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "}\n";

        _f << level_str << step << "ret = proto->readStructEnd();\n";
        _f << level_str << step << "if (ret < 0) { return ret; }\n";
        _f << level_str << step << "return nread;\n";
        _f << level_str << "}\n\n";
    }
}

void CppSourceWriter::output_header_class(const BidlType* bt, int32_t level) {
    const BidlClass* t = dynamic_cast<const BidlClass*>(bt);
    if (!t) {
        return;
    }

    output_header_class_service(t, level);
    output_header_class_args(t, level);
    output_header_class_pargs(t, level);
    output_header_class_result(t, level);
    output_header_class_presult(t, level);
    output_header_class_proxy(t, level);
    output_header_class_ssl_proxy(t, level);
    output_header_class_processor(t, level);
}

void CppSourceWriter::output_header_struct(const BidlType* bt, int32_t level) {
    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();
    std::string class_name = bt->get_name();

    _f << level_str << "class " << class_name << " {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << class_name << "();\n";
    _f << level_str << step << "~" << class_name << "();\n";
    _f << "\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlStructField* f = dynamic_cast<const BidlStructField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << f->get_field_type()->get_tag(this) << " " << f->get_name() << ";\n";
    }
    _f << "\n";

    _f << level_str << step << "bool operator==(const " << class_name << "& rhs) const;\n";
    _f << level_str << step << "bool operator!=(const " << class_name << "& rhs) const;\n";
    _f << level_str << step << "bool operator< (const " << class_name << "& rhs) const;\n";
    _f << level_str << step << "int32_t read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto);\n";
    _f << level_str << step << "int32_t write(bgcc::SharedPointer<bgcc::IProtocol> proto) const;\n";
    _f << level_str << "};\n";
    _f << "\n";
}

void CppSourceWriter::output_header_enum(const BidlType* bt, int32_t level) {
    std::string level_str = get_indent(level);
    std::string step = GlobalParser::get_desent();

    _f << "\n";
    _f << level_str << "class " << bt->get_name() << " {\n";
    _f << level_str << "public:\n";
    _f << level_str << step << "enum {\n";

    const std::vector<BidlType*>& children = bt->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        const BidlEnumField* f = dynamic_cast<const BidlEnumField*>(*citr);
        if (!f) {
            continue;
        }
        _f << level_str << step << step << f->get_name() << " = " << f->get_value();
        if (citr + 1 != children.end()) {
            _f << ",";
        }
        _f << "\n";
    }
    _f << level_str << step << "};\n";
    _f << "\n";

    _f << level_str << step << bt->get_name() << "();\n";
    _f << level_str << step << bt->get_name() << "(int32_t value);\n";
    _f << "\n";

    _f << level_str << step << "int32_t get_value() const;\n";
    _f << level_str << step << "std::string get_desc() const;\n";
    _f << "\n";

    _f << level_str << step << "bool operator==(int32_t value) const;\n";
    _f << level_str << step << "bool operator!=(int32_t value) const;\n";
    _f << level_str << step << "bool operator< (int32_t value) const;\n";
    _f << level_str << step << "bool operator!=(const " << bt->get_name() << "& rhs) const;\n";
    _f << level_str << step << "bool operator==(const " << bt->get_name() << "& rhs) const;\n";
    _f << level_str << step << "bool operator< (const " << bt->get_name() << "& rhs) const;\n";
    _f << "\n";


    _f << level_str << "private:\n";
    _f << level_str << step << "int32_t _value;\n";
    _f << "\n";
    _f << level_str << step << "static const struct desc_t {\n";
    _f << level_str << step << step << "int32_t value;\n";
    _f << level_str << step << step << "const char* desc;\n";
    _f << level_str << step << "} descs[];\n";

    _f << level_str << "};\n";

    _f << level_str << "bool operator==(int32_t value, const " << bt->get_name() << "&);\n";
    _f << level_str << "bool operator!=(int32_t value, const " << bt->get_name() << "&);\n";
    _f << level_str << "bool operator< (int32_t value, const " << bt->get_name() << "&);\n";
    _f << level_str << "std::ostream& operator<<(std::ostream& o, const " << bt->get_name() << "&);\n";
    _f << "\n";
}

void CppSourceWriter::output_header_typedef(const BidlType* bt, int32_t level) {
    std::string level_str = get_indent(level);
    const BidlTypedef* t = dynamic_cast<const BidlTypedef*>(bt);
    if (!t) {
        return;
    }
    _f << level_str << "typedef " << t->get_sub_type()->get_tag(this) << " " << bt->get_name() << ";\n";
}

void CppSourceWriter::output_header_include(const BidlType* bt, int32_t) {
    _f << "#include \"" << replace_string(bt->get_name(), "bidl", "h") << "\"\n";
}

void CppSourceWriter::output_header_const(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }
    const BidlConst* c = dynamic_cast<const BidlConst*>(bt);
    if (!c) {
        return;
    }

    std::string level_str = get_indent(level);
    _f << level_str
        << "extern " << c->get_tag(this) << " " << c->get_field_type()->get_tag(this) 
        << " " << c->get_name() << ";" << std::endl;
}

void CppSourceWriter::write_header_include() {
    if (_f.is_open()) {
        std::string file_macro = "_BIDL2SL_" + string_toupper(get_bidl_base().c_str()) + "_H_";
        _f << "#ifndef " << file_macro << "\n";
        _f << "#define " << file_macro << "\n\n";
        _f << "#include <string>\n"
            "#include <vector>\n"
            "#include <set>\n"
            "#include <map>\n"
            "#include <bgcc.h>\n"
            "\n";
    }
}

void CppSourceWriter::write_header_include_end() {
    _f << "#endif\n";
}

void CppSourceWriter::write_implement(const BidlType* bt) {
    if (!bt) {
        return;
    }
    if (!GlobalParser::is_dir_exist(g_parser.get_outdir())) {
        MKDIR(g_parser.get_outdir().c_str());
    }

    _f.open((g_parser.get_outdir() + get_bidl_base() + ".cpp").c_str());
    if (!_f.is_open()) {
        return;
    }

    _f << "#include \"" << get_bidl_base() << ".h\"\n\n";

    int32_t level = -1;
    write_implement_recursive(bt, level);
    _f.close();
}

void CppSourceWriter::write_implement_recursive(const BidlType* bt, int32_t level) {
    if (!bt) {
        return;
    }
    std::string level_str = get_indent(level);

    const BidlNamespace* ns = dynamic_cast<const BidlNamespace*>(bt);
    if (!ns) {
        return;
    }

    if (-1 != level) {
        _f << level_str << "namespace " << bt->get_name() << " {\n";
    }

    const std::vector<BidlType*>&children = ns->get_children();
    std::vector<BidlType*>::const_iterator citr;
    for (citr = children.begin(); citr != children.end(); ++citr) {
        switch((*citr)->get_type_id()) {
        case BidlType::CONST:
            output_implement_const(*citr, level + 1);
            break;
        case BidlType::STRUCT:
            output_implement_struct(*citr, level + 1);
            break;
        case BidlType::ENUM:
            output_implement_enum(*citr, level + 1);
            break;
        case BidlType::NAMESPACE:
            write_implement_recursive(*citr, level + 1);
            break;
        case BidlType::CLASS:
            output_implement_class(*citr, level + 1);
            break;
        default:
            break;
        }
    }

    if (-1 != level) {
        _f << level_str << "}\n";
    }
    _f << std::endl;
}

std::string CppSourceWriter::get_identifier_tag(const std::string& id) const {
    return replace_string(id, ".", "::");
}

