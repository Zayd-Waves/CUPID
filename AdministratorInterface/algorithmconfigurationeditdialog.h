#ifndef ALGORITHMCONFIGURATIONEDITDIALOG_H
#define ALGORITHMCONFIGURATIONEDITDIALOG_H

#include <QDialog>
#include "Storage/algorithmconfiguration.h"

namespace Ui {
  class AlgorithmConfigurationEditDialog;
}

class AdminInputManager;

class AlgorithmConfigurationEditDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit AlgorithmConfigurationEditDialog(
        AdminInputManager* adminInputManager, QWidget *parent = 0);
    ~AlgorithmConfigurationEditDialog();
    void show(AlgorithmConfiguration* algorithmConfig);

  private slots:
    void on_groupSizeSpinner_valueChanged(int value);
    void on_groupSizeScroll_valueChanged(int value);
    void on_cancelButton_clicked();
    void on_saveButton_clicked();

  private:
    Ui::AlgorithmConfigurationEditDialog *ui;
    AdminInputManager* adminInputManager;
    AlgorithmConfiguration* algorithmConfig;

};

#endif // ALGORITHMCONFIGURATIONEDITDIALOG_H
