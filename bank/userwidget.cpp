#include "userwidget.h"
#include "ui_userwidget.h"

userWidget::userWidget(QString loginUsername, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userWidget)
{
    ui->setupUi(this);
    currentUser = new user(loginUsername, this);
    currentCardWidget = new cardWidget(currentUser, loginUsername);
    //setCentralWidget(currentCardWidget);
    showMaximized();
    ui->stackedWidget->insertWidget(0, currentUser);
    ui->stackedWidget->insertWidget(1, currentCardWidget);
    ui->stackedWidget->setCurrentIndex(0);
    ui->radioButton->click();
}

userWidget::~userWidget()
{
    delete ui;
}

void userWidget::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void userWidget::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

