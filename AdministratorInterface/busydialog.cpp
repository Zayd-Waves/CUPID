#include "busydialog.h"
#include "ui_busydialog.h"

BusyDialog::BusyDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::BusyDialog)
{
  ui->setupUi(this);
}

BusyDialog::~BusyDialog()
{
  delete ui;
}

void BusyDialog::show()
{
  this->setFixedSize(380, 110);
  QDialog::show();
}
