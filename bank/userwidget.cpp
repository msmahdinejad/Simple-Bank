#include "userwidget.h"
#include "ui_userwidget.h"

userWidget::userWidget(QString loginUsername, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userWidget)
{
    ui->setupUi(this);
    currentUser = new user(loginUsername, this);
}

userWidget::~userWidget()
{
    delete ui;
}
