#include "card.h"

card::card(QString user, QString cardnum, QString acountnum, QString shaba, QString type, QString cvv2, int pass1, int pass2, long double in, int day, int month, int year)
    : ownerUsername(user)
    , cardNumber(cardnum)
    , accountNumber(acountnum)
    , shabaNumber(shaba)
    , type(type)
    , CVV2(cvv2)
    , pass1(pass1)
    , pass2(pass2)
    , inventory(in)
    , day(day)
    , month(month)
    , year(year)
{

}

void card::setPass1(int num){}
void card::setPass2(int num){}
void card::plusInventory(int num){}
QString & card::getOwnerUsername(){}
QString & card::getCardNumber(){}
QString & card::getAccountNumber(){}
QString & card::getShabaNumber(){}
QString & card::getType(){}
QString & card::getCVV2(){}
int & card::getPass1(){}
int & card::getPass2(){}
long double & card::getInventory(){}
int & card::getDay(){}
int & card::getMonth(){}
int & card::getYear(){}
