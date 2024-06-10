#include "user.h"
#include "ui_user.h"
#include "mainwindow.h"

user::user(QString loginUsername, QWidget *parent)
    : QWidget(parent)
    , username(loginUsername)
    , ui(new Ui::user)
    , parent(parent)
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
        lastDay = query.value(8).toInt();
        lastHour = query.value(9).toInt();
        lastMin = query.value(10).toInt();
        sumTransfers = query.value(11).toInt();
        qDebug() << "user profile loaded succefully!";
    }
    DB.close();


    ui->first->setText(firstName);
    ui->last->setText(lastName);
    ui->code->setText(nationalCode);
    ui->day->setText(QString::fromStdString(std::to_string(day)));
    ui->month->setText(QString::fromStdString(std::to_string(month)));
    ui->year->setText(QString::fromStdString(std::to_string(year)));
    ui->username->setText(loginUsername);
    ui->password->setText(password);

}

QString & user::getUsername(){return username;}
QString & user::getLastName(){return lastName;}
QString & user::getFirstName(){return firstName;}

user::~user()
{
    delete ui;
}

void user::on_pushButton_clicked()
{
    MainWindow * tmp = new MainWindow();
    tmp->show();
    parent->close();
}

int & user::getLastDay(){return lastDay;}
int & user::getSumTransfers(){return sumTransfers;}
void user::setLastDay(int num){lastDay = num;}
void user::setSumTransfers(int num){sumTransfers = num;}
