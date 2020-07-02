#ifndef IOBSERVER_CONFIG_H
#define IOBSERVER_CONFIG_H

/**
 * \brief
 * The definition of the general update function
 * \param [in] pData: The pointer to the data to read from.
 */
typedef void (*updateFunctionPtr)(const void * const pData);

/**
 * \brief
 * The function to be used for the limits check. This function is to be used for the lower and higher limits respectively
 * 
 * \param [in] pData: The data to be comparared.
 *
 * \retval unsigned char: The result of the function. 0 - Overpasses the limit, 1 - It is within the limit
 */
typedef unsigned char (*limitCheckFunctionPointer)(const void * const pData);

/**
 * \brief
 * The structure to be filled by the observer to have the limits checked.
 */
typedef struct
{
    updateFunctionPtr pFunctionCallback;        /* The update function callback from the observers */
    limitCheckFunctionPointer pFctLowerLimit;   /* The Lower limit funciton callback defined in the observer in question */
    limitCheckFunctionPointer pFctUpperLimit;   /* The Upper limit function callback defined in the obsesrver in question */
}tstObserverConfig;

#endif