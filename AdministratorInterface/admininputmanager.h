#ifndef ADMININPUTMANAGER_H
#define ADMININPUTMANAGER_H
#include "libs/event.h"
#include "libs/subscriber.h"

#include "Storage/project.h"
#include "Storage/administrator.h"
#include "libs/event.h"
#include "libs/subscriber.h"

#include "projectlistwindow.h"
#include "projecteditdialog.h"
#include "teamresultdialog.h"
#include "algorithmconfigurationeditdialog.h"
#include "busydialog.h"

class AdminInputManager
{

  public:
    AdminInputManager();
    ~AdminInputManager();
    void subscribeToCreateProjectEvent(Subscriber*);
    void subscribeToUpdateProjectEvent(Subscriber*);
    void subscribeToDeleteProjectEvent(Subscriber*);
    void subscribeToGenerateTeamsEvent(Subscriber*);
    void subscribeToSaveAlgorithmConfigEvent(Subscriber*);

    Project* getSelectedProject();
    Project* getProjectDetails();
    Administrator* getAdministrator();

    void createProject();
    void updateProject();
    void deleteProject();
    void generateTeams();
    void saveAlgorithmConfig();
    void displayProjectEditDialog(Project* project=0);
    void configureAlgorithm(AlgorithmConfiguration* algoConfig);

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

  private:
    ProjectListWindow* projectListWindow;
    ProjectEditDialog* projectEditDialog;
    TeamResultDialog* teamResultDialog;
    AlgorithmConfigurationEditDialog* algoEditDialog;
    BusyDialog* busyDialog;

    Event* createProjectEvent;
    Event* updateProjectEvent;
    Event* deleteProjectEvent;
    Event* generateTeamsEvent;
    Event* saveAlgorithmConfigEvent;
};

#endif // ADMININPUTMANAGER_H
