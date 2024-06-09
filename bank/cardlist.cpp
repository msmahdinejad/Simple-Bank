#include "cardlist.h"

template <typename Z> cardList<Z>::cardList(){head = 0; size = 0;}
template <typename Z> cardList<Z>::~cardList()
{
    node<Z> * tmp = this->head;

    while(tmp != 0)
    {
        node<Z> * tmp2 = tmp->n ;
        delete tmp;
        tmp = tmp2;
    }
    this->h = nullptr ;
    this->size = 0 ;
}
template <typename Z> void cardList<Z>::push_front(Z Data)
{
    node<Z> * tmp = new node<Z>;
    tmp->data = Data;
    tmp->next = this->head;
    this->head = tmp;
    this->size++;
}
template <typename Z> node<Z> * cardList<Z>::getHead(){return head;}
template <typename Z> int & cardList<Z>::getSize(){return size;}
