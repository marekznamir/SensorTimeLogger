#ifndef MODES_MODES_H_
#define MODES_MODES_H_

#include "main.h"
#include "../Display/display.h"
#include <stdlib.h>
#include <string.h>


#define EDIT 0x00
#define TIME 0x01
#define ANIMATION 0x02

extern volatile U8 prevState;
extern volatile U8 state;
extern volatile U32 startHalTick;
extern volatile U32 endHalTick;

extern U8 prevSwitchesState;
void editMode();

void animationMode();

void initEdit();

static U32 sectorsTimesTick[9999];
static U32 bestSectorsTimesTick[9999];

void processModeExti();

// main functionality

extern U8 sectorsDec;
extern U8 NUM_OF_SECTORS;
extern U32 prevMeasurment;
extern U8 lapCount;

void processLapZero(U32 sectorTimeTick);

extern I32 delta;
extern I32 lapToPrintAfterTime;
void processLapTime(U32 sectorTimeTick);

#endif
