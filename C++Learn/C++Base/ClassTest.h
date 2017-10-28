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
 类大小，涉及 内存对齐原则 虚函数内存机制 虚拟继承内存机制 基类要求
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
 子类有几个父类就存放几个虚函数表指针。这是为了保证各个基类的虚函数表相对位置不会改变。
 子类的虚函数会被放在第一个父类的虚函数表后边。
 
 C++多态的实现机制：
        在基类和子类中都存在虚函数表，存放所有的基类虚函数，但子类的虚函数表中相应偏移位置的虚函数为自身覆盖的虚函数
    指针。当使用基类指针操作子类时读取的是子类的虚函数表。所以可以操作子类的方法。
 例如 基类A中有10个虚函数，分别是a1..a10 其虚函数表为 A::a1,A::a2,A::a3,A::a4,A::a5,A::a6,A::a7,A::a8,A::a9,A::a10 子类B继承A类，其中重写了a1,a5,a9.子类B的虚函数表为 B::a1,A::a2,A::a3,A::a4,B::a5,A::a6,A::a7,A::a8,B::a9,A::a10
    当使用 A* a = new A();a->a1();时,a中虚函数表指针指向A类的虚函数表。就会调用A::a1()。
    当使用 A* a = new B();a->a1();时,a中虚函数表指针指向B类的虚函数表。就会调用B::a1()。
 

 */

/*
 虚拟继承内存机制
 不管多少个虚拟继承都保留一个虚函数继承指针。当有虚函数时，共用存储。
 */

/*
 类的大小 = 变量的大小 + 虚函数表指针大小*(继承基类(包含虚函数的基类)个数)+虚拟继承指针大小
 
 */

/*
 当一个类是基类时，其析构函数必须为虚函数，为了避免基类指针操作子类后，释放时只调用基类的析构而没有调用子类的析构，
 造成释放不完全的错误。而子类释放时会自动调用父类的析构函数。
 
 */

/*
 当一个子类中存在和基类中同名同参同返回值的函数方法且基类没有声明这个函数为虚函数时，使用基类指针指向子类，调用该
 方法调用的是基类的。
 */

class A{
public:
    A(){int a;a = 0;};
    virtual ~A(){cout<<"A::~A"<<endl;};
public:
    virtual void getDesc(){cout<<"A::getDesc"<<endl;};
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
    virtual ~B(){cout<<"B::~B"<<endl;};
public:
    void getDesc(){cout<<"B::getDesc"<<endl;};
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
    virtual void getDesc(){cout<<"C::getDesc"<<endl;};
public:
//    char c;
};

class D
: public virtual A
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
