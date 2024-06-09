#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>
#include "user.h"

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
    user * currentUser;
};

#endif // USERWIDGET_H
