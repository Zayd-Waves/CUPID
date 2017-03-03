#ifndef PPID_H
#define PPID_H

#include <QList>

#include "team.h"
#include "Storage/algorithmconfiguration.h"
#include "Storage/student.h"
#include "Storage/project.h"
#include "Storage/registration.h"
#include "Storage/storagemanager.h"

class Ppid
{
  public:
    Ppid();
    QList<Team*> generateTeams(AlgorithmConfiguration* config, Project* project);

  private:
    StorageManager* storage;
    QList<Student*> combinationBuffer;

    QList<Team*> computeTeamConfigurations(int teamSize, int studentCount, int** teamsNeeded);
    void combination(int offset, int k, QList<Student*> students, QList<Team*>* teams);
};

#endif // PPID_H
