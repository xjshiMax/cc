#include "math_demo.h"

namespace math {
    static std::vector<bool>  create_ss1() {
        std::vector<bool>  tmp_var1;

        tmp_var1.push_back(true);
        tmp_var1.push_back(false);
        tmp_var1.push_back(false);

        return tmp_var1;
    }
    const std::vector<bool>  ss1 = create_ss1();
    static std::vector<int32_t>  create_ss2() {
        std::vector<int32_t>  tmp_var2;

        tmp_var2.push_back(1);
        tmp_var2.push_back(2);
        tmp_var2.push_back(3);

        return tmp_var2;
    }
    const std::vector<int32_t>  ss2 = create_ss2();
    static std::vector<std::string>  create_ss3() {
        std::vector<std::string>  tmp_var3;

        tmp_var3.push_back("first");
        tmp_var3.push_back("second");

        return tmp_var3;
    }
    const std::vector<std::string>  ss3 = create_ss3();
    static std::vector<float>  create_ss4() {
        std::vector<float>  tmp_var4;

        tmp_var4.push_back(1.1f);
        tmp_var4.push_back(2.2f);
        tmp_var4.push_back(3.3f);

        return tmp_var4;
    }
    const std::vector<float>  ss4 = create_ss4();
    static std::vector<std::set<int32_t> >  create_tt1() {
        std::vector<std::set<int32_t> >  tmp_var5;

        std::set<int32_t>  tmp_var6;

        tmp_var6.insert(1);

        tmp_var5.push_back(tmp_var6);
        std::set<int32_t>  tmp_var7;

        tmp_var7.insert(2);

        tmp_var5.push_back(tmp_var7);
        std::set<int32_t>  tmp_var8;

        tmp_var8.insert(3);

        tmp_var5.push_back(tmp_var8);

        return tmp_var5;
    }
    const std::vector<std::set<int32_t> >  tt1 = create_tt1();
    static std::set<bool>  create_sk1() {
        std::set<bool>  tmp_var9;

        tmp_var9.insert(true);
        tmp_var9.insert(false);
        tmp_var9.insert(false);

        return tmp_var9;
    }
    const std::set<bool>  sk1 = create_sk1();
    static std::set<int32_t>  create_sk2() {
        std::set<int32_t>  tmp_var10;

        tmp_var10.insert(1);
        tmp_var10.insert(2);
        tmp_var10.insert(3);

        return tmp_var10;
    }
    const std::set<int32_t>  sk2 = create_sk2();
    static std::set<std::string>  create_sk3() {
        std::set<std::string>  tmp_var11;

        tmp_var11.insert("first");
        tmp_var11.insert("second");

        return tmp_var11;
    }
    const std::set<std::string>  sk3 = create_sk3();
    static std::set<float>  create_sk4() {
        std::set<float>  tmp_var12;

        tmp_var12.insert(1.1f);
        tmp_var12.insert(2.2f);
        tmp_var12.insert(3.3f);

        return tmp_var12;
    }
    const std::set<float>  sk4 = create_sk4();
    static std::set<std::vector<std::string> >  create_tt2() {
        std::set<std::vector<std::string> >  tmp_var13;

        std::vector<std::string>  tmp_var14;

        tmp_var14.push_back("first");

        tmp_var13.insert(tmp_var14);
        std::vector<std::string>  tmp_var15;

        tmp_var15.push_back("second");
        tmp_var15.push_back("third");

        tmp_var13.insert(tmp_var15);

        return tmp_var13;
    }
    const std::set<std::vector<std::string> >  tt2 = create_tt2();
    static std::map<int32_t, std::string>  create_sm1() {
        std::map<int32_t, std::string>  tmp_var16;

        tmp_var16.insert(std::make_pair(1, "first"));

        return tmp_var16;
    }
    const std::map<int32_t, std::string>  sm1 = create_sm1();
    static std::map<std::vector<int32_t> , std::set<std::string> >  create_tt3() {
        std::map<std::vector<int32_t> , std::set<std::string> >  tmp_var17;

        std::vector<int32_t>  tmp_var18;

        tmp_var18.push_back(1);

        std::set<std::string>  tmp_var19;

        tmp_var19.insert("first");

        tmp_var17.insert(std::make_pair(tmp_var18, tmp_var19));
        std::vector<int32_t>  tmp_var20;

        tmp_var20.push_back(2);

        std::set<std::string>  tmp_var21;

        tmp_var21.insert("second");

        tmp_var17.insert(std::make_pair(tmp_var20, tmp_var21));

        return tmp_var17;
    }
    const std::map<std::vector<int32_t> , std::set<std::string> >  tt3 = create_tt3();
    const b_t be_used = false;
    const bool be_health = true;
    const i8_t i8 = 8;
    const i16_t i16 = 16;
    const i32_t i32 = 32;
    const i64_t i64 = 64;
    const s_t str = "hello";
    const bin_t bin = "data";
    const f_t f = 3.3f;
    Person::Person() {
    }

    Person::~Person() {
    }

    bool Person::operator==(const Person& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (name != rhs.name) {
            return false;
        }
        if (age != rhs.age) {
            return false;
        }
        return true;
    }

    bool Person::operator!=(const Person& rhs) const {
        return !(*this == rhs);
    }

    bool Person::operator< (const Person& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (name < rhs.name) {
            return true;
        }
        else if (rhs.name < name) {
            return false;
        }

        if (age < rhs.age) {
            return true;
        }
        else if (rhs.age < age) {
            return false;
        }

        return false;
    }

    int32_t Person::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, name);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, age);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t Person::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("Person");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("name", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(name);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("age", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(age);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct Color::desc_t Color::descs[] = {
        {Color::RED, "Color::RED"},
        {Color::GREEN, "Color::GREEN"},
        {Color::BLUE, "Color::BLUE"},
        {0, NULL}
    };

    Color::Color() : _value(RED) {
    }

    Color::Color(int32_t value) : _value(value) {
    }

    int32_t Color::get_value() const {
        return _value;
    }

    std::string Color::get_desc() const {
        const struct desc_t* ptr = Color::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool Color::operator==(int32_t value) const {
        return _value == value;
    }

    bool Color::operator!=(int32_t value) const {
        return _value != value;
    }

    bool Color::operator< (int32_t value) const {
        return _value < value;
    }

    bool Color::operator==(const Color& rhs) const {
        return _value == rhs.get_value();
    }

    bool Color::operator!=(const Color& rhs) const {
        return _value != rhs.get_value();
    }

    bool Color::operator< (const Color& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const Color& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const Color& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const Color& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const Color& e) {
        o << e.get_value();
        return o;
    }


    const struct Gender::desc_t Gender::descs[] = {
        {Gender::MALE, "Gender::MALE"},
        {Gender::FEMALE, "Gender::FEMALE"},
        {0, NULL}
    };

    Gender::Gender() : _value(MALE) {
    }

    Gender::Gender(int32_t value) : _value(value) {
    }

    int32_t Gender::get_value() const {
        return _value;
    }

    std::string Gender::get_desc() const {
        const struct desc_t* ptr = Gender::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool Gender::operator==(int32_t value) const {
        return _value == value;
    }

    bool Gender::operator!=(int32_t value) const {
        return _value != value;
    }

    bool Gender::operator< (int32_t value) const {
        return _value < value;
    }

    bool Gender::operator==(const Gender& rhs) const {
        return _value == rhs.get_value();
    }

    bool Gender::operator!=(const Gender& rhs) const {
        return _value != rhs.get_value();
    }

    bool Gender::operator< (const Gender& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const Gender& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const Gender& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const Gender& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const Gender& e) {
        o << e.get_value();
        return o;
    }

    Citizen::Citizen() {
    }

    Citizen::~Citizen() {
    }

    bool Citizen::operator==(const Citizen& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (name != rhs.name) {
            return false;
        }
        if (age != rhs.age) {
            return false;
        }
        if (gender != rhs.gender) {
            return false;
        }
        if (address != rhs.address) {
            return false;
        }
        if (children != rhs.children) {
            return false;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        if (kkk != rhs.kkk) {
            return false;
        }
        return true;
    }

    bool Citizen::operator!=(const Citizen& rhs) const {
        return !(*this == rhs);
    }

    bool Citizen::operator< (const Citizen& rhs) const {
        if (this == &rhs) {
            return false;
        }

        if (name < rhs.name) {
            return true;
        }
        else if (rhs.name < name) {
            return false;
        }

        if (age < rhs.age) {
            return true;
        }
        else if (rhs.age < age) {
            return false;
        }

        if (gender < rhs.gender) {
            return true;
        }
        else if (rhs.gender < gender) {
            return false;
        }

        if (address < rhs.address) {
            return true;
        }
        else if (rhs.address < address) {
            return false;
        }

        if (children < rhs.children) {
            return true;
        }
        else if (rhs.children < children) {
            return false;
        }

        if (xxx < rhs.xxx) {
            return true;
        }
        else if (rhs.xxx < xxx) {
            return false;
        }

        if (kkk < rhs.kkk) {
            return true;
        }
        else if (rhs.kkk < kkk) {
            return false;
        }

        return false;
    }

    int32_t Citizen::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto){
        int32_t ret = 0;
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid;

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if(ret < 0) { return ret; }
            nread += ret;

            if(ftype == bgcc::IDSTOP){
                break;
            }

            switch(fid) {
            case 1:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, name);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, age);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                int32_t ele_var22;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var22);
                if (ret < 0) { return ret; }
                nread += ret;
                gender = ele_var22;
                break;
            case 4:
                ret = address.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 5:
                children.clear();

                int32_t size_var23;
                bgcc::DataTypeID etype_var24;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var24, size_var23);
                if (ret < 0) { return ret; }
                nread += ret;

                children.reserve(size_var23);
                for(int32_t i = 0; i < size_var23; ++i) {
                    std::string value_var25;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var25);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    children.push_back(value_var25);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 6:
                xxx.clear();

                int32_t size_var26;
                bgcc::DataTypeID etype_var27;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var27, size_var26);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var26; ++i) {
                    i32_t value_var28;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var28);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    xxx.insert(value_var28);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            case 7:
                kkk.clear();

                int32_t size_var29;
                bgcc::DataTypeID ktype_var30;
                bgcc::DataTypeID vtype_var31;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var30, vtype_var31, size_var29);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var29; ++i) {
                    int8_t key_var32;

                    ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, key_var32);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    bool& value_var33 = kkk[key_var32];
                    ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, value_var33);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }

        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    int32_t Citizen::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;

        ret = proto->writeStructBegin("Citizen");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("name", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(name);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("age", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(age);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("gender", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(gender.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("address", bgcc::IDSTRUCT, 4);
        if (ret < 0) { return ret; }
        ret = address.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("children", bgcc::IDLIST, 5);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTR, children.size());
        if (ret < 0) { return ret; }
        std::vector<std::string> ::const_iterator citr_var34;
        for (citr_var34 = children.begin(); citr_var34 != children.end(); ++citr_var34) {
            ret = proto->writeString((*citr_var34));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 6);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, xxx.size());
        if (ret < 0) { return ret; }
        std::set<i32_t> ::const_iterator citr_var35;
        for (citr_var35 = xxx.begin(); citr_var35 != xxx.end(); ++citr_var35) {
            ret = proto->writeInt32((*citr_var35));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("kkk", bgcc::IDMAP, 7);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDBYTE, bgcc::IDBOOL, kkk.size());
        if (ret < 0) { return ret; }
        std::map<int8_t, bool> ::const_iterator citr_var36;
        for (citr_var36 = kkk.begin(); citr_var36 != kkk.end(); ++citr_var36) {
            ret = proto->writeByte(citr_var36->first);
            if (ret < 0) { return ret; }
            ret = proto->writeBool(citr_var36->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    const struct AddResult::desc_t AddResult::descs[] = {
        {AddResult::E_SUCCESS, "AddResult::E_SUCCESS"},
        {AddResult::E_OVERFLOW, "AddResult::E_OVERFLOW"},
        {AddResult::E_DOWNFLOW, "AddResult::E_DOWNFLOW"},
        {0, NULL}
    };

    AddResult::AddResult() : _value(E_SUCCESS) {
    }

    AddResult::AddResult(int32_t value) : _value(value) {
    }

    int32_t AddResult::get_value() const {
        return _value;
    }

    std::string AddResult::get_desc() const {
        const struct desc_t* ptr = AddResult::descs;
        while (ptr->desc) {
            if (ptr->value == _value) {
                return ptr->desc;
            }
            ++ptr;
        }
        return "Unknown value";
    }

    bool AddResult::operator==(int32_t value) const {
        return _value == value;
    }

    bool AddResult::operator!=(int32_t value) const {
        return _value != value;
    }

    bool AddResult::operator< (int32_t value) const {
        return _value < value;
    }

    bool AddResult::operator==(const AddResult& rhs) const {
        return _value == rhs.get_value();
    }

    bool AddResult::operator!=(const AddResult& rhs) const {
        return _value != rhs.get_value();
    }

    bool AddResult::operator< (const AddResult& rhs) const {
        return _value < rhs.get_value();
    }

    bool operator==(int32_t value, const AddResult& rhs) {
        return value == rhs.get_value();
    }

    bool operator!=(int32_t value, const AddResult& rhs) {
        return value != rhs.get_value();
    }

    bool operator< (int32_t value, const AddResult& rhs) {
        return value < rhs.get_value();
    }

    std::ostream& operator<<(std::ostream& o, const AddResult& e) {
        o << e.get_value();
        return o;
    }

    Math_ping_args::Math_ping_args() {
    }

    Math_ping_args::~Math_ping_args() {
    }

    bool Math_ping_args::operator==(const Math_ping_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_ping_args::operator!=(const Math_ping_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_ping_args::operator< (const Math_ping_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_ping_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_add_args::Math_add_args() {
    }

    Math_add_args::~Math_add_args() {
    }

    bool Math_add_args::operator==(const Math_add_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (a != rhs.a) {
            return false;
        }
        if (b != rhs.b) {
            return false;
        }
        return true;
    }

    bool Math_add_args::operator!=(const Math_add_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_args::operator< (const Math_add_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(a < rhs.a)) {
            return false;
        }
        if (!(b < rhs.b)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, a);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 2:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, b);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_test_citizen_args::Math_test_citizen_args() {
    }

    Math_test_citizen_args::~Math_test_citizen_args() {
    }

    bool Math_test_citizen_args::operator==(const Math_test_citizen_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (ins != rhs.ins) {
            return false;
        }
        if (alls != rhs.alls) {
            return false;
        }
        return true;
    }

    bool Math_test_citizen_args::operator!=(const Math_test_citizen_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_test_citizen_args::operator< (const Math_test_citizen_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(ins < rhs.ins)) {
            return false;
        }
        if (!(alls < rhs.alls)) {
            return false;
        }
        return true;
    }

    int32_t Math_test_citizen_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = ins.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            case 3:
                {
                    ret = alls.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_boolean_args::Math_get_boolean_args() {
    }

    Math_get_boolean_args::~Math_get_boolean_args() {
    }

    bool Math_get_boolean_args::operator==(const Math_get_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_boolean_args::operator!=(const Math_get_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_boolean_args::operator< (const Math_get_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_boolean_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int8_args::Math_get_int8_args() {
    }

    Math_get_int8_args::~Math_get_int8_args() {
    }

    bool Math_get_int8_args::operator==(const Math_get_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int8_args::operator!=(const Math_get_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int8_args::operator< (const Math_get_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int8_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int16_args::Math_get_int16_args() {
    }

    Math_get_int16_args::~Math_get_int16_args() {
    }

    bool Math_get_int16_args::operator==(const Math_get_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int16_args::operator!=(const Math_get_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int16_args::operator< (const Math_get_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int16_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int32_args::Math_get_int32_args() {
    }

    Math_get_int32_args::~Math_get_int32_args() {
    }

    bool Math_get_int32_args::operator==(const Math_get_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int32_args::operator!=(const Math_get_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int32_args::operator< (const Math_get_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int32_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int64_args::Math_get_int64_args() {
    }

    Math_get_int64_args::~Math_get_int64_args() {
    }

    bool Math_get_int64_args::operator==(const Math_get_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int64_args::operator!=(const Math_get_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int64_args::operator< (const Math_get_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int64_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_float_args::Math_get_float_args() {
    }

    Math_get_float_args::~Math_get_float_args() {
    }

    bool Math_get_float_args::operator==(const Math_get_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_float_args::operator!=(const Math_get_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_float_args::operator< (const Math_get_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_float_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_string_args::Math_get_string_args() {
    }

    Math_get_string_args::~Math_get_string_args() {
    }

    bool Math_get_string_args::operator==(const Math_get_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_string_args::operator!=(const Math_get_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_args::operator< (const Math_get_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_binary_args::Math_get_binary_args() {
    }

    Math_get_binary_args::~Math_get_binary_args() {
    }

    bool Math_get_binary_args::operator==(const Math_get_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_binary_args::operator!=(const Math_get_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_binary_args::operator< (const Math_get_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_binary_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_color_args::Math_get_color_args() {
    }

    Math_get_color_args::~Math_get_color_args() {
    }

    bool Math_get_color_args::operator==(const Math_get_color_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_color_args::operator!=(const Math_get_color_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_color_args::operator< (const Math_get_color_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_color_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_sequence_args::Math_get_sequence_args() {
    }

    Math_get_sequence_args::~Math_get_sequence_args() {
    }

    bool Math_get_sequence_args::operator==(const Math_get_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_sequence_args::operator!=(const Math_get_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_sequence_args::operator< (const Math_get_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_sequence_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_string_set_args::Math_get_string_set_args() {
    }

    Math_get_string_set_args::~Math_get_string_set_args() {
    }

    bool Math_get_string_set_args::operator==(const Math_get_string_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_string_set_args::operator!=(const Math_get_string_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_set_args::operator< (const Math_get_string_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_set_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_int_str_map_args::Math_get_int_str_map_args() {
    }

    Math_get_int_str_map_args::~Math_get_int_str_map_args() {
    }

    bool Math_get_int_str_map_args::operator==(const Math_get_int_str_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_int_str_map_args::operator!=(const Math_get_int_str_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int_str_map_args::operator< (const Math_get_int_str_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int_str_map_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_bool_set_sequence_args::Math_get_bool_set_sequence_args() {
    }

    Math_get_bool_set_sequence_args::~Math_get_bool_set_sequence_args() {
    }

    bool Math_get_bool_set_sequence_args::operator==(const Math_get_bool_set_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_bool_set_sequence_args::operator!=(const Math_get_bool_set_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_bool_set_sequence_args::operator< (const Math_get_bool_set_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_bool_set_sequence_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_person_args::Math_get_person_args() {
    }

    Math_get_person_args::~Math_get_person_args() {
    }

    bool Math_get_person_args::operator==(const Math_get_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_person_args::operator!=(const Math_get_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_person_args::operator< (const Math_get_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_person_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons_args::Math_get_persons_args() {
    }

    Math_get_persons_args::~Math_get_persons_args() {
    }

    bool Math_get_persons_args::operator==(const Math_get_persons_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons_args::operator!=(const Math_get_persons_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons_args::operator< (const Math_get_persons_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons2_args::Math_get_persons2_args() {
    }

    Math_get_persons2_args::~Math_get_persons2_args() {
    }

    bool Math_get_persons2_args::operator==(const Math_get_persons2_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons2_args::operator!=(const Math_get_persons2_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons2_args::operator< (const Math_get_persons2_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons2_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons3_args::Math_get_persons3_args() {
    }

    Math_get_persons3_args::~Math_get_persons3_args() {
    }

    bool Math_get_persons3_args::operator==(const Math_get_persons3_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons3_args::operator!=(const Math_get_persons3_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons3_args::operator< (const Math_get_persons3_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons3_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_get_persons4_args::Math_get_persons4_args() {
    }

    Math_get_persons4_args::~Math_get_persons4_args() {
    }

    bool Math_get_persons4_args::operator==(const Math_get_persons4_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_get_persons4_args::operator!=(const Math_get_persons4_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons4_args::operator< (const Math_get_persons4_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons4_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_bool_args::Math_send_bool_args() {
    }

    Math_send_bool_args::~Math_send_bool_args() {
    }

    bool Math_send_bool_args::operator==(const Math_send_bool_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_bool_args::operator!=(const Math_send_bool_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_bool_args::operator< (const Math_send_bool_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_bool_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int8_args::Math_send_int8_args() {
    }

    Math_send_int8_args::~Math_send_int8_args() {
    }

    bool Math_send_int8_args::operator==(const Math_send_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int8_args::operator!=(const Math_send_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int8_args::operator< (const Math_send_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int8_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int16_args::Math_send_int16_args() {
    }

    Math_send_int16_args::~Math_send_int16_args() {
    }

    bool Math_send_int16_args::operator==(const Math_send_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int16_args::operator!=(const Math_send_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int16_args::operator< (const Math_send_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int16_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_args::Math_send_int32_args() {
    }

    Math_send_int32_args::~Math_send_int32_args() {
    }

    bool Math_send_int32_args::operator==(const Math_send_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_args::operator!=(const Math_send_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_args::operator< (const Math_send_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int64_args::Math_send_int64_args() {
    }

    Math_send_int64_args::~Math_send_int64_args() {
    }

    bool Math_send_int64_args::operator==(const Math_send_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_int64_args::operator!=(const Math_send_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int64_args::operator< (const Math_send_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int64_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_float_args::Math_send_float_args() {
    }

    Math_send_float_args::~Math_send_float_args() {
    }

    bool Math_send_float_args::operator==(const Math_send_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_float_args::operator!=(const Math_send_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_float_args::operator< (const Math_send_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_float_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_string_args::Math_send_string_args() {
    }

    Math_send_string_args::~Math_send_string_args() {
    }

    bool Math_send_string_args::operator==(const Math_send_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_string_args::operator!=(const Math_send_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_string_args::operator< (const Math_send_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_string_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_binary_args::Math_send_binary_args() {
    }

    Math_send_binary_args::~Math_send_binary_args() {
    }

    bool Math_send_binary_args::operator==(const Math_send_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_send_binary_args::operator!=(const Math_send_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_binary_args::operator< (const Math_send_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_binary_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_color_args::Math_send_color_args() {
    }

    Math_send_color_args::~Math_send_color_args() {
    }

    bool Math_send_color_args::operator==(const Math_send_color_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color != rhs.color) {
            return false;
        }
        return true;
    }

    bool Math_send_color_args::operator!=(const Math_send_color_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_color_args::operator< (const Math_send_color_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color < rhs.color)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_color_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    int32_t ele_var37;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var37);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color = ele_var37;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_person_args::Math_send_person_args() {
    }

    Math_send_person_args::~Math_send_person_args() {
    }

    bool Math_send_person_args::operator==(const Math_send_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (person != rhs.person) {
            return false;
        }
        return true;
    }

    bool Math_send_person_args::operator!=(const Math_send_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_args::operator< (const Math_send_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(person < rhs.person)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = person.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_sequence_args::Math_send_int32_sequence_args() {
    }

    Math_send_int32_sequence_args::~Math_send_int32_sequence_args() {
    }

    bool Math_send_int32_sequence_args::operator==(const Math_send_int32_sequence_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (numbers != rhs.numbers) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_sequence_args::operator!=(const Math_send_int32_sequence_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_sequence_args::operator< (const Math_send_int32_sequence_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(numbers < rhs.numbers)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_sequence_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    numbers.clear();

                    int32_t size_var38;
                    bgcc::DataTypeID etype_var39;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var39, size_var38);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    numbers.reserve(size_var38);
                    for(int32_t i = 0; i < size_var38; ++i) {
                        int32_t value_var40;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var40);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        numbers.push_back(value_var40);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons_args::Math_send_persons_args() {
    }

    Math_send_persons_args::~Math_send_persons_args() {
    }

    bool Math_send_persons_args::operator==(const Math_send_persons_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons_args::operator!=(const Math_send_persons_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons_args::operator< (const Math_send_persons_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var41;
                    bgcc::DataTypeID etype_var42;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var42, size_var41);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    persons.reserve(size_var41);
                    for(int32_t i = 0; i < size_var41; ++i) {
                        Person value_var43;
                        ret = value_var43.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        persons.push_back(value_var43);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons2_args::Math_send_persons2_args() {
    }

    Math_send_persons2_args::~Math_send_persons2_args() {
    }

    bool Math_send_persons2_args::operator==(const Math_send_persons2_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons2_args::operator!=(const Math_send_persons2_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons2_args::operator< (const Math_send_persons2_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons2_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var44;
                    bgcc::DataTypeID etype_var45;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var45, size_var44);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var44; ++i) {
                        Person value_var46;
                        ret = value_var46.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        persons.insert(value_var46);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_int32_set_seq_args::Math_send_int32_set_seq_args() {
    }

    Math_send_int32_set_seq_args::~Math_send_int32_set_seq_args() {
    }

    bool Math_send_int32_set_seq_args::operator==(const Math_send_int32_set_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xx != rhs.xx) {
            return false;
        }
        return true;
    }

    bool Math_send_int32_set_seq_args::operator!=(const Math_send_int32_set_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_set_seq_args::operator< (const Math_send_int32_set_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xx < rhs.xx)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_set_seq_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    xx.clear();

                    int32_t size_var47;
                    bgcc::DataTypeID etype_var48;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var48, size_var47);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    xx.reserve(size_var47);
                    for(int32_t i = 0; i < size_var47; ++i) {
                        std::set<int32_t>  value_var49;
                        value_var49.clear();

                        int32_t size_var50;
                        bgcc::DataTypeID etype_var51;
                        ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var51, size_var50);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        for(int32_t i = 0; i < size_var50; ++i) {
                            int32_t value_var52;
                            ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var52);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            value_var49.insert(value_var52);
                        }

                        ret = proto->readSetEnd();
                        if (ret < 0) { return ret; }
                        xx.push_back(value_var49);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_persons3_args::Math_send_persons3_args() {
    }

    Math_send_persons3_args::~Math_send_persons3_args() {
    }

    bool Math_send_persons3_args::operator==(const Math_send_persons3_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (persons != rhs.persons) {
            return false;
        }
        return true;
    }

    bool Math_send_persons3_args::operator!=(const Math_send_persons3_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons3_args::operator< (const Math_send_persons3_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(persons < rhs.persons)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons3_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    persons.clear();

                    int32_t size_var53;
                    bgcc::DataTypeID ktype_var54;
                    bgcc::DataTypeID vtype_var55;

                    ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var54, vtype_var55, size_var53);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var53; ++i) {
                        Person key_var56;

                        ret = key_var56.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        Person& value_var57 = persons[key_var56];
                        ret = value_var57.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_send_person_vec_set_args::Math_send_person_vec_set_args() {
    }

    Math_send_person_vec_set_args::~Math_send_person_vec_set_args() {
    }

    bool Math_send_person_vec_set_args::operator==(const Math_send_person_vec_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_send_person_vec_set_args::operator!=(const Math_send_person_vec_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_vec_set_args::operator< (const Math_send_person_vec_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_vec_set_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    xxx.clear();

                    int32_t size_var58;
                    bgcc::DataTypeID etype_var59;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var59, size_var58);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var58; ++i) {
                        std::vector<Person>  value_var60;
                        value_var60.clear();

                        int32_t size_var61;
                        bgcc::DataTypeID etype_var62;

                        ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var62, size_var61);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        value_var60.reserve(size_var61);
                        for(int32_t i = 0; i < size_var61; ++i) {
                            Person value_var63;
                            ret = value_var63.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                            if (ret < 0) { return ret; }
                            nread += ret;
                            value_var60.push_back(value_var63);
                        }

                        ret = proto->readListEnd();
                        if (ret < 0) { return ret; }
                        xxx.insert(value_var60);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_boolean_args::Math_out_boolean_args() {
    }

    Math_out_boolean_args::~Math_out_boolean_args() {
    }

    bool Math_out_boolean_args::operator==(const Math_out_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_boolean_args::operator!=(const Math_out_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_boolean_args::operator< (const Math_out_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_boolean_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int8_args::Math_out_int8_args() {
    }

    Math_out_int8_args::~Math_out_int8_args() {
    }

    bool Math_out_int8_args::operator==(const Math_out_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int8_args::operator!=(const Math_out_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int8_args::operator< (const Math_out_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int8_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int16_args::Math_out_int16_args() {
    }

    Math_out_int16_args::~Math_out_int16_args() {
    }

    bool Math_out_int16_args::operator==(const Math_out_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int16_args::operator!=(const Math_out_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_args::operator< (const Math_out_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int32_args::Math_out_int32_args() {
    }

    Math_out_int32_args::~Math_out_int32_args() {
    }

    bool Math_out_int32_args::operator==(const Math_out_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int32_args::operator!=(const Math_out_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int32_args::operator< (const Math_out_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int32_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int64_args::Math_out_int64_args() {
    }

    Math_out_int64_args::~Math_out_int64_args() {
    }

    bool Math_out_int64_args::operator==(const Math_out_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int64_args::operator!=(const Math_out_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int64_args::operator< (const Math_out_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int64_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_float_args::Math_out_float_args() {
    }

    Math_out_float_args::~Math_out_float_args() {
    }

    bool Math_out_float_args::operator==(const Math_out_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_float_args::operator!=(const Math_out_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_float_args::operator< (const Math_out_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_float_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_string_args::Math_out_string_args() {
    }

    Math_out_string_args::~Math_out_string_args() {
    }

    bool Math_out_string_args::operator==(const Math_out_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_string_args::operator!=(const Math_out_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_args::operator< (const Math_out_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_binary_args::Math_out_binary_args() {
    }

    Math_out_binary_args::~Math_out_binary_args() {
    }

    bool Math_out_binary_args::operator==(const Math_out_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_binary_args::operator!=(const Math_out_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_binary_args::operator< (const Math_out_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_binary_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_person_args::Math_out_person_args() {
    }

    Math_out_person_args::~Math_out_person_args() {
    }

    bool Math_out_person_args::operator==(const Math_out_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_person_args::operator!=(const Math_out_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_person_args::operator< (const Math_out_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_person_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_seq_args::Math_out_seq_args() {
    }

    Math_out_seq_args::~Math_out_seq_args() {
    }

    bool Math_out_seq_args::operator==(const Math_out_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_seq_args::operator!=(const Math_out_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_seq_args::operator< (const Math_out_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_seq_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_string_set_args::Math_out_string_set_args() {
    }

    Math_out_string_set_args::~Math_out_string_set_args() {
    }

    bool Math_out_string_set_args::operator==(const Math_out_string_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_string_set_args::operator!=(const Math_out_string_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_set_args::operator< (const Math_out_string_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_set_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int16_float_map_args::Math_out_int16_float_map_args() {
    }

    Math_out_int16_float_map_args::~Math_out_int16_float_map_args() {
    }

    bool Math_out_int16_float_map_args::operator==(const Math_out_int16_float_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int16_float_map_args::operator!=(const Math_out_int16_float_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_float_map_args::operator< (const Math_out_int16_float_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_float_map_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_out_int_vec_set_args::Math_out_int_vec_set_args() {
    }

    Math_out_int_vec_set_args::~Math_out_int_vec_set_args() {
    }

    bool Math_out_int_vec_set_args::operator==(const Math_out_int_vec_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_out_int_vec_set_args::operator!=(const Math_out_int_vec_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int_vec_set_args::operator< (const Math_out_int_vec_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int_vec_set_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_boolean_args::Math_all_boolean_args() {
    }

    Math_all_boolean_args::~Math_all_boolean_args() {
    }

    bool Math_all_boolean_args::operator==(const Math_all_boolean_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_boolean_args::operator!=(const Math_all_boolean_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_boolean_args::operator< (const Math_all_boolean_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_boolean_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int8_args::Math_all_int8_args() {
    }

    Math_all_int8_args::~Math_all_int8_args() {
    }

    bool Math_all_int8_args::operator==(const Math_all_int8_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int8_args::operator!=(const Math_all_int8_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int8_args::operator< (const Math_all_int8_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int8_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int16_args::Math_all_int16_args() {
    }

    Math_all_int16_args::~Math_all_int16_args() {
    }

    bool Math_all_int16_args::operator==(const Math_all_int16_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int16_args::operator!=(const Math_all_int16_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int16_args::operator< (const Math_all_int16_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int16_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_args::Math_all_int32_args() {
    }

    Math_all_int32_args::~Math_all_int32_args() {
    }

    bool Math_all_int32_args::operator==(const Math_all_int32_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_args::operator!=(const Math_all_int32_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_args::operator< (const Math_all_int32_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int64_args::Math_all_int64_args() {
    }

    Math_all_int64_args::~Math_all_int64_args() {
    }

    bool Math_all_int64_args::operator==(const Math_all_int64_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int64_args::operator!=(const Math_all_int64_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int64_args::operator< (const Math_all_int64_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int64_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_float_args::Math_all_float_args() {
    }

    Math_all_float_args::~Math_all_float_args() {
    }

    bool Math_all_float_args::operator==(const Math_all_float_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_float_args::operator!=(const Math_all_float_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_float_args::operator< (const Math_all_float_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_float_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_string_args::Math_all_string_args() {
    }

    Math_all_string_args::~Math_all_string_args() {
    }

    bool Math_all_string_args::operator==(const Math_all_string_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_string_args::operator!=(const Math_all_string_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_string_args::operator< (const Math_all_string_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_string_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_binary_args::Math_all_binary_args() {
    }

    Math_all_binary_args::~Math_all_binary_args() {
    }

    bool Math_all_binary_args::operator==(const Math_all_binary_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_binary_args::operator!=(const Math_all_binary_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_binary_args::operator< (const Math_all_binary_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_binary_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, value);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_seq_args::Math_all_int32_seq_args() {
    }

    Math_all_int32_seq_args::~Math_all_int32_seq_args() {
    }

    bool Math_all_int32_seq_args::operator==(const Math_all_int32_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_seq_args::operator!=(const Math_all_int32_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_seq_args::operator< (const Math_all_int32_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_seq_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var64;
                    bgcc::DataTypeID etype_var65;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var65, size_var64);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    value.reserve(size_var64);
                    for(int32_t i = 0; i < size_var64; ++i) {
                        int32_t value_var66;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var66);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.push_back(value_var66);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_person_args::Math_all_person_args() {
    }

    Math_all_person_args::~Math_all_person_args() {
    }

    bool Math_all_person_args::operator==(const Math_all_person_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_args::operator!=(const Math_all_person_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_args::operator< (const Math_all_person_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    ret = value.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_set_args::Math_all_int32_set_args() {
    }

    Math_all_int32_set_args::~Math_all_int32_set_args() {
    }

    bool Math_all_int32_set_args::operator==(const Math_all_int32_set_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_set_args::operator!=(const Math_all_int32_set_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_set_args::operator< (const Math_all_int32_set_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_set_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var67;
                    bgcc::DataTypeID etype_var68;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var68, size_var67);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var67; ++i) {
                        int32_t value_var69;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var69);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.insert(value_var69);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_person_seq_args::Math_all_person_seq_args() {
    }

    Math_all_person_seq_args::~Math_all_person_seq_args() {
    }

    bool Math_all_person_seq_args::operator==(const Math_all_person_seq_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_seq_args::operator!=(const Math_all_person_seq_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_seq_args::operator< (const Math_all_person_seq_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_seq_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var70;
                    bgcc::DataTypeID etype_var71;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var71, size_var70);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    value.reserve(size_var70);
                    for(int32_t i = 0; i < size_var70; ++i) {
                        Person value_var72;
                        ret = value_var72.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value.push_back(value_var72);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_all_int32_person_map_args::Math_all_int32_person_map_args() {
    }

    Math_all_int32_person_map_args::~Math_all_int32_person_map_args() {
    }

    bool Math_all_int32_person_map_args::operator==(const Math_all_int32_person_map_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_person_map_args::operator!=(const Math_all_int32_person_map_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_person_map_args::operator< (const Math_all_int32_person_map_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_person_map_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    value.clear();

                    int32_t size_var73;
                    bgcc::DataTypeID ktype_var74;
                    bgcc::DataTypeID vtype_var75;

                    ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var74, vtype_var75, size_var73);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var73; ++i) {
                        int32_t key_var76;

                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, key_var76);
                        if (ret < 0) { return ret; }
                        nread += ret;

                        Person& value_var77 = value[key_var76];
                        ret = value_var77.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_color_out_all_args::Math_color_out_all_args() {
    }

    Math_color_out_all_args::~Math_color_out_all_args() {
    }

    bool Math_color_out_all_args::operator==(const Math_color_out_all_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        return true;
    }

    bool Math_color_out_all_args::operator!=(const Math_color_out_all_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_out_all_args::operator< (const Math_color_out_all_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_out_all_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    int32_t ele_var78;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var78);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    color1 = ele_var78;
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_color_xx_args::Math_color_xx_args() {
    }

    Math_color_xx_args::~Math_color_xx_args() {
    }

    bool Math_color_xx_args::operator==(const Math_color_xx_args& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        if (color3 != rhs.color3) {
            return false;
        }
        return true;
    }

    bool Math_color_xx_args::operator!=(const Math_color_xx_args& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_xx_args::operator< (const Math_color_xx_args& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        if (!(color3 < rhs.color3)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_xx_args::read(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0; 
        std::string fname;
        int32_t nread = 0;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread += ret;

        while (true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread += ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }

            switch (fid) {
            case 1:
                {
                    color1.clear();

                    int32_t size_var79;
                    bgcc::DataTypeID etype_var80;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var80, size_var79);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var79; ++i) {
                        MyColor value_var81;
                        int32_t ele_var82;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var82);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var81 = ele_var82;
                        color1.insert(value_var81);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            case 3:
                {
                    color3.clear();

                    int32_t size_var83;
                    bgcc::DataTypeID ktype_var84;
                    bgcc::DataTypeID vtype_var85;

                    ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var84, vtype_var85, size_var83);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var83; ++i) {
                        MyColor key_var86;

                        int32_t ele_var87;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var87);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        key_var86 = ele_var87;

                        MyColor& value_var88 = color3[key_var86];
                        int32_t ele_var89;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var89);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var88 = ele_var89;
                    }

                    ret = proto->readMapEnd();
                    if (ret < 0) { return ret; }
                }
                break;
            default:
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->readStructEnd();
        if (ret < 0) { return ret; }
        return nread;
    }

    Math_ping_pargs::~Math_ping_pargs() {
    }

    int32_t Math_ping_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_ping_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_add_pargs::~Math_add_pargs() {
    }

    int32_t Math_add_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("a", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(a)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("b", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(b)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_test_citizen_pargs::~Math_test_citizen_pargs() {
    }

    int32_t Math_test_citizen_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_test_citizen_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("ins", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(ins)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("alls", bgcc::IDSTRUCT, 3);
        if (ret < 0) { return ret; }
        ret = (*(alls)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_boolean_pargs::~Math_get_boolean_pargs() {
    }

    int32_t Math_get_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int8_pargs::~Math_get_int8_pargs() {
    }

    int32_t Math_get_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int16_pargs::~Math_get_int16_pargs() {
    }

    int32_t Math_get_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int32_pargs::~Math_get_int32_pargs() {
    }

    int32_t Math_get_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int64_pargs::~Math_get_int64_pargs() {
    }

    int32_t Math_get_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_float_pargs::~Math_get_float_pargs() {
    }

    int32_t Math_get_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_string_pargs::~Math_get_string_pargs() {
    }

    int32_t Math_get_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_binary_pargs::~Math_get_binary_pargs() {
    }

    int32_t Math_get_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_color_pargs::~Math_get_color_pargs() {
    }

    int32_t Math_get_color_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_color_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_sequence_pargs::~Math_get_sequence_pargs() {
    }

    int32_t Math_get_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_string_set_pargs::~Math_get_string_set_pargs() {
    }

    int32_t Math_get_string_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_int_str_map_pargs::~Math_get_int_str_map_pargs() {
    }

    int32_t Math_get_int_str_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int_str_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_bool_set_sequence_pargs::~Math_get_bool_set_sequence_pargs() {
    }

    int32_t Math_get_bool_set_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_bool_set_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_person_pargs::~Math_get_person_pargs() {
    }

    int32_t Math_get_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons_pargs::~Math_get_persons_pargs() {
    }

    int32_t Math_get_persons_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons2_pargs::~Math_get_persons2_pargs() {
    }

    int32_t Math_get_persons2_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons2_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons3_pargs::~Math_get_persons3_pargs() {
    }

    int32_t Math_get_persons3_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons3_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_get_persons4_pargs::~Math_get_persons4_pargs() {
    }

    int32_t Math_get_persons4_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons4_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_bool_pargs::~Math_send_bool_pargs() {
    }

    int32_t Math_send_bool_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_bool_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int8_pargs::~Math_send_int8_pargs() {
    }

    int32_t Math_send_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int16_pargs::~Math_send_int16_pargs() {
    }

    int32_t Math_send_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_pargs::~Math_send_int32_pargs() {
    }

    int32_t Math_send_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int64_pargs::~Math_send_int64_pargs() {
    }

    int32_t Math_send_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_float_pargs::~Math_send_float_pargs() {
    }

    int32_t Math_send_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_string_pargs::~Math_send_string_pargs() {
    }

    int32_t Math_send_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_binary_pargs::~Math_send_binary_pargs() {
    }

    int32_t Math_send_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary((*(value)).c_str(), (*(value)).size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_color_pargs::~Math_send_color_pargs() {
    }

    int32_t Math_send_color_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_color_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(color)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_person_pargs::~Math_send_person_pargs() {
    }

    int32_t Math_send_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("person", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(person)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_sequence_pargs::~Math_send_int32_sequence_pargs() {
    }

    int32_t Math_send_int32_sequence_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_sequence_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("numbers", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, (*(numbers)).size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var90;
        for (citr_var90 = (*(numbers)).begin(); citr_var90 != (*(numbers)).end(); ++citr_var90) {
            ret = proto->writeInt32((*citr_var90));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons_pargs::~Math_send_persons_pargs() {
    }

    int32_t Math_send_persons_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var91;
        for (citr_var91 = (*(persons)).begin(); citr_var91 != (*(persons)).end(); ++citr_var91) {
            ret = (*citr_var91).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons2_pargs::~Math_send_persons2_pargs() {
    }

    int32_t Math_send_persons2_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons2_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::set<Person> ::const_iterator citr_var92;
        for (citr_var92 = (*(persons)).begin(); citr_var92 != (*(persons)).end(); ++citr_var92) {
            ret = (*citr_var92).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_int32_set_seq_pargs::~Math_send_int32_set_seq_pargs() {
    }

    int32_t Math_send_int32_set_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_set_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xx", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, (*(xx)).size());
        if (ret < 0) { return ret; }
        std::vector<std::set<int32_t> > ::const_iterator citr_var93;
        for (citr_var93 = (*(xx)).begin(); citr_var93 != (*(xx)).end(); ++citr_var93) {
            ret = proto->writeSetBegin(bgcc::IDINT32, (*citr_var93).size());
            if (ret < 0) { return ret; }
            std::set<int32_t> ::const_iterator citr_var94;
            for (citr_var94 = (*citr_var93).begin(); citr_var94 != (*citr_var93).end(); ++citr_var94) {
                ret = proto->writeInt32((*citr_var94));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_persons3_pargs::~Math_send_persons3_pargs() {
    }

    int32_t Math_send_persons3_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons3_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("persons", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDSTRUCT, bgcc::IDSTRUCT, (*(persons)).size());
        if (ret < 0) { return ret; }
        std::map<Person, Person> ::const_iterator citr_var95;
        for (citr_var95 = (*(persons)).begin(); citr_var95 != (*(persons)).end(); ++citr_var95) {
            ret = citr_var95->first.write(proto);
            if (ret < 0) { return ret; }
            ret = citr_var95->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_send_person_vec_set_pargs::~Math_send_person_vec_set_pargs() {
    }

    int32_t Math_send_person_vec_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_vec_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDLIST, (*(xxx)).size());
        if (ret < 0) { return ret; }
        std::set<std::vector<Person> > ::const_iterator citr_var96;
        for (citr_var96 = (*(xxx)).begin(); citr_var96 != (*(xxx)).end(); ++citr_var96) {
            ret = proto->writeListBegin(bgcc::IDSTRUCT, (*citr_var96).size());
            if (ret < 0) { return ret; }
            std::vector<Person> ::const_iterator citr_var97;
            for (citr_var97 = (*citr_var96).begin(); citr_var97 != (*citr_var96).end(); ++citr_var97) {
                ret = (*citr_var97).write(proto);
                if (ret < 0) { return ret; }
            }
            ret = proto->writeListEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_boolean_pargs::~Math_out_boolean_pargs() {
    }

    int32_t Math_out_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int8_pargs::~Math_out_int8_pargs() {
    }

    int32_t Math_out_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int16_pargs::~Math_out_int16_pargs() {
    }

    int32_t Math_out_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int32_pargs::~Math_out_int32_pargs() {
    }

    int32_t Math_out_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int64_pargs::~Math_out_int64_pargs() {
    }

    int32_t Math_out_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_float_pargs::~Math_out_float_pargs() {
    }

    int32_t Math_out_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_string_pargs::~Math_out_string_pargs() {
    }

    int32_t Math_out_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_binary_pargs::~Math_out_binary_pargs() {
    }

    int32_t Math_out_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_person_pargs::~Math_out_person_pargs() {
    }

    int32_t Math_out_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_seq_pargs::~Math_out_seq_pargs() {
    }

    int32_t Math_out_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_string_set_pargs::~Math_out_string_set_pargs() {
    }

    int32_t Math_out_string_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int16_float_map_pargs::~Math_out_int16_float_map_pargs() {
    }

    int32_t Math_out_int16_float_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_float_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_out_int_vec_set_pargs::~Math_out_int_vec_set_pargs() {
    }

    int32_t Math_out_int_vec_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int_vec_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_boolean_pargs::~Math_all_boolean_pargs() {
    }

    int32_t Math_all_boolean_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_boolean_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int8_pargs::~Math_all_int8_pargs() {
    }

    int32_t Math_all_int8_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int8_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int16_pargs::~Math_all_int16_pargs() {
    }

    int32_t Math_all_int16_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int16_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_pargs::~Math_all_int32_pargs() {
    }

    int32_t Math_all_int32_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int64_pargs::~Math_all_int64_pargs() {
    }

    int32_t Math_all_int64_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int64_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_float_pargs::~Math_all_float_pargs() {
    }

    int32_t Math_all_float_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_float_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_string_pargs::~Math_all_string_pargs() {
    }

    int32_t Math_all_string_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_string_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString((*(value)));
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_binary_pargs::~Math_all_binary_pargs() {
    }

    int32_t Math_all_binary_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_binary_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary((*(value)).c_str(), (*(value)).size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_seq_pargs::~Math_all_int32_seq_pargs() {
    }

    int32_t Math_all_int32_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, (*(value)).size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var98;
        for (citr_var98 = (*(value)).begin(); citr_var98 != (*(value)).end(); ++citr_var98) {
            ret = proto->writeInt32((*citr_var98));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_person_pargs::~Math_all_person_pargs() {
    }

    int32_t Math_all_person_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = (*(value)).write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_set_pargs::~Math_all_int32_set_pargs() {
    }

    int32_t Math_all_int32_set_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_set_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, (*(value)).size());
        if (ret < 0) { return ret; }
        std::set<int32_t> ::const_iterator citr_var99;
        for (citr_var99 = (*(value)).begin(); citr_var99 != (*(value)).end(); ++citr_var99) {
            ret = proto->writeInt32((*citr_var99));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_person_seq_pargs::~Math_all_person_seq_pargs() {
    }

    int32_t Math_all_person_seq_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_seq_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, (*(value)).size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var100;
        for (citr_var100 = (*(value)).begin(); citr_var100 != (*(value)).end(); ++citr_var100) {
            ret = (*citr_var100).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_all_int32_person_map_pargs::~Math_all_int32_person_map_pargs() {
    }

    int32_t Math_all_int32_person_map_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_person_map_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDSTRUCT, (*(value)).size());
        if (ret < 0) { return ret; }
        std::map<int32_t, Person> ::const_iterator citr_var101;
        for (citr_var101 = (*(value)).begin(); citr_var101 != (*(value)).end(); ++citr_var101) {
            ret = proto->writeInt32(citr_var101->first);
            if (ret < 0) { return ret; }
            ret = citr_var101->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_color_out_all_pargs::~Math_color_out_all_pargs() {
    }

    int32_t Math_color_out_all_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_out_all_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32((*(color1)).get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_color_xx_pargs::~Math_color_xx_pargs() {
    }

    int32_t Math_color_xx_pargs::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_xx_pargs");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, (*(color1)).size());
        if (ret < 0) { return ret; }
        std::set<MyColor> ::const_iterator citr_var102;
        for (citr_var102 = (*(color1)).begin(); citr_var102 != (*(color1)).end(); ++citr_var102) {
            ret = proto->writeInt32((*citr_var102).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color3", bgcc::IDMAP, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDINT32, (*(color3)).size());
        if (ret < 0) { return ret; }
        std::map<MyColor, MyColor> ::const_iterator citr_var103;
        for (citr_var103 = (*(color3)).begin(); citr_var103 != (*(color3)).end(); ++citr_var103) {
            ret = proto->writeInt32(citr_var103->first.get_value());
            if (ret < 0) { return ret; }
            ret = proto->writeInt32(citr_var103->second.get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }
        ret = proto->writeStructEnd();
        if (ret < 0) { return ret; }
        return ret;
    };

    Math_ping_result::Math_ping_result() {
    }

    Math_ping_result::~Math_ping_result() {
    }

    bool Math_ping_result::operator==(const Math_ping_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_ping_result::operator!=(const Math_ping_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_ping_result::operator< (const Math_ping_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_ping_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_ping_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_add_result::Math_add_result() {
    }

    Math_add_result::~Math_add_result() {
    }

    bool Math_add_result::operator==(const Math_add_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (sum != rhs.sum) {
            return false;
        }
        return true;
    }

    bool Math_add_result::operator!=(const Math_add_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_add_result::operator< (const Math_add_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(sum < rhs.sum)) {
            return false;
        }
        return true;
    }

    int32_t Math_add_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_add_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("sum", bgcc::IDINT32, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(sum);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_test_citizen_result::Math_test_citizen_result() {
    }

    Math_test_citizen_result::~Math_test_citizen_result() {
    }

    bool Math_test_citizen_result::operator==(const Math_test_citizen_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (outs != rhs.outs) {
            return false;
        }
        if (alls != rhs.alls) {
            return false;
        }
        return true;
    }

    bool Math_test_citizen_result::operator!=(const Math_test_citizen_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_test_citizen_result::operator< (const Math_test_citizen_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(outs < rhs.outs)) {
            return false;
        }
        if (!(alls < rhs.alls)) {
            return false;
        }
        return true;
    }

    int32_t Math_test_citizen_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_test_citizen_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTRUCT, 0);
        if (ret < 0) { return ret; }
        ret = return_value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("outs", bgcc::IDSTRUCT, 2);
        if (ret < 0) { return ret; }
        ret = outs.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("alls", bgcc::IDSTRUCT, 3);
        if (ret < 0) { return ret; }
        ret = alls.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_boolean_result::Math_get_boolean_result() {
    }

    Math_get_boolean_result::~Math_get_boolean_result() {
    }

    bool Math_get_boolean_result::operator==(const Math_get_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_boolean_result::operator!=(const Math_get_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_boolean_result::operator< (const Math_get_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBOOL, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int8_result::Math_get_int8_result() {
    }

    Math_get_int8_result::~Math_get_int8_result() {
    }

    bool Math_get_int8_result::operator==(const Math_get_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int8_result::operator!=(const Math_get_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int8_result::operator< (const Math_get_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBYTE, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int16_result::Math_get_int16_result() {
    }

    Math_get_int16_result::~Math_get_int16_result() {
    }

    bool Math_get_int16_result::operator==(const Math_get_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int16_result::operator!=(const Math_get_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int16_result::operator< (const Math_get_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT16, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int32_result::Math_get_int32_result() {
    }

    Math_get_int32_result::~Math_get_int32_result() {
    }

    bool Math_get_int32_result::operator==(const Math_get_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int32_result::operator!=(const Math_get_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int32_result::operator< (const Math_get_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int64_result::Math_get_int64_result() {
    }

    Math_get_int64_result::~Math_get_int64_result() {
    }

    bool Math_get_int64_result::operator==(const Math_get_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int64_result::operator!=(const Math_get_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int64_result::operator< (const Math_get_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT64, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_float_result::Math_get_float_result() {
    }

    Math_get_float_result::~Math_get_float_result() {
    }

    bool Math_get_float_result::operator==(const Math_get_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_float_result::operator!=(const Math_get_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_float_result::operator< (const Math_get_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDFLOAT, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_string_result::Math_get_string_result() {
    }

    Math_get_string_result::~Math_get_string_result() {
    }

    bool Math_get_string_result::operator==(const Math_get_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_string_result::operator!=(const Math_get_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_result::operator< (const Math_get_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTR, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeString(return_value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_binary_result::Math_get_binary_result() {
    }

    Math_get_binary_result::~Math_get_binary_result() {
    }

    bool Math_get_binary_result::operator==(const Math_get_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_binary_result::operator!=(const Math_get_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_binary_result::operator< (const Math_get_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDBIN, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(return_value.c_str(), return_value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_color_result::Math_get_color_result() {
    }

    Math_get_color_result::~Math_get_color_result() {
    }

    bool Math_get_color_result::operator==(const Math_get_color_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_color_result::operator!=(const Math_get_color_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_color_result::operator< (const Math_get_color_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_color_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_color_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDINT32, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(return_value.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_sequence_result::Math_get_sequence_result() {
    }

    Math_get_sequence_result::~Math_get_sequence_result() {
    }

    bool Math_get_sequence_result::operator==(const Math_get_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_sequence_result::operator!=(const Math_get_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_sequence_result::operator< (const Math_get_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var104;
        for (citr_var104 = return_value.begin(); citr_var104 != return_value.end(); ++citr_var104) {
            ret = proto->writeInt32((*citr_var104));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_string_set_result::Math_get_string_set_result() {
    }

    Math_get_string_set_result::~Math_get_string_set_result() {
    }

    bool Math_get_string_set_result::operator==(const Math_get_string_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_string_set_result::operator!=(const Math_get_string_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_string_set_result::operator< (const Math_get_string_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_string_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_string_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSET, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTR, return_value.size());
        if (ret < 0) { return ret; }
        std::set<std::string> ::const_iterator citr_var105;
        for (citr_var105 = return_value.begin(); citr_var105 != return_value.end(); ++citr_var105) {
            ret = proto->writeString((*citr_var105));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_int_str_map_result::Math_get_int_str_map_result() {
    }

    Math_get_int_str_map_result::~Math_get_int_str_map_result() {
    }

    bool Math_get_int_str_map_result::operator==(const Math_get_int_str_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_int_str_map_result::operator!=(const Math_get_int_str_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_int_str_map_result::operator< (const Math_get_int_str_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_int_str_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_int_str_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDMAP, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT64, bgcc::IDSTR, return_value.size());
        if (ret < 0) { return ret; }
        std::map<int64_t, std::string> ::const_iterator citr_var106;
        for (citr_var106 = return_value.begin(); citr_var106 != return_value.end(); ++citr_var106) {
            ret = proto->writeInt64(citr_var106->first);
            if (ret < 0) { return ret; }
            ret = proto->writeString(citr_var106->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_bool_set_sequence_result::Math_get_bool_set_sequence_result() {
    }

    Math_get_bool_set_sequence_result::~Math_get_bool_set_sequence_result() {
    }

    bool Math_get_bool_set_sequence_result::operator==(const Math_get_bool_set_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_bool_set_sequence_result::operator!=(const Math_get_bool_set_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_bool_set_sequence_result::operator< (const Math_get_bool_set_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_bool_set_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_bool_set_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<std::set<bool> > ::const_iterator citr_var107;
        for (citr_var107 = return_value.begin(); citr_var107 != return_value.end(); ++citr_var107) {
            ret = proto->writeSetBegin(bgcc::IDBOOL, (*citr_var107).size());
            if (ret < 0) { return ret; }
            std::set<bool> ::const_iterator citr_var108;
            for (citr_var108 = (*citr_var107).begin(); citr_var108 != (*citr_var107).end(); ++citr_var108) {
                ret = proto->writeBool((*citr_var108));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_person_result::Math_get_person_result() {
    }

    Math_get_person_result::~Math_get_person_result() {
    }

    bool Math_get_person_result::operator==(const Math_get_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_person_result::operator!=(const Math_get_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_person_result::operator< (const Math_get_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSTRUCT, 0);
        if (ret < 0) { return ret; }
        ret = return_value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons_result::Math_get_persons_result() {
    }

    Math_get_persons_result::~Math_get_persons_result() {
    }

    bool Math_get_persons_result::operator==(const Math_get_persons_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons_result::operator!=(const Math_get_persons_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons_result::operator< (const Math_get_persons_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var109;
        for (citr_var109 = return_value.begin(); citr_var109 != return_value.end(); ++citr_var109) {
            ret = (*citr_var109).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons2_result::Math_get_persons2_result() {
    }

    Math_get_persons2_result::~Math_get_persons2_result() {
    }

    bool Math_get_persons2_result::operator==(const Math_get_persons2_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons2_result::operator!=(const Math_get_persons2_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons2_result::operator< (const Math_get_persons2_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons2_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons2_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDSET, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::set<Person> ::const_iterator citr_var110;
        for (citr_var110 = return_value.begin(); citr_var110 != return_value.end(); ++citr_var110) {
            ret = (*citr_var110).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons3_result::Math_get_persons3_result() {
    }

    Math_get_persons3_result::~Math_get_persons3_result() {
    }

    bool Math_get_persons3_result::operator==(const Math_get_persons3_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons3_result::operator!=(const Math_get_persons3_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons3_result::operator< (const Math_get_persons3_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons3_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons3_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDMAP, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDSTRUCT, bgcc::IDSTRUCT, return_value.size());
        if (ret < 0) { return ret; }
        std::map<Person, Person> ::const_iterator citr_var111;
        for (citr_var111 = return_value.begin(); citr_var111 != return_value.end(); ++citr_var111) {
            ret = citr_var111->first.write(proto);
            if (ret < 0) { return ret; }
            ret = citr_var111->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_get_persons4_result::Math_get_persons4_result() {
    }

    Math_get_persons4_result::~Math_get_persons4_result() {
    }

    bool Math_get_persons4_result::operator==(const Math_get_persons4_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        return true;
    }

    bool Math_get_persons4_result::operator!=(const Math_get_persons4_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_get_persons4_result::operator< (const Math_get_persons4_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        return true;
    }

    int32_t Math_get_persons4_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_get_persons4_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSET, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<std::set<Person> > ::const_iterator citr_var112;
        for (citr_var112 = return_value.begin(); citr_var112 != return_value.end(); ++citr_var112) {
            ret = proto->writeSetBegin(bgcc::IDSTRUCT, (*citr_var112).size());
            if (ret < 0) { return ret; }
            std::set<Person> ::const_iterator citr_var113;
            for (citr_var113 = (*citr_var112).begin(); citr_var113 != (*citr_var112).end(); ++citr_var113) {
                ret = (*citr_var113).write(proto);
                if (ret < 0) { return ret; }
            }
            ret = proto->writeSetEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_bool_result::Math_send_bool_result() {
    }

    Math_send_bool_result::~Math_send_bool_result() {
    }

    bool Math_send_bool_result::operator==(const Math_send_bool_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_bool_result::operator!=(const Math_send_bool_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_bool_result::operator< (const Math_send_bool_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_bool_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_bool_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int8_result::Math_send_int8_result() {
    }

    Math_send_int8_result::~Math_send_int8_result() {
    }

    bool Math_send_int8_result::operator==(const Math_send_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int8_result::operator!=(const Math_send_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int8_result::operator< (const Math_send_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int16_result::Math_send_int16_result() {
    }

    Math_send_int16_result::~Math_send_int16_result() {
    }

    bool Math_send_int16_result::operator==(const Math_send_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int16_result::operator!=(const Math_send_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int16_result::operator< (const Math_send_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_result::Math_send_int32_result() {
    }

    Math_send_int32_result::~Math_send_int32_result() {
    }

    bool Math_send_int32_result::operator==(const Math_send_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_result::operator!=(const Math_send_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_result::operator< (const Math_send_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int64_result::Math_send_int64_result() {
    }

    Math_send_int64_result::~Math_send_int64_result() {
    }

    bool Math_send_int64_result::operator==(const Math_send_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int64_result::operator!=(const Math_send_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int64_result::operator< (const Math_send_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_float_result::Math_send_float_result() {
    }

    Math_send_float_result::~Math_send_float_result() {
    }

    bool Math_send_float_result::operator==(const Math_send_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_float_result::operator!=(const Math_send_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_float_result::operator< (const Math_send_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_string_result::Math_send_string_result() {
    }

    Math_send_string_result::~Math_send_string_result() {
    }

    bool Math_send_string_result::operator==(const Math_send_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_string_result::operator!=(const Math_send_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_string_result::operator< (const Math_send_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_binary_result::Math_send_binary_result() {
    }

    Math_send_binary_result::~Math_send_binary_result() {
    }

    bool Math_send_binary_result::operator==(const Math_send_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_binary_result::operator!=(const Math_send_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_binary_result::operator< (const Math_send_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_color_result::Math_send_color_result() {
    }

    Math_send_color_result::~Math_send_color_result() {
    }

    bool Math_send_color_result::operator==(const Math_send_color_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_color_result::operator!=(const Math_send_color_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_color_result::operator< (const Math_send_color_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_color_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_color_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_person_result::Math_send_person_result() {
    }

    Math_send_person_result::~Math_send_person_result() {
    }

    bool Math_send_person_result::operator==(const Math_send_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_person_result::operator!=(const Math_send_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_result::operator< (const Math_send_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_sequence_result::Math_send_int32_sequence_result() {
    }

    Math_send_int32_sequence_result::~Math_send_int32_sequence_result() {
    }

    bool Math_send_int32_sequence_result::operator==(const Math_send_int32_sequence_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_sequence_result::operator!=(const Math_send_int32_sequence_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_sequence_result::operator< (const Math_send_int32_sequence_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_sequence_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_sequence_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons_result::Math_send_persons_result() {
    }

    Math_send_persons_result::~Math_send_persons_result() {
    }

    bool Math_send_persons_result::operator==(const Math_send_persons_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons_result::operator!=(const Math_send_persons_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons_result::operator< (const Math_send_persons_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons2_result::Math_send_persons2_result() {
    }

    Math_send_persons2_result::~Math_send_persons2_result() {
    }

    bool Math_send_persons2_result::operator==(const Math_send_persons2_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons2_result::operator!=(const Math_send_persons2_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons2_result::operator< (const Math_send_persons2_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons2_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons2_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_int32_set_seq_result::Math_send_int32_set_seq_result() {
    }

    Math_send_int32_set_seq_result::~Math_send_int32_set_seq_result() {
    }

    bool Math_send_int32_set_seq_result::operator==(const Math_send_int32_set_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_int32_set_seq_result::operator!=(const Math_send_int32_set_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_int32_set_seq_result::operator< (const Math_send_int32_set_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_int32_set_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_int32_set_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_persons3_result::Math_send_persons3_result() {
    }

    Math_send_persons3_result::~Math_send_persons3_result() {
    }

    bool Math_send_persons3_result::operator==(const Math_send_persons3_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_persons3_result::operator!=(const Math_send_persons3_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_persons3_result::operator< (const Math_send_persons3_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_persons3_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_persons3_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_send_person_vec_set_result::Math_send_person_vec_set_result() {
    }

    Math_send_person_vec_set_result::~Math_send_person_vec_set_result() {
    }

    bool Math_send_person_vec_set_result::operator==(const Math_send_person_vec_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        return true;
    }

    bool Math_send_person_vec_set_result::operator!=(const Math_send_person_vec_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_send_person_vec_set_result::operator< (const Math_send_person_vec_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        return true;
    }

    int32_t Math_send_person_vec_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_send_person_vec_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_boolean_result::Math_out_boolean_result() {
    }

    Math_out_boolean_result::~Math_out_boolean_result() {
    }

    bool Math_out_boolean_result::operator==(const Math_out_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_boolean_result::operator!=(const Math_out_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_boolean_result::operator< (const Math_out_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int8_result::Math_out_int8_result() {
    }

    Math_out_int8_result::~Math_out_int8_result() {
    }

    bool Math_out_int8_result::operator==(const Math_out_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int8_result::operator!=(const Math_out_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int8_result::operator< (const Math_out_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int16_result::Math_out_int16_result() {
    }

    Math_out_int16_result::~Math_out_int16_result() {
    }

    bool Math_out_int16_result::operator==(const Math_out_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int16_result::operator!=(const Math_out_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_result::operator< (const Math_out_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int32_result::Math_out_int32_result() {
    }

    Math_out_int32_result::~Math_out_int32_result() {
    }

    bool Math_out_int32_result::operator==(const Math_out_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int32_result::operator!=(const Math_out_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int32_result::operator< (const Math_out_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int64_result::Math_out_int64_result() {
    }

    Math_out_int64_result::~Math_out_int64_result() {
    }

    bool Math_out_int64_result::operator==(const Math_out_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_int64_result::operator!=(const Math_out_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int64_result::operator< (const Math_out_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_float_result::Math_out_float_result() {
    }

    Math_out_float_result::~Math_out_float_result() {
    }

    bool Math_out_float_result::operator==(const Math_out_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_float_result::operator!=(const Math_out_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_float_result::operator< (const Math_out_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_string_result::Math_out_string_result() {
    }

    Math_out_string_result::~Math_out_string_result() {
    }

    bool Math_out_string_result::operator==(const Math_out_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_string_result::operator!=(const Math_out_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_result::operator< (const Math_out_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_binary_result::Math_out_binary_result() {
    }

    Math_out_binary_result::~Math_out_binary_result() {
    }

    bool Math_out_binary_result::operator==(const Math_out_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_out_binary_result::operator!=(const Math_out_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_binary_result::operator< (const Math_out_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(value.c_str(), value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_person_result::Math_out_person_result() {
    }

    Math_out_person_result::~Math_out_person_result() {
    }

    bool Math_out_person_result::operator==(const Math_out_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (person != rhs.person) {
            return false;
        }
        return true;
    }

    bool Math_out_person_result::operator!=(const Math_out_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_person_result::operator< (const Math_out_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(person < rhs.person)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("person", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = person.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_seq_result::Math_out_seq_result() {
    }

    Math_out_seq_result::~Math_out_seq_result() {
    }

    bool Math_out_seq_result::operator==(const Math_out_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_seq_result::operator!=(const Math_out_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_seq_result::operator< (const Math_out_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, xxx.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var114;
        for (citr_var114 = xxx.begin(); citr_var114 != xxx.end(); ++citr_var114) {
            ret = proto->writeInt32((*citr_var114));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_string_set_result::Math_out_string_set_result() {
    }

    Math_out_string_set_result::~Math_out_string_set_result() {
    }

    bool Math_out_string_set_result::operator==(const Math_out_string_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_string_set_result::operator!=(const Math_out_string_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_string_set_result::operator< (const Math_out_string_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_string_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_string_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDSTR, xxx.size());
        if (ret < 0) { return ret; }
        std::set<std::string> ::const_iterator citr_var115;
        for (citr_var115 = xxx.begin(); citr_var115 != xxx.end(); ++citr_var115) {
            ret = proto->writeString((*citr_var115));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int16_float_map_result::Math_out_int16_float_map_result() {
    }

    Math_out_int16_float_map_result::~Math_out_int16_float_map_result() {
    }

    bool Math_out_int16_float_map_result::operator==(const Math_out_int16_float_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_int16_float_map_result::operator!=(const Math_out_int16_float_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int16_float_map_result::operator< (const Math_out_int16_float_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int16_float_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int16_float_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT16, bgcc::IDFLOAT, xxx.size());
        if (ret < 0) { return ret; }
        std::map<int16_t, float> ::const_iterator citr_var116;
        for (citr_var116 = xxx.begin(); citr_var116 != xxx.end(); ++citr_var116) {
            ret = proto->writeInt16(citr_var116->first);
            if (ret < 0) { return ret; }
            ret = proto->writeFloat(citr_var116->second);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_out_int_vec_set_result::Math_out_int_vec_set_result() {
    }

    Math_out_int_vec_set_result::~Math_out_int_vec_set_result() {
    }

    bool Math_out_int_vec_set_result::operator==(const Math_out_int_vec_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (xxx != rhs.xxx) {
            return false;
        }
        return true;
    }

    bool Math_out_int_vec_set_result::operator!=(const Math_out_int_vec_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_out_int_vec_set_result::operator< (const Math_out_int_vec_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(xxx < rhs.xxx)) {
            return false;
        }
        return true;
    }

    int32_t Math_out_int_vec_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_out_int_vec_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("xxx", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDLIST, xxx.size());
        if (ret < 0) { return ret; }
        std::set<std::vector<int32_t> > ::const_iterator citr_var117;
        for (citr_var117 = xxx.begin(); citr_var117 != xxx.end(); ++citr_var117) {
            ret = proto->writeListBegin(bgcc::IDINT32, (*citr_var117).size());
            if (ret < 0) { return ret; }
            std::vector<int32_t> ::const_iterator citr_var118;
            for (citr_var118 = (*citr_var117).begin(); citr_var118 != (*citr_var117).end(); ++citr_var118) {
                ret = proto->writeInt32((*citr_var118));
                if (ret < 0) { return ret; }
            }
            ret = proto->writeListEnd();
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_boolean_result::Math_all_boolean_result() {
    }

    Math_all_boolean_result::~Math_all_boolean_result() {
    }

    bool Math_all_boolean_result::operator==(const Math_all_boolean_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_boolean_result::operator!=(const Math_all_boolean_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_boolean_result::operator< (const Math_all_boolean_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_boolean_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_boolean_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBOOL, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBool(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int8_result::Math_all_int8_result() {
    }

    Math_all_int8_result::~Math_all_int8_result() {
    }

    bool Math_all_int8_result::operator==(const Math_all_int8_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int8_result::operator!=(const Math_all_int8_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int8_result::operator< (const Math_all_int8_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int8_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int8_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBYTE, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeByte(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int16_result::Math_all_int16_result() {
    }

    Math_all_int16_result::~Math_all_int16_result() {
    }

    bool Math_all_int16_result::operator==(const Math_all_int16_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int16_result::operator!=(const Math_all_int16_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int16_result::operator< (const Math_all_int16_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int16_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int16_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT16, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt16(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_result::Math_all_int32_result() {
    }

    Math_all_int32_result::~Math_all_int32_result() {
    }

    bool Math_all_int32_result::operator==(const Math_all_int32_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_result::operator!=(const Math_all_int32_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_result::operator< (const Math_all_int32_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int64_result::Math_all_int64_result() {
    }

    Math_all_int64_result::~Math_all_int64_result() {
    }

    bool Math_all_int64_result::operator==(const Math_all_int64_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int64_result::operator!=(const Math_all_int64_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int64_result::operator< (const Math_all_int64_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int64_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int64_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDINT64, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt64(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_float_result::Math_all_float_result() {
    }

    Math_all_float_result::~Math_all_float_result() {
    }

    bool Math_all_float_result::operator==(const Math_all_float_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_float_result::operator!=(const Math_all_float_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_float_result::operator< (const Math_all_float_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_float_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_float_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDFLOAT, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeFloat(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_string_result::Math_all_string_result() {
    }

    Math_all_string_result::~Math_all_string_result() {
    }

    bool Math_all_string_result::operator==(const Math_all_string_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_string_result::operator!=(const Math_all_string_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_string_result::operator< (const Math_all_string_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_string_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_string_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTR, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeString(value);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_binary_result::Math_all_binary_result() {
    }

    Math_all_binary_result::~Math_all_binary_result() {
    }

    bool Math_all_binary_result::operator==(const Math_all_binary_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_binary_result::operator!=(const Math_all_binary_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_binary_result::operator< (const Math_all_binary_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_binary_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_binary_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDBIN, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeBinary(value.c_str(), value.size());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_seq_result::Math_all_int32_seq_result() {
    }

    Math_all_int32_seq_result::~Math_all_int32_seq_result() {
    }

    bool Math_all_int32_seq_result::operator==(const Math_all_int32_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_seq_result::operator!=(const Math_all_int32_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_seq_result::operator< (const Math_all_int32_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, value.size());
        if (ret < 0) { return ret; }
        std::vector<int32_t> ::const_iterator citr_var119;
        for (citr_var119 = value.begin(); citr_var119 != value.end(); ++citr_var119) {
            ret = proto->writeInt32((*citr_var119));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_person_result::Math_all_person_result() {
    }

    Math_all_person_result::~Math_all_person_result() {
    }

    bool Math_all_person_result::operator==(const Math_all_person_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_result::operator!=(const Math_all_person_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_result::operator< (const Math_all_person_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSTRUCT, 1);
        if (ret < 0) { return ret; }
        ret = value.write(proto);
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_set_result::Math_all_int32_set_result() {
    }

    Math_all_int32_set_result::~Math_all_int32_set_result() {
    }

    bool Math_all_int32_set_result::operator==(const Math_all_int32_set_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_set_result::operator!=(const Math_all_int32_set_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_set_result::operator< (const Math_all_int32_set_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_set_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_set_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDSET, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeSetBegin(bgcc::IDINT32, value.size());
        if (ret < 0) { return ret; }
        std::set<int32_t> ::const_iterator citr_var120;
        for (citr_var120 = value.begin(); citr_var120 != value.end(); ++citr_var120) {
            ret = proto->writeInt32((*citr_var120));
            if (ret < 0) { return ret; }
        }
        ret = proto->writeSetEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_person_seq_result::Math_all_person_seq_result() {
    }

    Math_all_person_seq_result::~Math_all_person_seq_result() {
    }

    bool Math_all_person_seq_result::operator==(const Math_all_person_seq_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_person_seq_result::operator!=(const Math_all_person_seq_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_person_seq_result::operator< (const Math_all_person_seq_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_person_seq_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_person_seq_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDLIST, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDSTRUCT, value.size());
        if (ret < 0) { return ret; }
        std::vector<Person> ::const_iterator citr_var121;
        for (citr_var121 = value.begin(); citr_var121 != value.end(); ++citr_var121) {
            ret = (*citr_var121).write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_all_int32_person_map_result::Math_all_int32_person_map_result() {
    }

    Math_all_int32_person_map_result::~Math_all_int32_person_map_result() {
    }

    bool Math_all_int32_person_map_result::operator==(const Math_all_int32_person_map_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (value != rhs.value) {
            return false;
        }
        return true;
    }

    bool Math_all_int32_person_map_result::operator!=(const Math_all_int32_person_map_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_all_int32_person_map_result::operator< (const Math_all_int32_person_map_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(value < rhs.value)) {
            return false;
        }
        return true;
    }

    int32_t Math_all_int32_person_map_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_all_int32_person_map_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("value", bgcc::IDMAP, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDSTRUCT, value.size());
        if (ret < 0) { return ret; }
        std::map<int32_t, Person> ::const_iterator citr_var122;
        for (citr_var122 = value.begin(); citr_var122 != value.end(); ++citr_var122) {
            ret = proto->writeInt32(citr_var122->first);
            if (ret < 0) { return ret; }
            ret = citr_var122->second.write(proto);
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_color_out_all_result::Math_color_out_all_result() {
    }

    Math_color_out_all_result::~Math_color_out_all_result() {
    }

    bool Math_color_out_all_result::operator==(const Math_color_out_all_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (color1 != rhs.color1) {
            return false;
        }
        if (color2 != rhs.color2) {
            return false;
        }
        return true;
    }

    bool Math_color_out_all_result::operator!=(const Math_color_out_all_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_out_all_result::operator< (const Math_color_out_all_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(color1 < rhs.color1)) {
            return false;
        }
        if (!(color2 < rhs.color2)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_out_all_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_out_all_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color1", bgcc::IDINT32, 1);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(color1.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color2", bgcc::IDINT32, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeInt32(color2.get_value());
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_color_xx_result::Math_color_xx_result() {
    }

    Math_color_xx_result::~Math_color_xx_result() {
    }

    bool Math_color_xx_result::operator==(const Math_color_xx_result& rhs) const {
        if (this == &rhs) {
            return true;
        }
        if (return_value != rhs.return_value) {
            return false;
        }
        if (color2 != rhs.color2) {
            return false;
        }
        if (color3 != rhs.color3) {
            return false;
        }
        return true;
    }

    bool Math_color_xx_result::operator!=(const Math_color_xx_result& rhs) const {
        return !(*this == rhs);
    }

    bool Math_color_xx_result::operator< (const Math_color_xx_result& rhs) const {
        if (this == &rhs) {
            return false;
        }
        if (!(return_value < rhs.return_value)) {
            return false;
        }
        if (!(color2 < rhs.color2)) {
            return false;
        }
        if (!(color3 < rhs.color3)) {
            return false;
        }
        return true;
    }

    int32_t Math_color_xx_result::write(bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret = 0;
        ret = proto->writeStructBegin("Math_color_xx_result");
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("return_value", bgcc::IDLIST, 0);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, return_value.size());
        if (ret < 0) { return ret; }
        std::vector<MyColor> ::const_iterator citr_var123;
        for (citr_var123 = return_value.begin(); citr_var123 != return_value.end(); ++citr_var123) {
            ret = proto->writeInt32((*citr_var123).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color2", bgcc::IDLIST, 2);
        if (ret < 0) { return ret; }
        ret = proto->writeListBegin(bgcc::IDINT32, color2.size());
        if (ret < 0) { return ret; }
        std::vector<MyColor> ::const_iterator citr_var124;
        for (citr_var124 = color2.begin(); citr_var124 != color2.end(); ++citr_var124) {
            ret = proto->writeInt32((*citr_var124).get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeListEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldBegin("color3", bgcc::IDMAP, 3);
        if (ret < 0) { return ret; }
        ret = proto->writeMapBegin(bgcc::IDINT32, bgcc::IDINT32, color3.size());
        if (ret < 0) { return ret; }
        std::map<MyColor, MyColor> ::const_iterator citr_var125;
        for (citr_var125 = color3.begin(); citr_var125 != color3.end(); ++citr_var125) {
            ret = proto->writeInt32(citr_var125->first.get_value());
            if (ret < 0) { return ret; }
            ret = proto->writeInt32(citr_var125->second.get_value());
            if (ret < 0) { return ret; }
        }
        ret = proto->writeMapEnd();
        if (ret < 0) { return ret; }
        ret = proto->writeFieldEnd();
        if (ret < 0) { return ret; }

        ret = proto->writeFieldStop();
        if (ret < 0) { return ret; }

        return proto->writeStructEnd();
    }

    Math_ping_presult::~Math_ping_presult() {
    }

    int32_t Math_ping_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_add_presult::~Math_add_presult() {
    }

    int32_t Math_add_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                int32_t ele_var126;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var126);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var126;
                break;
            case 3:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(sum)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_test_citizen_presult::~Math_test_citizen_presult() {
    }

    int32_t Math_test_citizen_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = (*(return_value)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 2:
                ret = (*(outs)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            case 3:
                ret = (*(alls)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_boolean_presult::~Math_get_boolean_presult() {
    }

    int32_t Math_get_boolean_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_int8_presult::~Math_get_int8_presult() {
    }

    int32_t Math_get_int8_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_int16_presult::~Math_get_int16_presult() {
    }

    int32_t Math_get_int16_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_int32_presult::~Math_get_int32_presult() {
    }

    int32_t Math_get_int32_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_int64_presult::~Math_get_int64_presult() {
    }

    int32_t Math_get_int64_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_float_presult::~Math_get_float_presult() {
    }

    int32_t Math_get_float_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_string_presult::~Math_get_string_presult() {
    }

    int32_t Math_get_string_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_binary_presult::~Math_get_binary_presult() {
    }

    int32_t Math_get_binary_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, (*(return_value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_color_presult::~Math_get_color_presult() {
    }

    int32_t Math_get_color_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                int32_t ele_var127;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var127);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(return_value)) = ele_var127;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_sequence_presult::~Math_get_sequence_presult() {
    }

    int32_t Math_get_sequence_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var128;
                bgcc::DataTypeID etype_var129;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var129, size_var128);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(return_value)).reserve(size_var128);
                for(int32_t i = 0; i < size_var128; ++i) {
                    int32_t value_var130;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var130);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(return_value)).push_back(value_var130);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_string_set_presult::~Math_get_string_set_presult() {
    }

    int32_t Math_get_string_set_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var131;
                bgcc::DataTypeID etype_var132;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var132, size_var131);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var131; ++i) {
                    std::string value_var133;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var133);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(return_value)).insert(value_var133);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_int_str_map_presult::~Math_get_int_str_map_presult() {
    }

    int32_t Math_get_int_str_map_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var134;
                bgcc::DataTypeID ktype_var135;
                bgcc::DataTypeID vtype_var136;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var135, vtype_var136, size_var134);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var134; ++i) {
                    int64_t key_var137;

                    ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, key_var137);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    std::string& value_var138 = (*(return_value))[key_var137];
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var138);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_bool_set_sequence_presult::~Math_get_bool_set_sequence_presult() {
    }

    int32_t Math_get_bool_set_sequence_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var139;
                bgcc::DataTypeID etype_var140;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var140, size_var139);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(return_value)).reserve(size_var139);
                for(int32_t i = 0; i < size_var139; ++i) {
                    std::set<bool>  value_var141;
                    value_var141.clear();

                    int32_t size_var142;
                    bgcc::DataTypeID etype_var143;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var143, size_var142);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var142; ++i) {
                        bool value_var144;
                        ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, value_var144);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var141.insert(value_var144);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var141);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_person_presult::~Math_get_person_presult() {
    }

    int32_t Math_get_person_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                ret = (*(return_value)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_persons_presult::~Math_get_persons_presult() {
    }

    int32_t Math_get_persons_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var145;
                bgcc::DataTypeID etype_var146;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var146, size_var145);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(return_value)).reserve(size_var145);
                for(int32_t i = 0; i < size_var145; ++i) {
                    Person value_var147;
                    ret = value_var147.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(return_value)).push_back(value_var147);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_persons2_presult::~Math_get_persons2_presult() {
    }

    int32_t Math_get_persons2_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var148;
                bgcc::DataTypeID etype_var149;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var149, size_var148);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var148; ++i) {
                    Person value_var150;
                    ret = value_var150.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(return_value)).insert(value_var150);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_persons3_presult::~Math_get_persons3_presult() {
    }

    int32_t Math_get_persons3_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var151;
                bgcc::DataTypeID ktype_var152;
                bgcc::DataTypeID vtype_var153;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var152, vtype_var153, size_var151);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var151; ++i) {
                    Person key_var154;

                    ret = key_var154.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    Person& value_var155 = (*(return_value))[key_var154];
                    ret = value_var155.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_get_persons4_presult::~Math_get_persons4_presult() {
    }

    int32_t Math_get_persons4_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var156;
                bgcc::DataTypeID etype_var157;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var157, size_var156);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(return_value)).reserve(size_var156);
                for(int32_t i = 0; i < size_var156; ++i) {
                    std::set<Person>  value_var158;
                    value_var158.clear();

                    int32_t size_var159;
                    bgcc::DataTypeID etype_var160;
                    ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var160, size_var159);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    for(int32_t i = 0; i < size_var159; ++i) {
                        Person value_var161;
                        ret = value_var161.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var158.insert(value_var161);
                    }

                    ret = proto->readSetEnd();
                    if (ret < 0) { return ret; }
                    (*(return_value)).push_back(value_var158);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_bool_presult::~Math_send_bool_presult() {
    }

    int32_t Math_send_bool_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int8_presult::~Math_send_int8_presult() {
    }

    int32_t Math_send_int8_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int16_presult::~Math_send_int16_presult() {
    }

    int32_t Math_send_int16_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int32_presult::~Math_send_int32_presult() {
    }

    int32_t Math_send_int32_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int64_presult::~Math_send_int64_presult() {
    }

    int32_t Math_send_int64_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_float_presult::~Math_send_float_presult() {
    }

    int32_t Math_send_float_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_string_presult::~Math_send_string_presult() {
    }

    int32_t Math_send_string_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_binary_presult::~Math_send_binary_presult() {
    }

    int32_t Math_send_binary_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_color_presult::~Math_send_color_presult() {
    }

    int32_t Math_send_color_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_person_presult::~Math_send_person_presult() {
    }

    int32_t Math_send_person_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int32_sequence_presult::~Math_send_int32_sequence_presult() {
    }

    int32_t Math_send_int32_sequence_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_persons_presult::~Math_send_persons_presult() {
    }

    int32_t Math_send_persons_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_persons2_presult::~Math_send_persons2_presult() {
    }

    int32_t Math_send_persons2_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_int32_set_seq_presult::~Math_send_int32_set_seq_presult() {
    }

    int32_t Math_send_int32_set_seq_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_persons3_presult::~Math_send_persons3_presult() {
    }

    int32_t Math_send_persons3_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_send_person_vec_set_presult::~Math_send_person_vec_set_presult() {
    }

    int32_t Math_send_person_vec_set_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_boolean_presult::~Math_out_boolean_presult() {
    }

    int32_t Math_out_boolean_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int8_presult::~Math_out_int8_presult() {
    }

    int32_t Math_out_int8_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int16_presult::~Math_out_int16_presult() {
    }

    int32_t Math_out_int16_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int32_presult::~Math_out_int32_presult() {
    }

    int32_t Math_out_int32_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int64_presult::~Math_out_int64_presult() {
    }

    int32_t Math_out_int64_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_float_presult::~Math_out_float_presult() {
    }

    int32_t Math_out_float_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_string_presult::~Math_out_string_presult() {
    }

    int32_t Math_out_string_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_binary_presult::~Math_out_binary_presult() {
    }

    int32_t Math_out_binary_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_person_presult::~Math_out_person_presult() {
    }

    int32_t Math_out_person_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = (*(person)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_seq_presult::~Math_out_seq_presult() {
    }

    int32_t Math_out_seq_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var162;
                bgcc::DataTypeID etype_var163;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var163, size_var162);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(xxx)).reserve(size_var162);
                for(int32_t i = 0; i < size_var162; ++i) {
                    int32_t value_var164;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var164);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(xxx)).push_back(value_var164);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_string_set_presult::~Math_out_string_set_presult() {
    }

    int32_t Math_out_string_set_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var165;
                bgcc::DataTypeID etype_var166;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var166, size_var165);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var165; ++i) {
                    std::string value_var167;
                    ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, value_var167);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(xxx)).insert(value_var167);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int16_float_map_presult::~Math_out_int16_float_map_presult() {
    }

    int32_t Math_out_int16_float_map_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var168;
                bgcc::DataTypeID ktype_var169;
                bgcc::DataTypeID vtype_var170;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var169, vtype_var170, size_var168);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var168; ++i) {
                    int16_t key_var171;

                    ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, key_var171);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    float& value_var172 = (*(xxx))[key_var171];
                    ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, value_var172);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_out_int_vec_set_presult::~Math_out_int_vec_set_presult() {
    }

    int32_t Math_out_int_vec_set_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(xxx)).clear();

                int32_t size_var173;
                bgcc::DataTypeID etype_var174;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var174, size_var173);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var173; ++i) {
                    std::vector<int32_t>  value_var175;
                    value_var175.clear();

                    int32_t size_var176;
                    bgcc::DataTypeID etype_var177;

                    ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var177, size_var176);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    value_var175.reserve(size_var176);
                    for(int32_t i = 0; i < size_var176; ++i) {
                        int32_t value_var178;
                        ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var178);
                        if (ret < 0) { return ret; }
                        nread += ret;
                        value_var175.push_back(value_var178);
                    }

                    ret = proto->readListEnd();
                    if (ret < 0) { return ret; }
                    (*(xxx)).insert(value_var175);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_boolean_presult::~Math_all_boolean_presult() {
    }

    int32_t Math_all_boolean_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBool(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int8_presult::~Math_all_int8_presult() {
    }

    int32_t Math_all_int8_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readByte(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int16_presult::~Math_all_int16_presult() {
    }

    int32_t Math_all_int16_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt16(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int32_presult::~Math_all_int32_presult() {
    }

    int32_t Math_all_int32_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int64_presult::~Math_all_int64_presult() {
    }

    int32_t Math_all_int64_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readInt64(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_float_presult::~Math_all_float_presult() {
    }

    int32_t Math_all_float_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readFloat(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_string_presult::~Math_all_string_presult() {
    }

    int32_t Math_all_string_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readString(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_binary_presult::~Math_all_binary_presult() {
    }

    int32_t Math_all_binary_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = proto->readBinary(OFFSET_PTR(request, nread), request_len - nread, (*(value)));
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int32_seq_presult::~Math_all_int32_seq_presult() {
    }

    int32_t Math_all_int32_seq_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var179;
                bgcc::DataTypeID etype_var180;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var180, size_var179);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(value)).reserve(size_var179);
                for(int32_t i = 0; i < size_var179; ++i) {
                    int32_t value_var181;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var181);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(value)).push_back(value_var181);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_person_presult::~Math_all_person_presult() {
    }

    int32_t Math_all_person_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                ret = (*(value)).read(OFFSET_PTR(request, nread), request_len - nread, proto);
                if (ret < 0) { return ret; }
                nread += ret;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int32_set_presult::~Math_all_int32_set_presult() {
    }

    int32_t Math_all_int32_set_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var182;
                bgcc::DataTypeID etype_var183;
                ret = proto->readSetBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var183, size_var182);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var182; ++i) {
                    int32_t value_var184;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, value_var184);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(value)).insert(value_var184);
                }

                ret = proto->readSetEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_person_seq_presult::~Math_all_person_seq_presult() {
    }

    int32_t Math_all_person_seq_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var185;
                bgcc::DataTypeID etype_var186;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var186, size_var185);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(value)).reserve(size_var185);
                for(int32_t i = 0; i < size_var185; ++i) {
                    Person value_var187;
                    ret = value_var187.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    (*(value)).push_back(value_var187);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_all_int32_person_map_presult::~Math_all_int32_person_map_presult() {
    }

    int32_t Math_all_int32_person_map_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                (*(value)).clear();

                int32_t size_var188;
                bgcc::DataTypeID ktype_var189;
                bgcc::DataTypeID vtype_var190;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var189, vtype_var190, size_var188);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var188; ++i) {
                    int32_t key_var191;

                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, key_var191);
                    if (ret < 0) { return ret; }
                    nread += ret;

                    Person& value_var192 = (*(value))[key_var191];
                    ret = value_var192.read(OFFSET_PTR(request, nread), request_len - nread, proto);
                    if (ret < 0) { return ret; }
                    nread += ret;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_color_out_all_presult::~Math_color_out_all_presult() {
    }

    int32_t Math_color_out_all_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 1:
                int32_t ele_var193;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var193);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(color1)) = ele_var193;
                break;
            case 2:
                int32_t ele_var194;
                ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var194);
                if (ret < 0) { return ret; }
                nread += ret;
                (*(color2)) = ele_var194;
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    Math_color_xx_presult::~Math_color_xx_presult() {
    }

    int32_t Math_color_xx_presult::read(char *request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) const {
        int32_t ret=0;
        int32_t nread=0;
        std::string fname;
        bgcc::DataTypeID ftype;
        bgcc::FieldIDType fid; 

        ret = proto->readStructBegin(OFFSET_PTR(request, nread), request_len - nread, fname);
        if (ret < 0) { return ret; }
        nread+=ret;

        while(true) {
            ret = proto->readFieldBegin(OFFSET_PTR(request, nread), request_len - nread, fname, ftype, fid);
            if (ret < 0) { return ret; }
            nread+=ret;

            if (ftype == bgcc::IDSTOP) {
                break;
            }
            switch(fid) {
            case 0:
                (*(return_value)).clear();

                int32_t size_var195;
                bgcc::DataTypeID etype_var196;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var196, size_var195);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(return_value)).reserve(size_var195);
                for(int32_t i = 0; i < size_var195; ++i) {
                    MyColor value_var197;
                    int32_t ele_var198;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var198);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    value_var197 = ele_var198;
                    (*(return_value)).push_back(value_var197);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 2:
                (*(color2)).clear();

                int32_t size_var199;
                bgcc::DataTypeID etype_var200;

                ret = proto->readListBegin(OFFSET_PTR(request, nread), request_len - nread, etype_var200, size_var199);
                if (ret < 0) { return ret; }
                nread += ret;

                (*(color2)).reserve(size_var199);
                for(int32_t i = 0; i < size_var199; ++i) {
                    MyColor value_var201;
                    int32_t ele_var202;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var202);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    value_var201 = ele_var202;
                    (*(color2)).push_back(value_var201);
                }

                ret = proto->readListEnd();
                if (ret < 0) { return ret; }
                break;
            case 3:
                (*(color3)).clear();

                int32_t size_var203;
                bgcc::DataTypeID ktype_var204;
                bgcc::DataTypeID vtype_var205;

                ret = proto->readMapBegin(OFFSET_PTR(request, nread), request_len - nread, ktype_var204, vtype_var205, size_var203);
                if (ret < 0) { return ret; }
                nread += ret;

                for(int32_t i = 0; i < size_var203; ++i) {
                    MyColor key_var206;

                    int32_t ele_var207;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var207);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    key_var206 = ele_var207;

                    MyColor& value_var208 = (*(color3))[key_var206];
                    int32_t ele_var209;
                    ret = proto->readInt32(OFFSET_PTR(request, nread), request_len - nread, ele_var209);
                    if (ret < 0) { return ret; }
                    nread += ret;
                    value_var208 = ele_var209;
                }

                ret = proto->readMapEnd();
                if (ret < 0) { return ret; }
                break;
            default:
                break;
            }

            ret = proto->readFieldEnd();
            if (ret < 0) { return ret; }
            nread+=ret; 
        }

        ret=proto->readStructEnd();
        if (ret < 0) { return ret; }
        nread+=ret; 

        return nread;
    }

    MathProxy::MathProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    MathProxy::MathProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::BaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    MathProxy::MathProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::BaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.math.Math";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    void MathProxy::ping(bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_ping(_seqid, conn);
                if(get_errno()==0){
                    recv_ping(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_ping(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ping", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_ping_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_ping(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_ping_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="ping"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    AddResult MathProxy::add(int32_t a, int32_t b, int32_t& sum, bool /*last*/) {
        AddResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_add(a, b, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_add(sum, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_add(const int32_t& a, const int32_t& b, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "add", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_add_pargs pargs;
        pargs.a = &a;
        pargs.b = &b;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    AddResult MathProxy::recv_add(int32_t& sum, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        AddResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_add_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="add"){
            presult.return_value = &ret_val;
            presult.sum = &sum;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Citizen MathProxy::test_citizen(const Citizen& ins, Citizen& outs, Citizen& alls, bool /*last*/) {
        Citizen return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_test_citizen(ins, alls, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_test_citizen(outs, alls, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_test_citizen(const Citizen& ins, const Citizen& alls, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "test_citizen", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_test_citizen_pargs pargs;
        pargs.ins = &ins;
        pargs.alls = &alls;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Citizen MathProxy::recv_test_citizen(Citizen& outs, Citizen& alls, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Citizen ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_test_citizen_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="test_citizen"){
            presult.return_value = &ret_val;
            presult.outs = &outs;
            presult.alls = &alls;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    bool MathProxy::get_boolean(bool /*last*/) {
        bool return_value = false;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_boolean(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_boolean(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    bool MathProxy::recv_get_boolean(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bool ret_val = false;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_boolean"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int8_t MathProxy::get_int8(bool /*last*/) {
        int8_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int8(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int8(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_int8(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int8_t MathProxy::recv_get_int8(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int8_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int8"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int16_t MathProxy::get_int16(bool /*last*/) {
        int16_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int16(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int16(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_int16(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int16_t MathProxy::recv_get_int16(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int16_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int16"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int32_t MathProxy::get_int32(bool /*last*/) {
        int32_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int32(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int32(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_int32(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int32_t MathProxy::recv_get_int32(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int32_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int32"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int64_t MathProxy::get_int64(bool /*last*/) {
        int64_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int64(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int64(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_int64(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int64_t MathProxy::recv_get_int64(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int64_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int64"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    float MathProxy::get_float(bool /*last*/) {
        float return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_float(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_float(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_float(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    float MathProxy::recv_get_float(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        float ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_float"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::string MathProxy::get_string(bool /*last*/) {
        std::string return_value = "";
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_string(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_string(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_string(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string MathProxy::recv_get_string(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::string ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_string"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::string MathProxy::get_binary(bool /*last*/) {
        std::string return_value = "";
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_binary(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_binary(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_binary(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string MathProxy::recv_get_binary(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::string ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_binary"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Color MathProxy::get_color(bool /*last*/) {
        Color return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_color(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_color(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_color(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_color_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Color MathProxy::recv_get_color(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Color ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_color_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_color"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<int32_t>  MathProxy::get_sequence(bool /*last*/) {
        std::vector<int32_t>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_sequence(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<int32_t>  MathProxy::recv_get_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<int32_t>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_sequence"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::set<std::string>  MathProxy::get_string_set(bool /*last*/) {
        std::set<std::string>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_string_set(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_string_set(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<std::string>  MathProxy::recv_get_string_set(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::set<std::string>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_string_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_string_set"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::map<int64_t, std::string>  MathProxy::get_int_str_map(bool /*last*/) {
        std::map<int64_t, std::string>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int_str_map(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int_str_map(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_int_str_map(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int_str_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int_str_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<int64_t, std::string>  MathProxy::recv_get_int_str_map(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::map<int64_t, std::string>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int_str_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int_str_map"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<bool> >  MathProxy::get_bool_set_sequence(bool /*last*/) {
        std::vector<std::set<bool> >  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_bool_set_sequence(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_bool_set_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_bool_set_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_bool_set_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_bool_set_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<bool> >  MathProxy::recv_get_bool_set_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<std::set<bool> >  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_bool_set_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_bool_set_sequence"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Person MathProxy::get_person(bool /*last*/) {
        Person return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_person(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_person(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_person(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Person MathProxy::recv_get_person(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Person ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_person"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<Person>  MathProxy::get_persons(bool /*last*/) {
        std::vector<Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_persons(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<Person>  MathProxy::recv_get_persons(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::set<Person>  MathProxy::get_persons2(bool /*last*/) {
        std::set<Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons2(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons2(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_persons2(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons2_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<Person>  MathProxy::recv_get_persons2(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::set<Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons2_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons2"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::map<Person, Person>  MathProxy::get_persons3(bool /*last*/) {
        std::map<Person, Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons3(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons3(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_persons3(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons3_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<Person, Person>  MathProxy::recv_get_persons3(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::map<Person, Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons3_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons3"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<Person> >  MathProxy::get_persons4(bool /*last*/) {
        std::vector<std::set<Person> >  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons4(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons4(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_get_persons4(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons4", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons4_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<Person> >  MathProxy::recv_get_persons4(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<std::set<Person> >  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons4_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons4"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    void MathProxy::send_bool(b_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_bool(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_bool(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_bool(const b_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_bool", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_bool_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_bool(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_bool_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_bool"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int8(i8_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int8(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int8(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int8(const i8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int8(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int8"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int16(i16_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int16(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int16(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int16(const i16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int16(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int16"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32(i32_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int32(const i32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int64(i64_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int64(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int64(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int64(const i64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int64(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int64"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_float(f_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_float(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_float(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_float(const f_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_float(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_float"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_string(const s_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_string(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_string(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_string(const s_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_string(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_string"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_binary(const bin_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_binary(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_binary(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_binary(const bin_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_binary(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_binary"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_color(const Color& color, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_color(color, _seqid, conn);
                if(get_errno()==0){
                    recv_send_color(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_color(const Color& color, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_color_pargs pargs;
        pargs.color = &color;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_color(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_color_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_color"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_person(const MyPerson& person, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_person(person, _seqid, conn);
                if(get_errno()==0){
                    recv_send_person(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_person(const MyPerson& person, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_pargs pargs;
        pargs.person = &person;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_person(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_person"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32_sequence(const std::vector<int32_t> & numbers, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32_sequence(numbers, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int32_sequence(const std::vector<int32_t> & numbers, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_sequence_pargs pargs;
        pargs.numbers = &numbers;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32_sequence"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons(const std::vector<Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_persons(const std::vector<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons2(const std::set<Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons2(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons2(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_persons2(const std::set<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons2_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons2(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons2_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons2"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32_set_seq(xx, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32_set_seq(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_set_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_set_seq_pargs pargs;
        pargs.xx = &xx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_int32_set_seq(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_set_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32_set_seq"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_persons3(const std::map<Person, Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons3(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons3(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_persons3(const std::map<Person, Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons3_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_persons3(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons3_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons3"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::send_person_vec_set(const std::set<std::vector<Person> > & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_person_vec_set(xxx, _seqid, conn);
                if(get_errno()==0){
                    recv_send_person_vec_set(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_send_person_vec_set(const std::set<std::vector<Person> > & xxx, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_vec_set_pargs pargs;
        pargs.xxx = &xxx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_send_person_vec_set(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_person_vec_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_person_vec_set"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_boolean(bool& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_boolean(_seqid, conn);
                if(get_errno()==0){
                    recv_out_boolean(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_boolean(bool& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_boolean"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int8(int8_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int8(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int8(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int8(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int8(int8_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int8"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int16(int16_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int16(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int16(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int16(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int16(int16_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int16"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int32(int32_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int32(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int32(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int32(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int32(int32_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int32"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int64(int64_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int64(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int64(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int64(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int64(int64_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int64"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_float(float& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_float(_seqid, conn);
                if(get_errno()==0){
                    recv_out_float(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_float(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_float(float& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_float"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_string(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_string(_seqid, conn);
                if(get_errno()==0){
                    recv_out_string(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_string(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_string(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_string"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_binary(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_binary(_seqid, conn);
                if(get_errno()==0){
                    recv_out_binary(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_binary(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_binary(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_binary"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_person(Person& person, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_person(_seqid, conn);
                if(get_errno()==0){
                    recv_out_person(person, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_person(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_person(Person& person, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_person"){
            presult.person = &person;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_seq(std::vector<int32_t> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_seq(_seqid, conn);
                if(get_errno()==0){
                    recv_out_seq(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_seq(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_seq_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_seq(std::vector<int32_t> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_seq"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_string_set(std::set<std::string> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_string_set(_seqid, conn);
                if(get_errno()==0){
                    recv_out_string_set(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_string_set(std::set<std::string> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_string_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_string_set"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int16_float_map(std::map<int16_t, float> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int16_float_map(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int16_float_map(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int16_float_map(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16_float_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_float_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int16_float_map(std::map<int16_t, float> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int16_float_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int16_float_map"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int_vec_set(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int_vec_set(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_out_int_vec_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int_vec_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int_vec_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int_vec_set"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_boolean(bool& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_boolean(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_boolean(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_boolean(const bool& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_boolean_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_boolean(bool& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_boolean"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int8(int8_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int8(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int8(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int8(const int8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int8(int8_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int8"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int16(int16_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int16(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int16(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int16(const int16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int16(int16_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int16"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32(int32_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int32(const int32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32(int32_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int64(int64_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int64(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int64(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int64(const int64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int64(int64_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int64"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_float(float& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_float(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_float(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_float(const float& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_float(float& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_float"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_string(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_string(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_string(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_string(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_string(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_string"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_binary(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_binary(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_binary(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_binary(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_binary(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_binary"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_seq(std::vector<int32_t> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_seq(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_seq(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int32_seq(const std::vector<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_seq(std::vector<int32_t> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_seq"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_person(Person& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_person(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_person(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_person(const Person& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_person(Person& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_person"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_set(std::set<int32_t> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_set(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_set(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int32_set(const std::set<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_set_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_set(std::set<int32_t> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_set"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_person_seq(std::vector<Person> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_person_seq(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_person_seq(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_person_seq(const std::vector<Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_person_seq(std::vector<Person> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_person_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_person_seq"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::all_int32_person_map(std::map<int32_t, Person> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_person_map(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_person_map(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_all_int32_person_map(const std::map<int32_t, Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_person_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_person_map_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_all_int32_person_map(std::map<int32_t, Person> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_person_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_person_map"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void MathProxy::color_out_all(MyColor& color1, MyColor& color2, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_color_out_all(color1, _seqid, conn);
                if(get_errno()==0){
                    recv_color_out_all(color1, color2, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void MathProxy::send_color_out_all(const MyColor& color1, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_out_all", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_out_all_pargs pargs;
        pargs.color1 = &color1;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void MathProxy::recv_color_out_all(MyColor& color1, MyColor& color2, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_color_out_all_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="color_out_all"){
            presult.color1 = &color1;
            presult.color2 = &color2;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    std::vector<MyColor>  MathProxy::color_xx(const std::set<MyColor> & color1, std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bool /*last*/) {
        std::vector<MyColor>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_color_xx(color1, color3, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_color_xx(color2, color3, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void MathProxy::send_color_xx(const std::set<MyColor> & color1, const std::map<MyColor, MyColor> & color3, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_xx", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_xx_pargs pargs;
        pargs.color1 = &color1;
        pargs.color3 = &color3;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<MyColor>  MathProxy::recv_color_xx(std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<MyColor>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_color_xx_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="color_xx"){
            presult.return_value = &ret_val;
            presult.color2 = &color2;
            presult.color3 = &color3;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    SSLMathProxy::SSLMathProxy(
        bgcc::ServerInfo serverinfo,
        int32_t maxConn,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, maxConn, true, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    SSLMathProxy::SSLMathProxy(
        bgcc::ServerInfo serverinfo,
        bgcc::ServiceManager* mgr,
        int32_t tryCount,
        int32_t tryInterval) :
        bgcc::SSLBaseProxy(serverinfo, 1, false, mgr, tryCount, tryInterval){
            _whoami = "global.math.Math";
    }

    SSLMathProxy::SSLMathProxy(const std::string& proxy_name, int32_t tryCount, int32_t tryInterval) :
        bgcc::SSLBaseProxy(bgcc::ServerInfo("", 0), 0, true, NULL, tryCount, tryInterval){
            _whoami = "global.math.Math";
            _use_existing_socket  = true;
            _name=proxy_name;
    }

    void SSLMathProxy::ping(bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_ping(_seqid, conn);
                if(get_errno()==0){
                    recv_ping(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_ping(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "ping", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_ping_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_ping(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_ping_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="ping"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    AddResult SSLMathProxy::add(int32_t a, int32_t b, int32_t& sum, bool /*last*/) {
        AddResult return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_add(a, b, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_add(sum, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_add(const int32_t& a, const int32_t& b, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "add", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_add_pargs pargs;
        pargs.a = &a;
        pargs.b = &b;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    AddResult SSLMathProxy::recv_add(int32_t& sum, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        AddResult ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_add_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="add"){
            presult.return_value = &ret_val;
            presult.sum = &sum;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Citizen SSLMathProxy::test_citizen(const Citizen& ins, Citizen& outs, Citizen& alls, bool /*last*/) {
        Citizen return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_test_citizen(ins, alls, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_test_citizen(outs, alls, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_test_citizen(const Citizen& ins, const Citizen& alls, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "test_citizen", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_test_citizen_pargs pargs;
        pargs.ins = &ins;
        pargs.alls = &alls;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Citizen SSLMathProxy::recv_test_citizen(Citizen& outs, Citizen& alls, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Citizen ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_test_citizen_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="test_citizen"){
            presult.return_value = &ret_val;
            presult.outs = &outs;
            presult.alls = &alls;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    bool SSLMathProxy::get_boolean(bool /*last*/) {
        bool return_value = false;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_boolean(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_boolean(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    bool SSLMathProxy::recv_get_boolean(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bool ret_val = false;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_boolean"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int8_t SSLMathProxy::get_int8(bool /*last*/) {
        int8_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int8(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int8(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_int8(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int8_t SSLMathProxy::recv_get_int8(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int8_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int8"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int16_t SSLMathProxy::get_int16(bool /*last*/) {
        int16_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int16(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int16(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_int16(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int16_t SSLMathProxy::recv_get_int16(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int16_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int16"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int32_t SSLMathProxy::get_int32(bool /*last*/) {
        int32_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int32(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int32(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_int32(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int32_t SSLMathProxy::recv_get_int32(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int32_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int32"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    int64_t SSLMathProxy::get_int64(bool /*last*/) {
        int64_t return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int64(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int64(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_int64(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    int64_t SSLMathProxy::recv_get_int64(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        int64_t ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int64"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    float SSLMathProxy::get_float(bool /*last*/) {
        float return_value = 0;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_float(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_float(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_float(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    float SSLMathProxy::recv_get_float(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        float ret_val = 0;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_float"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::string SSLMathProxy::get_string(bool /*last*/) {
        std::string return_value = "";
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_string(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_string(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_string(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string SSLMathProxy::recv_get_string(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::string ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_string"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::string SSLMathProxy::get_binary(bool /*last*/) {
        std::string return_value = "";
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_binary(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_binary(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_binary(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::string SSLMathProxy::recv_get_binary(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::string ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_binary"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Color SSLMathProxy::get_color(bool /*last*/) {
        Color return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_color(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_color(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_color(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_color_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Color SSLMathProxy::recv_get_color(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Color ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_color_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_color"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<int32_t>  SSLMathProxy::get_sequence(bool /*last*/) {
        std::vector<int32_t>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_sequence(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<int32_t>  SSLMathProxy::recv_get_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<int32_t>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_sequence"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::set<std::string>  SSLMathProxy::get_string_set(bool /*last*/) {
        std::set<std::string>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_string_set(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_string_set(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<std::string>  SSLMathProxy::recv_get_string_set(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::set<std::string>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_string_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_string_set"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::map<int64_t, std::string>  SSLMathProxy::get_int_str_map(bool /*last*/) {
        std::map<int64_t, std::string>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_int_str_map(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_int_str_map(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_int_str_map(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_int_str_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_int_str_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<int64_t, std::string>  SSLMathProxy::recv_get_int_str_map(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::map<int64_t, std::string>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_int_str_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_int_str_map"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<bool> >  SSLMathProxy::get_bool_set_sequence(bool /*last*/) {
        std::vector<std::set<bool> >  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_bool_set_sequence(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_bool_set_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_bool_set_sequence(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_bool_set_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_bool_set_sequence_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<bool> >  SSLMathProxy::recv_get_bool_set_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<std::set<bool> >  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_bool_set_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_bool_set_sequence"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    Person SSLMathProxy::get_person(bool /*last*/) {
        Person return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_person(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_person(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_person(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    Person SSLMathProxy::recv_get_person(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        Person ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_person"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<Person>  SSLMathProxy::get_persons(bool /*last*/) {
        std::vector<Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_persons(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<Person>  SSLMathProxy::recv_get_persons(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::set<Person>  SSLMathProxy::get_persons2(bool /*last*/) {
        std::set<Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons2(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons2(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_persons2(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons2_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::set<Person>  SSLMathProxy::recv_get_persons2(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::set<Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons2_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons2"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::map<Person, Person>  SSLMathProxy::get_persons3(bool /*last*/) {
        std::map<Person, Person>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons3(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons3(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_persons3(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons3_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::map<Person, Person>  SSLMathProxy::recv_get_persons3(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::map<Person, Person>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons3_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons3"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    std::vector<std::set<Person> >  SSLMathProxy::get_persons4(bool /*last*/) {
        std::vector<std::set<Person> >  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_get_persons4(_seqid, conn);
                if(get_errno()==0){
                    return_value = recv_get_persons4(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_get_persons4(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "get_persons4", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_get_persons4_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<std::set<Person> >  SSLMathProxy::recv_get_persons4(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<std::set<Person> >  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_get_persons4_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="get_persons4"){
            presult.return_value = &ret_val;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    void SSLMathProxy::send_bool(b_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_bool(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_bool(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_bool(const b_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_bool", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_bool_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_bool(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_bool_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_bool"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int8(i8_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int8(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int8(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int8(const i8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int8(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int8"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int16(i16_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int16(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int16(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int16(const i16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int16(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int16"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int32(i32_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int32(const i32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int32(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int64(i64_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int64(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int64(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int64(const i64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int64(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int64"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_float(f_t value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_float(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_float(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_float(const f_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_float(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_float"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_string(const s_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_string(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_string(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_string(const s_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_string(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_string"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_binary(const bin_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_binary(value, _seqid, conn);
                if(get_errno()==0){
                    recv_send_binary(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_binary(const bin_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_binary(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_binary"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_color(const Color& color, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_color(color, _seqid, conn);
                if(get_errno()==0){
                    recv_send_color(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_color(const Color& color, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_color", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_color_pargs pargs;
        pargs.color = &color;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_color(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_color_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_color"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_person(const MyPerson& person, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_person(person, _seqid, conn);
                if(get_errno()==0){
                    recv_send_person(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_person(const MyPerson& person, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_pargs pargs;
        pargs.person = &person;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_person(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_person"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int32_sequence(const std::vector<int32_t> & numbers, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32_sequence(numbers, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32_sequence(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int32_sequence(const std::vector<int32_t> & numbers, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_sequence", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_sequence_pargs pargs;
        pargs.numbers = &numbers;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int32_sequence(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_sequence_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32_sequence"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_persons(const std::vector<Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_persons(const std::vector<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_persons(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_persons2(const std::set<Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons2(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons2(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_persons2(const std::set<Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons2", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons2_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_persons2(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons2_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons2"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_int32_set_seq(xx, _seqid, conn);
                if(get_errno()==0){
                    recv_send_int32_set_seq(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_int32_set_seq(const std::vector<std::set<int32_t> > & xx, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_int32_set_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_int32_set_seq_pargs pargs;
        pargs.xx = &xx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_int32_set_seq(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_int32_set_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_int32_set_seq"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_persons3(const std::map<Person, Person> & persons, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_persons3(persons, _seqid, conn);
                if(get_errno()==0){
                    recv_send_persons3(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_persons3(const std::map<Person, Person> & persons, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_persons3", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_persons3_pargs pargs;
        pargs.persons = &persons;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_persons3(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_persons3_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_persons3"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::send_person_vec_set(const std::set<std::vector<Person> > & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_send_person_vec_set(xxx, _seqid, conn);
                if(get_errno()==0){
                    recv_send_person_vec_set(conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_send_person_vec_set(const std::set<std::vector<Person> > & xxx, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "send_person_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_send_person_vec_set_pargs pargs;
        pargs.xxx = &xxx;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_send_person_vec_set(bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_send_person_vec_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="send_person_vec_set"){
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_boolean(bool& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_boolean(_seqid, conn);
                if(get_errno()==0){
                    recv_out_boolean(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_boolean(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_boolean_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_boolean(bool& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_boolean"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int8(int8_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int8(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int8(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int8(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int8_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int8(int8_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int8"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int16(int16_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int16(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int16(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int16(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int16(int16_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int16"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int32(int32_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int32(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int32(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int32(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int32_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int32(int32_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int32"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int64(int64_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int64(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int64(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int64(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int64_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int64(int64_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int64"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_float(float& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_float(_seqid, conn);
                if(get_errno()==0){
                    recv_out_float(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_float(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_float_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_float(float& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_float"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_string(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_string(_seqid, conn);
                if(get_errno()==0){
                    recv_out_string(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_string(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_string(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_string"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_binary(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_binary(_seqid, conn);
                if(get_errno()==0){
                    recv_out_binary(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_binary(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_binary_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_binary(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_binary"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_person(Person& person, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_person(_seqid, conn);
                if(get_errno()==0){
                    recv_out_person(person, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_person(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_person_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_person(Person& person, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_person"){
            presult.person = &person;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_seq(std::vector<int32_t> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_seq(_seqid, conn);
                if(get_errno()==0){
                    recv_out_seq(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_seq(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_seq_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_seq(std::vector<int32_t> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_seq"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_string_set(std::set<std::string> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_string_set(_seqid, conn);
                if(get_errno()==0){
                    recv_out_string_set(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_string_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_string_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_string_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_string_set(std::set<std::string> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_string_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_string_set"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int16_float_map(std::map<int16_t, float> & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int16_float_map(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int16_float_map(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int16_float_map(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int16_float_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int16_float_map_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int16_float_map(std::map<int16_t, float> & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int16_float_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int16_float_map"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_out_int_vec_set(_seqid, conn);
                if(get_errno()==0){
                    recv_out_int_vec_set(xxx, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_out_int_vec_set(int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "out_int_vec_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_out_int_vec_set_pargs pargs;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_out_int_vec_set(std::set<std::vector<int32_t> > & xxx, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_out_int_vec_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="out_int_vec_set"){
            presult.xxx = &xxx;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_boolean(bool& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_boolean(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_boolean(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_boolean(const bool& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_boolean", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_boolean_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_boolean(bool& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_boolean_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_boolean"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int8(int8_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int8(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int8(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int8(const int8_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int8", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int8_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int8(int8_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int8_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int8"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int16(int16_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int16(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int16(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int16(const int16_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int16", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int16_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int16(int16_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int16_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int16"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int32(int32_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int32(const int32_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int32(int32_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int64(int64_t& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int64(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int64(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int64(const int64_t& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int64", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int64_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int64(int64_t& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int64_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int64"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_float(float& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_float(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_float(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_float(const float& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_float", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_float_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_float(float& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_float_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_float"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_string(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_string(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_string(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_string(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_string", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_string_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_string(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_string_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_string"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_binary(std::string& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_binary(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_binary(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_binary(const std::string& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_binary", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_binary_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_binary(std::string& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_binary_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_binary"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int32_seq(std::vector<int32_t> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_seq(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_seq(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int32_seq(const std::vector<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int32_seq(std::vector<int32_t> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_seq"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_person(Person& value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_person(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_person(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_person(const Person& value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_person(Person& value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_person_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_person"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int32_set(std::set<int32_t> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_set(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_set(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int32_set(const std::set<int32_t> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_set", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_set_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int32_set(std::set<int32_t> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_set_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_set"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_person_seq(std::vector<Person> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_person_seq(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_person_seq(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_person_seq(const std::vector<Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_person_seq", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_person_seq_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_person_seq(std::vector<Person> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_person_seq_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_person_seq"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::all_int32_person_map(std::map<int32_t, Person> & value, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_all_int32_person_map(value, _seqid, conn);
                if(get_errno()==0){
                    recv_all_int32_person_map(value, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_all_int32_person_map(const std::map<int32_t, Person> & value, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "all_int32_person_map", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_all_int32_person_map_pargs pargs;
        pargs.value = &value;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_all_int32_person_map(std::map<int32_t, Person> & value, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_all_int32_person_map_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="all_int32_person_map"){
            presult.value = &value;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    void SSLMathProxy::color_out_all(MyColor& color1, MyColor& color2, bool /*last*/) {
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_color_out_all(color1, _seqid, conn);
                if(get_errno()==0){
                    recv_color_out_all(color1, color2, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return ;
    }

    void SSLMathProxy::send_color_out_all(const MyColor& color1, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_out_all", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_out_all_pargs pargs;
        pargs.color1 = &color1;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    void SSLMathProxy::recv_color_out_all(MyColor& color1, MyColor& color2, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_color_out_all_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="color_out_all"){
            presult.color1 = &color1;
            presult.color2 = &color2;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return;
    }

    std::vector<MyColor>  SSLMathProxy::color_xx(const std::set<MyColor> & color1, std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bool /*last*/) {
        std::vector<MyColor>  return_value;
        int tryCount = 0;
        do{
            bgcc::SharedPointer<bgcc::ConnInfo> conn=get_Conn();
            if(conn.is_valid()&&conn->proto.is_valid()){
                send_color_xx(color1, color3, _seqid, conn);
                if(get_errno()==0){
                    return_value = recv_color_xx(color2, color3, conn);
                    free_Conn(conn, get_errno());
                }
            }
            else{
                set_errno(-1);
            }
        }while(!_use_existing_socket&&tryCount++<_tryCount&&get_errno()!=0);

        return return_value;
    }

    void SSLMathProxy::send_color_xx(const std::set<MyColor> & color1, const std::map<MyColor, MyColor> & color3, int32_t seqid, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        bgcc::SharedPointer<bgcc::IProtocol> proto = conn->proto;
        int32_t ret_code = 0;
        set_errno(ret_code);

        ret_code = proto->writeMessageBegin(_whoami.c_str(), "color_xx", bgcc::CALL, seqid);
        if (ret_code < 0) { set_errno(ret_code); return;}

        ret_code = proto->writeString(get_name());
        if (ret_code < 0) { set_errno(ret_code); return;}

        Math_color_xx_pargs pargs;
        pargs.color1 = &color1;
        pargs.color3 = &color3;
        ret_code = pargs.write(proto);
        if (ret_code < 0) { set_errno(ret_code); return;}

        proto->writeMessageEnd();
        if (ret_code < 0) { set_errno(ret_code); return;}
    }

    std::vector<MyColor>  SSLMathProxy::recv_color_xx(std::vector<MyColor> & color2, std::map<MyColor, MyColor> & color3, bgcc::SharedPointer<bgcc::ConnInfo> conn) {
        std::vector<MyColor>  ret_val;
        bgcc::SharedPointer<bgcc::IProtocol> proto=conn->proto;
        int32_t ret_code=0;
        std::string fname;
        bgcc::MsgTypeID  msg_type=bgcc::CALL;
        int32_t msg_seqid=0;
        char *read_buf=NULL;
        int32_t read_buf_len = 0;
        Math_color_xx_presult presult;
        set_errno(ret_code);

        if((ret_code=proto->readMessageBegin(&read_buf, read_buf_len, fname, msg_type, msg_seqid, conn->param))>HEAD_SIZE
            &&msg_type==bgcc::REPLY
            &&fname=="color_xx"){
            presult.return_value = &ret_val;
            presult.color2 = &color2;
            presult.color3 = &color3;
            ret_code = presult.read(OFFSET_PTR(read_buf, ret_code), read_buf_len - ret_code, proto);
            if(ret_code>0) { ret_code=proto->readMessageEnd();}
        }
        else{
            ret_code=-1;
        }
        set_errno(ret_code);
        return ret_val;
    }

    MathProcessor::MathProcessor(bgcc::SharedPointer<Math> intf) :
        bgcc::BaseProcessor(), __intf(intf) {
        __fun_map["ping"] = &MathProcessor::do_ping;
        __fun_map["add"] = &MathProcessor::do_add;
        __fun_map["test_citizen"] = &MathProcessor::do_test_citizen;
        __fun_map["get_boolean"] = &MathProcessor::do_get_boolean;
        __fun_map["get_int8"] = &MathProcessor::do_get_int8;
        __fun_map["get_int16"] = &MathProcessor::do_get_int16;
        __fun_map["get_int32"] = &MathProcessor::do_get_int32;
        __fun_map["get_int64"] = &MathProcessor::do_get_int64;
        __fun_map["get_float"] = &MathProcessor::do_get_float;
        __fun_map["get_string"] = &MathProcessor::do_get_string;
        __fun_map["get_binary"] = &MathProcessor::do_get_binary;
        __fun_map["get_color"] = &MathProcessor::do_get_color;
        __fun_map["get_sequence"] = &MathProcessor::do_get_sequence;
        __fun_map["get_string_set"] = &MathProcessor::do_get_string_set;
        __fun_map["get_int_str_map"] = &MathProcessor::do_get_int_str_map;
        __fun_map["get_bool_set_sequence"] = &MathProcessor::do_get_bool_set_sequence;
        __fun_map["get_person"] = &MathProcessor::do_get_person;
        __fun_map["get_persons"] = &MathProcessor::do_get_persons;
        __fun_map["get_persons2"] = &MathProcessor::do_get_persons2;
        __fun_map["get_persons3"] = &MathProcessor::do_get_persons3;
        __fun_map["get_persons4"] = &MathProcessor::do_get_persons4;
        __fun_map["send_bool"] = &MathProcessor::do_send_bool;
        __fun_map["send_int8"] = &MathProcessor::do_send_int8;
        __fun_map["send_int16"] = &MathProcessor::do_send_int16;
        __fun_map["send_int32"] = &MathProcessor::do_send_int32;
        __fun_map["send_int64"] = &MathProcessor::do_send_int64;
        __fun_map["send_float"] = &MathProcessor::do_send_float;
        __fun_map["send_string"] = &MathProcessor::do_send_string;
        __fun_map["send_binary"] = &MathProcessor::do_send_binary;
        __fun_map["send_color"] = &MathProcessor::do_send_color;
        __fun_map["send_person"] = &MathProcessor::do_send_person;
        __fun_map["send_int32_sequence"] = &MathProcessor::do_send_int32_sequence;
        __fun_map["send_persons"] = &MathProcessor::do_send_persons;
        __fun_map["send_persons2"] = &MathProcessor::do_send_persons2;
        __fun_map["send_int32_set_seq"] = &MathProcessor::do_send_int32_set_seq;
        __fun_map["send_persons3"] = &MathProcessor::do_send_persons3;
        __fun_map["send_person_vec_set"] = &MathProcessor::do_send_person_vec_set;
        __fun_map["out_boolean"] = &MathProcessor::do_out_boolean;
        __fun_map["out_int8"] = &MathProcessor::do_out_int8;
        __fun_map["out_int16"] = &MathProcessor::do_out_int16;
        __fun_map["out_int32"] = &MathProcessor::do_out_int32;
        __fun_map["out_int64"] = &MathProcessor::do_out_int64;
        __fun_map["out_float"] = &MathProcessor::do_out_float;
        __fun_map["out_string"] = &MathProcessor::do_out_string;
        __fun_map["out_binary"] = &MathProcessor::do_out_binary;
        __fun_map["out_person"] = &MathProcessor::do_out_person;
        __fun_map["out_seq"] = &MathProcessor::do_out_seq;
        __fun_map["out_string_set"] = &MathProcessor::do_out_string_set;
        __fun_map["out_int16_float_map"] = &MathProcessor::do_out_int16_float_map;
        __fun_map["out_int_vec_set"] = &MathProcessor::do_out_int_vec_set;
        __fun_map["all_boolean"] = &MathProcessor::do_all_boolean;
        __fun_map["all_int8"] = &MathProcessor::do_all_int8;
        __fun_map["all_int16"] = &MathProcessor::do_all_int16;
        __fun_map["all_int32"] = &MathProcessor::do_all_int32;
        __fun_map["all_int64"] = &MathProcessor::do_all_int64;
        __fun_map["all_float"] = &MathProcessor::do_all_float;
        __fun_map["all_string"] = &MathProcessor::do_all_string;
        __fun_map["all_binary"] = &MathProcessor::do_all_binary;
        __fun_map["all_int32_seq"] = &MathProcessor::do_all_int32_seq;
        __fun_map["all_person"] = &MathProcessor::do_all_person;
        __fun_map["all_int32_set"] = &MathProcessor::do_all_int32_set;
        __fun_map["all_person_seq"] = &MathProcessor::do_all_person_seq;
        __fun_map["all_int32_person_map"] = &MathProcessor::do_all_int32_person_map;
        __fun_map["color_out_all"] = &MathProcessor::do_color_out_all;
        __fun_map["color_xx"] = &MathProcessor::do_color_xx;
    }

    int32_t MathProcessor::process(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto) {
        int32_t ret = 0;
        bgcc::MsgTypeID mtype;
        int32_t seqid;
        std::string fname;
        int32_t nread = 0;
        ret = proto->readMessageBegin(&request, request_len, fname, mtype, seqid);
        if (ret < 0) { return ret;}
        nread += ret;
        if (mtype != ::bgcc::CALL){
            return -1;
        }
        return do_function__(OFFSET_PTR(request, nread), request_len-nread, proto, fname, seqid);
    }

    std::string MathProcessor::get_name() const {
        return "global.math.Math";
    }

    int32_t MathProcessor::do_function__(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, 
        const std::string& fname, int32_t seqid) {
        std::map<std::string, do_function_ptr>::iterator it;
        it = __fun_map.find(fname);
        if (it == __fun_map.end()) {
            return bgcc::BaseProcessor::do_function__(request, request_len, proto, fname, seqid);
        }

        return (this->*(it->second))(request, request_len, proto, seqid);
    }

    int32_t MathProcessor::do_ping(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_ping_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_ping_result result;
        __intf->ping(map);
        ret = proto->writeMessageBegin("global.math.Math", "ping", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_add(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_add_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_add_result result;
        result.return_value = __intf->add(args.a, args.b, result.sum, map);
        ret = proto->writeMessageBegin("global.math.Math", "add", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_test_citizen(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_test_citizen_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_test_citizen_result result;
        result.return_value = __intf->test_citizen(args.ins, result.outs, args.alls, map);
        result.alls = args.alls;
        ret = proto->writeMessageBegin("global.math.Math", "test_citizen", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_boolean_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_boolean_result result;
        result.return_value = __intf->get_boolean(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_int8_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_int8_result result;
        result.return_value = __intf->get_int8(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_int16_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_int16_result result;
        result.return_value = __intf->get_int16(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_int32_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_int32_result result;
        result.return_value = __intf->get_int32(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_int64_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_int64_result result;
        result.return_value = __intf->get_int64(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_float_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_float_result result;
        result.return_value = __intf->get_float(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_string_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_string_result result;
        result.return_value = __intf->get_string(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_binary_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_binary_result result;
        result.return_value = __intf->get_binary(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_color(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_color_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_color_result result;
        result.return_value = __intf->get_color(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_color", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_sequence_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_sequence_result result;
        result.return_value = __intf->get_sequence(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_string_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_string_set_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_string_set_result result;
        result.return_value = __intf->get_string_set(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_string_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_int_str_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_int_str_map_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_int_str_map_result result;
        result.return_value = __intf->get_int_str_map(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_int_str_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_bool_set_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_bool_set_sequence_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_bool_set_sequence_result result;
        result.return_value = __intf->get_bool_set_sequence(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_bool_set_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_person_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_person_result result;
        result.return_value = __intf->get_person(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_persons_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_persons_result result;
        result.return_value = __intf->get_persons(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons2(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_persons2_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_persons2_result result;
        result.return_value = __intf->get_persons2(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons2", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons3(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_persons3_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_persons3_result result;
        result.return_value = __intf->get_persons3(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons3", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_get_persons4(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_get_persons4_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_get_persons4_result result;
        result.return_value = __intf->get_persons4(map);
        ret = proto->writeMessageBegin("global.math.Math", "get_persons4", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_bool(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_bool_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_bool_result result;
        __intf->send_bool(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_bool", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int8_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int8_result result;
        __intf->send_int8(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int16_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int16_result result;
        __intf->send_int16(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int32_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int32_result result;
        __intf->send_int32(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int64_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int64_result result;
        __intf->send_int64(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_float_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_float_result result;
        __intf->send_float(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_string_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_string_result result;
        __intf->send_string(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_binary_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_binary_result result;
        __intf->send_binary(args.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_color(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_color_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_color_result result;
        __intf->send_color(args.color, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_color", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_person_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_person_result result;
        __intf->send_person(args.person, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32_sequence(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int32_sequence_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int32_sequence_result result;
        __intf->send_int32_sequence(args.numbers, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32_sequence", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_persons_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_persons_result result;
        __intf->send_persons(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons2(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_persons2_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_persons2_result result;
        __intf->send_persons2(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons2", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_int32_set_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_int32_set_seq_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_int32_set_seq_result result;
        __intf->send_int32_set_seq(args.xx, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_int32_set_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_persons3(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_persons3_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_persons3_result result;
        __intf->send_persons3(args.persons, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_persons3", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_send_person_vec_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_send_person_vec_set_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_send_person_vec_set_result result;
        __intf->send_person_vec_set(args.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "send_person_vec_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_boolean_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_boolean_result result;
        __intf->out_boolean(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int8_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int8_result result;
        __intf->out_int8(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int16_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int16_result result;
        __intf->out_int16(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int32_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int32_result result;
        __intf->out_int32(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int64_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int64_result result;
        __intf->out_int64(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_float_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_float_result result;
        __intf->out_float(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_string_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_string_result result;
        __intf->out_string(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_binary_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_binary_result result;
        __intf->out_binary(result.value, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_person_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_person_result result;
        __intf->out_person(result.person, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_seq_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_seq_result result;
        __intf->out_seq(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_string_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_string_set_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_string_set_result result;
        __intf->out_string_set(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_string_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int16_float_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int16_float_map_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int16_float_map_result result;
        __intf->out_int16_float_map(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int16_float_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_out_int_vec_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_out_int_vec_set_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_out_int_vec_set_result result;
        __intf->out_int_vec_set(result.xxx, map);
        ret = proto->writeMessageBegin("global.math.Math", "out_int_vec_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_boolean(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_boolean_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_boolean_result result;
        __intf->all_boolean(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_boolean", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int8(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int8_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int8_result result;
        __intf->all_int8(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int8", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int16(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int16_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int16_result result;
        __intf->all_int16(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int16", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int32_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int32_result result;
        __intf->all_int32(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int64(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int64_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int64_result result;
        __intf->all_int64(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int64", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_float(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_float_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_float_result result;
        __intf->all_float(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_float", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_string(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_string_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_string_result result;
        __intf->all_string(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_string", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_binary(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_binary_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_binary_result result;
        __intf->all_binary(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_binary", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int32_seq_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int32_seq_result result;
        __intf->all_int32_seq(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_person(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_person_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_person_result result;
        __intf->all_person(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_person", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_set(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int32_set_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int32_set_result result;
        __intf->all_int32_set(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_set", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_person_seq(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_person_seq_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_person_seq_result result;
        __intf->all_person_seq(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_person_seq", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_all_int32_person_map(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_all_int32_person_map_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_all_int32_person_map_result result;
        __intf->all_int32_person_map(args.value, map);
        result.value = args.value;
        ret = proto->writeMessageBegin("global.math.Math", "all_int32_person_map", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_color_out_all(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_color_out_all_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_color_out_all_result result;
        __intf->color_out_all(args.color1, result.color2, map);
        result.color1 = args.color1;
        ret = proto->writeMessageBegin("global.math.Math", "color_out_all", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

    int32_t MathProcessor::do_color_xx(char* request, int32_t request_len, bgcc::SharedPointer<bgcc::IProtocol> proto, int32_t seqid) {
        int32_t ret = 0;
        std::map<std::string, std::string> map;

        int32_t proxy_name_len = INT32(request);
        std::string proxy_name(OFFSET_PTR(request, LENGTH_SIZE), proxy_name_len);
        request+=(LENGTH_SIZE+proxy_name_len);
        request_len-=(proxy_name_len+LENGTH_SIZE);
        typedef bgcc::SharedPointer<bgcc::ITransport> ITransSharedPointer;

        ITransSharedPointer ITransptr= proto->getTransport();
        bgcc::ServerPeerSocket* pServer = dynamic_cast<bgcc::ServerPeerSocket*>(ITransptr.get());
        if (pServer) {
            typedef bgcc::SharedPointer<bgcc::PeerInfo> PeerInfoSharedPointer;
            PeerInfoSharedPointer peerptr = pServer->GetPeerInfo();
            map[PEER_IP] =  peerptr->GetHost();
            std::string strPort;
            std::stringstream stream;
            stream<<peerptr->GetPort();
            stream>>strPort;
            map[PEER_PORT]= strPort;
        }
        map[PROXY_NAME] = proxy_name;

        Math_color_xx_args args;
        ret = args.read(request, request_len, proto);
        if (ret < 0) { return ret;}

        request += ret;
        request_len -= ret;

        ret = proto->readMessageEnd();
        if (ret < 0) { return ret; }

        Math_color_xx_result result;
        result.return_value = __intf->color_xx(args.color1, result.color2, args.color3, map);
        result.color3 = args.color3;
        ret = proto->writeMessageBegin("global.math.Math", "color_xx", ::bgcc::REPLY, seqid);
        if (ret < 0) { return ret;}
        ret = result.write(proto);
        if (ret < 0) { return ret; }

        ret = proto->writeMessageEnd();
        return ret;
    }

}


