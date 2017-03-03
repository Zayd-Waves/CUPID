#ifndef TEAMGENERATIONCONTROL_H
#define TEAMGENERATIONCONTROL_H

#include "administratorupdateinterfacecontrol.h"
#include "Storage/algorithmconfiguration.h"
#include "Storage/project.h"
#include "ppid.h"

#include <QObject>

class TeamGenerationControl : public QObject
{
    Q_OBJECT

  public:
    TeamGenerationControl(AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl);
    void generateTeams(AlgorithmConfiguration* algorithmConfig,
                       Project* project);

  private slots:
    void ppidCompleted();

  private:
    AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl;
    Ppid ppid;
    QFutureWatcher<QList <Team*> > ppidWatcher;
};

#endif // TEAMGENERATIONCONTROL_H
