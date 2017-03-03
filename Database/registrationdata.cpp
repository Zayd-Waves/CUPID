#include "registrationdata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

RegistrationData::RegistrationData()
{}

bool RegistrationData::updateRegistration(Registration* registration)
{
  QSqlQuery query;
  query.prepare("UPDATE registration SET "
                "studentId=:studentId, projectId=:projectId, date=:date "
                "WHERE id=:id;");

  query.bindValue(":studentId", registration->getStudentId());
  query.bindValue(":projectId", registration->getProjectId());
  query.bindValue(":date", dateToString(registration->getDate()));
  query.bindValue(":id", registration->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool RegistrationData::insertRegistration(Registration* registration)
{
  QSqlQuery query;
  query.prepare("INSERT INTO registration (studentId, projectId, date) "
                "VALUES (:studentId, :projectId, :date)");

  query.bindValue(":studentId", registration->getStudentId());
  query.bindValue(":projectId", registration->getProjectId());
  query.bindValue(":date", dateToString(registration->getDate()));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  registration->setId(assignedId);

  return true;
}

bool RegistrationData::deleteRegistration(Registration* registration)
{
  QSqlQuery query;
  query.prepare(QString("DELETE FROM registration WHERE id=%1").arg(registration->getId()));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return query.numRowsAffected() > 0;
}

Registration*RegistrationData::retrieveRegistration(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT studentId, projectId, date "
                  "FROM registration "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int studentId = query.value(0).toInt();
    int projectId = query.value(1).toInt();
    QDate date = stringToDate(query.value(2).toString());

    return new Registration(id, studentId, projectId, date);
  }

  return NULL;
}

QList<Registration*> RegistrationData::retrieveAllRegistrations()
{
  QSqlQuery query;
  query.prepare("SELECT id, studentId, projectId, date "
                "FROM registration");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<Registration*> registrations;
  while (query.next()) {
    int id = query.value(0).toInt();
    int studentId = query.value(1).toInt();
    int projectId = query.value(2).toInt();
    QDate date = stringToDate(query.value(3).toString());

    registrations.append(new Registration(id, studentId, projectId, date));
  }

  return registrations;
}

QString RegistrationData::dateToString(const QDate& date)
{
  return date.toString("yyyy-MM-dd");
}

QDate RegistrationData::stringToDate(const QString& date)
{
  return QDate::fromString(date, "yyyy-MM-dd");
}
