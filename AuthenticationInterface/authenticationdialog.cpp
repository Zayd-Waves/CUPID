#include "authenticationdialog.h"
#include "ui_authenticationdialog.h"
#include <QMessageBox>
#include <QString>

AuthenticationDialog::AuthenticationDialog(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::AuthenticationDialog)
{
  ui->setupUi(this);
  adminLoginEvent = new Event("adminLogin");
  studentLoginEvent = new Event("studentLogin");
}

AuthenticationDialog::~AuthenticationDialog()
{
  delete ui;
  delete adminLoginEvent;
  delete studentLoginEvent;
}

void AuthenticationDialog::show()
{
  this->setFixedSize(540, 180);
  QMainWindow::show();
}

void AuthenticationDialog::showMessage(const QString& title, const QString& message)
{
  QMessageBox::information(this, title, message);
}

void AuthenticationDialog::subscribeToAdminAuthEvent(Subscriber* subscriber)
{
  adminLoginEvent->subscribe(subscriber);
}

void AuthenticationDialog::subscribeToStudentAuthEvent(Subscriber* subscriber)
{
  studentLoginEvent->subscribe(subscriber);
}

QString AuthenticationDialog::getAuthEmail()
{
  return ui->emailText->text();
}

void AuthenticationDialog::closeInterface()
{
  this->close();
}

void AuthenticationDialog::on_studentLogInButton_clicked()
{
  QString email = ui->emailText->text();
  if (email.length() < 1) {
    QMessageBox::warning(this, "Error",
                         "Please enter an Email address.");
    return;
  }
  studentLoginEvent->notifySubscribers();
}

void AuthenticationDialog::on_adminLoginButton_clicked()
{
  QString email = ui->emailText->text();
  if (email.length() < 1) {
    QMessageBox::warning(this, "Error",
                         "Please enter an Email address.");
    return;
  }
  adminLoginEvent->notifySubscribers();
}

void AuthenticationDialog::on_actionAbout_triggered()
{
  QMessageBox::about(this, "About cuPID", "The cuPID system will generate teams of students for projects based on questionnaires.");
}

void AuthenticationDialog::on_actionExit_triggered()
{
  this->close();
}

void AuthenticationDialog::on_exitButton_clicked()
{
  this->close();
}
