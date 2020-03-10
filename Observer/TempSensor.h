#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

/**
 * \brief
 * Retrieve the current temperature from the sensor
 * \retval *float.
 */
float* TempSensor_f32GetCurrentTemp(void);

/**
 * \brief
 * TempSensor_Init function
 */
void TempSensor_Init(void);

/**
 * \brief
 * Sets the current temperature to be measured
 */
void TempSensor_vSetCurrentTemp(float newTemp);

#endif