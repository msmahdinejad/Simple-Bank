#ifndef CARD_H
#define CARD_H

#include <QString>

class card
{
private:
    QString ownerUsername;
    QString cardNumber;
    QString accountNumber;
    QString shabaNumber;
    QString type;
    QString CVV2;
    int pass1;
    int pass2;
    long double inventory;
    int day;
    int month;
    int year;

public:
    card(QString user, QString cardnum, QString acountnum, QString shaba, QString type, QString cvv2, int pass1, int pass2, long double in, int day, int month, int year);
    void setPass1(int num);
    void setPass2(int num);
    void plusInventory(int num);
    QString & getOwnerUsername();
    QString & getCardNumber();
    QString & getAccountNumber();
    QString & getShabaNumber();
    QString & getType();
    QString & getCVV2();
    int & getPass1();
    int & getPass2();
    long double & getInventory();
    int & getDay();
    int & getMonth();
    int & getYear();
};

#endif // CARD_H
