#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>
#include "user.h"
#include "cardwidget.h"

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
    cardWidget * currentCardWidget;
};

#endif // USERWIDGET_H
