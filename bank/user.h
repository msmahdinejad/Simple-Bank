#ifndef USER_H
#define USER_H

#include <QWidget>
#include <QMainWindow>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <bits/stdc++.h>
//#include "userwidget.h"

using namespace std;

namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

private:
    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString nationalCode;
    int day;
    int month;
    int year;
    int lastDay;
    int lastHour;
    int lastMin;
    int sumTransfers;

public:
    explicit user(QString loginUsername, QWidget *parent = nullptr);
    ~user();
    QString & getUsername();
    QString & getLastName();
    QString & getFirstName();
    int & getLastDay();
    int & getSumTransfers();
    void setLastDay(int num);
    void setSumTransfers(int num);
private slots:
    void on_pushButton_clicked();

private:
    Ui::user *ui;
    QSqlDatabase DB;
    //userWidget * Parent;
    QWidget *parent;
};

#endif // USER_H
