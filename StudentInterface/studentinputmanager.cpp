#include "studentinputmanager.h"
#include "studentprojectlistwindow.h"
#include "profiledetailsform.h"
#include "QMessageBox"

StudentInputManager::StudentInputManager()
{
  registerForProjectEvent = new Event("registerForProject");
  deregisterFromProjectEvent = new Event("deregisterFromProject");
  updateProfileEvent = new Event("updateProfile");
}

StudentInputManager::~StudentInputManager()
{
  delete registerForProjectEvent;
  delete deregisterFromProjectEvent;
  delete updateProfileEvent;

  if (studentProjectListWindow) {
    delete studentProjectListWindow;
  }
  if (profileDetailsForm) {
    delete profileDetailsForm;
  }
}

void StudentInputManager::setProjectListView(StudentProjectListWindow * projectListView)
{
  studentProjectListWindow = projectListView;
}

void StudentInputManager::setProfileDetailsView(ProfileDetailsForm *profileDetailsView)
{
  profileDetailsForm = profileDetailsView;
}

void StudentInputManager::subscribeToRegisterForProjectEvent(Subscriber* s)
{
  registerForProjectEvent->subscribe(s);
}

void StudentInputManager::subscribeToDeregisterFromProjectEvent(Subscriber* s)
{
  deregisterFromProjectEvent->subscribe(s);
}

void StudentInputManager::subscribeToUpdateProfileEvent(Subscriber* s)
{
  updateProfileEvent->subscribe(s);
}

int StudentInputManager::getSelectedProject()
{
  return studentProjectListWindow->getSelectedProjectId();
}

Profile* StudentInputManager::getProfileDetails()
{
  return student->getProfile();
}

void StudentInputManager::displayProfileDetails()
{
  profileDetailsForm->display(this->student);
}

// Methods that the View will call when a Student user does any
// of these actions
void StudentInputManager::notifyOfRegisterEvent()
{
  registerForProjectEvent->notifySubscribers();
}

void StudentInputManager::notifyOfDeRegisterEvent()
{
  deregisterFromProjectEvent->notifySubscribers();
}

void StudentInputManager::notifyOfUpdateProfileEvent()
{
  updateProfileEvent->notifySubscribers();
}
//

void StudentInputManager::setStudent(Student *stud)
{
  this->student = stud;
}

Student* StudentInputManager::getStudent()
{
  return student;
}

void StudentInputManager::showMessage(const QString& title, const QString& message)
{
  studentProjectListWindow->showMessage(title, message);
}
