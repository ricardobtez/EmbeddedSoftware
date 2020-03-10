
#include <stdio.h>
#include <stdlib.h>

#include "Application.h"
#include "TempSensor.h"

void vLatestTemperatureCbk(void* pData)
{
    float number = *(float*)pData;
    printf("vLatestTemperatureCbk New temp is::%f\n", number);
}

void vUpdateTempCbk(void* pData)
{
    float num = *(float*)pData;

    if (num < 30.0f && num > 20.0f)
    {
        printf("vUpdateTempCbk the temperature is in optimal range\n");
    }
}


int main(void)
{
    TempSensor_Init();


    /*********  Updates the current temperature of the sensor  **********/
    for(unsigned char i=0; i < 10; i++)
    {
        TempSensor_vSetCurrentTemp((float)i * 2.50f + 10.0f);
    }

    return 0;
}