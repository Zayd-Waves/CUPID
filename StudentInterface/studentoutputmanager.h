#ifndef STUDENTOUTPUTMANAGER_H
#define STUDENTOUTPUTMANAGER_H

#include "Storage/profile.h"
#include "Storage/project.h"
#include "profiledetailsform.h"
#include "studentprojectlistwindow.h"

class StudentOutputManager
{
public:
    StudentOutputManager(StudentProjectListWindow*, ProfileDetailsForm*);
    ~StudentOutputManager();
    void setProjectList(QList<Project*>);
    void setStudent(Student*);
    void displayProjectList();
    void displayProfileDetails(Student*);
    void registrationHasAdded(Registration*);
    void registrationHasRemoved(int);

private:
    StudentProjectListWindow *studentProjectWindow;
    ProfileDetailsForm *profileDetailsForm;
    QList<Project*> projects;
    Student* student;

};

#endif // STUDENTOUTPUTMANAGER_H
