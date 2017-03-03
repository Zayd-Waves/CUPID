#include "projecteditdialog.h"
#include "ui_projecteditdialog.h"
#include "admininputmanager.h"

ProjectEditDialog::ProjectEditDialog(AdminInputManager* adminInputManager, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ProjectEditDialog)
{
  ui->setupUi(this);
  this->adminInputManager = adminInputManager;
  this->project = NULL;
}

ProjectEditDialog::~ProjectEditDialog()
{
  delete ui;
}

void ProjectEditDialog::show()
{
  ui->titleText->setText("");
  ui->courseCode->setText("");
  ui->descriptionText->document()->setPlainText("");
  ui->maxStudentsSpinner->setMinimum(1);
  ui->maxStudentsSpinner->setValue(1);
  this->project = NULL;
  QDialog::show();
}

void ProjectEditDialog::showEdit(Project* project)
{
  this->project = project;
  ui->titleText->setText(project->getTitle());
  ui->courseCode->setText(project->getCourseCode());
  ui->descriptionText->document()->setPlainText(project->getDescription());
  ui->maxStudentsSpinner->setValue(project->getMaxNumberOfRegistrations());

  // the max number of students cannot be less than the number
  // of students currently registered in the project
  ui->maxStudentsSpinner->setMinimum(project->getCurrentNumberOfRegistrations());

  QDialog::show();
}

Project* ProjectEditDialog::getProject()
{
  QString title = ui->titleText->text();
  QString courseCode = ui->courseCode->text();
  QString description = ui->descriptionText->document()->toPlainText();
  int maxStudents = ui->maxStudentsSpinner->value();

  if (this->project == NULL) {
    this->project = new Project(title, courseCode, description, maxStudents);
  } else {
    this->project->setTitle(title);
    this->project->setCourseCode(courseCode);
    this->project->setDescription(description);
    this->project->setMaxNumberOfRegistrations(maxStudents);
  }
  return this->project;
}


void ProjectEditDialog::on_cancelButton_clicked()
{
  this->close();
}

void ProjectEditDialog::on_saveButton_clicked()
{
  if (this->project == NULL) {
    adminInputManager->createProject();
  } else {
    adminInputManager->updateProject();
  }
}
