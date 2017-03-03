#ifndef TEAM_H
#define TEAM_H

#include <QList>
#include <QMap>
#include "Storage/student.h"
#include "Storage/questionnaireanswer.h"

class Team
{
  public:
    Team(int teamSize);
    int getTeamSize() const;
    void setTeamSize(int value);
    bool addStudent(Student* student);
    bool addStudents(QList<Student*> newStudents);
    Student* getStudent(int studentId);
    QList<Student*> getAllStudents();
    float computeTeamCompatibility() const;
    int getStudentCompatibility(Student* s1, Student* s2);

  private:
    int teamSize;
    QList<Student*> students;
    mutable int teamCompatibilityCache;

    /* {student: {student: compatibility, student: compatibility, ...}, ...} */
    mutable QMap<Student*, QMap<Student*, int> > studentCompatibilities;

    int computeStudentCompatibility(const Student* student1, const Student* student2) const;
    bool answersMatch(const QuestionnaireAnswer* answer1,
                      const QuestionnaireAnswer* answer2) const;

};

#endif // TEAM_H
