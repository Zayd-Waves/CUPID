/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          QuestionnaireAnswer                                 |
|   Description:    QuestionnaireAnswer entity class.                   |
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

#include "questionnaireanswer.h"

QuestionnaireAnswer::QuestionnaireAnswer()
{
  id = -1;
  questionNumber = -1;
  ownAnswer1Selected = false;
  ownAnswer2Selected = false;
  ownAnswer3Selected = false;
  ownAnswer4Selected = false;
  groupAnswer1Selected = false;
  groupAnswer2Selected = false;
  groupAnswer3Selected = false;
  groupAnswer4Selected = false;
}

QuestionnaireAnswer::QuestionnaireAnswer(int id, int questionNumber)
{
  this->id = id;
  profileId = -1;
  this->questionNumber = questionNumber;
  ownAnswer1Selected = false;
  ownAnswer2Selected = false;
  ownAnswer3Selected = false;
  ownAnswer4Selected = false;
  groupAnswer1Selected = false;
  groupAnswer2Selected = false;
  groupAnswer3Selected = false;
  groupAnswer4Selected = false;
}

QuestionnaireAnswer::QuestionnaireAnswer(const QuestionnaireAnswer& other)
{
  id = other.getId();
  profileId = other.getProfileId();
  questionNumber = other.getQuestionNumber();
  ownAnswer1Selected = other.getOwnAnswer1Selected();
  ownAnswer2Selected = other.getOwnAnswer2Selected();
  ownAnswer3Selected = other.getOwnAnswer3Selected();
  ownAnswer4Selected = other.getOwnAnswer4Selected();
  groupAnswer1Selected = other.getGroupAnswer1Selected();
  groupAnswer2Selected = other.getGroupAnswer2Selected();
  groupAnswer3Selected = other.getGroupAnswer3Selected();
  groupAnswer4Selected = other.getGroupAnswer4Selected();
}

QuestionnaireAnswer::QuestionnaireAnswer(int questionNumber,
                   bool ownAnswer1Selected, bool ownAnswer2Selected, bool ownAnswer3Selected, bool ownAnswer4Selected,
                   bool groupAnswer1Selected, bool groupAnswer2Selected, bool groupAnswer3Selected, bool groupAnswer4Selected)
{
  this->id = -1;
  this->profileId = -1;
  this->questionNumber = questionNumber;
  this->ownAnswer1Selected = ownAnswer1Selected;
  this->ownAnswer2Selected = ownAnswer2Selected;
  this->ownAnswer3Selected = ownAnswer3Selected;
  this->ownAnswer4Selected = ownAnswer4Selected;
  this->groupAnswer1Selected = groupAnswer1Selected;
  this->groupAnswer2Selected = groupAnswer2Selected;
  this->groupAnswer3Selected = groupAnswer3Selected;
  this->groupAnswer4Selected = groupAnswer4Selected;
}

QuestionnaireAnswer::QuestionnaireAnswer(int profileId, int questionNumber,
                                         bool ownAnswer1Selected, bool ownAnswer2Selected, bool ownAnswer3Selected, bool ownAnswer4Selected,
                                         bool groupAnswer1Selected, bool groupAnswer2Selected, bool groupAnswer3Selected, bool groupAnswer4Selected)
{
  this->id = -1;
  this->profileId = profileId;
  this->questionNumber = questionNumber;
  this->ownAnswer1Selected = ownAnswer1Selected;
  this->ownAnswer2Selected = ownAnswer2Selected;
  this->ownAnswer3Selected = ownAnswer3Selected;
  this->ownAnswer4Selected = ownAnswer4Selected;
  this->groupAnswer1Selected = groupAnswer1Selected;
  this->groupAnswer2Selected = groupAnswer2Selected;
  this->groupAnswer3Selected = groupAnswer3Selected;
  this->groupAnswer4Selected = groupAnswer4Selected;
}


QuestionnaireAnswer::QuestionnaireAnswer(int id, int profileId, int questionNumber,
                   bool ownAnswer1Selected, bool ownAnswer2Selected, bool ownAnswer3Selected, bool ownAnswer4Selected,
                   bool groupAnswer1Selected, bool groupAnswer2Selected, bool groupAnswer3Selected, bool groupAnswer4Selected)
{
  this->id = id;
  this->profileId = profileId;
  this->questionNumber = questionNumber;
  this->ownAnswer1Selected = ownAnswer1Selected;
  this->ownAnswer2Selected = ownAnswer2Selected;
  this->ownAnswer3Selected = ownAnswer3Selected;
  this->ownAnswer4Selected = ownAnswer4Selected;
  this->groupAnswer1Selected = groupAnswer1Selected;
  this->groupAnswer2Selected = groupAnswer2Selected;
  this->groupAnswer3Selected = groupAnswer3Selected;
  this->groupAnswer4Selected = groupAnswer4Selected;
}

int QuestionnaireAnswer::getId() const
{
  return id;
}

void QuestionnaireAnswer::setId(int value)
{
  id = value;
}

int QuestionnaireAnswer::getProfileId() const
{
  return profileId;
}

void QuestionnaireAnswer::setProfileId(int value)
{
  profileId = value;
}

int QuestionnaireAnswer::getQuestionNumber() const
{
  return questionNumber;
}

void QuestionnaireAnswer::setQuestionNumber(int value)
{
  questionNumber = value;
}

bool QuestionnaireAnswer::getOwnAnswer1Selected() const
{
  return ownAnswer1Selected;
}

void QuestionnaireAnswer::setOwnAnswer1Selected(bool value)
{
  ownAnswer1Selected = value;
}
bool QuestionnaireAnswer::getOwnAnswer2Selected() const
{
  return ownAnswer2Selected;
}

void QuestionnaireAnswer::setOwnAnswer2Selected(bool value)
{
  ownAnswer2Selected = value;
}
bool QuestionnaireAnswer::getOwnAnswer3Selected() const
{
  return ownAnswer3Selected;
}

void QuestionnaireAnswer::setOwnAnswer3Selected(bool value)
{
  ownAnswer3Selected = value;
}
bool QuestionnaireAnswer::getOwnAnswer4Selected() const
{
  return ownAnswer4Selected;
}

void QuestionnaireAnswer::setOwnAnswer4Selected(bool value)
{
  ownAnswer4Selected = value;
}
bool QuestionnaireAnswer::getGroupAnswer1Selected() const
{
  return groupAnswer1Selected;
}

void QuestionnaireAnswer::setGroupAnswer1Selected(bool value)
{
  groupAnswer1Selected = value;
}
bool QuestionnaireAnswer::getGroupAnswer2Selected() const
{
  return groupAnswer2Selected;
}

void QuestionnaireAnswer::setGroupAnswer2Selected(bool value)
{
  groupAnswer2Selected = value;
}
bool QuestionnaireAnswer::getGroupAnswer3Selected() const
{
  return groupAnswer3Selected;
}

void QuestionnaireAnswer::setGroupAnswer3Selected(bool value)
{
  groupAnswer3Selected = value;
}
bool QuestionnaireAnswer::getGroupAnswer4Selected() const
{
  return groupAnswer4Selected;
}

void QuestionnaireAnswer::setGroupAnswer4Selected(bool value)
{
  groupAnswer4Selected = value;
}
