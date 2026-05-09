#include "display.h"
#include "main.h"

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef int32_t I32;

U8 dispPos = 0;
U8 dispDigit[4] = {0, 0, 0, 0};
U8 isDot[4] = {0, 0, 0, 0};
char dispChar[4] = {'E', 'D', 'I', 'T'};

U8 DIGIT_MAP[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

U8 ALPHABET_MAP[] = {
    0x77, // A
    0x7C, // b (małe, żeby nie mylić z 8)
    0x39, // C
    0x5E, // d (małe, żeby nie mylić z 0)
    0x79, // E
    0x71, // F
    0x3D, // G
    0x76, // H
    0x06, // I (tak samo jak 1)
    0x1E, // J
    0x75, // K (dosyć umowne)
    0x38, // L
    0x37, // M (często jako dwa łuki, tutaj góra/lewo/prawo)
    0x54, // n (małe)
    0x3F, // O (jak cyfra 0)
    0x73, // P
    0x67, // Q (często jak 9)
    0x50, // r
    0x6D, // S (jak cyfra 5)
    0x78, // t
    0x3E, // U
    0x1C, // v (często jak dolne u)
    0x1D, // W (trudne, tutaj dół/lewo/prawo)
    0x76, // X (często jak H)
    0x6E, // y
    0x5B  // Z (jak cyfra 2)
};

void setDisplayChars(char letter)
{
	I32 pos = letter - 'A';

	if(pos >= 0 && pos <= 25)
	{
		HAL_GPIO_WritePin(DISP_A_GPIO_Port, DISP_A_Pin, (ALPHABET_MAP[pos] & 0x01) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_B_GPIO_Port, DISP_B_Pin, (ALPHABET_MAP[pos] & 0x02) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_C_GPIO_Port, DISP_C_Pin, (ALPHABET_MAP[pos] & 0x04) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_D_GPIO_Port, DISP_D_Pin, (ALPHABET_MAP[pos] & 0x08) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_E_GPIO_Port, DISP_E_Pin, (ALPHABET_MAP[pos] & 0x10) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_F_GPIO_Port, DISP_F_Pin, (ALPHABET_MAP[pos] & 0x20) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_G_GPIO_Port, DISP_G_Pin, (ALPHABET_MAP[pos] & 0x40) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_DOT_GPIO_Port, DISP_DOT_Pin, 1);
	}
	else
	{
		HAL_GPIO_WritePin(DISP_A_GPIO_Port, DISP_A_Pin, 1);
		HAL_GPIO_WritePin(DISP_B_GPIO_Port, DISP_B_Pin, 1);
		HAL_GPIO_WritePin(DISP_C_GPIO_Port, DISP_C_Pin, 1);
		HAL_GPIO_WritePin(DISP_D_GPIO_Port, DISP_D_Pin, 1);
		HAL_GPIO_WritePin(DISP_E_GPIO_Port, DISP_E_Pin, 1);
		HAL_GPIO_WritePin(DISP_F_GPIO_Port, DISP_F_Pin, 1);
		HAL_GPIO_WritePin(DISP_G_GPIO_Port, DISP_G_Pin, 1);
		HAL_GPIO_WritePin(DISP_DOT_GPIO_Port, DISP_DOT_Pin, 1);
	}
}

void setDisplayDigits(U8 digit, U8 dispPos)
{
	if(digit <= 9 && digit >= 0)
	{
		HAL_GPIO_WritePin(DISP_A_GPIO_Port, DISP_A_Pin, (DIGIT_MAP[digit] & 0x01) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_B_GPIO_Port, DISP_B_Pin, (DIGIT_MAP[digit] & 0x02) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_C_GPIO_Port, DISP_C_Pin, (DIGIT_MAP[digit] & 0x04) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_D_GPIO_Port, DISP_D_Pin, (DIGIT_MAP[digit] & 0x08) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_E_GPIO_Port, DISP_E_Pin, (DIGIT_MAP[digit] & 0x10) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_F_GPIO_Port, DISP_F_Pin, (DIGIT_MAP[digit] & 0x20) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_G_GPIO_Port, DISP_G_Pin, (DIGIT_MAP[digit] & 0x40) ? 0 : 1);
		HAL_GPIO_WritePin(DISP_DOT_GPIO_Port, DISP_DOT_Pin, (isDot[dispPos] & 0x01) ? 0 : 1);
	}
	else if(digit == '-')
		{
			HAL_GPIO_WritePin(DISP_A_GPIO_Port, DISP_A_Pin, 1);
			HAL_GPIO_WritePin(DISP_B_GPIO_Port, DISP_B_Pin, 1);
			HAL_GPIO_WritePin(DISP_C_GPIO_Port, DISP_C_Pin, 1);
			HAL_GPIO_WritePin(DISP_D_GPIO_Port, DISP_D_Pin, 1);
			HAL_GPIO_WritePin(DISP_E_GPIO_Port, DISP_E_Pin, 1);
			HAL_GPIO_WritePin(DISP_F_GPIO_Port, DISP_F_Pin, 1);
			HAL_GPIO_WritePin(DISP_G_GPIO_Port, DISP_G_Pin, 0);
			HAL_GPIO_WritePin(DISP_DOT_GPIO_Port, DISP_DOT_Pin, 1);
		}
	else
	{
		HAL_GPIO_WritePin(DISP_A_GPIO_Port, DISP_A_Pin, 1);
		HAL_GPIO_WritePin(DISP_B_GPIO_Port, DISP_B_Pin, 1);
		HAL_GPIO_WritePin(DISP_C_GPIO_Port, DISP_C_Pin, 1);
		HAL_GPIO_WritePin(DISP_D_GPIO_Port, DISP_D_Pin, 1);
		HAL_GPIO_WritePin(DISP_E_GPIO_Port, DISP_E_Pin, 1);
		HAL_GPIO_WritePin(DISP_F_GPIO_Port, DISP_F_Pin, 1);
		HAL_GPIO_WritePin(DISP_G_GPIO_Port, DISP_G_Pin, 1);
		HAL_GPIO_WritePin(DISP_DOT_GPIO_Port, DISP_DOT_Pin, 1);
	}
}

void showNumOfSectors(U8 NUM_OF_SECTORS)
{
	if(NUM_OF_SECTORS < 10)
	{
		dispDigit[0] = 11;
		dispDigit[1] = 11;
	    dispDigit[2] = 11;
		dispDigit[3] = NUM_OF_SECTORS;
	}
	else if(NUM_OF_SECTORS < 100)
	{
		dispDigit[0] = 11;
		dispDigit[1] = 11;
		for(int i = 3; i >= 2; i--)
		{
			dispDigit[i] = (U8)(NUM_OF_SECTORS % 10);
			NUM_OF_SECTORS /= 10;
		}
	}
	else if(NUM_OF_SECTORS < 1000)
	{
		dispDigit[0] = -1;
		for(int i = 3; i >= 1; i--)
		{
			dispDigit[i] = (U8)(NUM_OF_SECTORS % 10);
			NUM_OF_SECTORS /= 10;
		}
	}
	else if(NUM_OF_SECTORS < 10000)
	{
		show4DigitNumber(NUM_OF_SECTORS);
	}
	else
	{
		dispDigit[0] = -1;
		dispDigit[1] = -1;
	    dispDigit[2] = -1;
		dispDigit[3] = -1;
	}
}

void show4DigitNumber(I32 value)
{
	for(int i = 3; i >= 0; i--)
	{
		dispDigit[i] = (U8)(value % 10);
		value /= 10;
	}
}

void showAllZeros()
{
	dispDigit[0] = 0;
	dispDigit[1] = 0;
	dispDigit[2] = 0;
	dispDigit[3] = 0;
}

void processDisplayDigits()
{
	HAL_GPIO_WritePin(DISP_COMM_1_GPIO_Port, DISP_COMM_1_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_2_GPIO_Port, DISP_COMM_2_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_3_GPIO_Port, DISP_COMM_3_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_4_GPIO_Port, DISP_COMM_4_Pin, 1);

    setDisplayDigits(dispDigit[dispPos], dispPos);

	U8 dispComm = 1 << dispPos;

	HAL_GPIO_WritePin(DISP_COMM_1_GPIO_Port, DISP_COMM_1_Pin, (dispComm & 1) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_2_GPIO_Port, DISP_COMM_2_Pin, (dispComm & 2) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_3_GPIO_Port, DISP_COMM_3_Pin, (dispComm & 4) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_4_GPIO_Port, DISP_COMM_4_Pin, (dispComm & 8) ? 0 : 1);

	if (dispPos == 3)
	{
		dispPos = 0;
	}
	else
	{
		dispPos++;
	}
}

void processDisplayChars()
{
	HAL_GPIO_WritePin(DISP_COMM_1_GPIO_Port, DISP_COMM_1_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_2_GPIO_Port, DISP_COMM_2_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_3_GPIO_Port, DISP_COMM_3_Pin, 1);
	HAL_GPIO_WritePin(DISP_COMM_4_GPIO_Port, DISP_COMM_4_Pin, 1);

    setDisplayChars(dispChar[dispPos]);

	U8 dispComm = 1 << dispPos;

	HAL_GPIO_WritePin(DISP_COMM_1_GPIO_Port, DISP_COMM_1_Pin, (dispComm & 1) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_2_GPIO_Port, DISP_COMM_2_Pin, (dispComm & 2) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_3_GPIO_Port, DISP_COMM_3_Pin, (dispComm & 4) ? 0 : 1);
	HAL_GPIO_WritePin(DISP_COMM_4_GPIO_Port, DISP_COMM_4_Pin, (dispComm & 8) ? 0 : 1);

	if (dispPos == 3)
	{
		dispPos = 0;
	}
	else
	{
		dispPos++;
	}
}

void showEditChars()
{
	  dispChar[0] = 'E';
	  dispChar[1] = 'D';
	  dispChar[2] = 'I';
	  dispChar[3] = 'T';
}

void showTimeChars()
{
	  dispChar[0] = 'T';
	  dispChar[1] = 'I';
	  dispChar[2] = 'M';
	  dispChar[3] = 'E';
}

void showDashes()
{
	dispDigit[0] = '-';
	dispDigit[1] = '-';
	dispDigit[2] = '-';
	dispDigit[3] = '-';
}

// main time functionality

void prepareTime(U32 lapTimeTick)
{
	U32 rest = lapTimeTick;

	U32 minutes = rest / (60000);
	rest -= minutes * (60000);

	U32 seconds = rest / (1000);
	rest -= seconds * (1000);

	U32 tenthsSec = rest / (100);
	rest -= tenthsSec * (100);

	U32 hundrethSec = rest / (10);
	rest -= hundrethSec * (10);

	U32 thousandthSec = rest;

	if(minutes != 0)
	{
		dispDigit[0] = minutes;
		isDot[0] = 1;

		U8 secFirstDigit  = seconds / 10;
		dispDigit[1] = secFirstDigit;
		isDot[1] = 0;

		U8 secSecondDigit  = seconds % 10;
		dispDigit[2] = secSecondDigit;
		isDot[2] = 1;

		dispDigit[3] = tenthsSec;
		isDot[3] = 0;
	}
	else if(seconds != 0)
	{
		U8 secFirstDigit  = seconds / 10;
		dispDigit[0] = secFirstDigit;
		isDot[0] = 0;

		U8 secSecondDigit  = seconds % 10;
		dispDigit[1] = secSecondDigit;
		isDot[1] = 1;

		dispDigit[2] = tenthsSec;
		isDot[2] = 0;

		dispDigit[3] = hundrethSec;
		isDot[3] = 0;
	}
	else
	{
		dispDigit[0] = 0;
		isDot[0] = 1;

		dispDigit[1] = tenthsSec;
		isDot[1] = 0;

		dispDigit[2] = hundrethSec;
		isDot[2] = 0;

		dispDigit[3] = thousandthSec;
		isDot[3] = 0;
	}
}
