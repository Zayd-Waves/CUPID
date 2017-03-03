#include "projectuserinputcontrol.h"
#include <QDebug>


ProjectUserInputControl::ProjectUserInputControl(StudentInputManager* studentInputManager,
                                                 AdminInputManager* adminInputManager,
                                                 ProjectControl* projectControl,
                                                 RegistrationControl* registrationControl) :
  Subscriber()
{
  this->studentInputManager = studentInputManager;
  this->adminInputManager = adminInputManager;
  this->projectControl = projectControl;
  this->registrationControl = registrationControl;

  /* subscribe to events */
  studentInputManager->subscribeToRegisterForProjectEvent(this);
  studentInputManager->subscribeToDeregisterFromProjectEvent(this);

  adminInputManager->subscribeToCreateProjectEvent(this);
  adminInputManager->subscribeToUpdateProjectEvent(this);
  adminInputManager->subscribeToDeleteProjectEvent(this);
}

ProjectUserInputControl::~ProjectUserInputControl()
{
  delete studentInputManager;
  delete adminInputManager;
  delete projectControl;
  delete registrationControl;
}

void ProjectUserInputControl::notify(Event* event)
{
  QString eventName = event->getName();
  if (eventName == "registerForProject") {
    registerForProject();
  } else if (eventName == "deregisterFromProject") {
    deregisterFromProject();
  } else if (eventName == "createProject") {
    createProject();
  } else if (eventName == "updateProject") {
    updateProject();
  } else if (eventName == "deleteProject") {
    deleteProject();
  } else {
    qDebug() << "ProjectUserInputControl: Unknown event" << event->getName();
  }
}

void ProjectUserInputControl::registerForProject()
{
  int projectId = studentInputManager->getSelectedProject();
  if (projectId < 0) {
    return;
  }

  Project* project = projectControl->get(projectId);
  Student* student = studentInputManager->getStudent();
  if(student->isRegisteredIn(project)) {
    studentInputManager->showMessage("Already registered",
                                     "You cannot register for a project you're already registered in!");
    return;
  }

  registrationControl->addRegistration(project, student);
}


void ProjectUserInputControl::deregisterFromProject()
{
  int projectId = studentInputManager->getSelectedProject();
  if (projectId < 0) {
    return;
  }

  Project* project = projectControl->get(projectId);
  Student* student = studentInputManager->getStudent();

  Registration *r;
  QList<Registration*> studentRegistrations = student->getAllRegistrations();
  for(int i = 0; i < studentRegistrations.size(); i++){
      if(studentRegistrations.at(i)->getProjectId() == projectId) {
          r = studentRegistrations.at(i);
      }
  }
  if(!(student->isRegisteredIn(project))) {
    studentInputManager->showMessage("Already not registered",
                                     "You cannot de-register from a project you're not registered for.");
    return;
  }
  registrationControl->removeRegistration(r);
}


void ProjectUserInputControl::createProject()
{
  Project* project = adminInputManager->getProjectDetails();
  if (!project) {
    return;
  }
  projectControl->addProject(project);
}

void ProjectUserInputControl::updateProject()
{
  Project* project = adminInputManager->getProjectDetails();
  if (!project) {
    return;
  }
  projectControl->updateProject(project);
}

void ProjectUserInputControl::deleteProject()
{
  Project* project = adminInputManager->getSelectedProject();
  if (!project) {
    return;
  }
  projectControl->removeProject(project);
}


