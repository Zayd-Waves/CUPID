#include "projectdata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

ProjectData::ProjectData()
{}

bool ProjectData::updateProject(Project* project)
{
  QSqlQuery query;
  query.prepare("UPDATE project SET "
                "title=:title, courseCode=:courseCode, description=:description, "
                "maxNumberRegistrations=:maxNumberRegistrations "
                "WHERE id=:id;");

  query.bindValue(":title", project->getTitle());
  query.bindValue(":courseCode", project->getCourseCode());
  query.bindValue(":description", project->getDescription());
  query.bindValue(":maxNumberRegistrations", project->getMaxNumberOfRegistrations());
  query.bindValue(":id", project->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool ProjectData::insertProject(Project* project)
{
  QSqlQuery query;
  query.prepare("INSERT INTO project (title, courseCode, description, maxNumberRegistrations) "
                "VALUES (:title, :courseCode, :description, :maxNumberRegistrations)");

  query.bindValue(":title", project->getTitle());
  query.bindValue(":courseCode", project->getCourseCode());
  query.bindValue(":description", project->getDescription());
  query.bindValue(":maxNumberRegistrations", project->getMaxNumberOfRegistrations());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  project->setId(assignedId);

  return true;
}

bool ProjectData::deleteProject(Project* project)
{
  QSqlQuery query;
  query.prepare(QString("DELETE FROM project WHERE id=%1").arg(project->getId()));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return query.numRowsAffected() > 0;
}

Project*ProjectData::retrieveProject(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT title, courseCode, description, maxNumberRegistrations "
                  "FROM project "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    QString title = query.value(0).toString();
    QString courseCode = query.value(1).toString();
    QString description = query.value(2).toString();
    int maxNumberRegistrations = query.value(3).toInt();

    return new Project(id, title, courseCode, description, maxNumberRegistrations);
  }

  return NULL;
}

QList<Project*> ProjectData::retrieveAllProjects()
{
  QSqlQuery query;
  query.prepare("SELECT id, title, courseCode, description, maxNumberRegistrations "
                "FROM project");

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<Project*> projects;
  while (query.next()) {
    int id = query.value(0).toInt();
    QString title = query.value(1).toString();
    QString courseCode = query.value(2).toString();
    QString description = query.value(3).toString();
    int maxNumberRegistrations = query.value(4).toInt();

    projects.append(new Project(id, title, courseCode, description,
                                maxNumberRegistrations));
  }

  return projects;
}
