#include "userwidget.h"
#include "ui_userwidget.h"

userWidget::userWidget(QString loginUsername, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userWidget)
{
    ui->setupUi(this);
    currentUser = new user(loginUsername);
    currentCardWidget = new cardWidget(currentUser, loginUsername);
    setCentralWidget(currentCardWidget);
    showMaximized();
}

userWidget::~userWidget()
{
    delete ui;
}
