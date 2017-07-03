//
//  DesignPatternTest.cpp
//  C++Learn
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 ZhangChen. All rights reserved.
//

#include "DesignPatternTest.h"
#include "TestBase.hpp"
#include "StateDesign.h"

DesignPatternTest* DesignPatternTest::create()
{
    DesignPatternTest* test = new (std::nothrow)DesignPatternTest();
    if(test && test->init()){
        return test;
    }
    delete test;
    test = nullptr;
    return test;
}

DesignPatternTest::DesignPatternTest()
{
    
}

DesignPatternTest::~DesignPatternTest()
{
    
}

bool DesignPatternTest::init()
{
    StateDesignTest* stateDesigntest = StateDesignTest::create();
    stateDesigntest->release();

    return true;
}

void DesignPatternTest::release()
{
    delete this;
}
