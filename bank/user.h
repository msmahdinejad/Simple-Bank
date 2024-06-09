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

using namespace std;

namespace Ui {
class user;
}

class user : public QWidget
{
    Q_OBJECT

private:
    string username;
    string password;
    string firstName;
    string lastName;
    string nationalCode;
    int day;
    int month;
    int year;

public:
    explicit user(QString loginUsername, QWidget *parent = nullptr);
    ~user();

private:
    Ui::user *ui;
    QSqlDatabase DB;
};

#endif // USER_H
