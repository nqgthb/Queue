#include "user.h"
#include <iostream>
using namespace std;
User::User(int i,int w,int a,int s,wchar_t t)
{
    id=i;
    isWait=w;
    arriveTime=a;
    serveTime=s;
    type=t;
}
NormalUser::NormalUser(int i,int w,int a,int s,wchar_t t)User()
