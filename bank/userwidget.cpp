#include "userwidget.h"
#include "ui_userwidget.h"

userWidget::userWidget(QString loginUsername, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userWidget)
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
}

userWidget::~userWidget()
{
    delete ui;
}
