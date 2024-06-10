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
private:
    T * data;
    node<T> * next;
public:
    node(T * d);
    T * getData();
    void setNext(node<T> * next);
    node<T> * getNext();
};

template <typename T> node<T>::node(T * d)
{
    data = d;
    next = nullptr;
}
template <typename T> T * node<T>::getData()
{
    return data;
}
template <typename T> void node<T>::setNext(node<T> * Next)
{
    next = Next;
}
template <typename T> node<T> * node<T>::getNext()
{
    return next;
}
template <typename Z>
class cardList
{
private:
    node<Z> * head;
    int size ;
public:
    cardList();
    ~cardList();
    void deleteCards();
    void push_front(Z * Data);
    node<Z> * getHead();
    int & getSize();
};

template <typename Z> cardList<Z>::cardList(){head = nullptr; size = 0;}
template <typename Z> cardList<Z>::~cardList()
{
    node<Z> * tmp = this->head;

    while(tmp != 0)
    {
        node<Z> * tmp2 = tmp->getNext();
        delete tmp;
        tmp = tmp2;
    }
    this->head = nullptr ;
    this->size = 0 ;
}
template <typename Z> void cardList<Z>::deleteCards()
{
    node<Z> * tmp = this->head;

    while(tmp != 0)
    {
        node<Z> * tmp2 = tmp->getNext();
        delete tmp;
        tmp = tmp2;
    }
    this->head = nullptr ;
    this->size = 0 ;
}
template <typename Z> void cardList<Z>::push_front(Z * Data)
{
    node<Z> * tmp = new node<Z>(Data);
    tmp->setNext(this->head);
    this->head = tmp;
    this->size++;
}
template <typename Z> node<Z> * cardList<Z>::getHead(){return head;}
template <typename Z> int & cardList<Z>::getSize(){return size;}


#endif // CARDLIST_H
