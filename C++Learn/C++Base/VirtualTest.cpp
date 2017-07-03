//
//  VirtualTest.cpp
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include "VirtualTest.h"


VirtualTest* VirtualTest::create()
{
    VirtualTest* test = new (std::nothrow)VirtualTest();
    if(test && test->init()){
        return test;
    }
    delete test;
    test = nullptr;
    return test;
}

VirtualTest::VirtualTest()
{
    
}

VirtualTest::~VirtualTest()
{
    
}


bool VirtualTest::init()
{
    ClxBase* base = new ClxChild();
    base->getString();
    delete base;
    
    return true;
}


void VirtualTest::release()
{
    delete this;
}
