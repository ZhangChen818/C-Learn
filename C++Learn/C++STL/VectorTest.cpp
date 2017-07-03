//
//  VectorTest.cpp
//  C++STL
//
//  Created by DreamSky on 2017/6/28.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include "VectorTest.h"

VectorTest* VectorTest::create()
{
    VectorTest* test = new (std::nothrow)VectorTest();
    if(test && test->init()){
        return test;
    }
    delete test;
    test = nullptr;
    return test;
}

VectorTest::VectorTest()
{
    
}

VectorTest::~VectorTest()
{
    
}


bool VectorTest::init()
{
    
    return true;
}


void VectorTest::release()
{
    delete this;
}
