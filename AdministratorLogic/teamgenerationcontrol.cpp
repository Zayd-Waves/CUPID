#include "teamgenerationcontrol.h"
#include "team.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

TeamGenerationControl::TeamGenerationControl(
    AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl) :
  QObject()
{
  this->adminUpdateInterfaceControl = adminUpdateInterfaceControl;

  // connect thread result handler
  QObject::connect(&ppidWatcher, SIGNAL( finished() ),
                   this, SLOT( ppidCompleted() ));
}

void TeamGenerationControl::generateTeams(AlgorithmConfiguration* algorithmConfig, Project* project)
{
  // Run the algorithm in a spearate thread so the UI stays responsive
  QFuture< QList<Team*> > future = QtConcurrent::run(
        &ppid, &Ppid::generateTeams, algorithmConfig, project);
  ppidWatcher.setFuture(future);
}

void TeamGenerationControl::ppidCompleted()
{
  // algorithm thread has completed. Show result.
  adminUpdateInterfaceControl->teamsGenerated(ppidWatcher.result());
}

