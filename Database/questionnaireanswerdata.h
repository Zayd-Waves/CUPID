#ifndef QUESTIONNAIREANSWERDATA_H
#define QUESTIONNAIREANSWERDATA_H

#include "Storage/questionnaireanswer.h"
#include <QList>

class QuestionnaireAnswerData
{
  public:
    QuestionnaireAnswerData();
    bool updateQuestionnaireAnswer(QuestionnaireAnswer* qa);
    bool insertQuestionnaireAnswer(QuestionnaireAnswer* qa);
    QuestionnaireAnswer* retrieveQuestionnaireAnswer(int id);
    QList<QuestionnaireAnswer*> retrieveAllQuestionnaireAnswers();
    QList<QuestionnaireAnswer*> retrieveProfileQuestionnaireAnswers(int profileId);
};

#endif // QUESTIONNAIREANSWERDATA_H
