#include "card.h"

card::card(QString user, QString cardnum, QString acountnum, QString shaba, QString type, QString cvv2, int pass1, int pass2, long double in, int day, int month, int year,
           QString firstName,
           QString lastName)
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
    , firstName(firstName)
    , lastName(lastName)
{

}

void card::setPass1(int num){pass1 = num;}
void card::setPass2(int num){pass2 = num;}
void card::plusInventory(int num){inventory += num;}
QString & card::getOwnerUsername(){return ownerUsername;}
QString & card::getCardNumber(){return cardNumber;}
QString & card::getAccountNumber(){return accountNumber;}
QString & card::getShabaNumber(){return shabaNumber;}
QString & card::getType(){return type;}
QString & card::getCVV2(){return CVV2;}
int & card::getPass1(){return pass1;}
int & card::getPass2(){return pass2;}
long double & card::getInventory(){return inventory;}
int & card::getDay(){return day;}
int & card::getMonth(){return month;}
int & card::getYear(){return year;}
QString & card::getFirstName(){return firstName;}
QString & card::getLastName(){return lastName;}
