#include "simulater.h"
#include <iostream>
using namespace std;
simulater::simulater()
{
    NormalBankWindow nWindow1(1);
    NormalBankWindow nWindow2(2);
    NormalBankWindow nWindow3(3);
    VIPBankWindow vWindow(1);
    OfficialBankWindow oWindow(1);
    nbw.insertTail(nWindow1);
    nbw.insertTail(nWindow2);
    nbw.insertTail(nWindow3);
    vbw.insertTail(vWindow1);
    obw.insertTail(oWindow1);
}
void simulater::customerEnter()
{
    int CustomerEnterMatrix[10][3];
}
