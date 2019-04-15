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

#include "time_util.h"
#include "string_util.h"

namespace bgcc {

    static struct tm* localtime_r(const time_t* timep, struct tm* result = NULL) {
#ifdef _WIN32
        (void)result;
        return localtime(timep);
#else
        return ::localtime_r(timep, result);
#endif
    }

#ifdef _WIN32
    //gettimeofday 引用自http://suacommunity.com/dictionary/gettimeofday-entry.php
    FILETIME TimeUtil::_ft = {0};
	LARGE_INTEGER TimeUtil::_pform = {0};
#endif
	  
    int32_t TimeUtil::gettimeofday(struct ::timeval *tv, struct timezone *tz)
    {
#ifndef _WIN32
        return ::gettimeofday(tv,tz);
#else
        FILETIME ft;

        unsigned __int64 tmpres = 0;
        unsigned __int64 tmpres2 = 0;
        static int tzflag = 0;
        LARGE_INTEGER pform={0};
        QueryPerformanceCounter(&pform);

        if (NULL != tv)
        {
            GetSystemTimeAsFileTime(&ft);
            if(ft.dwLowDateTime == _ft.dwLowDateTime && ft.dwHighDateTime == _ft.dwHighDateTime)
            {
                //时间相等时，计算时间偏移
                LARGE_INTEGER pfreq = {0};
                QueryPerformanceFrequency(&pfreq);
                tmpres2 = ((pform.QuadPart - _pform.QuadPart) * 1000000UL)/pfreq.QuadPart;
            }
            else
            {
                //时间不等时，更新标准时间
                TimeUtil::_ft = ft;
                QueryPerformanceCounter(&_pform);
            }

            tmpres |= ft.dwHighDateTime;
            tmpres <<= 32;
            tmpres |= ft.dwLowDateTime;

            tmpres /= 10;
            tmpres -= DELTA_EPOCH_IN_MICROSECS;
			tmpres += tmpres2;	//增加修正偏移


            tv->tv_sec = (long)(tmpres / 1000000UL);
            tv->tv_usec = (long)(tmpres % 1000000UL);
        }

        if (NULL != tz)
        {
            if (!tzflag)
            {
                _tzset();
                tzflag++;
            }

            tz->tz_minuteswest = _timezone / 60;
            tz->tz_dsttime = _daylight;
        }

        return 0;
#endif
    }

    uint64_t TimeUtil::get_timestamp_s() {
        struct ::timeval tv = {0, 0};
		gettimeofday(&tv, NULL);
        return tv.tv_sec;
    }

    uint64_t TimeUtil::get_timestamp_ms() {
        struct ::timeval tv = {0, 0};
        gettimeofday(&tv, NULL);
        return (uint64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
    }

    uint64_t TimeUtil::get_timestamp_us() {
        struct ::timeval tv = {0, 0};
        gettimeofday(&tv, NULL);
        return (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
    }

    void TimeUtil::safe_sleep_s(uint32_t second) {
#ifdef _WIN32
        return TimeUtil::safe_sleep_ms(second * 1000);
#else
        struct timespec interval, remainder;
        int32_t ret;

        interval.tv_sec = second;
        interval.tv_nsec = 0;

        ret = nanosleep(&interval, &remainder);
        if (-1 == ret) {
            while (EINTR == errno && -1 == ret) {
                ret = nanosleep(&remainder, &remainder);
            }
        }
#endif
    }

    void TimeUtil::safe_sleep_ms(uint32_t millisecond) {
#ifdef _WIN32
        ::Sleep(millisecond);
#else
        struct timespec interval, remainder;
        int32_t ret;

        interval.tv_sec = millisecond / 1000U;
        interval.tv_nsec = (uint64_t)millisecond % 1000UL * 1000UL * 1000UL;

        ret = nanosleep(&interval, &remainder);
        if (-1 == ret) {
            while (EINTR == errno && -1 == ret) {
                ret = nanosleep(&remainder, &remainder);
            }
        }
#endif
    }

    std::string TimeUtil::format_datetime_str(uint64_t millisecond) {
        time_t time = (time_t)(millisecond / 1000);
        struct tm t;
        struct tm *pt = NULL;
        char buffer[24] = {0};

        pt = bgcc::localtime_r(&time, &t);
        if(NULL != pt)
        {
            t = *pt;
            snprintf(buffer, 24, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, (int32_t)(millisecond % 1000));
        }
        return std::string(buffer);
    }

#ifndef _WIN32
    int32_t TimeUtil::get_abs_timespec(struct timespec* ts, int32_t millisecond) {
        struct timeval tv;
        int32_t ret;

        if (NULL == ts) {
            return EINVAL;
        }

        ret = gettimeofday(&tv, NULL);
        if (0 != ret) {
            return ret;
        }

        ts->tv_sec = tv.tv_sec;
        ts->tv_nsec = tv.tv_usec * 1000UL;

        ts->tv_sec += millisecond / 1000UL;
        ts->tv_nsec += millisecond % 1000UL * 1000000UL;

        ts->tv_sec += ts->tv_nsec/(1000UL * 1000UL *1000UL);
        ts->tv_nsec %= (1000UL * 1000UL *1000UL);

        return 0;
    }
#endif

    int32_t TimeUtil::strftimeval(char* buffer, int32_t buflen, const struct timeval* tv) {
        if (NULL == buffer || NULL == tv) {
            return -1;
        }

        time_t time = tv->tv_sec;
        struct tm t;
        struct tm *pt = NULL;

        pt = bgcc::localtime_r(&time, &t);
        if(NULL == pt)
        {
            return -1;
        }
        t = *pt;
        return snprintf(buffer, buflen, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
                t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, (int32_t)tv->tv_usec / 1000);   
    }

    std::string TimeUtil::get_date() {
        time_t t = time(NULL);
        struct tm result;
        struct tm *presult = NULL;
        char buffer[20] = {0};
        presult = bgcc::localtime_r(&t, &result);
        if(NULL != presult)
        {
            result = *presult;
            strftime(buffer, 20, "%Y%m%d", &result);
        }

        return std::string(buffer);
    }

    std::string TimeUtil::get_time() {
        time_t t = time(NULL);
        struct tm result;
        struct tm *presult = NULL;
        char buffer[20] = {0};
        presult = bgcc::localtime_r(&t, &result);
        if(NULL != presult)
        {
            result = *presult;
            strftime(buffer, 20, "%H%M%S", &result);
        }

        return std::string(buffer);
    }
    
    int32_t TimeUtil::get_day()
    {
        time_t t = time(NULL);
        struct tm result;
        struct tm *presult = NULL;
        presult = bgcc::localtime_r(&t, &result);
        if(NULL == presult)
        {
            return -1;
        }
        result = *presult;
        return result.tm_wday;
    }

    int32_t TimeUtil::get_day( time_t time )
    {
        struct tm result;
        struct tm *presult = NULL;
        presult = bgcc::localtime_r(&time, &result);
        if(NULL == presult)
        {
            return -1;
        }
        result = *presult;
        return result.tm_wday;
    }

    std::string TimeUtil::format_time(const char * fmt)
    {
        //获取时间
        struct ::timeval tv = {0, 0};
        gettimeofday(&tv, NULL);
        
        return format_time(&tv, fmt);
    }
    
    std::string TimeUtil::format_time(time_t time, const char * fmt)
    {
        struct ::timeval tv = {0, 0};
        tv.tv_sec = static_cast <long>(time);

        return format_time(&tv, fmt);
    }

    std::string TimeUtil::format_time(const struct timeval* tv, const char * fmt)
    {
        struct tm result;
        struct tm  *presult = NULL;
        time_t t = tv->tv_sec;
        char buffer[50] = {0};
        char tmp[8];
        if(NULL == fmt)
        {
            //格式化当前时间
            presult = bgcc::localtime_r(&t, &result);
            if(NULL != presult)
            {
                result = *presult;
                strftime(buffer, sizeof(buffer), "%Y%m%d-%H:%M:%S", &result);
            }
        }
        else
        {
            std::string str_fmt(fmt);
            std::string str_tmp;
            if(std::string::npos != str_fmt.find("[m]"))
            {
                //替换毫秒时间
                snprintf(tmp,8,"%03d", (int)(tv->tv_usec / 1000) );
                str_tmp.assign(tmp);
                str_fmt = StringUtil::replace_string(str_fmt, "[m]", str_tmp);
            }
            if(std::string::npos != str_fmt.find("[u]"))
            {
                //替换微秒时间
                snprintf(tmp,8,"%06d", (int)(tv->tv_usec) );
                str_tmp.assign(tmp);
                str_fmt = StringUtil::replace_string(str_fmt, "[u]", str_tmp);
            }
            if(std::string::npos != str_fmt.find("[U]"))
            {
                //替换微秒时间
                snprintf(tmp,8,"%03d", (int)(tv->tv_usec % 1000) );
                str_tmp.assign(tmp);
                str_fmt = StringUtil::replace_string(str_fmt, "[U]", str_tmp);
            }
            presult = bgcc::localtime_r(&t, &result);
            if(NULL != presult)
            {
                result = *presult;
                strftime(buffer, sizeof(buffer), str_fmt.c_str(), &result);
            }
        }
        return std::string(buffer);
    }
}

