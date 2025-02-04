#include "card_w.h"
#include "ui_card_w.h"

card_w::card_w(cardWidget * Parent, card * Card ,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::card_w)
    , myCard(Card)
    , Parent(Parent)
{
    ui->setupUi(this);
    ui->cvv2->setText(myCard->getCVV2());
    ui->cardnum->setText(myCard->getCardNumber());
    ui->username->setText(myCard->getFirstName() + " " + myCard->getLastName());
}

card_w::~card_w()
{
    delete ui;
}

void card_w::on_moreBotton_clicked()
{
    Parent->showCardMore(myCard);
}

