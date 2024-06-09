#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LogInWidget->hide();
    ui->SignUpWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
