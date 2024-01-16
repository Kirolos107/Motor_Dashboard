#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "KPD_interface.h"
#include "MOTOR_interface.h"
#include "STP_interface.h"


void MD_voidWelcomScreen(void)
{
	CLCD_voidGoToXY(3, 0);
	CLCD_u8SendString("Welcome To");

	CLCD_voidGoToXY(0, 1);
	CLCD_u8SendString("Motor Dashboard!");
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidHamokshaRun(void)
{
	/* Hamoksha can run */
	uint8 Local_au8Run1[8] = {0b00000100, 0b00001010, 0b00001010, 0b00000100, 0b00000101, 0b00001110, 0b00010100, 0b00000100};
	uint8 Local_au8Run2[8] = {0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00001010, 0b00011001, 0b00000001, 0b00000000};

	uint8 Local_au8Run3[8] = {0b00000100, 0b00001010, 0b00001010, 0b00000100, 0b00000101, 0b00001110, 0b00010100, 0b00000100};
	uint8 Local_au8Run4[8] = {0b00000100, 0b00000100, 0b00000100, 0b00000100, 0b00001011, 0b00001001, 0b00010000, 0b00000000};

	uint8 Local_u8Iterator = 0u;

	for(Local_u8Iterator = 0u; Local_u8Iterator < 14; Local_u8Iterator++)
	{
		CLCD_u8SendSpecialCharacter(1, Local_au8Run1, Local_u8Iterator, 0);
		CLCD_u8SendSpecialCharacter(2, Local_au8Run2, Local_u8Iterator, 1);
		_delay_ms(100);
		CLCD_voidGoToXY(Local_u8Iterator,0);
		CLCD_voidSendData(' ');
		CLCD_voidGoToXY(Local_u8Iterator,1);
		CLCD_voidSendData(' ');

		CLCD_u8SendSpecialCharacter(3, Local_au8Run3, (Local_u8Iterator + 1), 0);
		CLCD_u8SendSpecialCharacter(4, Local_au8Run4, (Local_u8Iterator + 1), 1);
		_delay_ms(100);
		CLCD_voidGoToXY((Local_u8Iterator + 1),0);
		CLCD_voidSendData(' ');
		CLCD_voidGoToXY((Local_u8Iterator + 1),1);
		CLCD_voidSendData(' ');
	}
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidChooseMotor(void)
{
	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0, 0);
	CLCD_u8SendString("DC  Motor -> (1)");
	CLCD_voidGoToXY(0, 1);
	CLCD_u8SendString("STP Motor -> (2)");
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidDC_MotorChoices(void)
{
	CLCD_voidSendCmd(1);
	CLCD_voidGoToXY(0, 0);
	CLCD_u8SendString("Rotate CW  ->(1)");
	CLCD_voidGoToXY(0, 1);
	CLCD_u8SendString("Rotate CCW ->(2)");
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidRCW_Message(void)
{
	CLCD_voidSendCmd(1);
	CLCD_u8SendString("Motor Rotates in");

	CLCD_voidGoToXY(4,1);
	CLCD_u8SendString("ClockWise");
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidCCW_Message(void)
{
	CLCD_voidSendCmd(1);
	CLCD_u8SendString("Motor Rotates in");

	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("Counter ClockWise");
}
/********************************************************************************************/
/********************************************************************************************/
void MD_voidExitOrRestart(void)
{
	CLCD_voidSendCmd(1);
	CLCD_u8SendString("Motor Stopped");

	CLCD_voidGoToXY(0,1);
	CLCD_u8SendString("Exit(0), Rest(1)");
}
