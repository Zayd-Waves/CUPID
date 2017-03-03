#ifndef ProjectListWindow_H
#define ProjectListWindow_H

#include "Storage/administrator.h"
#include "Storage/project.h"
#include "Storage/project.h"
#include <QMainWindow>
#include <QList>

namespace Ui {
  class ProjectListWindow;
}

class AdminInputManager;

class ProjectListWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit ProjectListWindow(AdminInputManager* adminInputManager, QWidget *parent = 0);
    ~ProjectListWindow();
    void show(Administrator* admin, QList<Project*> projectList);
    void showMessage(const QString& title, const QString& message);
    void showCriticalMessage(const QString& title, const QString& message);
    Project* findSelectedProject() const;
    Administrator* getAdministrator() const;
    void addProject(Project* project);
    void updateProject(Project* project);
    void removeProject(int projectId);


  private slots:
    void on_createProjectButton_clicked();
    void on_editProjectButton_clicked();
    void on_deleteProjectButton_clicked();
    void on_generateTeamsButton_clicked();
    void on_configureAlgorithmButton_clicked();

    void on_actionCreate_Project_triggered();
    void on_actionEdit_Project_triggered();
    void on_actionDelete_Project_triggered();
    void on_actionGenerate_Teams_triggered();
    void on_actionExit_triggered();
    void on_actionConfigure_Algorithm_triggered();

    void on_projectTable_doubleClicked(const QModelIndex &index);

  private:
    Ui::ProjectListWindow *ui;
    Administrator* administrator;
    AdminInputManager* adminInputManager;
    QList<Project*> projectList;

    void addProjectToTable(Project* project);
    int findProjectRow(int);
    int findSelectedProjectId() const;
    void doCreateProject();
    void doEditProject();
    void doDeleteProject();
    void doGenerateTeams();
    void doConfigureAlgorithm();

};

#endif // ProjectListWindow_H
