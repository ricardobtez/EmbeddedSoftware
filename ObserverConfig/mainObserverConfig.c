
#include "stdio.h"
#include "stdlib.h"

#include "WaterFlowController.h"
#include "HumiditySensor.h"

int main(void)
{
    HumiditySensor_vInit();
    WaterFlowCtrl_vInit();

    for(unsigned char i=0; i<10; i++)
    {
        HumiditySensor_vSetNewHumidity(*HumiditySensor_pu8GetLatestMeasurement() + (i*2));
    }
    return 0;
}