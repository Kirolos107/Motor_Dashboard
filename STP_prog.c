#include "STD_TYPES.h"
#include "util/delay.h"
#include "ErrType.h"

#include "DIO_interface.h"
#include "STP_interface.h"


uint8 STP_u8Rotate(const STP_Config_t* Copy_pConfiguration, uint8 Copy_u8Direction, uint16 Copy_u8Angle)
{
	uint16 Local_u8Steps = (uint16)(((uint32)Copy_u8Angle * 2048UL) / 360UL);

	uint16 Local_u8Iterator = 0u;

	uint8 Local_u8ErrorState = OK;

	if(Copy_pConfiguration != NULL)
	{
		if(Copy_u8Direction == CCW_Rotate)
		{
			for(Local_u8Iterator = 0u; Local_u8Iterator < Local_u8Steps; Local_u8Iterator++)
			{
				if(Local_u8Iterator % 4 == 0)
				{
					/* Activate only the Blue wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 1)
				{
					/* Activate only the Pink wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 2)
				{
					/* Activate only the Yellow wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 3)
				{
					/* Activate only the Orange wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
			}
		}
		else if(Copy_u8Direction == RCW_Rotate)
		{
			for(Local_u8Iterator = 0u; Local_u8Iterator < Local_u8Steps; Local_u8Iterator++)
			{
				if(Local_u8Iterator % 4 == 0)
				{
					/* Activate only the Orange wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 1)
				{
					/* Activate only the Yellow wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 2)
				{
					/* Activate only the Pink wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
				else if(Local_u8Iterator % 4 == 3)
				{
					/* Activate only the Blue wire */
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Blue_PIN, DIO_u8PIN_LOW);

					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Pink_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Yellow_PIN, DIO_u8PIN_HIGH);
					DIO_u8SetPinValue(Copy_pConfiguration -> STP_u8PORT, Copy_pConfiguration -> STP_u8Orange_PIN, DIO_u8PIN_HIGH);
					_delay_ms(2);
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
