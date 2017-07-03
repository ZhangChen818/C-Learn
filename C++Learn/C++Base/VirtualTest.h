//
//  VirtualTest.h
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#ifndef VirtualTest_h
#define VirtualTest_h

#include <stdio.h>
#include "TestBase.hpp"
/*
 虚函数，虚拟继承
 */

/*
 当一个类是基类时，其析构函数必须为虚函数，为了避免基类指针操作子类后，释放时只调用基类的析构而没有调用子类的析构，
 造成释放不完全的错误。而子类释放时会自动调用父类的析构函数。
 
 */

class ClxBase
{
public:
    ClxBase(){};
    virtual ~ClxBase(){cout<<"ClxBase::~ClxBase"<<endl;};
public:
    virtual void getString(){cout<<"ClxBase::getString"<<endl;};
};

class ClxChild  :   public ClxBase
{
public:
    ClxChild(){};
    ~ClxChild(){cout<<"ClxChild::~ClxChild"<<endl;};
public:
    void getString(){cout<<"ClxChild::getString"<<endl;};
};

class VirtualTest
{
public:
    VirtualTest();
    ~VirtualTest();
    bool init();
    static VirtualTest* create();
    void release();
public:
};

#endif /* VirtualTest_h */
