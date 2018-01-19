//
//  main.cpp
//  C++STL
//
//  Created by DreamSky on 2017/6/27.
//  Copyright © 2017年 DreamSky. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "ClassTest.h"
#include "VectorTest.h"
#include "DesignPatternTest.h"
#include "TimeTest.h"
#include "TestBase.hpp"

long long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main(int argc, const char * argv[]) {
    //输入参数
    vector<string> m_vecArg;
    for(int i=0;i<argc;i++)
    {
        //cout<<"输入参数 "<<i<<": "<<argv[i]<<endl;
        m_vecArg.push_back(argv[i]);
    }
    VectorTest* vectortest = VectorTest::create();
    vectortest->release();
    
    ClassTest* classtest = ClassTest::create();
    classtest->release();
    
    DesignPatternTest* designPatterntest = DesignPatternTest::create();
    designPatterntest->release();
    
    TimeTest* timetest = TimeTest::create();
    timetest->release();
    
    long long turn_count = 10000000;
    
    long long now_time1 = getCurrentTime();
    string str = "1001";
    string str1 = "1001";
    for(long long i=0;i<turn_count;i++){
        if(str == str1){
            continue;
        }else{
            continue;
        }
    }
    
    long long now_time2 = getCurrentTime();
    cout<<"俩个string比较花费的时间为:"<<now_time2-now_time1<<endl;
    
    
    long long now_time3 = getCurrentTime();
    for(long long i=0;i<turn_count;i++){
        if(str == "1001"){
            continue;
        }else{
            continue;
        }
    }
    
    long long now_time4 = getCurrentTime();
    cout<<"string比较常量字符串花费的时间为:"<<now_time4-now_time3<<endl;
    
    long long now_time5 = getCurrentTime();
    int temp1 = 1001;
    int temp2 = 1001;
    for(long long i=0;i<turn_count;i++){
        if(temp1 == temp2){
            continue;
        }else{
            continue;
        }
    }
    
    long long now_time6 = getCurrentTime();
    cout<<"俩个int比较花费的时间为:"<<now_time6-now_time5<<endl;
    
    long long now_time7 = getCurrentTime();
    for(long long i=0;i<turn_count;i++){
        if(temp1 == 1001){
            continue;
        }else{
            continue;
        }
    }
    
    long long now_time8 = getCurrentTime();
    cout<<"int比较常量花费的时间为:"<<now_time8-now_time7<<endl;
    // insert code here...
//    std::cout << "Hello, World!\n";
    return 0;
}
