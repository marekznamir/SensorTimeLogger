#ifndef DISPLAY_DISPLAY_H_
#define DISPLAY_DISPLAY_H_

#include "stdint.h"

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef int32_t I32;

void setDisplayChars(char letter);

void setDisplayDigits(U8 digit, U8 dispPos);

void showNumOfSectors(U8 NUM_OF_SECTORS);

void show4DigitNumber(I32 value);

void showAllZeros();

void processDisplayDigits();

void processDisplayChars();

void showEditChars();

void showTimeChars();

void showDashes();

// main functionality

void prepareTime(U32 lapTimeTick);

#endif
