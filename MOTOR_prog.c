#include "STD_TYPES.h"
#include "ErrType.h"

#include "MOTOR_interface.h"
#include "DIO_interface.h"

uint8 M_voidMotor_Rotate_CW(const M_Config_t* Copy_pConfiguration)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pConfiguration != NULL)
	{
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN2, DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
/********************************************************************************************/
/********************************************************************************************/
uint8 M_voidMotor_Rotate_CCW(const M_Config_t* Copy_pConfiguration)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pConfiguration != NULL)
	{
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN2, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN1, DIO_u8PIN_HIGH);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
/********************************************************************************************/
/********************************************************************************************/
uint8 M_voidMotor_Stop(const M_Config_t* Copy_pConfiguration)
{
	uint8 Local_u8ErrorState = OK;
	if(Copy_pConfiguration != NULL)
	{
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN1, DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Copy_pConfiguration -> M_u8PORT, Copy_pConfiguration -> M_u8PIN2, DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}


