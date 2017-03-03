#ifndef AUTHENTICATIONDIALOG_H
#define AUTHENTICATIONDIALOG_H

#include <QMainWindow>
#include <QString>
#include <QObject>
#include "libs/event.h"
#include "libs/subscriber.h"


namespace Ui {
  class AuthenticationDialog;
}

class AuthenticationDialog : public QMainWindow
{
    Q_OBJECT

  public:
    explicit AuthenticationDialog(QWidget *parent = 0);
    ~AuthenticationDialog();
    void show();
    void showMessage(const QString& title, const QString& message);
    void subscribeToAdminAuthEvent(Subscriber* subscriber);
    void subscribeToStudentAuthEvent(Subscriber* subscriber);
    QString getAuthEmail();
    void closeInterface();

  private slots:
    void on_studentLogInButton_clicked();
    void on_adminLoginButton_clicked();
    void on_exitButton_clicked();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

  private:
    Ui::AuthenticationDialog *ui;
    Event* adminLoginEvent;
    Event* studentLoginEvent;
};

#endif // AUTHENTICATIONDIALOG_H
