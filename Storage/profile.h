#ifndef PROFILE_H
#define PROFILE_H

#include <QList>
#include "questionnaireanswer.h"

class Profile
{
  public:
    Profile();
    Profile(const Profile& other);
    Profile(int id);
    int getId() const;
    void setId(int value);

    QuestionnaireAnswer* getAnswer(int questionNumber) const;
    QList<QuestionnaireAnswer*> getAllAnswers() const;
    bool addAnswer(QuestionnaireAnswer* answer);
    bool addAllAnswers(QList<QuestionnaireAnswer*> answers);
    QuestionnaireAnswer* removeAnswer(int questionNumber);
    bool removeAnswer(QuestionnaireAnswer* answer);

  private:
    int id;
    QList<QuestionnaireAnswer*> questionnaire;
};

#endif // PROFILE_H
