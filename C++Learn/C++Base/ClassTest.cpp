//
//  ClassTest.cpp
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include "ClassTest.h"


ClassTest* ClassTest::create()
{
    ClassTest* test = new (std::nothrow)ClassTest();
    if(test && test->init()){
        return test;
    }
    delete test;
    test = nullptr;
    return test;
}
ClassTest::ClassTest()
{
    
}

ClassTest::~ClassTest()
{
    
}

bool ClassTest::init()
{
    cout<<"sizeof(char) = " <<sizeof(char)<<endl;
    cout<<"sizeof(bool) = " <<sizeof(bool)<<endl;
    cout<<"sizeof(int) = " <<sizeof(int)<<endl;
    cout<<"sizeof(long) = " <<sizeof(long)<<endl;
    cout<<"sizeof(long long) = " <<sizeof(long long)<<endl;
    cout<<"sizeof(float) = " <<sizeof(float)<<endl;
    cout<<"sizeof(double) = " <<sizeof(double)<<endl;
    cout<<"sizeof(int*) = " <<sizeof(int*)<<endl;
    cout<<"========================================================="<<endl;
    cout<<"sizeof(A) = "<<sizeof(A)<<endl; //1
    cout<<"sizeof(B) = "<<sizeof(B)<<endl; //4
    cout<<"sizeof(C) = "<<sizeof(C)<<endl; //5
    cout<<"sizeof(D) = "<<sizeof(D)<<endl; //8
    cout<<"sizeof(E) = "<<sizeof(E)<<endl; //13+4
    
    
    return true;
}

void ClassTest::release()
{
    delete this;
}
