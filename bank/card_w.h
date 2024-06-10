#ifndef CARD_W_H
#define CARD_W_H

#include <QWidget>
#include <card.h>
#include "cardwidget.h"

namespace Ui {
class card_w;
}

class card_w : public QWidget
{
    Q_OBJECT

public:
    explicit card_w(cardWidget * Parent, card * Card, QWidget *parent = nullptr);
    ~card_w();

private slots:
    void on_moreBotton_clicked();

private:
    Ui::card_w *ui;
    card * myCard;
    cardWidget * Parent;
};

#endif // CARD_W_H
