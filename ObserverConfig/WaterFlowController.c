

#include "WaterFlowController.h"


/*********  WaterFlowCtrl_vUpdateHumidityCbk  **********/
void WaterFlowCtrl_vUpdateHumidityCbk(const void * const pData)
{
    unsigned char *pu8NewData = (unsigned char*)pData;
    *pu8NewData = 65U;
}


/*********  WaterFlowCtrl_u8LowerLimitCheck  **********/
unsigned char WaterFlowCtrl_u8LowerLimitCheck(const void * const pData)
{
    /* Initializes the return value with the positive values */
    unsigned char u8ReturnVal = 0U;



    return u8ReturnVal;
}


/*********  WaterFlowCtrl_vInit  **********/
void WaterFlowCtrl_vInit(void)
{

}