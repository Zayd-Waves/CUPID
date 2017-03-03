#ifndef PROFILEDETAILSFORM_H
#define PROFILEDETAILSFORM_H

#include <QFrame>
#include "Storage/profile.h"
#include "Storage/student.h"

namespace Ui {
class ProfileDetailsForm;
}

class StudentInputManager ;

class ProfileDetailsForm : public QFrame
{
    Q_OBJECT

public:
    explicit ProfileDetailsForm(StudentInputManager*, QWidget *parent = 0);
    void display(Student*);
    ~ProfileDetailsForm();

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::ProfileDetailsForm *ui;
    Student* student;
    StudentInputManager* studentInputManager;
};

#endif // PROFILEDETAILSFORM_H
