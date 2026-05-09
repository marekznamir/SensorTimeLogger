#include "Modes.h"
#include "main.h"

#define KEY_UP   0x01
#define KEY_DWN  0x02

#define EDIT 0x00
#define TIME 0x01
#define ANIMATION 0x02

volatile U8 prevState = TIME;
volatile U8 state = ANIMATION; // normally animation
volatile U32 startHalTick = 0;
volatile U32 endHalTick = 0;

U8 sectorsDec = 0;
U8 NUM_OF_SECTORS = 2;
U8 lapCount = 0;

U32 lapTimeTick = 0;
U32 bestLapTimeTick = 0;

U8 prevSwitchesState = 0;
void editMode()
{
	U8 switchesState = 0;
	if (HAL_GPIO_ReadPin(BUTTON_INC_GPIO_Port, BUTTON_INC_Pin) == GPIO_PIN_RESET) switchesState |= KEY_UP;
	if (HAL_GPIO_ReadPin(BUTTON_DEC_GPIO_Port, BUTTON_DEC_Pin) == GPIO_PIN_RESET) switchesState |= KEY_DWN;

	U8 edgeDetect = (~prevSwitchesState) & switchesState;

	if (edgeDetect & KEY_UP)
	{
		NUM_OF_SECTORS++;
		showNumOfSectors(NUM_OF_SECTORS);
	}
	if (edgeDetect & KEY_DWN)
	{
		if(NUM_OF_SECTORS > 2)
		{
			NUM_OF_SECTORS--;
			showNumOfSectors(NUM_OF_SECTORS);
		}
	}

	prevSwitchesState = switchesState;

	processDisplayDigits();
	HAL_Delay(5);
}

void animationMode()
{
	processDisplayChars();
	HAL_Delay(5);
	if(HAL_GetTick() > endHalTick)
	{
		if(prevState == TIME)
		{
			state = EDIT;
		}
		else if(prevState == EDIT)
		{
			state = TIME;
		}
	}
}

void initEdit()
{
	showNumOfSectors(NUM_OF_SECTORS);
	showEditChars();
	startHalTick = (volatile U32)HAL_GetTick();
	endHalTick = startHalTick + 1500;
}

static U32 sectorsTimesTick[9999];
static U32 bestSectorsTimesTick[9999];

void processModeExti()
{
	if (state == ANIMATION)
	{
		return;
	}
	startHalTick = (volatile U32)HAL_GetTick();
	endHalTick = startHalTick + 1500;
	if(state == EDIT) // zmiana na TIME
	{
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		__HAL_TIM_SET_COUNTER(&htim9, 0);
		__HAL_TIM_ENABLE_IT(&htim9, TIM_IT_UPDATE);

		showTimeChars();
		showDashes();

		sectorsDec = NUM_OF_SECTORS;
	}
	else if(state == TIME) // zmiana na EDIT
	{
		showEditChars();
		showNumOfSectors(NUM_OF_SECTORS);

		lapCount = 0;
		lapTimeTick = 0;
		bestLapTimeTick = 0;
		delta = 0;
		lapToPrintAfterTime = 0;
		HAL_GPIO_WritePin(MINUS_GPIO_Port, MINUS_Pin, 1);

	}
	prevState = state;
	state = ANIMATION;
}

// main functionality

void processLapZero(U32 sectorTimeTick)
{
	int index = NUM_OF_SECTORS - sectorsDec;
	sectorsTimesTick[index] = sectorTimeTick;
	lapTimeTick += sectorTimeTick;

	if(sectorsDec != 1)
	{
		prepareTime(sectorTimeTick);

		sectorsDec--;
	}
	else
	{
		memcpy(bestSectorsTimesTick, sectorsTimesTick, sizeof(U32) * NUM_OF_SECTORS);
		bestLapTimeTick = lapTimeTick;

		prepareTime(lapTimeTick);
		//SDLogInt(lapTimeTick);

		lapTimeTick = 0;
		sectorsDec = NUM_OF_SECTORS;
		lapCount = 1;
	}
}

I32 delta = 0;
I32 lapToPrintAfterTime = 0;
void processLapTime(U32 sectorTimeTick)
{
	int index = NUM_OF_SECTORS - sectorsDec;
	sectorsTimesTick[index] = sectorTimeTick;
	lapTimeTick += sectorTimeTick;

	delta += (bestSectorsTimesTick[index] - sectorTimeTick);
	HAL_GPIO_WritePin(MINUS_GPIO_Port, MINUS_Pin, (delta < 0) ? 1 : 0);
	I32 newDelta = delta;
	if(delta < 0)
	{
		newDelta = -delta;
	}

	if(sectorsDec != 1)
	{
		prepareTime(newDelta);
		sectorsDec--;
	}
	else
	{
		if(lapTimeTick < bestLapTimeTick)
		{
			bestLapTimeTick = lapTimeTick;
			memcpy(bestSectorsTimesTick, sectorsTimesTick, sizeof(U32) * NUM_OF_SECTORS);
		}

		prepareTime(newDelta);

		lapToPrintAfterTime = lapTimeTick;
		//SDLogInt(lapTimeTick);

		HAL_TIM_Base_Start_IT(&htim9);

		lapTimeTick = 0;
		sectorsDec = NUM_OF_SECTORS;
		delta = 0;
		lapCount++;
	}
}



















