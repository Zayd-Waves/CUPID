#include "projectlistwindow.h"
#include "ui_projectlistwindow.h"
#include "admininputmanager.h"
#include <QMessageBox>

ProjectListWindow::ProjectListWindow(AdminInputManager* adminInputManager, QWidget *parent) :
  QMainWindow(parent), ui(new Ui::ProjectListWindow)
{
  this->adminInputManager = adminInputManager,
      ui->setupUi(this);
}


ProjectListWindow::~ProjectListWindow()
{
  delete ui;
}

void ProjectListWindow::show(Administrator* administrator, QList<Project*> projectList)
{
  this->administrator = administrator;
  this->projectList.clear();
  this->projectList.append(projectList);

  // set up the table
  QStringList columnTitles;
  columnTitles << "Id" << "Title" << "Course" << "Description" << "Registration Count";

  ui->projectTable->setColumnCount(5);
  ui->projectTable->setHorizontalHeaderLabels(columnTitles);
  ui->projectTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  ui->projectTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->projectTable->setShowGrid(true);
  ui->projectTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  ui->projectTable->horizontalHeader()->setStretchLastSection(true);
  ui->projectTable->verticalHeader()->hide();


  QList<Project*>::const_iterator iter;

  for (iter = projectList.begin(); iter != projectList.end(); ++iter) {
    Project* p = *iter;
    addProjectToTable(p);
  }

  QMainWindow::show();
}

void ProjectListWindow::showMessage(const QString& title, const QString& message)
{
  QMessageBox::information(this, title, message);
}

void ProjectListWindow::showCriticalMessage(const QString& title, const QString& message)
{
  QMessageBox::critical(this, title, message);
}

/*
 * UI Listeners
 */

void ProjectListWindow::on_createProjectButton_clicked()
{
  doCreateProject();
}

void ProjectListWindow::on_editProjectButton_clicked()
{
  doEditProject();
}

void ProjectListWindow::on_deleteProjectButton_clicked()
{
  doDeleteProject();
}

void ProjectListWindow::on_generateTeamsButton_clicked()
{
  doGenerateTeams();
}

void ProjectListWindow::on_configureAlgorithmButton_clicked()
{
  doConfigureAlgorithm();
}

void ProjectListWindow::on_projectTable_doubleClicked(const QModelIndex &index)
{
  if (index.row() >= 0) {
    doEditProject();
  }
}

void ProjectListWindow::on_actionCreate_Project_triggered()
{
  doCreateProject();
}

void ProjectListWindow::on_actionEdit_Project_triggered()
{
  doEditProject();
}

void ProjectListWindow::on_actionDelete_Project_triggered()
{
  doDeleteProject();
}

void ProjectListWindow::on_actionGenerate_Teams_triggered()
{
  doGenerateTeams();
}

void ProjectListWindow::on_actionExit_triggered()
{
  QMessageBox::StandardButton ret = QMessageBox::question(
        this, "Exit?", "Are you sure you want to exit?",
        QMessageBox::Yes | QMessageBox::No);

  if (ret == QMessageBox::Yes) {
    this->close();
  }
}

void ProjectListWindow::on_actionConfigure_Algorithm_triggered()
{
  doConfigureAlgorithm();
}


/*
 * Helper functions
*/

void ProjectListWindow::doCreateProject()
{
  adminInputManager->displayProjectEditDialog();
}

void ProjectListWindow::doEditProject()
{
  Project* project = findSelectedProject();
  if (!project) {
    this->showMessage("No project selected!", "Please select a project first.");
    return;
  }

  adminInputManager->displayProjectEditDialog(project);
}

void ProjectListWindow::doDeleteProject()
{
  int projectId = findSelectedProjectId();
  if (projectId < 0) {
    this->showMessage("No project selected!", "Please select a project first.");
    return;
  }

  QMessageBox::StandardButton ret = QMessageBox::question(
        this, "Delete?", "Are you sure you want to delete this project?",
        QMessageBox::Yes | QMessageBox::No);

  if (ret == QMessageBox::Yes) {
    adminInputManager->deleteProject();
  }
}

void ProjectListWindow::doGenerateTeams()
{
  int projectId = findSelectedProjectId();
  if (projectId < 0) {
    this->showMessage("No project selected!", "Please select a project first.");
    return;
  }

  adminInputManager->generateTeams();
}

void ProjectListWindow::doConfigureAlgorithm()
{
  adminInputManager->configureAlgorithm(administrator->getAlgorithmConfiguration());
}

void ProjectListWindow::addProjectToTable(Project* p)
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
  int numRegistrations = p->getCurrentNumberOfRegistrations();
  registeredItem->setText(QString::number(numRegistrations));

  ui->projectTable->setItem(row, 4, registeredItem);
}

int ProjectListWindow::findProjectRow(int projectId)
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

int ProjectListWindow::findSelectedProjectId() const
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

Project* ProjectListWindow::findSelectedProject() const
{
  int id = findSelectedProjectId();

  if (id < 0) {
    return NULL;
  }

  foreach (Project* p, projectList) {
    if (p->getId() == id) {
      return p;
    }
  }

  return NULL;
}

Administrator* ProjectListWindow::getAdministrator() const
{
  return administrator;
}

void ProjectListWindow::addProject(Project* project)
{
  projectList.append(project);
  addProjectToTable(project);
}

void ProjectListWindow::updateProject(Project* project)
{
  int row = findProjectRow(project->getId());
  if(row < 0) {
    return;
  }

  QTableWidgetItem* idItem = ui->projectTable->item(row, 0);
  idItem->setText(QString::number(project->getId()));

  QTableWidgetItem* title = ui->projectTable->item(row, 1);
  title->setText(project->getTitle());

  QTableWidgetItem* code = ui->projectTable->item(row, 2);
  code->setText(project->getCourseCode());

  QTableWidgetItem* desc = ui->projectTable->item(row, 3);
  desc->setText(project->getDescription());

  QTableWidgetItem* registrationCount = ui->projectTable->item(row, 4);
  registrationCount->setText(QString::number(project->getCurrentNumberOfRegistrations()));
}
#include <QDebug>
void ProjectListWindow::removeProject(int projectId)
{
  int row = findProjectRow(projectId);
  if (row < 0) {
    return;
  }
  qDebug() << row;
  projectList.removeAt(row);
  ui->projectTable->removeRow(row);
}

