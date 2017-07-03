//
//  VectorTest.h
//  C++STL
//
//  Created by DreamSky on 2017/6/28.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#ifndef VectorTest_h
#define VectorTest_h

#include <stdio.h>
#include <iostream>

using namespace std;

/*
 最大的疑惑。释放vector时，其中存的指针内存会释放不。
 */

class VectorTest
{
public:
    VectorTest();
    ~VectorTest();
    bool init();
    static VectorTest* create();
    void release();
public:
};

#endif /* VectorTest_hpp */
