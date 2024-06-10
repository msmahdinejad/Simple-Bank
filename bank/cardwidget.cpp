#include "cardwidget.h"
#include "ui_cardwidget.h"

cardWidget::cardWidget(QString loginUser, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardWidget)
    , loginUsername(loginUser)
{
    ui->setupUi(this);
    cards = loadData();

}

cardWidget::~cardWidget()
{
    delete ui;
}

cardList<card> * cardWidget::loadData()
{
    cardList<card> * myCardList = new cardList<card>;
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
    if(!DB.open())
        qDebug() << "DB in cardList page failed!";
    else
        qDebug() << "DB in cardList page opened!";
    QSqlQuery query;
    query.prepare("SELECT * FROM cards WHERE ownerusername ='" + loginUsername + "'");
    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }
    else
    {
        while(query.next())
        {
            QString ownerUsername = query.value(0).toString();
            QString cardNumber = query.value(1).toString();
            QString accountNumber = query.value(2).toString();
            QString shabaNumber = query.value(3).toString();
            QString type = query.value(4).toString();
            QString CVV2 = query.value(5).toString();
            int pass1 = query.value(6).toInt();
            int pass2 = query.value(7).toInt();
            long double inventory = query.value(8).toDouble();
            int day = query.value(9).toInt();
            int month = query.value(10).toInt();
            int year = query.value(11).toInt();
            card * temp = new card(ownerUsername, cardNumber, accountNumber, shabaNumber, type, CVV2, pass1, pass2, inventory, day, month, year);
            myCardList->push_front(temp);
            qDebug() << "card loaded succefully!";
        }
    }
    return myCardList;
}

