#include "algorithmconfigurationcontrol.h"

AlgorithmConfigurationControl::AlgorithmConfigurationControl(
    AdministratorUpdateInterfaceControl* adminUpdateInterfaceControl,
    AdministratorStorageAccess* adminStorageAccess)
{
  this->adminUpdateInterfaceControl = adminUpdateInterfaceControl;
  this->adminStorageAccess = adminStorageAccess;
}


bool AlgorithmConfigurationControl::updateAlgorithmConfiguration(Administrator* administrator)
{
    bool success = adminStorageAccess->storeAdministrator(administrator);
    if (success == true) {
        adminUpdateInterfaceControl->algorithmConfigUpdated(administrator->getAlgorithmConfiguration());
    }
    return success;
}
