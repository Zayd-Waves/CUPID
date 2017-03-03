#ifndef ADMINOUTPUTMANAGER_H
#define ADMINOUTPUTMANAGER_H

#include "libs/event.h"
#include "libs/subscriber.h"

#include "Storage/project.h"
#include "Storage/profile.h"
#include "Storage/student.h"
#include "Storage/administrator.h"
#include "libs/event.h"
#include "libs/subscriber.h"
#include "Storage/storagemanager.h"
#include "AdministratorLogic/team.h"

#include "projectlistwindow.h"
#include "teamresultdialog.h"
#include "projecteditdialog.h"
#include "algorithmconfigurationeditdialog.h"
#include "busydialog.h"


class AdminOutputManager
{
public:
    AdminOutputManager();
    ~AdminOutputManager();

    void displayProjectList(Administrator* administrator);
    void setProjectList(QList<Project*>);

    void projectAdded(Project* project);
    void projectUpdated(Project* project);
    void projectDeleted(int projectId);
    void algorithmConfigurationUpdated(AlgorithmConfiguration* config);
    void teamsGenerated(QList<Team*> teams);

    ProjectListWindow* getProjectListWindow() const;
    void setProjectListWindow(ProjectListWindow* value);
    ProjectEditDialog* getProjectEditDialog() const;
    void setProjectEditDialog(ProjectEditDialog* value);
    TeamResultDialog* getTeamResultDialog() const;
    void setTeamResultDialog(TeamResultDialog* value);
    BusyDialog* getBusyDialog() const;
    void setBusyDialog(BusyDialog* value);
    AlgorithmConfigurationEditDialog* getAlgoEditDialog() const;
    void setAlgoEditDialog(AlgorithmConfigurationEditDialog* value);

  private :
    QList<Project*> projectList;
    Administrator* administrator;

    ProjectListWindow* projectListWindow;
    ProjectEditDialog* projectEditDialog;
    TeamResultDialog*  teamResultDialog;
    AlgorithmConfigurationEditDialog* algoEditDialog;
    BusyDialog* busyDialog;
};

#endif // ADMINOUTPUTMANAGER_H
