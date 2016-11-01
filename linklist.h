#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
using namespace std;
template <class T>
class LinkListNode
{
public:
    T data;
    LinkListNode<T>* next;
    LinkListNode(const T&x,LinkListNode<T>* ptr=0)
    {
        data=x;
        next=ptr;
    }
};
template <class T>
class LinkList
{
private:
    LinkListNode<T>* head;
    LinkListNode<T>* tail;
    LinkListNode<T>* prevPtr;
    LinkListNode<T>* currPtr;
    int position;
public:
    LinkList();
    ~LinkList();
    void next();
    bool endOfList()const;
    void insertTail(const T& item);
    T &currData();
};
template <class T>
LinkList<T>::LinkList()
{
    head=NULL;
    tail=NULL;
    prevPtr=NULL;
    currPtr=NULL;
    position=0;
}
template <class T>
LinkList<T>::~LinkList()
{
    LinkListNode<T>* temp;
    while(head!=tail)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
    delete head;
    delete tail;
    delete prevPtr;
    delete currPtr;
    position=0;
}
template <class T>
void LinkList<T>::next()
{
    LinkListNode<T>* temp;
    if(currPtr==tail)
    {
        cout<<"the end of list!";
    }
    else
    {
        temp=currPtr;
        currPtr=currPtr->next;
        prevPtr=temp;
        position++;
    }
}
template <class T>
bool LinkList<T>::endOfList()const
{
    return currPtr==tail;
}
template <class T>
void LinkList<T>::insertTail(const T& item)
{
    LinkListNode<T>* temp=new LinkListNode<T>(item,NULL);
    tail->next=temp;
    tail=temp;
}
template <class T>
T& LinkList<T>::currData()
{
    return currPtr->data;
}
#endif // LINKLIST_H_INCLUDED
