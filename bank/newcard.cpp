#include "newcard.h"
#include "ui_newcard.h"

newCard::newCard(user * user, cardWidget * Parent, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::newCard)
    , myUser(user)
    , Parent(Parent)
{
    ui->setupUi(this);
    ui->type_2->addItems({"سپرده", "جاری", "قرض الحسنه"});
    ui->type_2->setCurrentIndex(0);
    QIntValidator *validatorPass = new QIntValidator(1000, 9999, ui->Password);
    ui->Password->setValidator(validatorPass);
    QIntValidator *validatorInventory = new QIntValidator(10000, 100000000000000, ui->inventory);
    ui->inventory->setValidator(validatorInventory);
}

newCard::~newCard()
{
    delete ui;
}

bool newCard::checkInputs()
{
    if(ui->Password->text().toInt() < 1000 || ui->Password->text().toInt() > 9999)
    {
        QMessageBox::critical(this, "Error", "Password must be 4 digits!");
        return false;
    }
    if(ui->inventory->text().toInt() < 50000)
    {
        QMessageBox::critical(this, "Error", "Inventory must be at least 50000!");
        return false;
    }
    return true;
}

void newCard::on_pushButton_2_clicked()
{
    if(checkInputs())
    {
        std::tm now = getCurrentTime();
        QString ownerUsername = myUser->getUsername();
        QString cardNumber = QString::fromStdString(generate_unique_id(6));
        QString accountNumber = QString::fromStdString(generate_unique_id(5));
        QString shabaNumber = "IR" + QString::fromStdString(generate_unique_id(8));
        QString type = ui->type_2->currentText();
        QString CVV2 = QString::fromStdString(generate_unique_id(3));
        QString pass1 = ui->Password->text();
        QString inventory = ui->inventory->text();
        QString day = QString::fromStdString(getDay(now));
        QString month = QString::fromStdString(getMonth(now));
        QString year = QString::fromStdString(getYear(now));
        QString firstName = myUser->getFirstName();
        QString lastName = myUser->getLastName();
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
        DB.setDatabaseName("C:/saleh/UNI/AP/Bank/uiap-sec-mini-project-msmahdinejad/Data.db");
        if(!DB.open())
            qDebug() << "DB in newCard page failed!";
        else
            qDebug() << "DB in newCard page opened!";
        QSqlQuery query;
        query.prepare("INSERT INTO cards (ownerusername, cardnumber, accountnumber, shabanumber, type, cvv2, pass1, inventory, day, month, year, FirstName, LastName) VALUES ('"
                    + ownerUsername +"', '" + cardNumber+ "', '" + accountNumber+ "', '"+shabaNumber+"', '"
                    + type + "', '" + CVV2 + "', " + pass1 + ", " + inventory + ", " + day + ", " + month + ", "
                      + year + ", '" + firstName + "', '" + lastName + "')");
        if (!query.exec())
        {
            qDebug() << query.lastError().text();
        }
        else
        {
            qDebug() << "card added succecfully";
        }
        DB.close();
        sendSignalToB();
        Parent->refreshCards();
        this->close();
    }
}

