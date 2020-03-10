#ifndef IOBSERVER_H
#define IOBSERVER_H

/**
 * \brief
 * The definition of the general update function
 * \param [in] pData: The pointer to the data to read from.
 */
typedef void (*updateFunctionPtr)(void * pData);

#endif