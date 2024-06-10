#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

#include "cardlist.h"
#include "card.h"
#include "user.h"

namespace Ui {
class cardWidget;
}

class cardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cardWidget(user * user, QString loginUser, QWidget *parent = nullptr);
    ~cardWidget();
    void refreshCards();
    cardList<card> * loadData();
    void loadWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cardWidget *ui;
    QString loginUsername;
    cardList<card> * cards;
    user * myUser;
};

#endif // CARDWIDGET_H
