#include "team.h"
#include "Storage/profile.h"

Team::Team(int teamSize)
{
  this->teamSize = teamSize;
  this->teamCompatibilityCache = -1;
}

bool Team::addStudent(Student* student)
{
  if (students.size() == teamSize) {
    return false;
  }
  students.append(student);
  teamCompatibilityCache = -1;
  return true;
}

bool Team::addStudents(QList<Student*> newStudents)
{
  if (students.size() + newStudents.size() > teamSize) {
    return false;
  }
  students.append(newStudents);
  teamCompatibilityCache = -1;
  return true;
}

Student* Team::getStudent(int studentId)
{
  foreach (Student* stu, students) {
    if (stu->getId() == studentId) {
      return stu;
    }
  }
  return NULL;
}

QList<Student*> Team::getAllStudents()
{
  return students;
}

float Team::computeTeamCompatibility() const
{
  /* prevent division by zero */
  if (students.size() <= 0) {
    return 0;
  }

  if (teamCompatibilityCache >= 0) {
    return teamCompatibilityCache / students.size();
  }

  int groupCompatibilityTotal = 0;

  QList<Student*>::const_iterator iter;
  for (iter = students.begin(); iter != students.end(); ++iter) {

    QList<Student*>::const_iterator iter2;
    for (iter2 = students.begin(); iter2 != students.end(); ++iter2) {
      if (*iter == *iter2) continue;

      /* did we already compute the compatibility using the other student (iter2) */
      if (studentCompatibilities.contains(*iter2) &&
          studentCompatibilities[*iter2].contains(*iter)) {
        int compVal = studentCompatibilities[*iter2][*iter];
        studentCompatibilities[*iter].insert(*iter2, compVal);
        continue;
      }

      int compatibility = computeStudentCompatibility(*iter, *iter2);
      studentCompatibilities[*iter].insert(*iter2, compatibility);

      groupCompatibilityTotal += compatibility;
    }
  }

  teamCompatibilityCache = groupCompatibilityTotal;
  return (groupCompatibilityTotal / students.size());
}

int Team::getStudentCompatibility(Student* s1, Student* s2)
{
  return studentCompatibilities[s1][s2];
}

int Team::getTeamSize() const
{
  return teamSize;
}

void Team::setTeamSize(int value)
{
  teamSize = value;
}


int Team::computeStudentCompatibility(const Student* student1,
                                      const Student* student2) const
{
  int compatibility = 0;
  Profile* s1Profile = student1->getProfile();
  Profile* s2Profile = student2->getProfile();

  foreach (QuestionnaireAnswer* s1Answer, s1Profile->getAllAnswers()) {
    QuestionnaireAnswer* s2Answer = s2Profile->getAnswer(s1Answer->getQuestionNumber());
    if (!s2Answer) {
      continue;
    }

    if (answersMatch(s1Answer, s2Answer)) {
      compatibility++;
    }
    if (answersMatch(s2Answer, s1Answer)) {
      compatibility++;
    }
  }
  return compatibility;
}

bool Team::answersMatch(const QuestionnaireAnswer* answer1,
                        const QuestionnaireAnswer* answer2) const
{
  if (answer1->getGroupAnswer1Selected() && answer2->getOwnAnswer1Selected()) {
    return true;
  }
  if (answer1->getGroupAnswer2Selected() && answer2->getOwnAnswer2Selected()) {
    return true;
  }
  if (answer1->getGroupAnswer3Selected() && answer2->getOwnAnswer3Selected()) {
    return true;
  }
  if (answer1->getGroupAnswer4Selected() && answer2->getOwnAnswer4Selected()) {
    return true;
  }

  return false;
}
