#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>




//everything below here is an array that saves data for each build function
//In total, there will be a function to make 7 chunks of levels
//gaps in the ground tiles
//pipes
//single blocks
//horizontal rows
//vertical columns
//stairs, like the ones before the flagpole
//rectangles of blocks

//this one isn't super important, each number place saves a piece of the level theme
//for example, if the middle is 1, sky is white. If 2, black. 

struct Level
{
  uint8_t themeInfo;
  uint8_t endSpot;
  bool tallFloor;
};

constexpr Level levelInfo[] PROGMEM 
{
  {113,183},
  {123,183},
  {113,183},
  {124,183,true},
  {113,185},
  105,
  113,
  124,
  123,
  123,
  123,
  124,
  113,
  123,
  113,
  124,
  113,
  113,
  113,
  124,
  123,
  123,
  123,
  124,
  113,
  105,
  113,
  124,
  113,
  113,
  113,
  124,
};

struct Gap
{
  uint8_t xSpot;
  uint8_t gapWidth;
};

constexpr Gap gapInfo[] PROGMEM  
{
  //1-1 gaps
  {54,2},
  {71,3},
  {138,2},

  //1-2 gaps
  {65,3},
  {105,2},
  {109,2},
  {123,7},
  {138,7},

  //1-3 gaps
  {1,65},

  //1-4 gaps
  {11,3},
  {17,3},

  //2-1 gaps
  {77,4},
  {91,3},
  {124,3},
  {137,2},
  
};

//first int is the x position of the pipe
//second int is split(1st place does nothing)
//second place can be 0-4, tells how tall the pipe will be
//third place can be 0-9, tells where the y position of the pipe starts
struct Pipe
{
  uint8_t xSpot;
  uint8_t pipeHeightySpot;
  //bool isTall;
};

constexpr Pipe pipeInfo[] PROGMEM
{
  //1-1 pipes
  {13,101},
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {164,101},//ends 1-1

  //1-2 pipes
  {88,111},
  {94,121},
  {100,101},
  {153,183},

  //2-1 pipes
  {31,121},
  {59,121},
  {88,121},
  {100,101},
  {107,121},
  {111,111},
  {115,131},
  {161,111},

  //3-1 pipes NOTHING DONE
  {31,121},
  {31,121},
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {165,101},//ends 1-1
  {103,111},
  {109,121},
  {115,101},
  {168,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},
  {127,111},
  {131,131},
  {167,111},//ends 2-1, 2-2, 2-3, and 2-4
  {31,121},
  {31,121},
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {165,101},//ends 1-1
  {103,111},
  {109,121},
  {115,101},
  {168,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},
  {127,111},
  {131,131},
  {167,111},//ends 2-1, 2-2, 2-3, and 2-4
  {31,121},
  {31,121},
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {165,101},//ends 1-1
  {103,111},
  {109,121},
  {115,101},
  {168,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},
  {127,111},
  {131,131},
  {167,111},//ends 2-1, 2-2, 2-3, and 2-4
  {31,121},
  {31,121},
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {165,101},//ends 1-1
  {103,111},
  {109,121},
  {115,101},
  {168,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},
  {127,111},
  {131,131},
  {167,111},//ends 2-1, 2-2, 2-3, and 2-4
  {31,121},
  {31,121},
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {165,101},//ends 1-1
  {103,111},
  {109,121},
  {115,101},
  {168,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},//last
};

struct Block
{
  uint8_t xSpot;
  uint8_t blockTypeySpot;
  bool extraHeight;
};

constexpr Block blockInfo[] PROGMEM
{
  //1-1 blocks
  {1,85},
  {5,75},
  {6,85},
  {7,75},
  {8,85},
  {9,75},
  {7,81,true},
  {49,96},//life block
  {62,75},
  {63,85},
  {64,75},
  {79,81,true},//question block
  {79,75},
  {91,85},
  {94,85},
  {94,81,true},
  {97,85},
  {103,75},
  {113,71,true},
  {114,81,true},
  {115,81,true},
  {116,71,true},
  {137,16},
  {155,85},
  {156,75},

  //1-2 blocks
  {2,62},
  {14,96},

  //1-4 blocks
  {8,98},
  {8,49},
  {15,88},
  {22,98},
  

};

struct Row
{
  uint8_t xSpot;
  uint8_t xWidth;
  uint8_t blockTypeySpot;
  bool extraHeight;
};

constexpr Row rowInfo [] PROGMEM
{
  //1-1 rows
  {65,8,71,true},
  {76,3,71,true},
  {85,2,75},
  {106,3,71,true},
  {114,2,75},
  {153,2,75},

  //1-2 rows
  {1,100,74,true},
  {26,4,109},
  {43,4,106},
  {61,4,75},
  {69,6,109},
  {130,6,76},
  {146,26,74,true},

  //1-4 rows
  {1,150,44,true},
  {20,37,45},

  //2-1 rows
  {13,4,79},
  {38,5,85},
  {38,5,89},
  {54,4,79},
  {64,4,85},
  {66,5,79},
  {70,3,85},
  {77,4,79},
  {110,4,79},
  {149,5,79},
  {170,2,75},
};

struct Column 
{
  uint8_t xSpot;
  uint8_t yHeightySpot;
  uint8_t blockType;
};

constexpr Column columnInfo [] PROGMEM
{
  //1-2 columns
  {4,122,6},
  {6,132,6},
  {8,142,6},
  {10,142,6},
  {12,132,6},
  {16,132,6},
  {18,122,6},
  {24,126,7},
  {27,125,2},
  {29,126,7},
  {41,193,2},
  {50,155,2},
  {53,137,2},


  //2-1 columns
  {19,142,6},
  {20,122,6},
  {139,132,6},
};

struct Stairs
{
  uint8_t xSpot;
  uint8_t faceRightBlockWidthBlockType;
};

constexpr Stairs stairInfo [] PROGMEM
{
  //1-1 stairs
  {119,116},
  {125,216},
  {133,126},
  {140,216},
  {166,146},

  //1-2 stairs
  {118,126},

  //2-1 stairs
  {5,126},
};

struct Rectangle
{
  uint8_t xSpot;
  uint8_t ySpotBlockHeight;
  uint8_t blockWidth;
  uint8_t extraHeightBlockType;
};

constexpr Rectangle rectInfo [] PROGMEM
{
  //1-1 rectangles
  {173,128,2,106},

  //1-2 rectangles
  {24,153,8,107},
  {37,157,12,107},
  {39,133,2,107},
  {39,164,7,102},
  {51,157,4,107},
  {57,155,2,107},
  {69,162,6,107},
  {107,123,2,107},
  {145,123,17,107},
  {155,159,7,107},

  //1-4 rectangles
  {1,202,8,104},
  {22,193,35,104},
  {83,202,31,104},
  {90,126,18,202},
  {102,123,4,104},

  //2-1 rectangles
  {175,126,2,206},
 
};
