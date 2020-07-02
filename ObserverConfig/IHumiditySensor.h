#ifndef IHUMIDITY_SENSOR_H
#define IHUMIDITY_SENSOR_H

/* This is where the observers will include its functions */
#include "IObserverConfig.h"
#include "WaterFlowController.h"

tstObserverConfig aObserversFctPtrCbk[] =
{
    /* The Water Controller configuration, no upper limit check */
    { WaterFlowCtrl_vUpdateHumidityCbk, WaterFlowCtrl_u8LowerLimitCheck, 0}
};

#endif