
#include "stdio.h"
#include "IHumiditySensor.h"
#include "HumiditySensor.h"


/*--------  Static variables definitions  --------*/
static unsigned char s_u8Humidity;

/*--------  Static function definitions  --------*/
static void NotifyObservers(void);


/*********  NotifyObservers  **********/
void NotifyObservers(void)
{
    unsigned char u8LimitCheckResult = 1U;
    unsigned char u8Notify = 0;
    for(unsigned char i=0; i < sizeof(aObserversFctPtrCbk)/sizeof(tstObserverConfig); i++)
    {
        /* Checks for the limit function to exist */
        if(0 != aObserversFctPtrCbk[i].pFctLowerLimit)
        {
            u8LimitCheckResult = aObserversFctPtrCbk[i].pFctLowerLimit((const void *const)HumiditySensor_pu8GetLatestMeasurement());
            /* If the check fails, call the update callback */
            if (0 == u8LimitCheckResult)
            {
                u8Notify = 1U;
            }
        }

        /* Checks for the upper limit to exist */
        if(0 != aObserversFctPtrCbk[i].pFctUpperLimit)
        {
            u8LimitCheckResult = aObserversFctPtrCbk[i].pFctUpperLimit((const void*const)HumiditySensor_pu8GetLatestMeasurement());
            /* If the check fails, call the update callback */
            if (0 == u8LimitCheckResult)
            {
                u8Notify = 1U;
            }
        }

        if(1U == u8Notify)
        {
            if (0 != aObserversFctPtrCbk[i].pFunctionCallback)
            {
                aObserversFctPtrCbk[i].pFunctionCallback((const void*const)HumiditySensor_pu8GetLatestMeasurement());
            }
        }
    }
}


/*********  HumiditySensor_f32GetLatestMeasurement  **********/
unsigned char* HumiditySensor_pu8GetLatestMeasurement(void)
{
    return &s_u8Humidity;
}


/*********  HumiditySensor_vSetNewHumidity  **********/
void HumiditySensor_vSetNewHumidity(unsigned char u8NewHumidity)
{
    unsigned char u8TempVar = s_u8Humidity;
    /* Range check for the new humidity percentage */
    if (u8NewHumidity < 101)
    {
        s_u8Humidity = u8NewHumidity;
        NotifyObservers();
        if(s_u8Humidity != u8TempVar)
        {
            printf("The variable was modified in one of the observers!!\n");
        }
    }
}


/*********  HumiditySensor_vInit  **********/
void HumiditySensor_vInit(void)
{
    /* Initializes the sensor with 50% */
    s_u8Humidity = 50U;
}
