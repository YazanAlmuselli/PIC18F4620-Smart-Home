
#include "mcc_generated_files/mcc.h"
#include "AECUL_Modules/RealTimeClockDS1307/RealTimeClockDS1307.h"
#include "AECUL_Modules/EEPROM_24C02C/EEPROM_24C02C.h"
#include "AECUL_Modules/TemSensor_TC74/TemSensor_TC74.h"

RealTimeClockDS1307_T RealTimeClockDS1307;
uint8_t U3Rec_Value, U4Rec_Value;
uint8_t TC74_A7_Temp_Value = 0;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    UART_LoggingDebugData_Send_String("System Started\r", 15);
    
    EEPROM_24C02C_Write_Byte(0xA2, 0x08, 5);
    __delay_us(500);
    EEPROM_24C02C_Write_Byte(0xA6, 0x08, 6);
    __delay_us(500);
    U3Rec_Value = EEPROM_24C02C_Read_Byte(0xA2, 0x08);
    U4Rec_Value = EEPROM_24C02C_Read_Byte(0xA6, 0x08);
    
    while (1)
    {
        RealTimeClockDS1307 = RealTimeClockDS1307_Get_Date_Time();
        Print_RealTimeClockDS1307();
        
        TC74_A7_Temp_Value = TempSensor_TC74_Read_Temp(0x9E);
        I2C_Write1ByteRegister(0x70, 0x00, TC74_A7_Temp_Value);
        
        __delay_ms(500);
    }
}