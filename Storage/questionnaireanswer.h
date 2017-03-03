#ifndef QUESTIONNAIREANSWER_H
#define QUESTIONNAIREANSWER_H

class QuestionnaireAnswer
{
  public:
    QuestionnaireAnswer();
    QuestionnaireAnswer(int questionNumber);
    QuestionnaireAnswer(int id, int questionNumber);
    QuestionnaireAnswer(const QuestionnaireAnswer&);
    QuestionnaireAnswer(int questionNumber, bool, bool, bool, bool, bool, bool, bool, bool);
    QuestionnaireAnswer(int profileId, int questionNumber, bool, bool, bool, bool, bool, bool, bool, bool);
    QuestionnaireAnswer(int id, int profileId, int questionNumber, bool, bool, bool, bool, bool, bool, bool, bool);

    int getId() const;
    void setId(int value);
    int getProfileId() const;
    void setProfileId(int value);
    int getQuestionNumber() const;
    void setQuestionNumber(int value);

    bool getOwnAnswer1Selected() const;
    void setOwnAnswer1Selected(bool value);
    bool getOwnAnswer2Selected() const;
    void setOwnAnswer2Selected(bool value);
    bool getOwnAnswer3Selected() const;
    void setOwnAnswer3Selected(bool value);
    bool getOwnAnswer4Selected() const;
    void setOwnAnswer4Selected(bool value);
    bool getGroupAnswer1Selected() const;
    void setGroupAnswer1Selected(bool value);
    bool getGroupAnswer2Selected() const;
    void setGroupAnswer2Selected(bool value);
    bool getGroupAnswer3Selected() const;
    void setGroupAnswer3Selected(bool value);
    bool getGroupAnswer4Selected() const;
    void setGroupAnswer4Selected(bool value);

  private:
    int id;
    int profileId;
    int questionNumber;
    bool ownAnswer1Selected;
    bool ownAnswer2Selected;
    bool ownAnswer3Selected;
    bool ownAnswer4Selected;
    bool groupAnswer1Selected;
    bool groupAnswer2Selected;
    bool groupAnswer3Selected;
    bool groupAnswer4Selected;
};

#endif // QUESTIONNAIREANSWER_H
