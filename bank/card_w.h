#ifndef CARD_W_H
#define CARD_W_H

#include <QWidget>
#include <card.h>

namespace Ui {
class card_w;
}

class card_w : public QWidget
{
    Q_OBJECT

public:
    explicit card_w(card * Card ,QWidget *parent = nullptr);
    ~card_w();

private:
    Ui::card_w *ui;
    card * myCard;
};

#endif // CARD_W_H
