//
//  main.cpp
//  C++STL
//
//  Created by DreamSky on 2017/6/27.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include <iostream>
#include "VirtualTest.h"
#include "ClassTest.h"
#include "VectorTest.h"

int main(int argc, const char * argv[]) {
    
    VectorTest* vectortest = VectorTest::create();
    vectortest->release();
    
    VirtualTest* virtualtest = VirtualTest::create();
    virtualtest->release();
    
    ClassTest* classtest = ClassTest::create();
    classtest->release();
    
    // insert code here...
//    std::cout << "Hello, World!\n";
    return 0;
}
