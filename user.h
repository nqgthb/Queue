#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
class User
{
private:
    char type;
public:
    int serveTime;
    int id;
    User(char t='n',int i=0);
    char getType();
};
User::User(char t,int i)
{
    serveTime=0;
    id=i;
    type=t;
}char User::getType()
{
    return type;
}
#endif // USER_H_INCLUDED
