#include "studentprojectlistwindow.h"
#include "ui_studentprojectlistwindow.h"
#include "studentinputmanager.h"
#include <QMessageBox>

StudentProjectListWindow::StudentProjectListWindow(StudentInputManager* sim, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::StudentProjectListWindow)
{
  ui->setupUi(this);
  studentInputManager = sim;
}

StudentProjectListWindow::~StudentProjectListWindow()
{
  delete ui;
}

void StudentProjectListWindow::display(QList<Project *> projects)
{
  // set up the table
  QStringList columnTitles;
  columnTitles << "Id" << "Title" << "Course" << "Description" << "Registered";
  ui->projectTable->setColumnCount(5);
  ui->projectTable->setHorizontalHeaderLabels(columnTitles);
  ui->projectTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->projectTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->projectTable->setShowGrid(true);
  ui->projectTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  ui->projectTable->horizontalHeader()->setStretchLastSection(true);
  ui->projectTable->verticalHeader()->hide();

  QList<Project*>::const_iterator iter;

  for (iter = projects.begin(); iter != projects.end(); ++iter) {
    Project* p = *iter;
    addProjectToTable(p);
  }

  QMainWindow::show();
}

void StudentProjectListWindow::addProjectToTable(Project *p)
{
  int row = ui->projectTable->rowCount();

  ui->projectTable->insertRow(row);

  QTableWidgetItem* idItem = new QTableWidgetItem();
  idItem->setText(QString::number(p->getId()));
  ui->projectTable->setItem(row, 0, idItem);

  QTableWidgetItem* titleItem = new QTableWidgetItem();
  titleItem->setText(p->getTitle());
  ui->projectTable->setItem(row, 1, titleItem);

  QTableWidgetItem* courseItem = new QTableWidgetItem();
  courseItem->setText(p->getCourseCode());
  ui->projectTable->setItem(row, 2, courseItem);

  QTableWidgetItem* descriptionItem = new QTableWidgetItem();
  descriptionItem->setText(p->getDescription());
  ui->projectTable->setItem(row, 3, descriptionItem);

  QTableWidgetItem* registeredItem = new QTableWidgetItem();
  Student* currentStudent = studentInputManager->getStudent();

  if (currentStudent->isRegisteredIn(p)) {
    QList<Registration*> registrations = currentStudent->getAllRegistrations();
    for(int i = 0; i < registrations.size(); i++)  {
      if (registrations.at(i)->getProjectId() == p->getId()) {
        Registration* r = registrations.at(i);
        registeredItem->setText(r->getDate().toString());
        registeredItem->setBackgroundColor("#B6DE90");
        break;
      }
    }
  } else {
    registeredItem->setText("No");
  }
  ui->projectTable->setItem(row, 4, registeredItem);

}

void StudentProjectListWindow::updateRegistration(Registration* newRegistration)
{
  int row = findProjectRow(newRegistration->getProjectId());
  if (row < 0) {
    return;
  }

  QTableWidgetItem* registrationItem = ui->projectTable->item(row, 4);
  registrationItem->setBackgroundColor("#B6DE90");
  registrationItem->setText(newRegistration->getDate().toString());
}

void StudentProjectListWindow::updateDeRegistration(int projectId)
{
  int row = findProjectRow(projectId);
  if (row < 0) {
    return;
  }

  QTableWidgetItem* registrationItem = ui->projectTable->item(row, 4);
  registrationItem->setBackgroundColor(Qt::white);
  registrationItem->setText("No");
}

int StudentProjectListWindow::getSelectedProjectId()
{
  return findSelectedProjectId();
}

void StudentProjectListWindow::on_registerButton_clicked()
{
  doRegister();
}

void StudentProjectListWindow::on_deregisterButton_clicked()
{
  doDeRegister();
}

void StudentProjectListWindow::on_editProfileButton_clicked()
{
  doEditProfile();
}

void StudentProjectListWindow::on_actionRegister_triggered()
{
  doRegister();
}

void StudentProjectListWindow::on_actionDeregister_triggered()
{
  doDeRegister();
}

void StudentProjectListWindow::on_actionExit_triggered()
{
  QMessageBox::StandardButton ret = QMessageBox::question(
        this, "Exit?", "Are you sure you want to exit?",
        QMessageBox::Yes | QMessageBox::No);

  if (ret == QMessageBox::Yes) {
    this->close();
  }
}

void StudentProjectListWindow::on_actionEdit_Profile_triggered()
{
  doEditProfile();
}

void StudentProjectListWindow::doRegister()
{
  int projectId = findSelectedProjectId();
  if (projectId < 0) {
    showMessage("No Project selected", "Please select a project first.");
    return;
  }
  studentInputManager->notifyOfRegisterEvent();
}

void StudentProjectListWindow::doDeRegister()
{
  int projectId = findSelectedProjectId();
  if (projectId < 0) {
    showMessage("No Project selected", "Please select a project first.");
    return;
  }
  studentInputManager->notifyOfDeRegisterEvent();
}

void StudentProjectListWindow::doEditProfile()
{
  studentInputManager->displayProfileDetails();
}

int StudentProjectListWindow::findProjectRow(int projectId)
{
  int rowCount = ui->projectTable->rowCount();

  for (int i = 0; i < rowCount; i++) {
    QTableWidgetItem* idItem = ui->projectTable->item(i, 0);
    QString idStr = idItem->text();
    bool ok;
    int rowProjectId = idStr.toInt(&ok, 10);
    if (!ok) {
      continue;
    }

    if (rowProjectId == projectId) {
      return i;
    }
  }

  return -1;
}

int StudentProjectListWindow::findSelectedProjectId()
{
  QItemSelectionModel* selection = ui->projectTable->selectionModel();

  if (!selection->hasSelection()) {
    return -1;
  }
  int selectedRow = selection->currentIndex().row();
  QTableWidgetItem* idItem = ui->projectTable->item(selectedRow, 0);

  QString idStr = idItem->text();
  bool ok;
  int projectId = idStr.toInt(&ok, 10);
  if (!ok) {
    return -1;
  }
  return projectId;
}

void StudentProjectListWindow::onRegistrationAdded(Registration* newRegistration)
{
  int row = findProjectRow(newRegistration->getProjectId());
  if (row < 0) {
    return;
  }

  QTableWidgetItem* registrationItem = ui->projectTable->item(row, 4);
  registrationItem->setBackgroundColor("#B6DE90");
  registrationItem->setText(newRegistration->getDate().toString());
}

void StudentProjectListWindow::onRegistrationUpdated(Registration* updatedRegistration)
{
  int row = findProjectRow(updatedRegistration->getProjectId());
  if (row < 0) {
    return;
  }

  QTableWidgetItem* registrationItem = ui->projectTable->item(row, 4);
  registrationItem->setBackgroundColor("#B6DE90");
  registrationItem->setText(updatedRegistration->getDate().toString());
}

void StudentProjectListWindow::onRegistrationRemoved(Registration* removedRegistration)
{
  int row = findProjectRow(removedRegistration->getProjectId());
  if (row < 0) {
    return;
  }

  QTableWidgetItem* registrationItem = ui->projectTable->item(row, 4);
  registrationItem->setBackgroundColor(Qt::white);
  registrationItem->setText("No");
}

void StudentProjectListWindow::showMessage(const QString & title , const QString & message)
{
  QMessageBox::information(this, title, message);
}


