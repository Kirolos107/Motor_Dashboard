#ifndef STP_INTERFACE_H_
#define STP_INTERFACE_H_


typedef enum
{
	RCW_Rotate = 1u,
	CCW_Rotate = 2u

}STP_Rotate_t;

typedef struct
{
	uint8 STP_u8PORT;
	uint8 STP_u8Blue_PIN;
	uint8 STP_u8Pink_PIN;
	uint8 STP_u8Yellow_PIN;
	uint8 STP_u8Orange_PIN;

}STP_Config_t;


uint8 STP_u8Rotate(const STP_Config_t* Copy_pConfiguration, uint8 Copy_u8Direction, uint16 Copy_u8Angle);

#endif
