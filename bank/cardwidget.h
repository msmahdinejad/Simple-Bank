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

namespace Ui {
class cardWidget;
}

class cardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit cardWidget(QString loginUser, QWidget *parent = nullptr);
    ~cardWidget();
    cardList<card> * loadData();
    void loadWidget();
    void refreshCards();
private:
    Ui::cardWidget *ui;
    QString loginUsername;
    cardList<card> * cards;
};

#endif // CARDWIDGET_H
