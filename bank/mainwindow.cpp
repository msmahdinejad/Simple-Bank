#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LogInWidget->hide();
    ui->SignUpWidget->hide();
    QIntValidator *validatorYear = new QIntValidator(1900, 2030, ui->year);
    ui->year->setValidator(validatorYear);
    QIntValidator *validatorMonth = new QIntValidator(1, 12, ui->month);
    ui->month->setValidator(validatorMonth);
    QIntValidator *validatorDay = new QIntValidator(1, 30, ui->day);
    ui->day->setValidator(validatorDay);
    QIntValidator *validatorNationalCode = new QIntValidator(ui->nationalCode);
    ui->nationalCode->setValidator(validatorNationalCode);
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
    if(!DB.open())
        qDebug() << "DB in first page failed!";
    else
        qDebug() << "DB in first page opened!";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MainLoginButton_clicked()
{
    ui->LogInWidget->show();
}


void MainWindow::on_MainSignupButton_clicked()
{
    ui->SignUpWidget->show();
}



void MainWindow::on_LogInInSignUp_clicked()
{
    ui->LogInWidget->show();
}


void MainWindow::on_SignUpnInLogIn_clicked()
{
    ui->SignUpWidget->show();
}

bool MainWindow::checkLoginInputs()
{
    QString username, password;
    username = ui->usernameInLogIn->text();
    password = ui->PasswordInLogin->text();
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Fill in all the items!");
        return false;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username ='" + username + "'");
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return false;
    }
    QSqlRecord record = query.record();
    if (!query.next())
    {
        QMessageBox::critical(this, "Error", "Username not found!");
        return false;
    }
    QString DBUsername = record.value("username").toString();
    QString DBPassword = record.value("password").toString();
    if(password != DBPassword)
    {
        QMessageBox::critical(this, "Error", "Password is not correct");
        return false;
    }
    return true;
}

void MainWindow::on_LoginButton_clicked()
{
    if(checkLoginInputs())
    {

    }
}

