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
  {113,199},
  {123,250},
  {113,183},
  {124,183,true},
  {113,201},
  {105,250},
  {113,185},
  {124,185},
  {123,185},
  {123,185},
  {123,185},
  {124,185},
  {113,185},
  {123,185},
  {113,185},
  {124,185},
  {113,185},
  {113,185},
  {113,185},
  {124,185},
  {123,185},
  {123,185},
  {123,185},
  {124,185},
  {113,185},
  {105,185},
  {113,185},
  {124,185},
  {113,185},
  {113,185},
  {113,185},
  {124,185},
};

struct Gap
{
  uint8_t xSpot;
  uint8_t gapWidth;
};

constexpr Gap gapInfo[] PROGMEM  
{
  //1-1 gaps
  {70,2},
  {87,3},
  {154,2},

  //1-2 gaps
  {81,3},
  {121,2},
  {125,2},
  {139,7},
  {154,7},

  //1-3 gaps
  {17,120},
  //{1,65},

  //1-4 gaps
  {14,2},
  {27,3},
  {33,3},

  //2-1 gaps
  {93,4},
  {107,3},
  {140,3},
  {153,2},

  //2-2 gaps
  {67,5},
  {133,9},
  {160,7},

  //2-3 gaps
  {8,201},
  
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
  {29,01},
  {39,11},
  {47,21},
  {58,21},
  {164,01},
  {180,01},//ends 1-1

  //1-2 pipes
  {104,11},
  {110,21},
  {116,01},
  {169,93},
  {179,11},
  {183,11},
  {187,11},

  //2-1 pipes
  {47,21},
  {76,21},
  {105,21},
  {117,01},
  {124,21},
  {128,11},
  {132,31},
  {179,11},

  //3-1 pipes NOTHING DONE
  {31,21},
  {31,21},
  {13,01},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,1},
  {31,21},
  {42,21},
  {148,01},
  {165,01},//ends 1-1
  {103,11},
  {109,21},
  {115,01},
  {168,43},//ends 1-2,1-3, and 1-4
  {47,21},
  {75,21},
  {104,21},
  {116,01},
  {123,21},
  {127,11},
  {131,31},
  {167,11},//ends 2-1, 2-2, 2-3, and 2-4
  {31,21},
  {31,21},
  {13,01},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,11},
  {31,21},
  {42,21},
  {148,01},
  {165,01},//ends 1-1
  {103,11},
  {109,21},
  {115,01},
  {168,43},//ends 1-2,1-3, and 1-4
  {47,21},
  {75,21},
  {104,21},
  {116,01},
  {123,21},
  {127,11},
  {131,31},
  {167,11},//ends 2-1, 2-2, 2-3, and 2-4
  {31,21},
  {31,21},
  {13,01},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,11},
  {31,21},
  {42,21},
  {148,01},
  {165,01},//ends 1-1
  {103,11},
  {109,21},
  {115,01},
  {168,43},//ends 1-2,1-3, and 1-4
  {47,21},
  {75,21},
  {104,21},
  {116,01},
  {123,21},
  {127,11},
  {131,31},
  {167,11},//ends 2-1, 2-2, 2-3, and 2-4
  {31,21},
  {31,21},
  {13,01},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,11},
  {31,21},
  {42,21},
  {148,01},
  {165,01},//ends 1-1
  {103,11},
  {109,21},
  {115,01},
  {168,43},//ends 1-2,1-3, and 1-4
  {47,21},
  {75,21},
  {104,21},
  {116,01},
  {123,21},
  {127,11},
  {131,31},
  {167,11},//ends 2-1, 2-2, 2-3, and 2-4
  {31,21},
  {31,21},
  {13,01},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,11},
  {31,21},
  {42,21},
  {148,01},
  {165,01},//ends 1-1
  {103,11},
  {109,21},
  {115,01},
  {168,43},//ends 1-2,1-3, and 1-4
  {47,21},
  {75,21},
  {104,21},
  {116,01},
  {123,21},//last
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
  {17,85},
  {22,85},
  {24,85},
  {23,81,true},
  {65,96},//life block
  {78,75},
  {79,85},
  {80,75},
  {95,81,true},//question block
  {95,75},
  {107,85},
  {110,85},
  {110,81,true},
  {113,85},
  {119,75},
  {129,71,true},
  {130,81,true},
  {131,81,true},
  {132,71,true},
  {153,16},
  {171,85},

  //1-2 blocks
  {18,62},
  {30,96},
  {41,106},
  {41,27},
  {46,106},
  {46,27},
  {69,106},
  {138,26},

  //1-4 blocks
  {24,98},
  {24,49},
  {31,88},
  {38,98},
  {81,43,true},
  {89,43,true},

  //2-1 blocks
  {69,75},
  {162,75},
  {171,85},
  {173,79},
  

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
  {21,5,75},
  {81,8,71,true},
  {92,3,71,true},
  {101,2,75},
  {122,3,71,true},
  {130,2,75},
  {169,4,75},

  //1-2 rows
  {7,132,74,true},
  {11,5,85},
  {42,4,109},
  {59,4,106},
  {77,4,75},
  {85,6,109},
  {146,6,76},
  {162,26,74,true},

  //1-4 rows
  {1,160,44,true},
  {36,36,45},

  //2-1 rows
  {16,3,75},
  {30,3,79},
  {54,5,85},
  {54,5,89},
  {70,4,79},
  {80,4,85},
  {82,5,79},
  {86,3,85},
  {93,4,79},
  {126,4,79},
  {165,5,79},
  {186,2,75},

  //2-2 rows
  {15,2,102},
  {19,3,55},
  {28,3,109},
  {37,3,102},
  {43,2,55},
  {68,3,104},
  {84,3,59},
  {103,3,103},
  {104,2,55},
  {115,3,108},
  {117,2,56},
  {133,9,51,true},
  {136,3,102},
  {162,3,102},
  {162,3,105},
  {175,5,55},
  {175,5,59},
  {183,5,55},
  {183,5,59},

  //2-3 rows
  {16,48,124},
  {16,49,135},
  {54,10,124},
  {54,10,135},
  {70,11,124},
  {70,11,135},
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
  {1,112,7},
  {20,22,6},
  {22,32,6},
  {24,42,6},
  {26,42,6},
  {28,32,6},
  {32,32,6},
  {34,22,6},
  {68,55,7},

  



  //2-1 columns
  {35,42,6},
  {36,22,6},
  {155,32,6},

  //2-2 columns
  {12,32,14},
  {34,52,14},
  {43,26,14},
  {51,42,14},
  {85,46,14},
  {91,32,14},
  {104,32,14},
  {122,24,14},
  {150,22,14},
  {152,32,14},
  {176,29,14},
  {65,32,5},
  {66,52,5},
  {72,52,5},
  {73,32,5},
  
  {131,42,5},
  {132,22,5},
  {143,22,5},
  {144,42,5},
  {159,82,5},
  {167,82,5},

  //2-3 columns
  {32,41,6},
  {48,41,6},
  {53,41,6},
  {64,41,6},
  {69,41,6},
  {81,41,6},
  {85,51,6},
  {91,51,6},
  {113,41,6},
  {129,41,6},
  {132,21,6},
  {142,21,6},
  {146,41,6},
  {155,41,6},
  {170,41,6},

  
};

struct Stairs
{
  uint8_t xSpot;
  uint8_t faceRightBlockWidthBlockType;
};

constexpr Stairs stairInfo [] PROGMEM
{
  //1-1 stairs
  {135,116},
  {141,216},
  {149,126},
  {156,216},
  {182,146},

  //1-2 stairs
  {134,126},

  //1-4 stairs
  {3,234},

  //2-1 stairs
  {21,126},

  //2-2 stairs
  {188,125},

  //2-3 stairs
  {11,126},
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
  {189,28,2,106},

  //1-2 rectangles
  {40,53,8,107},
  {43,52,2,102},
  {53,57,12,107},
  {53,102,2,102},
  {55,33,2,107},
  {55,64,8,102},
  {57,57,2,102},
  {67,102,4,107},
  {69,52,2,107},
  {73,55,2,107},

  {77,102,4,107},
  
  {85,62,6,107},
  {123,23,2,107},
  {161,23,17,107},
  {171,59,7,107},
  {191,27,2,207},//after warp pipes

  //1-4 rectangles
  {1,102,24,104},
  {1,53,2,104},
  {38,93,34,104},
  {98,102,30,104},
  {106,26,18,202},
  {117,23,4,104},

  //2-1 rectangles
  {191,26,2,206},

  //2-2 rectangles
  {80,23,2,105},
  {80,103,2,105},
  {191,94,2,105},
  //CHECK THESE LAST 2
  {191,18,2,205},

  //2-3 rectangles
  {14,52,2,101},
  

 
 
};
