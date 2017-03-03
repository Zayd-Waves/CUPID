#ifndef ALGORITHMCONFIGURATIONCONTROL_H
#define ALGORITHMCONFIGURATIONCONTROL_H

#include "administratorupdateinterfacecontrol.h"
#include "administratorstorageaccess.h"

class AlgorithmConfigurationControl
{
  public:
    AlgorithmConfigurationControl(AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl,
                                  AdministratorStorageAccess* adminStorageAccess);
    bool updateAlgorithmConfiguration(Administrator*);

  private:
    AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl;
    AdministratorStorageAccess* adminStorageAccess;
};

#endif // ALGORITHMCONFIGURATIONCONTROL_H
