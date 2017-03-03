#include "administratordata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AdministratorData::AdministratorData()
{}

bool AdministratorData::updateAdministrator(Administrator* administrator)
{
  QSqlQuery query;
  query.prepare("UPDATE administrator SET "
                "algorithmConfigId=:algorithmConfigId, email=:email, firstName=:firstName, "
                "lastName=:lastName WHERE id=:id;");

  query.bindValue(":algorithmConfigId", administrator->getAlgorithmConfigurationId());
  query.bindValue(":email", administrator->getEmail());
  query.bindValue(":firstName", administrator->getFirstName());
  query.bindValue(":lastName", administrator->getLastName());
  query.bindValue(":id", administrator->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool AdministratorData::insertAdministrator(Administrator* administrator)
{
  QSqlQuery query;
  query.prepare("INSERT INTO administrator (algorithmConfigId, email, firstName, lastName) "
                "VALUES (:algorithmConfigId, :email, :firstName, :lastName)");

  query.bindValue(":algorithmConfigId", administrator->getAlgorithmConfigurationId());
  query.bindValue(":email", administrator->getEmail());
  query.bindValue(":firstName", administrator->getFirstName());
  query.bindValue(":lastName", administrator->getLastName());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  administrator->setId(assignedId);

  return true;
}

Administrator* AdministratorData::retrieveAdministrator(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT algorithmConfigId, email, firstName, lastName "
                  "FROM administrator "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int algorithmConfigId = query.value(0).toInt();
    QString email = query.value(1).toString();
    QString firstName = query.value(2).toString();
    QString lastName = query.value(3).toString();

    return new Administrator(id, email, firstName, lastName, algorithmConfigId);
  }

  return NULL;
}

QList<Administrator*> AdministratorData::retrieveAllAdministrators()
{
  QSqlQuery query;
  query.prepare("SELECT id, algorithmConfigId, email, firstName, lastName "
                "FROM administrator");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<Administrator*> administrators;
  while (query.next()) {
    int id = query.value(0).toInt();
    int algorithmConfigId = query.value(1).toInt();
    QString email = query.value(2).toString();
    QString firstName = query.value(3).toString();
    QString lastName = query.value(4).toString();

    administrators.append(new Administrator(id, email,
                                firstName, lastName, algorithmConfigId));
  }

  return administrators;
}
