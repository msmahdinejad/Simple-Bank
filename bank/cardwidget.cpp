#include "cardwidget.h"
#include "ui_cardwidget.h"
#include "card_w.h"
#include "newcard.h"

cardWidget::cardWidget(user * user, QString loginUser, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardWidget)
    , loginUsername(loginUser)
    , myUser(user)
{
    ui->setupUi(this);
    cards = loadData();
    loadWidget();
    //ui->scrollLayOut->setAlignment(Qt::AlignTop);
    ui->moreWidget->hide();
    QIntValidator *validatorPass1 = new QIntValidator(1000, 9999, ui->pass1);
    ui->pass1->setValidator(validatorPass1);
    QIntValidator *validatorPass2 = new QIntValidator(10000, 99999, ui->pass2);
    ui->pass2->setValidator(validatorPass2);
}

cardList<card> * cardWidget::getCards(){return cards;}

void cardWidget::showCardMore(card * selectedCard)
{
    ui->moreWidget->show();
    ui->name->setText(selectedCard->getFirstName() + " " + selectedCard->getLastName());
    ui->card->setText(selectedCard->getCardNumber());
    ui->acc->setText(selectedCard->getAccountNumber());
    ui->shaba->setText(selectedCard->getShabaNumber());
    ui->type->setText(selectedCard->getType());
    ui->cvv2->setText(selectedCard->getCVV2());
    ui->pass1->setText(QString::fromStdString(std::to_string(selectedCard->getPass1())));
    ui->pass2->setText(QString::fromStdString(std::to_string(selectedCard->getPass2())));
    ui->inventoy->setText(QString::fromStdString(std::to_string(selectedCard->getInventory())));
    ui->day->setText(QString::fromStdString(std::to_string(selectedCard->getDay())));
    ui->month->setText(QString::fromStdString(std::to_string(selectedCard->getMonth())));
    ui->year->setText(QString::fromStdString(std::to_string(selectedCard->getYear())));
}

cardWidget::~cardWidget()
{
    delete ui;
}

void cardWidget::refreshCards()
{
    ui->moreWidget->hide();
    cards->deleteCards();
    cards = loadData();
    loadWidget();
}

void cardWidget::loadWidget()
{
    while (QLayoutItem* item = ui->scrollLayOut->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater(); // حذف ویجت
        }
        delete item; // حذف آیتم
    }
    if(cards->getSize() == 5)
    {
        ui->pushButton->hide();
    }
    node<card> * tmp = cards->getHead();
    while(tmp != 0)
    {
        card_w * cardW = new card_w(this, tmp->getData());
        ui->scrollLayOut->addWidget(cardW);
        tmp = tmp->getNext();
    }
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
            QString firstName = query.value(12).toString();
            QString lastName = query.value(13).toString();
            card * temp = new card(ownerUsername, cardNumber, accountNumber, shabaNumber, type, CVV2, pass1, pass2, inventory, day, month, year, firstName, lastName);
            myCardList->push_front(temp);
            qDebug() << "card loaded succefully!";
        }
    }
    DB.close();
    return myCardList;
}


void cardWidget::on_pushButton_clicked()
{
    newCard * tmp = new newCard(myUser, this);
    tmp->show();
}


void cardWidget::on_pass1Edit_clicked()
{
    if(ui->pass1->text().toInt() >= 1000 && ui->pass1->text().toInt() <= 9999)
    {
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
        if(!DB.open())
            qDebug() << "DB in updateCard page failed!";
        else
            qDebug() << "DB in updateCard page opened!";
        QSqlQuery query;
        query.prepare("UPDATE cards SET pass1 = ? WHERE cardnumber = ?");
        query.addBindValue(ui->pass1->text());
        query.addBindValue(ui->card->text());
        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        else
        {
            qDebug() << "card updated succecfully";
            QMessageBox::information(this, "Success", "Update was succefully!");
        }
        DB.close();
        refreshCards();
    }
}


void cardWidget::on_pass2Edit_clicked()
{
    if(ui->pass2->text().toInt() >= 10000 && ui->pass2->text().toInt() <= 99999)
    {
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
        if(!DB.open())
            qDebug() << "DB in updateCard page failed!";
        else
            qDebug() << "DB in updateCard page opened!";
        QSqlQuery query;
        query.prepare("UPDATE cards SET pass2 = ? WHERE cardnumber = ?");
        query.addBindValue(ui->pass2->text());
        query.addBindValue(ui->card->text());
        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        else
        {
            qDebug() << "card updated succecfully";
            QMessageBox::information(this, "Success", "Update was succefully!");
        }
        DB.close();
        refreshCards();
    }
}

