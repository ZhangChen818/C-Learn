//
//  StateDesign.h
//  C++Learn
//
//  Created by DreamSky on 2017/7/3.
//  Copyright © 2017年 ZhangChen. All rights reserved.
//

#ifndef StateDesign_h
#define StateDesign_h

/*
 状态机
 */

#include <stdio.h>
#include "TestBase.hpp"

class SiegeTank;
class ISiegeTankState
{
public:
    virtual void move(int x,int y)=0;
    virtual void attack()=0;
};

class SiegeState   :    public ISiegeTankState
{
public:
    SiegeState(SiegeTank* pTank):m_pTank(pTank){};
    
    virtual void move(int x,int y)
    {
        cout<<"Can't move in siege mode."<<endl;
    };
    
    virtual void attack(){
        cout<<"Attacking for 40"<<endl;
    };
private:
    SiegeTank* m_pTank;
};

class TankState :  public ISiegeTankState
{
public:
    TankState(SiegeTank* pTank):m_pTank(pTank){};
    
public:
    virtual void move(int x,int y){
        cout<<"Move to ("<<x<<", "<<y<<")"<<endl;
    };
    
    virtual void attack(){
        cout<<"Attacking for 20"<<endl;
    }
private:
    SiegeTank* m_pTank;
};

class SiegeTank
{
public:
    SiegeTank(){
        m_pTankState = new TankState(this);
        m_pSiegeState = new SiegeState(this);
        m_pSiegeTankState = m_pTankState;
    }
    
    void enterTankMode(){
        m_pSiegeTankState =m_pTankState;
        cout<<"Switch to tank mode"<<endl;
    }
    void enterSiegeMode(){
        m_pSiegeTankState = m_pSiegeState;
        cout<<"Switch to siege mode"<<endl;
    }
    
    void attack(){
        m_pSiegeTankState->attack();
    }
    
    void move(int x,int y){
        m_pSiegeTankState->move(x,y);
    }
private:
    void setState(ISiegeTankState* pSiegeTankMode){
        m_pSiegeTankState = pSiegeTankMode;
    }
    
    
private:
    TankState* m_pTankState;
    SiegeState* m_pSiegeState;
    ISiegeTankState* m_pSiegeTankState;
};

class StateDesignTest
{
public:
    StateDesignTest();
    ~StateDesignTest();
    bool init();
    static StateDesignTest* create();
    void release();
public:
};

#endif /* StateDesign_h */
