//
//  ClassTest.h
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#ifndef ClassTest_h
#define ClassTest_h

#include <stdio.h>
#include "TestBase.hpp"
/*
 类大小，涉及 内存对齐原则 虚函数内存机制 虚拟继承内存机制
 */

/*
 C++内存对齐原则，基本类型(内置类型char,int等)
 1.第一个数据成员放在offset为0的地方，以后每个数据成员存储的起始位置要从该成员大小或者成员的子成员大小(数组，结构体等)的整数倍开始
 2.结构体作为成员:结构体成员要从其内部“最宽基本类型成员”的整数倍地址开始存储
 3.收尾工作:结构体等的总大小，必须是其内部最大成员的“最宽基本类型成员”的整数倍。不足要补齐
 4.在类中虚函数表指针和虚拟继承指针也参与对齐
*/

/*
 虚函数内存机制
 当类中存在虚函数时，会自动生成虚函数表，而类中存放虚函数表指针。
 在子类只有一个基类时,会和基类共用一个虚函数表
 在子类中有多个基类时,会和第一个基类共用虚函数表，而单独记录其他基类的指针
 */

/*
 虚拟继承内存机制
 不管多少个虚拟继承都保留一个虚函数继承指针。当有虚函数时，共用存储。
 */

/*
 类的大小 = 变量的大小 + 虚函数表指针大小*(继承基类(包含虚函数的基类)个数)+虚拟继承指针大小
 
 */

class A{
public:
    A(){int a;a = 0;};
    ~A(){cout<<"A::~A"<<endl;};
public:
    void getDesc(){cout<<"A::getDesc"<<endl;};
};

class A1{
public:
    A1(){int a;a = 0;};
    ~A1(){cout<<"A1::~A1"<<endl;};
public:
    void getDesc(){cout<<"A1::getDesc"<<endl;};
};

class B{
public:
    B(){int a;a = 0;};
    ~B(){cout<<"B::~B"<<endl;};
public:
    virtual void getDesc(){cout<<"B::getDesc"<<endl;};
public:
//    char b;
};

class C
//:public A
//,public A1
//,public B
:public B
{
public:
    C(){int a;a = 0;};
    ~C(){cout<<"C::~C"<<endl;};
public:
    void getDesc(){cout<<"C::getDesc"<<endl;};
    virtual void getDesc1(){};
public:
//    char c;
};

class D
: public virtual B
//,public virtual A
//,public virtual A1
{
public:
    D(){};
    ~D(){cout<<"D::~D"<<endl;};
public:
    void getDesc(){cout<<"D::getDesc"<<endl;};
public:
//    char d;
};

class E :   public C,public D
{
public:
    E(){};
    ~E(){cout<<"E::~E"<<endl;};
public:
    void getDesc(){cout<<"E::getDesc"<<endl;};
public:
    int e;
};


class ClassTest
{
public:
    ClassTest();
    ~ClassTest();
    bool init();
    static ClassTest* create();
    void release();
public:
};



#endif /* ClassTest_h */
