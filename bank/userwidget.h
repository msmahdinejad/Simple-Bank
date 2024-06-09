#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QMainWindow>

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
};

#endif // USERWIDGET_H
