/* 
 * File:   TemSensor_TC74.h
 * Author: HP
 *
 * Created on September 28, 2023, 4:56 PM
 */

#ifndef TEMSENSOR_TC74_H
#define	TEMSENSOR_TC74_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t TempSensor_TC74_Read_Temp(i2c_address_t TC74_Address);

#endif	/* TEMSENSOR_TC74_H */

