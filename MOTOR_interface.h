#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H

typedef struct
{
	uint8 M_u8PORT;
	uint8 M_u8PIN1;
	uint8 M_u8PIN2;

}M_Config_t;

uint8 M_voidMotor_Rotate_CW(const M_Config_t* Copy_pConfiguration);

uint8 M_voidMotor_Rotate_CCW(const M_Config_t* Copy_pConfiguration);

uint8 M_voidMotor_Stop(const M_Config_t* Copy_pConfiguration);

#endif
