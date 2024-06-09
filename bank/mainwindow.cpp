#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userwidget.h"

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
    //QSqlRecord record = query.record();
    if (!query.next())
    {
        QMessageBox::critical(this, "Error", "Username not found!");
        return false;
    }
    QString DBPassword = query.value(1).toString();
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
        userWidget * UW = new userWidget(ui->usernameInLogIn->text());
        UW->show();
        this->hide();
    }
}

bool MainWindow::checkSignupInputs()
{
    QString user, pass, first, last, code, day, month, year;
    user = ui->usernamInSignUp->text();
    pass = ui->passwordInSignUp->text();
    first = ui->firstName->text();
    last = ui->lastName->text();
    code = ui->nationalCode->text();
    day = ui->day->text();
    month = ui->month->text();
    year = ui->year->text();
    if(user.isEmpty() || pass.isEmpty() || first.isEmpty() || last.isEmpty() ||
        code.isEmpty() || day.isEmpty() || month.isEmpty() || year.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Fill in all the items!");
        return false;
    }
    if(user.size() < 8)
    {
        QMessageBox::critical(this, "Error", "Username must be at least 8 characters!");
        return false;
    }
    if(pass.size() < 8)
    {
        QMessageBox::critical(this, "Error", "Password must be at least 8 characters!");
        return false;
    }
    bool specialCheck = false;
    QString specialCharacters = "!@#$%^&*()_+{}|:\"<>?-=[]\\;',./";
    for (const QChar &ch : specialCharacters) {
        if (pass.contains(ch)) {
            specialCheck = true;
            break;
        }
    }
    if(!specialCheck)
    {
        QMessageBox::critical(this, "Error", "Password must contain special characters!");
        return false;
    }
    bool capitalCheck = false;
    bool numbersCheck = false;
    for (const QChar &ch : pass) {
        if (ch.isUpper()) {
            capitalCheck = true;
        }
        if(ch >= '0' && ch <= '9')
        {
            numbersCheck = true;
        }
    }
    if(!capitalCheck)
    {
        QMessageBox::critical(this, "Error", "Password must contain capital letters!");
        return false;
    }
    if(!numbersCheck)
    {
        QMessageBox::critical(this, "Error", "Password must contain numbers!");
        return false;
    }
    if(code.size() != 10)
    {
        QMessageBox::critical(this, "Error", "National code must be 10 digits!");
        return false;
    }
    if(year.toInt() < 1900 || year.toInt() > 2024)
    {
        QMessageBox::critical(this, "Error", "Wrong year!");
        return false;
    }
    if(month.toInt() < 1 || month.toInt() > 12)
    {
        QMessageBox::critical(this, "Error", "Wrong month!");
        return false;
    }
    if(day.toInt() < 1 || day.toInt() > 30)
    {
        QMessageBox::critical(this, "Error", "Wrong day!");
        return false;
    }
    return true;
}

void MainWindow::on_SignUpBotton_clicked()
{
    if(checkSignupInputs())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO users (username, password, firstname, lastname, nationalcode, "
                      "day, month, year) VALUES ('"+ui->usernamInSignUp->text()+"', '"+ui->passwordInSignUp->text()+
                      "', '"+ui->firstName->text()+"', '"+ui->lastName->text()+"', '"+ui->nationalCode->text()+
                      "', "+ui->day->text()+", "+ui->month->text()+", "+ui->year->text()+")");
        if (!query.exec())
        {
            QMessageBox::critical(this, "Error", query.lastError().text());
            return;
        }
        else
        {
            ui->usernamInSignUp->setText("");
            ui->passwordInSignUp->setText("");
            ui->firstName->setText("");
            ui->lastName->setText("");
            ui->nationalCode->setText("");
            ui->year->setText("");
            ui->month->setText("");
            ui->day->setText("");
            QMessageBox::information(this, "Success", "Sing up was succefully!");
            return;
        }
    }
}

