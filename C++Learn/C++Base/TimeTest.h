//
//  TimeTest.hpp
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//
/*
 测试时间
 */

#ifndef TimeTest_hpp
#define TimeTest_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

class TimeTest
{
public:
    static TimeTest* create();
    void release();
private:
    TimeTest();
    ~TimeTest();
    bool init();
public:
    void coutTM(const struct tm* _tm);
};
#endif /* TimeTest_hpp */
