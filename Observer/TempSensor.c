
#include "ITempSensor.h"
#include "TempSensor.h"

// Current temperature read from the sensor
static float s_f32CurrentTemp = 0.0f;

/**
 * \brief
 * Notify the Observers of the Temp Sensor
 */
static void NotifyObservers(void);


/*********  Notify Observers  **********/
void NotifyObservers(void)
{
    for(unsigned char i=0; i < sizeof(aFnctPtrObservers)/sizeof(updateFunctionPtr); i++)
    {
        // Calls the update callback function with the latest measurement
        aFnctPtrObservers[i](TempSensor_f32GetCurrentTemp());
    }
}

/*********  TempSensor_f32GetCurrentTemp  **********/
float* TempSensor_f32GetCurrentTemp(void)
{
    return &s_f32CurrentTemp;
}

/*********  TempSensor_vSetCurrentTemp  **********/
void TempSensor_vSetCurrentTemp(float newTemp)
{
    s_f32CurrentTemp = newTemp;
    NotifyObservers();
}

/*********  TempSensor_Init  **********/
void TempSensor_Init(void)
{
    s_f32CurrentTemp = 0.0f;
}

