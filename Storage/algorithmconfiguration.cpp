/*
 -----------------------------------------------------------------------
|                                                                       |
|   Class:          AlgorithmConfiguration                              |
|   Description:    AlgorithmConfiguration entity class.                |
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

#include "algorithmconfiguration.h"

AlgorithmConfiguration::AlgorithmConfiguration()
{
  id = -1;
  teamSize = 4;
}

AlgorithmConfiguration::AlgorithmConfiguration(const AlgorithmConfiguration& other)
{
  this->id = other.getId();
  teamSize = other.getTeamSize();
}

AlgorithmConfiguration::AlgorithmConfiguration(int teamSize)
{
  this->id = -1;
  this->teamSize = teamSize;
}

AlgorithmConfiguration::AlgorithmConfiguration(int id, int teamSize)
{
  this->id = id;
  this->teamSize = teamSize;
}

int AlgorithmConfiguration::getId() const
{
  return id;
}

void AlgorithmConfiguration::setId(int value)
{
  id = value;
}

int AlgorithmConfiguration::getTeamSize() const
{
  return teamSize;
}

void AlgorithmConfiguration::setTeamSize(int value)
{
  teamSize = value;
}



