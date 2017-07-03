//
//  DesignPatternTest.h
//  C++Learn
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 ZhangChen. All rights reserved.
//

#ifndef DesignPatternTest_hpp
#define DesignPatternTest_hpp

#include <stdio.h>

class DesignPatternTest
{
public:
    DesignPatternTest();
    ~DesignPatternTest();
    bool init();
    static DesignPatternTest* create();
    void release();
public:
};

#endif /* DesignPatternTest_h */
