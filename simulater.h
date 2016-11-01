#ifndef SIMULATER_H_INCLUDED
#define SIMULATER_H_INCLUDED
#include "circularQueue.h"
#include "linklist.h"
#include "bankWindow.h"
#include <ctime>
#include <cstdlib>
class Simulater
{
private:
    int normalNum;
    int vipNum;
    int officialNum;
    int index;
    int a[50][4];
    int endTime;
    int intervalTime;
    int dealTime;
    bankWindow NormalBankWindow[3];
    bankWindow VIPBankWindow;
    bankWindow OfficialBankWindow;
    circularQueue<User> *NormalUserQueue;
    circularQueue<User> *VIPUserQueue;
    circularQueue<User> *OfficialUserQueue;
public:
    Simulater();
    void customerEnter();
    void simulatecustomerEnter();
    void simulateCallCustomer();
    void Simulate();
    void setEndTime(int n);
    void setIntervalTime(int n);
    void setDealTime(int n);
};
void Simulater::setDealTime(int n)
{
    dealTime=n;
}
void Simulater::setEndTime(int n)
{
    endTime=n;
}
void Simulater::setIntervalTime(int n)
{
    intervalTime=n;
}
Simulater::Simulater()
{
    normalNum=0;vipNum=0;officialNum=0;
    index=0;
   int i;
   NormalUserQueue=new circularQueue<User>;
   VIPUserQueue=new circularQueue<User>;
   OfficialUserQueue=new circularQueue<User>;
   for(i=0;i<3;i++)
   {
       NormalBankWindow[i].type='n';
   }
   VIPBankWindow.type='v';
   OfficialBankWindow.type='o';
}
void Simulater::customerEnter()
{
    cout<<"welcome to BBC system"<<endl;
    cout<<"***************************"<<endl;
    cout<<"时间"<<' '<<"普通用户"<<' '<<"VIP用户"<<' '<<"对公用户"<<endl;
    srand(time(0));
    int t=0;
    for(int i=0;i<10;i++)
    {
        a[i][0]=t;
        a[i][1]=rand()%4;
        a[i][2]=rand()%2;
        a[i][3]=rand()%2;
        t+=intervalTime;
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }

}
void Simulater::simulatecustomerEnter()
{
    if(a[index][1]!=0)
    {
        int temp=a[index][1];
        for(int i=0;i<temp;i++)
        {
            User nUser('n');
            nUser.id=normalNum+1;
            normalNum++;
            NormalUserQueue->enQueue(nUser);
        }
    }
    if(a[index][2]!=0)
    {
        int temp=a[index][2];
        for(int i=0;i<temp;i++)
        {
            User vUser('v');
            vUser.id=vipNum+1;
            vipNum++;
            VIPUserQueue->enQueue(vUser);
        }
    }
    if(a[index][3]!=0)
    {
        int temp=a[index][3];
        for(int i=0;i<temp;i++)
        {
            User oUser('o');
            oUser.id=officialNum+1;
            officialNum++;
            OfficialUserQueue->enQueue(oUser);
        }
    }
    index++;
}
void Simulater::simulateCallCustomer()
{
    User vipuTemp('v');
    User offuTemp('o');
    User normuTemp('n');
    if(!VIPUserQueue->isEmpty()&&!VIPBankWindow.isBusy)
    {
        VIPBankWindow.client=(VIPUserQueue->getFront());
        VIPUserQueue->deQueue(vipuTemp);
        VIPBankWindow.isBusy=true;
        //VIPBankWindow.HandleUser();
    }
    if(!OfficialUserQueue->isEmpty()&&!OfficialBankWindow.isBusy)
    {
        OfficialBankWindow.client=(OfficialUserQueue->getFront());
        OfficialUserQueue->deQueue(offuTemp);
        OfficialBankWindow.isBusy=true;
        //OfficialBankWindow.HandleUser();
    }
        if((!NormalUserQueue->isEmpty())&&!NormalBankWindow[0].isBusy)
        {
            NormalBankWindow[0].client=(NormalUserQueue->getFront());
            NormalUserQueue->deQueue(normuTemp);
            NormalBankWindow[0].isBusy=true;
            //NormalBankWindow[0].HandleUser();
        }

        if((!NormalUserQueue->isEmpty())&&!NormalBankWindow[1].isBusy)
            {
                NormalBankWindow[1].client=(NormalUserQueue->getFront());
                NormalUserQueue->deQueue(normuTemp);
                NormalBankWindow[1].isBusy=true;
                //NormalBankWindow[1].HandleUser();
            }
        if((!NormalUserQueue->isEmpty())&&!NormalBankWindow[2].isBusy)
        {
            NormalBankWindow[2].client=(NormalUserQueue->getFront());
            NormalUserQueue->deQueue(normuTemp);
            NormalBankWindow[2].isBusy=true;
            //NormalBankWindow[2].HandleUser();

        }
        if((!NormalUserQueue->isEmpty())&&!VIPBankWindow.isBusy&&VIPUserQueue->isEmpty()&&NormalBankWindow[0].isBusy&&NormalBankWindow[1].isBusy&&NormalBankWindow[2].isBusy)
        {
            VIPBankWindow.client=(NormalUserQueue->getFront());
            NormalUserQueue->deQueue(normuTemp);
            VIPBankWindow.isBusy=true;
            //VIPBankWindow.HandleUser();
        }
        if((!NormalUserQueue->isEmpty())&&!OfficialBankWindow.isBusy&&OfficialUserQueue->isEmpty()&&NormalBankWindow[0].isBusy&&NormalBankWindow[1].isBusy&&NormalBankWindow[2].isBusy)
        {
            OfficialBankWindow.client=(NormalUserQueue->getFront());
            NormalUserQueue->deQueue(normuTemp);
            VIPBankWindow.isBusy=true;
            //OfficialBankWindow.HandleUser();
        }
}
void Simulater::Simulate()
{
    int time=0;
    customerEnter();
    while(time<=endTime)
    {
        cout<<"time:"<<time<<endl;
        simulatecustomerEnter();
        simulateCallCustomer();
        for(int i=0;i<3;i++)
        {
            if(NormalBankWindow[i].isBusy)
            {
                cout<<"第"<<i+1<<"号普通窗口正在办理业务"<<' ';
                NormalBankWindow[i].HandleUser();
                NormalBankWindow[i].client.serveTime+=dealTime;
                if(NormalBankWindow[i].client.serveTime==dealTime)
                {
                    NormalBankWindow[i].isBusy=false;
                }
            }
        }
        if(VIPBankWindow.isBusy)
        {
            cout<<"VIP窗口正在办理业务"<<' ';
            VIPBankWindow.HandleUser();
            VIPBankWindow.client.serveTime+=dealTime;
            if(VIPBankWindow.client.serveTime==dealTime)
            {
                VIPBankWindow.isBusy=false;
            }
        }

        if(OfficialBankWindow.isBusy)
        {
            cout<<"对公窗口正在办理业务"<<' ';
            OfficialBankWindow.HandleUser();
            OfficialBankWindow.client.serveTime+=dealTime;
            if(OfficialBankWindow.client.serveTime==dealTime)
            {
                OfficialBankWindow.isBusy=false;
            }
        }
    time+=intervalTime;
    }

}

#endif // SIMULATER_H_INCLUDED
