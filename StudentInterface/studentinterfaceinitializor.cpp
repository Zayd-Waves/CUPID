#include "studentinterfaceinitializor.h"

StudentInterfaceInitializor::StudentInterfaceInitializor()
{
  this->studentInputManager = NULL;
  this->studentOutputManager = NULL;
}

StudentInterfaceInitializor::~StudentInterfaceInitializor()
{
  if (studentInputManager) {
    delete studentInputManager;
  }
  if (studentOutputManager) {
    delete studentOutputManager;
  }
}

void StudentInterfaceInitializor::initialize()
{
  if (!this->studentInputManager) {
    this->studentInputManager = new StudentInputManager();
  }

  StudentProjectListWindow* projectListWindow = new StudentProjectListWindow(this->studentInputManager);
  ProfileDetailsForm* profileDetailsForm = new ProfileDetailsForm(this->studentInputManager);

  this->studentInputManager->setProjectListView(projectListWindow);
  this->studentInputManager->setProfileDetailsView(profileDetailsForm);

  if (!this->studentOutputManager) {
    this->studentOutputManager = new StudentOutputManager(projectListWindow, profileDetailsForm);
  }
}

StudentInputManager* StudentInterfaceInitializor::getStudentInputManager() const
{
  return studentInputManager;
}

StudentOutputManager* StudentInterfaceInitializor::getStudentOutputManager() const
{
  return studentOutputManager;
}
