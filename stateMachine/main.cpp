//��������״̬����
//һ������ж���״̬����ͬ��״̬�в�ͬ����Ϊ��״̬֮������л����ı���Ϊ������˵ ��һ��������Ϊȡ��������״̬������������������ʱ�̸���״̬�ı�������Ϊʱ���Ϳ��Կ���ʹ��״̬ģʽ�ˡ�

#include <iostream>
#include <stdio.h>
#include <list>
#include <QList>
#include <QDebug>
using namespace std;


//��������״̬�� ���͹أ�����ʱ���ܽ������ܴ򿪣�    �ص�ʱ�򣬲��ܽ����ܴ򿪡�
class Door;

class DoorState
{
public:
    DoorState(){}
    virtual ~DoorState(){}
    virtual bool open()=0;
    virtual bool in()=0;
};

class CloseState: public DoorState
{
public:
    // CloseState(Door* _door):m_door(_door){}
    CloseState(){}
    virtual bool open()
    {
        cout<<"--------can open-------\n";
        return true;
    }

    virtual bool in()
    {
        cout<<"--------can't in-------\n";
        return true;
    }

private:
    Door * m_door;
};

class OpenState: public DoorState
{

public:
    //OpenState(Door* _door):m_door(_door){}
    OpenState(){}
    virtual bool open()
    {
        cout<<"--------can't open-------\n";
        return true;
    }

    virtual bool in()
    {
        cout<<"--------can in-------\n";
        return true;
    }
private:
    Door * m_door;
};

class Door
{
public:
    Door():m_doorState(NULL){}
    ~Door(){}
    void addState(DoorState* _doorState)
    {
        m_stateList.push_back(_doorState);
    }

    void changeToIState(int i)
    {
        if(i<0 && i> m_stateList.size())
        {
            return;
        }
        m_doorState=m_stateList.at(i);
    }
    void showCurrentState()
    {
        if(NULL==m_doorState)
        {
            return;
        }

        m_doorState->in();
        m_doorState->open();
    }

private:
    DoorState* m_doorState;
    OpenState * m_openState;
    CloseState * m_closeState;

    QList<DoorState*> m_stateList;

};



int main()
{
    Door _door;
    DoorState * _openState=new OpenState;
    _door.addState(_openState);

    DoorState * _closeState=new CloseState;
    _door.addState(_closeState);

    _door.changeToIState(0);
    _door.showCurrentState();
    qDebug()<<"------------------------------\n";
    _door.changeToIState(1);
    _door.showCurrentState();


    delete _openState;
    _openState=NULL;
    delete _closeState;
    _closeState=NULL;
}



//LCL's stateMachine
/*
class SiegeTank;
class ISiegeTankState//����״̬����
{
public:
    virtual void move(int x, int y) = 0;
    virtual void attack() = 0;
};

class SiegeState : public ISiegeTankState //����״̬
{
public:
    SiegeState(SiegeTank* pTank): m_pTank(pTank){}
    virtual void move(int x, int y)
    {
        std::cout << "Can't move in siege mode." << std::endl;
    }
    virtual void attack()
    {
        std::cout << "Attacking for 40" << std::endl;
    }
private:
    SiegeTank* m_pTank;
};

class TankState : public ISiegeTankState //�߶�״̬
{
public:
    TankState(SiegeTank* pTank): m_pTank(pTank){}

    virtual void move(int x, int y)
    {
        std::cout << "Move to (" << x << ", " << y << ")" << std::endl;
    }
    virtual void attack()
    {
        std::cout << "Attacking for 20" << std::endl;
    }
private:
    SiegeTank* m_pTank;
};

class SiegeTank
{
public:
    SiegeTank()
    {
        m_pTankState = new TankState(this);
        m_pSiegeState = new SiegeState(this);
        m_pSiegeTankState = m_pTankState;
    }
    void enterTankMode()
    {
        m_pSiegeTankState = m_pTankState;
        std::cout << "Switch to tank mode" << std::endl;
    }
    void enterSiegeMode()
    {
        m_pSiegeTankState = m_pSiegeState;
        std::cout << "Switch to siege mode" << std::endl;
    }
public:
    void attack()
    {
        m_pSiegeTankState->attack();
    }
    void move(int x, int y)
    {
        m_pSiegeTankState->move(x, y);
    }
private:
    void setState(ISiegeTankState* pSiegeTankMode)
    {
        m_pSiegeTankState = pSiegeTankMode;
    }
private:
    TankState* m_pTankState;
    SiegeState* m_pSiegeState;
    ISiegeTankState* m_pSiegeTankState;
};

int main()
{
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

    return 0;
}

*/


