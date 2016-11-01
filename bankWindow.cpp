#include "bankWindow.h"
bankWindow::bankWindow(wchar_t t)
{
    type=t;
    num=0;
}
bool bankWindow::isBusy()
{
    return num!=0;
}
void bankWindow::HandleUser()
{
    num--;
}

