#ifndef TEAMRESULTDIALOG_H
#define TEAMRESULTDIALOG_H

#include <QDialog>
#include <QList>
#include "AdministratorLogic/team.h"

namespace Ui {
  class TeamResultDialog;
}

class TeamResultDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit TeamResultDialog(QWidget *parent = 0);
    ~TeamResultDialog();
    void show(QList<Team*> teams);

  private slots:
    void on_closeButton_clicked();
    void on_showDetailsCheck_toggled(bool checked);

  private:
    Ui::TeamResultDialog *ui;
    QList<Team*> teams;
    void showResult();
    void showDetailedResult();
};

#endif // TEAMRESULTDIALOG_H
