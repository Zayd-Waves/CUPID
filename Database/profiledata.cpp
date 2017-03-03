#include "profiledata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

ProfileData::ProfileData()
{}

bool ProfileData::updateProfile(Profile* profile)
{
  QSqlQuery query;
  query.prepare("UPDATE profile SET id=:ida WHERE id=:idb;");
  query.bindValue(":ida", profile->getId());
  query.bindValue(":idb", profile->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool ProfileData::insertProfile(Profile* profile)
{
  QSqlQuery query;
  query.prepare("INSERT INTO profile VALUES (NULL)");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  profile->setId(assignedId);

  return true;
}

Profile* ProfileData::retrieveProfile(int id)
{
  QSqlQuery query;
  query.prepare(QString("SELECT id FROM profile WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int id = query.value(0).toInt();

    return new Profile(id);
  }

  return NULL;
}


QList<Profile*> ProfileData::retrieveAllProfiles()
{
  QSqlQuery query;
  query.prepare("SELECT id FROM profile");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<Profile*> profiles;
  while (query.next()) {
    int id = query.value(0).toInt();
    profiles.append(new Profile(id));
  }

  return profiles;
}

