#include "treanfer.h"
#include "ui_treanfer.h"

Treanfer::Treanfer(user * Sender, cardWidget * Parent, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Treanfer)
    , Parent(Parent)
    , Sender(Sender)
{
    ui->setupUi(this);
    node<card> * tmp = Parent->getCards()->getHead();
    while(tmp != 0)
    {
        ui->sender->addItem(tmp->getData()->getCardNumber());
        tmp = tmp->getNext();
    }
}

bool Treanfer::checkInputs()
{
    if(ui->card->text().isEmpty() || ui->pass->text().isEmpty() || ui->amount->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Fill in all the items!");
        return false;
    }
    if(ui->card->text() == ui->sender->currentText())
    {
        QMessageBox::critical(this, "Error", "cant tranfer to same card!");
        return false;
    }
    if(ui->amount->text().toInt() > 3000000)
    {
        QMessageBox::critical(this, "Error", "maximum amount is 3000000!");
        return false;
    }
    if(ui->amount->text().toInt() < 1000)
    {
        QMessageBox::critical(this, "Error", "minimum amount is 1000!");
        return false;
    }
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
    if(!DB.open())
        qDebug() << "DB in cardList page failed!";
    else
        qDebug() << "DB in cardList page opened!";
    QSqlQuery query;
    query.prepare("SELECT * FROM cards WHERE cardnumber ='" + ui->card->text() + "'");
    if (!query.exec())
    {
        qDebug() << query.lastError().text();
    }
    else
    {
        if(query.next())
        {
            Inventory = query.value(8).toDouble();
        }
        else
        {
            QMessageBox::critical(this, "Error", "Recipient card number is wrong!");
            return false;
        }
    }
    node<card> * tmp = Parent->getCards()->getHead();
    while(tmp != 0)
    {
        if(tmp->getData()->getCardNumber() == ui->sender->currentText())
        {
            senderInventory = tmp->getData()->getInventory();
            if(ui->amount->text().toInt() > tmp->getData()->getInventory())
            {
                QMessageBox::critical(this, "Error", "Amount is more than Inventory!");
                return false;
            }
            if(tmp->getData()->getPass2() == ui->pass->text().toInt() && tmp->getData()->getPass2() != 0)
            {
                if(ui->amount->text().toInt() > 100000)
                {
                    QMessageBox::critical(this, "Error", "cant tranfer more than 100000 with pass2!");
                    return false;
                }
                else
                {
                    std::tm now = getCurrentTime();
                    if(getDay(now) == Sender->getLastDay())
                    {
                        if(Sender->getSumTransfers() > 6000000)
                        {
                            QMessageBox::critical(this, "Error", "maximum Transfer in a day is 6000000!");
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        tmp = tmp->getNext();
    }
    if(ui->pass->text() != PooyaPass)
    {
        QMessageBox::critical(this, "Error", "Pass is wronge!");
        return false;
    }
    std::tm now = getCurrentTime();
    if(getDay(now) == Sender->getLastDay())
    {
        if(Sender->getSumTransfers() > 6000000)
        {
            QMessageBox::critical(this, "Error", "maximum Transfer in a day is 6000000!");
            return false;
        }
    }
    return true;
}

Treanfer::~Treanfer()
{
    delete ui;
}

void Treanfer::on_pushButton_2_clicked()
{
    if(checkInputs())
    {
        QString first;
        QString last;
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
        if(!DB.open())
            qDebug() << "DB in cardList page failed!";
        else
            qDebug() << "DB in cardList page opened!";
        QSqlQuery query;
        query.prepare("SELECT * FROM cards WHERE cardnumber ='" + ui->card->text() + "'");
        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        else
        {
            while(query.next())
            {
                first = query.value(12).toString();
                last = query.value(13).toString();
                qDebug() << "card loaded succefully!";
            }
        }
        DB.close();
        QMessageBox::StandardButton reply;
        QString tmp ="Do you want transfer to " + first + " " + last + "?";
        reply = QMessageBox::question(this, "confirmation", tmp,
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            std::tm now = getCurrentTime();
            if(getDay(now) == Sender->getLastDay())
            {
                if(Sender->getSumTransfers() > 6000000)
                {
                    QMessageBox::critical(this, "Error", "maximum Transfer in a day is 6000000!");
                }
                else
                {
                    Sender->setSumTransfers(Sender->getSumTransfers() + ui->amount->text().toInt());
                }
            }
            else
            {
                Sender->setLastDay(getDay(now));
                Sender->setSumTransfers(ui->amount->text().toInt());
            }
            QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
            DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
            if(!DB.open())
                qDebug() << "DB in updateCard page failed!";
            else
                qDebug() << "DB in updateCard page opened!";
            QSqlQuery query;
            query.prepare("UPDATE cards SET inventory = ? WHERE cardnumber = ?");
            query.addBindValue(Inventory + ui->amount->text().toDouble() - 0.01*ui->amount->text().toDouble());
            query.addBindValue(ui->card->text());
            QSqlQuery query2;
            query2.prepare("UPDATE cards SET inventory = ? WHERE cardnumber = ?");
            query2.addBindValue(senderInventory - ui->amount->text().toDouble());
            query2.addBindValue(ui->sender->currentText());
            QSqlQuery query3;
            query3.prepare("UPDATE users SET lastday = ?, sumtransfers = ? WHERE username = ?");
            query3.addBindValue(Sender->getLastDay());
            query3.addBindValue(Sender->getSumTransfers());
            query3.addBindValue(Sender->getUsername());
            if (!query.exec() || !query2.exec())
            {
                qDebug() << query.lastError().text();
            }
            else
            {
                QMessageBox::information(this, "Success", "Transfer was succefully!");
            }
            DB.close();
            Parent->refreshCards();
            this->close();
        } else {
            return;
        }
    }
}


void Treanfer::on_pushButton_3_clicked()
{
    PooyaPass = QString::fromStdString(generate_unique_id(5));
    ui->pass->setText(PooyaPass);
}

