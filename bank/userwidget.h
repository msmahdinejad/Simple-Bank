#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

namespace Ui {
class userWidget;
}

class userWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit userWidget(QString loginUsername, QWidget *parent = nullptr);
    ~userWidget();

private:
    Ui::userWidget *ui;
    QSqlDatabase DB;
};

#endif // USERWIDGET_H
