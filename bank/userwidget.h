#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>
#include "user.h"
#include "cardwidget.h"
#include "treanfer.h"

namespace Ui {
class userWidget;
}

class userWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit userWidget(QString loginUsername, QWidget *parent = nullptr);
    ~userWidget();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::userWidget *ui;
    user * currentUser;
    cardWidget * currentCardWidget;
};

#endif // USERWIDGET_H
