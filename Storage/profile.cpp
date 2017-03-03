/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          Profile                                             |
|   Description:    Profile entity class.                               |
|                                                                       |
|                                                                       |
|                                                                       |
|                                                                       |
|   Author:         Syzgy                                               |
|   Date:           11/27/2015                                          |
|                                                                       |
|                                                                       |
 -----------------------------------------------------------------------
*/

#include "profile.h"

Profile::Profile()
{
  id = -1;
}

Profile::Profile(const Profile& other)
{
  id = other.getId();
  addAllAnswers(other.getAllAnswers());
}


Profile::Profile(int id)
{
  this->id = id;
}

int Profile::getId() const
{
  return id;
}

void Profile::setId(int value)
{
  id = value;
}

QuestionnaireAnswer*Profile::getAnswer(int questionNumber) const
{
  if (!questionnaire.length()) {
    return NULL;
  }

  QList<QuestionnaireAnswer*>::const_iterator iter;
  QuestionnaireAnswer* a = NULL;

  for (iter = questionnaire.begin(); iter != questionnaire.end(); ++iter) {
    if ((*iter)->getQuestionNumber() == questionNumber) {
      a = *iter;
      break;
    }
  }

  return a;
}

QList<QuestionnaireAnswer*> Profile::getAllAnswers() const
{
  QList<QuestionnaireAnswer*> copy(questionnaire);
  return copy;
}

bool Profile::addAnswer(QuestionnaireAnswer* answer)
{
  questionnaire.append(answer);
  return true;
}

bool Profile::addAllAnswers(QList<QuestionnaireAnswer*> answers)
{
  questionnaire.append(answers);
  return true;
}

QuestionnaireAnswer* Profile::removeAnswer(int questionNumber)
{
  if (!questionnaire.length()) {
    return NULL;
  }

  QList<QuestionnaireAnswer*>::iterator iter;
  QuestionnaireAnswer* a = NULL;

  for (iter = questionnaire.begin(); iter != questionnaire.end(); ++iter) {
    if ((*iter)->getQuestionNumber() == questionNumber) {
      a = *iter;
      questionnaire.erase(iter);
    }
  }

  return a;
}

bool Profile::removeAnswer(QuestionnaireAnswer* answer)
{
  return questionnaire.removeOne(answer);
}
