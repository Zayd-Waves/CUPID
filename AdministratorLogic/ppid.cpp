#include "ppid.h"
#include <QDebug>
#include <QSet>

bool teamCompare(Team* team1, Team* team2);

Ppid::Ppid()
{}

QList<Team*> Ppid::generateTeams(AlgorithmConfiguration* config, Project* project)
{
  QList<Registration*> registrations = project->getAllRegistrations();

  qDebug() << "Rnning PPID" << registrations.length() << "students,"
              << config->getTeamSize() << "team size.";

  if ( (2 * config->getTeamSize()) - 1 > registrations.size()) {
    qDebug() << "There aren't enough students registered";

    // should throw an exception here!

    QList<Team*> l;
    return l;
  }

  int* teamsNeeded;
  QList<Team*> teams = computeTeamConfigurations(config->getTeamSize(),
                                                 registrations.size(),
                                                 &teamsNeeded);

  QList<Student*> students;
  foreach (Registration* r, registrations) {
    students.append(r->getStudent());
  }

  /* compute ALL possible teams of students */
  QList<Team*>* allPossibleTeams = new QList<Team*>();
  combination(0, config->getTeamSize() - 1, students, allPossibleTeams);
  combination(0, config->getTeamSize(), students, allPossibleTeams);
  combination(0, config->getTeamSize() + 1, students, allPossibleTeams);

  /* sort teams by compatibility (this will take a LONG time) */
  qDebug() << "# Possible teams:" << allPossibleTeams->size();
  qDebug() << "Sorting teams by compatibility... (please be patient)";
  qSort(allPossibleTeams->begin(), allPossibleTeams->end(), teamCompare);


  /* assign students to teams */
  QList<Student*> assignedStudents;
  QList<Team*> selectedTeams;
  int smallTeamsNeeded = teamsNeeded[0];
  int normalTeamsNeeded = teamsNeeded[1];
  int bigTeamsNeeded = teamsNeeded[2];
  int pos = 0;

  qDebug() << "Finding most compatible groups";

  while ( (smallTeamsNeeded || normalTeamsNeeded || bigTeamsNeeded) &&
          (pos < allPossibleTeams->size()) ) {
    bool skip = false;
    Team* possibleTeam = allPossibleTeams->at(pos++);

    /* has any student of the team already been assigned? */
    foreach (Student* s, possibleTeam->getAllStudents()) {
      if (assignedStudents.contains(s)) {
        skip = true;
        break;
      }
    }

    if (skip) {
      continue;
    }

    /* do we still need teams of that size? */
    if (possibleTeam->getTeamSize() < config->getTeamSize()) {
      skip = smallTeamsNeeded <= 0;
    } else if (possibleTeam->getTeamSize() == config->getTeamSize()) {
      skip = normalTeamsNeeded <= 0;
    } else {
      skip = bigTeamsNeeded <= 0;
    }

    if (skip) {
      continue;
    }

    /* we have found a team we want */
    if (possibleTeam->getTeamSize() < config->getTeamSize()) {
      smallTeamsNeeded--;
    } else if (possibleTeam->getTeamSize() == config->getTeamSize()) {
      normalTeamsNeeded--;
    } else {
      bigTeamsNeeded--;
    }

    assignedStudents.append(possibleTeam->getAllStudents());
    selectedTeams.append(possibleTeam);
  }

  QSet<Student*> doubleCheckSet;
  foreach(Team* t, selectedTeams) {
    doubleCheckSet.unite(QSet<Student*>::fromList(t->getAllStudents()));
  }

  return selectedTeams;
}

QList<Team*> Ppid::computeTeamConfigurations(int teamSize, int studentCount,
                                             int** teamsNeeded)
{
  QList<int*> teamConfigurations;

  /* find all possibilities */
  int sizeLessOne = teamSize - 1;
  int sizeExact = teamSize;
  int sizePlusOne = teamSize + 1;

  for (int x = 0; (x * sizeLessOne ) <= studentCount; ++x) {

    for (int y = 0; (y * sizeExact) <= studentCount; ++y) {

      for (int z = 0; (z * sizePlusOne) <= studentCount; ++z) {

        int total = (x * sizeLessOne) + (y * sizeExact) + (z * sizePlusOne);
        if (total == studentCount) {
          int* config = new int[3];
          config[0] = x;
          config[1] = y;
          config[2] = z;
          teamConfigurations.append(config);
        }
      }
    }
  }

  /* find the configurations with the highest number of exact size */
  QList<int*> filteredConfigs;
  int currentMax = 0;
  QList<int*>::const_iterator iter;

  for (iter = teamConfigurations.begin(); iter != teamConfigurations.end(); ++iter) {
    if ((*iter)[1] > currentMax) {
      currentMax = (*iter)[1];
      filteredConfigs.clear();
    }
    if ((*iter)[1] == currentMax) {
      filteredConfigs.append(*iter);
    }
  }

  /* find the configuration with the lowest number of oversized groups */
  int* chosenConfig = filteredConfigs.size() > 1 ? NULL : filteredConfigs.at(0);

  if (!chosenConfig) {
    QList<int*>::const_iterator iter;

    for (iter = filteredConfigs.begin(); iter != filteredConfigs.end(); ++iter) {
      if (!chosenConfig) {
        chosenConfig = *iter;
      } else {
        chosenConfig = chosenConfig[2] > (*iter)[2] ? *iter : chosenConfig;
      }
    }
  }

  /* generate team objects */
  QList<Team*> result;
  int teamSizes[3] = {sizeLessOne, sizeExact, sizePlusOne};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < chosenConfig[i]; ++j) {
      result.append(new Team(teamSizes[i]));
    }
  }

  *teamsNeeded = new int[3];
  (*teamsNeeded)[0] = chosenConfig[0];
  (*teamsNeeded)[1] = chosenConfig[1];
  (*teamsNeeded)[2] = chosenConfig[2];

  return result;
}

void Ppid::combination(int offset, int k, QList<Student*> students, QList<Team*>* teams)
{
  if (k == 0) {
    Team* t = new Team(combinationBuffer.size());
    t->addStudents(combinationBuffer);
    teams->append(t);
    return;
  }

  for (int i = offset; i <= students.size() - k; ++i) {
    combinationBuffer.push_back(students[i]);
    combination(i+1, k-1, students, teams);
    combinationBuffer.pop_back();
  }
}

bool teamCompare(Team* team1, Team* team2)
{
  return team1->computeTeamCompatibility() > team2->computeTeamCompatibility();
}



