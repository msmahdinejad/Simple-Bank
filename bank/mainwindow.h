#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MainLoginButton_clicked();

    void on_MainSignupButton_clicked();

    void on_LogInInSignUp_clicked();

    void on_SignUpnInLogIn_clicked();

    void on_LoginButton_clicked();

    void on_SignUpBotton_clicked();

private:
    bool checkLoginInputs();
    bool checkSigninInputs();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB;
};
#endif // MAINWINDOW_H
