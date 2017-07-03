//
//  StateDesign.cpp
//  C++Learn
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 ZhangChen. All rights reserved.
//

#include "StateDesign.h"

StateDesignTest* StateDesignTest::create()
{
    StateDesignTest* test = new (std::nothrow)StateDesignTest();
    if(test && test->init()){
        return test;
    }
    delete test;
    test = nullptr;
    return test;
}

StateDesignTest::StateDesignTest()
{
    
}

StateDesignTest::~StateDesignTest()
{
    
}

bool StateDesignTest::init()
{
    cout<<"=================StateDesignTest::Start===================="<<endl;
    SiegeTank tank;
    tank.enterTankMode();
    tank.attack();
    tank.move(1, 1);
    
    tank.enterSiegeMode();
    tank.attack();
    tank.move(2, 2);
    
    tank.enterTankMode();
    tank.attack();
    tank.move(3, 3);
    cout<<"=================StateDesignTest::End===================="<<endl<<endl;
    return true;
}

void StateDesignTest::release()
{
    delete this;
}
