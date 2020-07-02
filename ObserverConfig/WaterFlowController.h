#ifndef WATER_FLOW_CONTROLLER_H
#define WATER_FLOW_CONTROLLER_H

/* This is the controller that will have the observer functionality */
#include "IObserverConfig.h"

/**
 * \brief
 * The function callback used for the notification of the observers.
 * 
 * \param [in] pData: Pointer to the data needed for the callback to receive the information
 * 
 * \retval void.
 */
void WaterFlowCtrl_vUpdateHumidityCbk(const void * const pData);

/**
 * \brief
 * The lower limit check defined for the subject to call when needed
 * 
 * \param [in] pData: The pointer to the newest lecture to be checked against.
 * 
 * \retval unsigned char: 0 - Surpasses the limits, 1 - Within limits
 */
unsigned char WaterFlowCtrl_u8LowerLimitCheck(const void * const pData);

/**
 * \brief
 * The Water Flow Controller initialization function
 * 
 * \retval void.
 */
void WaterFlowCtrl_vInit(void);

#endif