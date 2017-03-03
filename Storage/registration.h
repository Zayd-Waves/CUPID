#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDate>

class Student;
class Project;

class Registration
{
  public:
    Registration();
    Registration(const Registration& other);
    Registration(Student* student, Project* project);
    Registration(Student* student, Project* project, QDate& date);
    Registration(int studentId, int projectId);
    Registration(int id, Student* student, Project* project);
    Registration(int id, Student* student, Project* project, QDate& date);
    Registration(int id, int studentId, int projectId, QDate& date);
    Registration(int id, Student* student, int studentId,
                 Project* project, int projectId, QDate& date);

    int getId() const;
    void setId(int value);
    Student* getStudent() const;
    void setStudent(Student* value);
    int getStudentId() const;
    void setStudentId(int value);
    Project* getProject() const;
    void setProject(Project* value);
    int getProjectId() const;
    void setProjectId(int value);
    QDate getDate() const;
    void setDate(const QDate& value);

  private:
    int id;
    Student* student;
    int studentId;
    Project* project;
    int projectId;
    QDate date;
};

#endif // REGISTRATION_H
