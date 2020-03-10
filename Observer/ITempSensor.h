#ifndef ITEMP_SENSOR_H
#define ITEMP_SENSOR_H

// Function callback prototype needed
#include "IObserver.h"
// Clients headers where the function callbacks are defined.
#include "Application.h"

updateFunctionPtr aFnctPtrObservers[] =
{
    vLatestTemperatureCbk,
    vUpdateTempCbk
};

#endif