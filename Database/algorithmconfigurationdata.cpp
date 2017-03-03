#include "algorithmconfigurationdata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

AlgorithmConfigurationData::AlgorithmConfigurationData()
{}

bool AlgorithmConfigurationData::updateAlgorithmConfiguration(AlgorithmConfiguration* ac)
{
  QSqlQuery query;
  query.prepare("UPDATE algorithmConfig SET "
                "teamSize=:teamSize WHERE id=:id;");

  query.bindValue(":teamSize", ac->getTeamSize());
  query.bindValue(":id", ac->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool AlgorithmConfigurationData::insertAlgorithmConfiguration(AlgorithmConfiguration* ac)
{
  QSqlQuery query;
  query.prepare("INSERT INTO algorithmConfig (teamSize) "
                "VALUES (:teamSize)");

  query.bindValue(":teamSize", ac->getTeamSize());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  ac->setId(assignedId);

  return true;
}

AlgorithmConfiguration* AlgorithmConfigurationData::retrieveAlgorithmConfiguration(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT teamSize "
                  "FROM algorithmConfig "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int teamSize = query.value(0).toInt();
    return new AlgorithmConfiguration(id, teamSize);
  }

  return NULL;
}

QList<AlgorithmConfiguration*> AlgorithmConfigurationData::retrieveAllAlgorithmConfigurations()
{
  QSqlQuery query;
  query.prepare("SELECT id, teamSize "
                "FROM algorithmConfig");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<AlgorithmConfiguration*> acs;
  while (query.next()) {
    int id = query.value(0).toInt();
    int teamSize = query.value(1).toInt();

    acs.append(new AlgorithmConfiguration(id, teamSize));
  }

  return acs;
}
