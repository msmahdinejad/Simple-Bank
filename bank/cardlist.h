#ifndef CARDLIST_H
#define CARDLIST_H

#include <QString>

template <typename T>
class node {

public :
    T data;
    node * next;
};

template <typename Z>
class cardList
{
private:
    node<Z> * head;
    int size ;
public:
    cardList();
    ~cardList();
    void loadData(QString loginUsername);
    void push_front(Z Data);
    node<Z> * getHead();
    int & getSize();
};

#endif // CARDLIST_H
