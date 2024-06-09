#include "userwidget.h"
#include "ui_userwidget.h"

userWidget::userWidget(QString loginUsername, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userWidget)
{
    ui->setupUi(this);
}

userWidget::~userWidget()
{
    delete ui;
}
