//
//  TimeTest.hpp
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include "TimeTest.h"

TimeTest* TimeTest::create()
{
    TimeTest* test = new (std::nothrow)TimeTest();
    if(test && test->init()){
        return test;
    }
    
    test->release();
    test = nullptr;
    return test;
}

void TimeTest::release()
{
    
}


TimeTest::TimeTest()
{
    
}

TimeTest::~TimeTest()
{
    
}

bool TimeTest::init()
{
    cout<<"=================TimeTest::Start===================="<<endl;
    //获取处理器时钟所使用的时间，如果不可用，返回1
    clock_t oldClock = clock();
    
    /* 获取从1970年1月1日0点到现在的秒数 */
    const time_t time_tNT = time(NULL);
    cout<<"time_t当前时间:"<<time_tNT<<endl;
    
    /*
     struct tm {
     int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
     int tm_min;   // 分，范围从 0 到 59
     int tm_hour;  // 小时，范围从 0 到 23
     int tm_mday;  // 一月中的第几天，范围从 1 到 31
     int tm_mon;   // 月，范围从 0 到 11
     int tm_year;  // 自 1900 年起的年数
     int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
     int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
     int tm_isdst; // 夏令时(因夏日阳光充足，为了充分利用阳光，节约资源而人为的调整时间)
     }
     真实的年数需要加上1900,月数加上1 一年中的第几天加上1
     */
    /*返回指向表示本地时间的tm结构的指针*/
    struct tm* tmNT = localtime(&time_tNT);
    /* 返回指向一个 用协调世界时(UTC)也被称为格林尼治标准时间(GMT)表示的tm结构的指针 */
    struct tm* tmNT2 = gmtime(&time_tNT);
    
    cout<<"本地时间:";
    coutTM(tmNT);
    cout<<"UTC时间:";
    coutTM(tmNT2);
    //获取本地时间和UTC时间的差
    time_t time_tNT2 = mktime(tmNT);
    time_t time_tNT3 = mktime(tmNT2);
    double time_tDif = difftime(time_tNT2,time_tNT3);
    cout<<"本地时间和UTC时间差:"<< time_tNT2<<"  "<<time_tNT3<<"  dif="<<time_tDif<<endl;
    
    /* 字符串形式 day month year hours:minutes:seconds year\n\0 */
    /* MAC下实际字符串形式 wday month day hours:minutes:seconds year\n\0 */
    char* ctimeNT = ctime(&time_tNT);
    cout<<"ctime当前时间:"<<ctimeNT;
    
    /* 字符串形式 day month date hours:minutes:seconds year\n\0 */
    /* MAC下实际字符串形式 wday month day hours:minutes:seconds year\n\0 */
    char* asctimeNT = asctime(tmNT);
    cout<<"asctime当前时间:"<<asctimeNT;
    
    //程序运行时间差
    cout<<oldClock<<"   "<<clock()<<"     "<<clock()-oldClock<<endl;
    
    
    cout<<"=================TimeTest::End===================="<<endl;
    return true;
}
//time时间
void TimeTest::coutTM(const struct tm* _tm)
{
    cout<<"输出tm结构体:{"<<"tm_sec="<<_tm->tm_sec<<",tm_min="<<_tm->tm_min<<",tm_hour="<<_tm->tm_hour<<
    ",tm_mday="<<_tm->tm_mday<<",tm_mon="<<_tm->tm_mon<<",tm_year="<<_tm->tm_year<<",tm_wday="<<_tm->tm_wday
    <<",tm_yday="<<_tm->tm_yday<<",tm_isdst="<<_tm->tm_isdst<<"}"<<endl;
}

