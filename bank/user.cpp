#include "user.h"
#include "ui_user.h"

user::user(QString loginUsername, QWidget *parent)
    : QWidget(parent)
    , username(loginUsername)
    , ui(new Ui::user)
{
    ui->setupUi(this);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
    if(!DB.open())
        qDebug() << "DB in user page failed!";
    else
        qDebug() << "DB in user page opened!";
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username ='" + loginUsername + "'");
    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }
    else
    {
        qDebug() << "user loaded succefully!";
    }
    if (!query.next())
    {
        qDebug() << query.lastError().text();
    }
    else
    {
        password = query.value(1).toString();
        firstName = query.value(2).toString();
        lastName = query.value(3).toString();
        nationalCode = query.value(4).toString();
        day = query.value(5).toInt();
        month = query.value(6).toInt();
        year = query.value(7).toInt();
        qDebug() << "user profile loaded succefully!";
    }

}

user::~user()
{
    delete ui;
}
