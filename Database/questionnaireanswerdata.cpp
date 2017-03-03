#include "questionnaireanswerdata.h"
#include "dataqueryfailedexception.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

QuestionnaireAnswerData::QuestionnaireAnswerData()
{
}

bool QuestionnaireAnswerData::updateQuestionnaireAnswer(QuestionnaireAnswer* qa)
{
  QSqlQuery query;
  query.prepare("UPDATE questionnaireAnswer SET "
                "profileId=:profileId, questionNumber=:questionNumber, "
                "ownAnswer1Selected=:ownAnswer1Selected, "
                "ownAnswer2Selected=:ownAnswer2Selected, "
                "ownAnswer3Selected=:ownAnswer3Selected, "
                "ownAnswer4Selected=:ownAnswer4Selected, "
                "groupAnswer1Selected=:groupAnswer1Selected, "
                "groupAnswer2Selected=:groupAnswer2Selected, "
                "groupAnswer3Selected=:groupAnswer3Selected, "
                "groupAnswer4Selected=:groupAnswer4Selected "
                "WHERE id=:id;");

  query.bindValue(":profileId", qa->getProfileId());
  query.bindValue(":questionNumber", qa->getQuestionNumber());
  query.bindValue(":ownAnswer1Selected", (qa->getOwnAnswer1Selected() ? 1 : 0));
  query.bindValue(":ownAnswer2Selected", (qa->getOwnAnswer2Selected() ? 1 : 0));
  query.bindValue(":ownAnswer3Selected", (qa->getOwnAnswer3Selected() ? 1 : 0));
  query.bindValue(":ownAnswer4Selected", (qa->getOwnAnswer4Selected() ? 1 : 0));
  query.bindValue(":groupAnswer1Selected", (qa->getGroupAnswer1Selected() ? 1 : 0));
  query.bindValue(":groupAnswer2Selected", (qa->getGroupAnswer2Selected() ? 1 : 0));
  query.bindValue(":groupAnswer3Selected", (qa->getGroupAnswer3Selected() ? 1 : 0));
  query.bindValue(":groupAnswer4Selected", (qa->getGroupAnswer4Selected() ? 1 : 0));
  query.bindValue(":id", qa->getId());

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  return true;
}

bool QuestionnaireAnswerData::insertQuestionnaireAnswer(QuestionnaireAnswer* qa)
{
  QSqlQuery query;
  query.prepare("INSERT INTO questionnaireAnswer "
                "(profileId, questionNumber, "
                "ownAnswer1Selected, ownAnswer2Selected, "
                "ownAnswer3Selected, ownAnswer4Selected, "
                "groupAnswer1Selected, groupAnswer2Selected, "
                "groupAnswer3Selected, groupAnswer4Selected) "
                "VALUES (:profileId, :questionNumber, "
                ":ownAnswer1Selected, :ownAnswer2Selected, "
                ":ownAnswer3Selected, :ownAnswer4Selected, "
                ":groupAnswer1Selected, :groupAnswer2Selected, "
                ":groupAnswer3Selected, :groupAnswer4Selected)");

  query.bindValue(":profileId", qa->getProfileId());
  query.bindValue(":questionNumber", qa->getQuestionNumber());
  query.bindValue(":ownAnswer1Selected", (qa->getOwnAnswer1Selected() ? 1 : 0));
  query.bindValue(":ownAnswer2Selected", (qa->getOwnAnswer2Selected() ? 1 : 0));
  query.bindValue(":ownAnswer3Selected", (qa->getOwnAnswer3Selected() ? 1 : 0));
  query.bindValue(":ownAnswer4Selected", (qa->getOwnAnswer4Selected() ? 1 : 0));
  query.bindValue(":groupAnswer1Selected", (qa->getGroupAnswer1Selected() ? 1 : 0));
  query.bindValue(":groupAnswer2Selected", (qa->getGroupAnswer2Selected() ? 1 : 0));
  query.bindValue(":groupAnswer3Selected", (qa->getGroupAnswer3Selected() ? 1 : 0));
  query.bindValue(":groupAnswer4Selected", (qa->getGroupAnswer4Selected() ? 1 : 0));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  int assignedId = query.lastInsertId().toInt();
  qa->setId(assignedId);

  return true;
}

QuestionnaireAnswer*QuestionnaireAnswerData::retrieveQuestionnaireAnswer(int id)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT profileId, questionNumber, "
                  "ownAnswer1Selected, ownAnswer2Selected, "
                  "ownAnswer3Selected, ownAnswer4Selected, "
                  "groupAnswer1Selected, groupAnswer2Selected, "
                  "groupAnswer3Selected, groupAnswer4Selected "
                  "FROM questionnaireAnswer "
                  "WHERE id=%1").arg(id));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  if (query.next()) {
    int profileId = query.value(0).toInt();
    int questionNumber = query.value(1).toInt();
    bool ownAnswer1Selected = (query.value(2).toInt() != 0);
    bool ownAnswer2Selected = (query.value(3).toInt() != 0);
    bool ownAnswer3Selected = (query.value(4).toInt() != 0);
    bool ownAnswer4Selected = (query.value(5).toInt() != 0);
    bool groupAnswer1Selected = (query.value(6).toInt() != 0);
    bool groupAnswer2Selected = (query.value(7).toInt() != 0);
    bool groupAnswer3Selected = (query.value(8).toInt() != 0);
    bool groupAnswer4Selected = (query.value(9).toInt() != 0);

    return new QuestionnaireAnswer(id, profileId, questionNumber,
                                   ownAnswer1Selected, ownAnswer2Selected,
                                   ownAnswer3Selected, ownAnswer4Selected,
                                   groupAnswer1Selected, groupAnswer2Selected,
                                   groupAnswer3Selected, groupAnswer4Selected);
  }

  return NULL;
}

QList<QuestionnaireAnswer*> QuestionnaireAnswerData::retrieveAllQuestionnaireAnswers()
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT id, profileId, questionNumber, "
                  "ownAnswer1Selected, ownAnswer2Selected, "
                  "ownAnswer3Selected, ownAnswer4Selected, "
                  "groupAnswer1Selected, groupAnswer2Selected, "
                  "groupAnswer3Selected, groupAnswer4Selected "
                  "FROM questionnaireAnswer"));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<QuestionnaireAnswer*> qas;
  while (query.next()) {
    int id = query.value(0).toInt();
    int profileId = query.value(1).toInt();
    int questionNumber = query.value(2).toInt();
    bool ownAnswer1Selected = (query.value(3).toInt() != 0);
    bool ownAnswer2Selected = (query.value(4).toInt() != 0);
    bool ownAnswer3Selected = (query.value(5).toInt() != 0);
    bool ownAnswer4Selected = (query.value(6).toInt() != 0);
    bool groupAnswer1Selected = (query.value(7).toInt() != 0);
    bool groupAnswer2Selected = (query.value(8).toInt() != 0);
    bool groupAnswer3Selected = (query.value(9).toInt() != 0);
    bool groupAnswer4Selected = (query.value(10).toInt() != 0);

    qas.append(new QuestionnaireAnswer(id, profileId, questionNumber,
                                       ownAnswer1Selected, ownAnswer2Selected,
                                       ownAnswer3Selected, ownAnswer4Selected,
                                       groupAnswer1Selected, groupAnswer2Selected,
                                       groupAnswer3Selected, groupAnswer4Selected));
  }

  return qas;
}

QList<QuestionnaireAnswer*> QuestionnaireAnswerData::retrieveProfileQuestionnaireAnswers(int profileId)
{
  QSqlQuery query;
  query.prepare(QString(
                  "SELECT id, profileId, questionNumber, "
                  "ownAnswer1Selected, ownAnswer2Selected, "
                  "ownAnswer3Selected, ownAnswer4Selected, "
                  "groupAnswer1Selected, groupAnswer2Selected, "
                  "groupAnswer3Selected, groupAnswer4Selected "
                  "FROM questionnaireAnswer "
                  "WHERE profileId=%1").arg(profileId));

  bool result = query.exec();
  if (!result) {
    qDebug() << "Query" << query.executedQuery() << "failed: " << query.lastError();
    throw new DataQueryFailedException();
  }

  QList<QuestionnaireAnswer*> qas;
  while (query.next()) {
    int id = query.value(0).toInt();
    int profileId = query.value(1).toInt();
    int questionNumber = query.value(2).toInt();
    bool ownAnswer1Selected = (query.value(3).toInt() != 0);
    bool ownAnswer2Selected = (query.value(4).toInt() != 0);
    bool ownAnswer3Selected = (query.value(5).toInt() != 0);
    bool ownAnswer4Selected = (query.value(6).toInt() != 0);
    bool groupAnswer1Selected = (query.value(7).toInt() != 0);
    bool groupAnswer2Selected = (query.value(8).toInt() != 0);
    bool groupAnswer3Selected = (query.value(9).toInt() != 0);
    bool groupAnswer4Selected = (query.value(10).toInt() != 0);

    qas.append(new QuestionnaireAnswer(id, profileId, questionNumber,
                                       ownAnswer1Selected, ownAnswer2Selected,
                                       ownAnswer3Selected, ownAnswer4Selected,
                                       groupAnswer1Selected, groupAnswer2Selected,
                                       groupAnswer3Selected, groupAnswer4Selected));
  }

  return qas;
}
