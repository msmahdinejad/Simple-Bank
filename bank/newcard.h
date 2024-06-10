#ifndef NEWCARD_H
#define NEWCARD_H

#include <QMainWindow>
#include "user.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <chrono>
#include "cardwidget.h"

namespace Ui {
class newCard;
}

class newCard : public QMainWindow
{
    Q_OBJECT

public:
    explicit newCard(user * user, cardWidget * Parent, QWidget *parent = nullptr);
    ~newCard();
    bool checkInputs();

private slots:
    void on_pushButton_2_clicked();

signals:
    void signalToB();

private:
    void sendSignalToB() {
        emit signalToB();
    }

private:
    // تابعی برای تولید شناسه یکتا بر اساس زمان سیستم
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
    std::string getYear(const std::tm& date) {
        return std::to_string(date.tm_year + 1900 + 3); // tm_year represents years since 1900
    }

    std::string getMonth(const std::tm& date) {
        return std::to_string(date.tm_mon + 1); // tm_mon is 0-based, so add 1
    }

    std::string getDay(const std::tm& date) {
        return std::to_string(date.tm_mday);
    }
    Ui::newCard *ui;
    user * myUser;
    cardWidget * Parent;
};

#endif // NEWCARD_H
