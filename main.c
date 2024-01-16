#include "STD_TYPES.h"
#include "util/delay.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "MOTOR_interface.h"
#include "STP_interface.h"

#include "App.h"

void main (void)
{
	PORT_voidInit();
	CLCD_voidInit();;

	uint8 Local_u8KeypadKey;       // Variable to store the pressed key
	uint16 Local_u8STP_Angle = 0u; // Variable to the stepper motor angle

	/* DC motor configuration */
	M_Config_t DC_Config =
	{
			.M_u8PORT = DIO_u8PORTC,
			.M_u8PIN1 = DIO_u8PIN0,
			.M_u8PIN2 = DIO_u8PIN1,
	};


	/* Stepper motor configuration */
	STP_Config_t STP_Config =
	{
			.STP_u8PORT       = DIO_u8PORTC,
			.STP_u8Blue_PIN   = DIO_u8PIN2,
			.STP_u8Pink_PIN   = DIO_u8PIN3,
			.STP_u8Yellow_PIN = DIO_u8PIN4,
			.STP_u8Orange_PIN = DIO_u8PIN5
	};


	while(1)
	{
		Local_u8STP_Angle = 0u; // Reset the stepper motor angle every program starting

		/* Display welcome screen */
		MD_voidWelcomScreen();

		_delay_ms(1500);
		CLCD_voidSendCmd(1);

		//MD_voidHamokshaRun();

		/* Choose the required motor mode*/
		MD_voidChooseMotor();



		do
		{
			Local_u8KeypadKey = KPD_u8GetPressedKey();

		}while(Local_u8KeypadKey == 0xff);

/*********************************************************************************************/
/**************************************** DC motor mode **************************************/
/*********************************************************************************************/
		if(Local_u8KeypadKey == 1)
		{
			/* DC motor mode */
			MD_voidDC_MotorChoices();

			do
			{
				Local_u8KeypadKey = KPD_u8GetPressedKey();

			}while(Local_u8KeypadKey == 0xff);

			if(Local_u8KeypadKey == 1)
			{
				/* DC motor mode (Rotate CW) */
				MD_voidRCW_Message();

				M_voidMotor_Rotate_CW(&DC_Config);
				_delay_ms(5000);
				M_voidMotor_Stop(&DC_Config);

				MD_voidExitOrRestart();

				do
				{
					Local_u8KeypadKey = KPD_u8GetPressedKey();

				}while(Local_u8KeypadKey == 0xff);

				if(Local_u8KeypadKey == 0)
				{
					/* Exit from the program */
					CLCD_voidSendCmd(1);
					CLCD_voidGoToXY(4, 0);
					CLCD_u8SendString("Goodbye!");
					break;
				}
				else if(Local_u8KeypadKey == 1)
				{
					/* Restart the program */
					CLCD_voidSendCmd(1);
					continue;
				}
			}
			else if(Local_u8KeypadKey == 2)
			{
				/* DC motor mode (Rotate CCW) */
				MD_voidCCW_Message();

				M_voidMotor_Rotate_CCW(&DC_Config);
				_delay_ms(5000);
				M_voidMotor_Stop(&DC_Config);

				MD_voidExitOrRestart();

				do
				{
					Local_u8KeypadKey = KPD_u8GetPressedKey();

				}while(Local_u8KeypadKey == 0xff);

				if(Local_u8KeypadKey == 0)
				{
					/* Exit from the program */
					CLCD_voidSendCmd(1);
					CLCD_voidGoToXY(4, 0);
					CLCD_u8SendString("Goodbye!");
					break;
				}
				else if(Local_u8KeypadKey == 1)
				{
					/* Restart the program */
					CLCD_voidSendCmd(1);
					continue;
				}
			}

		}
/*********************************************************************************************/
/************************************* Stepper motor mode ************************************/
/*********************************************************************************************/
		else if(Local_u8KeypadKey == 2)
		{
			/* Stepper motor mode */
			CLCD_voidSendCmd(1);
			CLCD_voidGoToXY(0, 0);
			CLCD_u8SendString("Rotate CW  ->(1)");
			CLCD_voidGoToXY(0, 1);
			CLCD_u8SendString("Rotate CCW ->(2)");

			do
			{
				Local_u8KeypadKey = KPD_u8GetPressedKey();

			}while(Local_u8KeypadKey == 0xff);

			if(Local_u8KeypadKey == 1)
			{
				/* Stepper motor mode (Rotate CW) */
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0, 0);
				CLCD_u8SendString("Angle -> ");

				/* Enter the angle */
				while(Local_u8KeypadKey != '=')
				{
					do
					{
						Local_u8KeypadKey = KPD_u8GetPressedKey();

					}while(Local_u8KeypadKey == 0xff);

					if(Local_u8KeypadKey != '=')
					{
						CLCD_voidSendNumber(Local_u8KeypadKey);
						Local_u8STP_Angle = (Local_u8STP_Angle * 10) + Local_u8KeypadKey;
					}
				}

				MD_voidCCW_Message();

				STP_u8Rotate(&STP_Config, RCW_Rotate, Local_u8STP_Angle);

				MD_voidExitOrRestart();

				do
				{
					Local_u8KeypadKey = KPD_u8GetPressedKey();

				}while(Local_u8KeypadKey == 0xff);

				if(Local_u8KeypadKey == 0)
				{
					/* Exit from the program */
					CLCD_voidSendCmd(1);
					CLCD_voidGoToXY(4, 0);
					CLCD_u8SendString("Goodbye!");
					break;
				}
				else if(Local_u8KeypadKey == 1)
				{
					/* Restart the program */
					CLCD_voidSendCmd(1);
					continue;
				}
			}
			else if(Local_u8KeypadKey == 2)
			{
				/* Stepper motor mode (Rotate CCW) */
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(0, 0);
				CLCD_u8SendString("Angle -> ");

				/* Enter the angle */
				while(Local_u8KeypadKey != '=')
				{
					do
					{
						Local_u8KeypadKey = KPD_u8GetPressedKey();

					}while(Local_u8KeypadKey == 0xff);

					if(Local_u8KeypadKey != '=')
					{
						CLCD_voidSendNumber(Local_u8KeypadKey);
						Local_u8STP_Angle = (Local_u8STP_Angle * 10) + Local_u8KeypadKey;
					}
				}

				MD_voidCCW_Message();

				STP_u8Rotate(&STP_Config, CCW_Rotate, Local_u8STP_Angle);

				MD_voidExitOrRestart();

				do
				{
					Local_u8KeypadKey = KPD_u8GetPressedKey();

				}while(Local_u8KeypadKey == 0xff);

				if(Local_u8KeypadKey == 0)
				{
					/* Exit from the program */
					CLCD_voidSendCmd(1);
					CLCD_voidGoToXY(4, 0);
					CLCD_u8SendString("Goodbye!");
					break;
				}
				else if(Local_u8KeypadKey == 1)
				{
					/* Restart the program */
					CLCD_voidSendCmd(1);
					continue;
				}
			}
		}
	}
}



