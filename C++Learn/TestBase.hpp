//
//  TestBase.hpp
//  C++STL
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

// 共同支持的头文件和类，模板等。
/*
 .hpp和.h的不同之处是人为规定的(不一定必须如此(编译器不区分后缀)，但默认规矩)。
 .h文件中只包含声明，不包含定义
 .hpp文件中即包含声明和包含定义。不用再多一个.cpp文件，编译时也不用多生成一个.obj文件，.hpp直接被编译到包含其的.obj中。节省开支。 一般使用于模板这种声明和定义必须在一起的结构中。。
 */

#ifndef TestBase_hpp
#define TestBase_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
#endif /* TestBase_hpp */
