#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

/* This is the actual sensor API definition */

/**
 * \brief
 * Get the latest percentage of humidity from the sensor.
 * 
 * \retval unsigned char*
 */
unsigned char* HumiditySensor_pu8GetLatestMeasurement(void);

/**
 *
 * \brief
 * The Sethumidity function used for the demonstration example
 * 
 * \param [in] u8NewHumidity: The new humidity to set. In the range from 0-100 %
 * 
 * \retval void.

 */
void HumiditySensor_vSetNewHumidity(unsigned char u8NewHimidity);

/**
 * \brief
 * The initialization of the Humidity Sensor component
 * 
 * \retval void.
 */
void HumiditySensor_vInit(void);

#endif