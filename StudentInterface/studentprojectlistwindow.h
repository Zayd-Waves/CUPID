#ifndef STUDENTPROJECTLISTWINDOW_H
#define STUDENTPROJECTLISTWINDOW_H

#include <QMainWindow>
#include "Storage/project.h"

namespace Ui {
class StudentProjectListWindow;
}

class StudentInputManager ;

class StudentProjectListWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentProjectListWindow(StudentInputManager*, QWidget *parent = 0);
    ~StudentProjectListWindow();
    void display(QList<Project*>);
    void updateRegistration(Registration*);
    void updateDeRegistration(int);
    int getSelectedProjectId();
    void showMessage(const QString&, const QString&);

private:
    Ui::StudentProjectListWindow *ui;
    void addProjectToTable(Project* p);
    StudentInputManager* studentInputManager;
    Student* student;
    void doRegister();
    void doDeRegister();
    void doEditProfile();
    int findProjectRow(int);
    int findSelectedProjectId();
    void onRegistrationAdded(Registration* newRegistration);
    void onRegistrationUpdated(Registration* updatedRegistration);
    void onRegistrationRemoved(Registration* removedRegistration);

private slots:
    void on_registerButton_clicked();
    void on_deregisterButton_clicked();
    void on_editProfileButton_clicked();
    void on_actionRegister_triggered();
    void on_actionDeregister_triggered();
    void on_actionExit_triggered();
    void on_actionEdit_Profile_triggered();
};

#endif // STUDENTPROJECTLISTWINDOW_H
