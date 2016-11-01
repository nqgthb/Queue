#include "user.h"
#include "simulater.h"
#include "bankWindow.h"
int main()
{
    Simulater simulate;
    simulate.setDealTime(4);
    simulate.setEndTime(12);
    simulate.setIntervalTime(2);
    simulate.Simulate();
    return 0;
}
