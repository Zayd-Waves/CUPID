#include "algorithmconfigurationeditdialog.h"
#include "ui_algorithmconfigurationeditdialog.h"
#include "admininputmanager.h"

AlgorithmConfigurationEditDialog::AlgorithmConfigurationEditDialog(
    AdminInputManager* adminInputManager, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AlgorithmConfigurationEditDialog)
{
  this->adminInputManager = adminInputManager;
  ui->setupUi(this);
}

AlgorithmConfigurationEditDialog::~AlgorithmConfigurationEditDialog()
{
  delete ui;
}

void AlgorithmConfigurationEditDialog::show(AlgorithmConfiguration* algorithmConfig)
{
  this->algorithmConfig = algorithmConfig;

  if (algorithmConfig != NULL) {
    ui->groupSizeScroll->setValue(algorithmConfig->getTeamSize());
    ui->groupSizeSpinner->setValue(algorithmConfig->getTeamSize());
  }
  this->setFixedSize(275, 120);
  QDialog::show();
}

void AlgorithmConfigurationEditDialog::on_groupSizeSpinner_valueChanged(int value)
{
  ui->groupSizeScroll->setValue(value);
}

void AlgorithmConfigurationEditDialog::on_groupSizeScroll_valueChanged(int value)
{
  ui->groupSizeSpinner->setValue(value);
}

void AlgorithmConfigurationEditDialog::on_cancelButton_clicked()
{
  this->close();
}

void AlgorithmConfigurationEditDialog::on_saveButton_clicked()
{
  algorithmConfig->setTeamSize(ui->groupSizeSpinner->value());
  adminInputManager->saveAlgorithmConfig();
}
