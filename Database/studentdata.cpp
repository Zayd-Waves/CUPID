#include "studentdata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

StudentData::StudentData()
{}

bool StudentData::updateStudent(Student* student)
{
  QSqlQuery query;
  query.prepare("UPDATE student SET "
                "profileId=:profileId, email=:email, studentNumber=:studentNumber, "
                "firstName=:firstName, lastName=:lastName WHERE id=:id;");

  query.bindValue(":profileId", student->getProfileId());
  query.bindValue(":email", student->getEmail());
  query.bindValue(":studentNumber", student->getStudentNumber());
  query.bindValue(":firstName", student->getFirstName());
  query.bindValue(":lastName", student->getLastName());
  query.bindValue(":id", student->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool StudentData::insertStudent(Student* student)
{
  QSqlQuery query;
  query.prepare("INSERT INTO student (profileId, email, studentNumber, firstName, lastName) "
                "VALUES (:profileId, :email, :studentNumber, :firstName, :lastName)");

  query.bindValue(":profileId", student->getProfileId());
  query.bindValue(":email", student->getEmail());
  query.bindValue(":studentNumber", student->getStudentNumber());
  query.bindValue(":firstName", student->getFirstName());
  query.bindValue(":lastName", student->getLastName());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  student->setId(assignedId);

  return true;
}

Student* StudentData::retrieveStudent(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT profileId, email, studentNumber, firstName, lastName "
                  "FROM student "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int profileId = query.value(0).toInt();
    QString email = query.value(1).toString();
    int studentNumber = query.value(2).toInt();
    QString firstName = query.value(3).toString();
    QString lastName = query.value(4).toString();

    return new Student(id, profileId, studentNumber, email,
                       firstName, lastName);
  }

  return NULL;
}

QList<Student*> StudentData::retrieveAllStudents()
{
  QSqlQuery query;
  query.prepare("SELECT id, profileId, email, studentNumber, firstName, lastName "
                "FROM student");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<Student*> students;
  while (query.next()) {
    int id = query.value(0).toInt();
    int profileId = query.value(1).toInt();
    QString email = query.value(2).toString();
    int studentNumber = query.value(3).toInt();
    QString firstName = query.value(4).toString();
    QString lastName = query.value(5).toString();

    students.append(new Student(id, profileId, studentNumber, email,
                                firstName, lastName));
  }

  return students;
}
