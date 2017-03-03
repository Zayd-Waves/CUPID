/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          Administrator                                       |
|   Description:    Administrator entity class.                         |
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

#include "administrator.h"

Administrator::Administrator() : User()
{
  algorithmConfiguration = NULL;
  algorithmConfigurationId = -1;
}

Administrator::Administrator(const Administrator& other) : User(other)
{
  this->algorithmConfiguration = other.getAlgorithmConfiguration();
  this->algorithmConfigurationId = other.getAlgorithmConfigurationId();
}

Administrator::Administrator(const QString& email, const QString& firstName,
                             const QString& lastName, AlgorithmConfiguration* algorithmConfiguration) :
  User(email, firstName, lastName)
{
  this->algorithmConfiguration = algorithmConfiguration;
  this->algorithmConfigurationId = algorithmConfiguration ? algorithmConfiguration->getId() : -1;
}

Administrator::Administrator(const QString& email, const QString& firstName, const QString& lastName, int algorithmConfigurationId) :
  User(email, firstName, lastName)
{
  this->algorithmConfiguration = NULL;
  this->algorithmConfigurationId = algorithmConfigurationId;
}

Administrator::Administrator(int id, const QString& email, const QString& firstName,
                             const QString& lastName, AlgorithmConfiguration* algorithmConfiguration) :
  User(id, email, firstName, lastName)
{
  this->algorithmConfiguration = algorithmConfiguration;
  if (this->algorithmConfiguration) {
    this->algorithmConfigurationId = algorithmConfiguration->getId();
  } else {
    this->algorithmConfigurationId = -1;
  }
}

Administrator::Administrator(int id, const QString& email, const QString& firstName,
                             const QString& lastName, int algorithmConfigurationId) :
  User(id, email, firstName, lastName)
{
  this->algorithmConfiguration = NULL;
  this->algorithmConfigurationId = algorithmConfigurationId;
}

AlgorithmConfiguration* Administrator::getAlgorithmConfiguration() const
{
  return algorithmConfiguration;
}

void Administrator::setAlgorithmConfiguration(AlgorithmConfiguration* value)
{
  algorithmConfiguration = value;
  if (algorithmConfiguration) {
    algorithmConfigurationId = algorithmConfiguration->getId();
  } else {
    algorithmConfigurationId = -1;
  }
}

int Administrator::getAlgorithmConfigurationId() const
{
  return algorithmConfigurationId;
}

void Administrator::setAlgorithmConfigurationId(int value)
{
  algorithmConfigurationId = value;
}


