#ifndef BANKWINDOW_H_INCLUDED
#define BANKWINDOW_H_INCLUDED
#include "user.h"
class bankWindow
{
public:
    User client;
    char type;
    bankWindow(char t);
    bool isBusy;
    void HandleUser();
};
bankWindow::bankWindow(char t='n')
{
    isBusy=false;
    type=t;
}
void bankWindow::HandleUser()
{

        cout<<type<<' '<<client.id<<endl;
}
#endif // BANKWINDOW_H_INCLUDED
