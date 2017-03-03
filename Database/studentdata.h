#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QList>

#include "Storage/student.h"

class StudentData
{
  public:
    StudentData();
    bool updateStudent(Student* student);
    bool insertStudent(Student* student);
    Student* retrieveStudent(int id);
    QList<Student*> retrieveAllStudents();
};

#endif // STUDENTDATA_H
