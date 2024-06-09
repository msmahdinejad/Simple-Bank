#ifndef CARDLIST_H
#define CARDLIST_H

#include <QString>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

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
    void push_front(Z Data);
    node<Z> * getHead();
    int & getSize();
};

#endif // CARDLIST_H
