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
    // Function to get the current date and time
    std::tm getCurrentTime() {
        std::time_t now = std::time(nullptr);
        return *std::localtime(&now);
    }

    // Function to check if a date is before the current date and time
    bool isBeforeNow(const std::tm& date) {
        std::time_t now = std::time(nullptr);
        std::time_t inputTime = std::mktime(const_cast<std::tm*>(&date));
        return inputTime < now;
    }

    // Function to calculate a date that is a certain number of years into the future
    std::tm calculateFutureDate(int years) {
        std::tm currentDate = getCurrentTime();
        currentDate.tm_year += years;
        std::mktime(&currentDate); // Normalize the date
        return currentDate;
    }

    // Function to calculate a date that is a certain number of years into the past
    std::tm calculatePastDate(int years) {
        return calculateFutureDate(-years);
    }

    // Utility functions to extract components of a date
    int getYear(const std::tm& date) {
        return date.tm_year + 1900; // tm_year represents years since 1900
    }

    int getMonth(const std::tm& date) {
        return date.tm_mon + 1; // tm_mon is 0-based, so add 1
    }

    int getDay(const std::tm& date) {
        return date.tm_mday;
    }

    int getHour(const std::tm& date) {
        return date.tm_hour;
    }

    int getMinute(const std::tm& date) {
        return date.tm_min;
    }

    int getSecond(const std::tm& date) {
        return date.tm_sec;
    }
    Ui::Treanfer *ui;
    cardWidget * Parent;
    user * Sender;
    QString PooyaPass;
    double senderInventory;
    double Inventory;
};

#endif // TREANFER_H
