#ifndef STUDENTINPUTMANAGER_H
#define STUDENTINPUTMANAGER_H

#include "Storage/project.h"
#include "Storage/profile.h"
#include "Storage/student.h"
#include "libs/event.h"
#include "libs/subscriber.h"

class StudentProjectListWindow ;
class ProfileDetailsForm ;

class StudentInputManager
{
  public:
    StudentInputManager();
    ~StudentInputManager();
    void subscribeToRegisterForProjectEvent(Subscriber*);
    void subscribeToDeregisterFromProjectEvent(Subscriber*);
    void subscribeToUpdateProfileEvent(Subscriber*);
    int getSelectedProject();
    Profile* getProfileDetails();
    void setStudent(Student*);
    Student* getStudent();
    void showMessage(const QString&, const QString&);
    void setProjectListView(StudentProjectListWindow*);
    void setProfileDetailsView(ProfileDetailsForm*);

    // called only by the StudentProjectListView when a user clicks the edit profile button
    void displayProfileDetails();

    // Methods that the View will call when a Student user does any
    // of these actions
    void notifyOfRegisterEvent();
    void notifyOfDeRegisterEvent();
    void notifyOfUpdateProfileEvent();

  private:
    StudentProjectListWindow* studentProjectListWindow;
    ProfileDetailsForm* profileDetailsForm;
    Event* registerForProjectEvent;
    Event* deregisterFromProjectEvent;
    Event* updateProfileEvent;
    Student* student;

};

#endif // STUDENTINPUTMANAGER_H
