#ifndef TREANFER_H
#define TREANFER_H

#include <QMainWindow>
#include "cardwidget.h"
#include "user.h"

namespace Ui {
class Treanfer;
}

class Treanfer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Treanfer(user * Sender, cardWidget * Parent, QWidget *parent = nullptr);
    ~Treanfer();
    bool checkInputs();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    std::string generate_unique_id(int n) {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        // قالب‌بندی جلویی با صفر (zero-padding) برای تضمین 10 رقم
        return std::to_string(millis % (int)pow(10,n)); // حاصل تقسیم بر 10 میلیارد تا تعداد رقم‌ها حفظ شود
    }
    Ui::Treanfer *ui;
    cardWidget * Parent;
    user * Sender;
    QString PooyaPass;
    double senderInventory;
    double Inventory;
};

#endif // TREANFER_H
