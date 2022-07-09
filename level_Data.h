#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>

#include "byteFunctions.h"



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
  {113,182},//1-1
  {123,250},
  {113,136},
  {124,129,true},
  
  {113,184},//2-1
  {125,250},
  {113,209},
  {124,129,true},
  
  {123,184},//3-1
  {123,193},
  {123,140},
  {124,129,true},
  
  {113,209},//4-1
  {123,250},
  {113,148},
  {124,161,true},
  
  {113,183},//5-1
  {113,184},
  {113,136},
  {124,129,true},

  
  {123,170},//6-1
  {123,200},
  {123,160},
  {124,129,true},

  
  {113,163},//7-1
  {125,250},
  {113,209},
  {124,193,true},

  
  {113,185},//8-1
  {113,200},
  {113,198},
  //not done?
  {124,185},

  {123,185},//SUB AREA 1
  {123,185},//SUB AREA 2
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
  {17,113},

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
  {132,9},
  {158,7},

  //2-3 gaps
  {8,200},

  //2-4 gaps
  {17,16},
  {85,8},
  {110,2},
  {114,2},
  {121,2},
  {125,2},

  //3-1 gaps
  {46,3},
  {78,8},
  {87,2},
  {129,4},
  {143,2},
  {178,3},

  //3-2 gaps
  {81,2},
  {124,2},
  {129,2},

  //3-2 gaps
  {17,128},

  //3-4 gaps
  {17,2},
  {22,2},
  {27,2},
  {32,2},
  {47,2},
  {89,2},
  {97,3},
  {103,3},
  {109,3},

  //4-1 gaps
  {33,2},
  {79,4},
  {150,2},
  {175,3},
  {181,2},
  {191,2},

  //4-2 gaps
  {12,2},
  {16,2},
  {19,3},
  {58,6},
  {106,2},
  {110,2},
  {114,6},
  {124,6},
  {145,2},
  {156,5},
  {184,2},

  //4-3 gaps
  {16,126},

  //4-4 gaps
  {8,2},
  {12,2},
  {89,2},
  {92,4},

  //5-1 gaps
  {50,2},
  {93,4},
  {115,2},
  {153,3},

  //5-2 gaps
  {27,3},
  {67,2},
  {93,4},
  {128,2},
  {145,7},
  {171,3},
  {176,2},

  //5-3 gaps
  {17,113},

  //5-4 gaps
  {17,16},
  {85,8},
  {110,2},
  {114,2},
  {121,2},
  {125,2},

  //6-1 gaps
  {21,2},
  {32,6},
  {40,2},
  {58,2},
  {75,3},
  {94,3},
  {128,7},
  {137,1},
  {150,6},
  {165,3},

  //6-2 gaps
  {124,6},
  {142,1},
  {144,1},
  {153,1},

  //6-3 gaps
  {17,145},

  //6-4 gaps
  {14,2},
  {27,3},
  {33,3},

  //7-1 gaps
  {74,2},
  {153,1},

  //7-2 gaps
  {67,5},
  {132,9},
  {158,7},

  //7-3 gaps
  {8,200},

  //7-4 gaps
  {17,11},
  {101,3},
  {105,3},
  {161,3},
  {167,2},
  {177,2},
  {181,2},
  {185,2},

  //8-1 PART ONE gaps
  {47,1},
  {49,1},
  {52,1},
  {55,1},
  {58,1},
  {170,1},
  {172,1},
  {175,1},
  {177,1},
  {180,1},
  {198,1},
  {200,1},
  {202,1},
  {222,6},

  //8-2 gaps
  {16,1},
  {37,1},
  {46,1},
  {51,1},
  {53,1},
  {57,1},
  {64,1},
  {79,2},
  {85,1},
  {139,1},
  {145,1},
  {147,1},
  {149,6},
  {175,1},
  {177,3},

  //8-3 gaps
  {70,2},
  {76,2},
  {125,2},
  {129,2},
  
};

//first int is the x position of the pipe
//second int is split(1st place does nothing)
//second place can be 0-4, tells how tall the pipe will be
//third place can be 0-9, tells where the y position of the pipe starts
struct Pipe
{
  uint8_t xSpot;
  uint8_t ySpotPipeHeightSideways;
};

constexpr Pipe pipeInfo[] PROGMEM
{
  //1-1 pipes
  {29,packPipe(1,0,0)},
  {39,packPipe(1,1,0)},
  {47,packPipe(1,2,0)},
  {58,packPipe(1,2,0)},
  {164,packPipe(1,0,0)},
  {180,packPipe(1,0,0)},

  //1-2 pipes
  {104,packPipe(1,1,0)},
  {110,packPipe(1,2,0)},
  {116,packPipe(1,0,0)},
  {167,packPipe(4,1,1)},//sideways pipe
  {169,packPipe(4,7,0)},
  {179,packPipe(1,1,0)},
  {183,packPipe(1,1,0)},
  {187,packPipe(1,1,0)},

  //2-1 pipes
  {47,packPipe(1,2,0)},
  {75,packPipe(1,2,0)},
  {104,packPipe(1,2,0)},
  {116,packPipe(1,0,0)},
  {123,packPipe(1,2,0)},
  {127,packPipe(1,1,0)},
  {131,packPipe(1,3,0)},
  {177,packPipe(1,1,0)},

  //2-2 pipes
  {190,packPipe(5,0,1)},//sideways pipe
  
  //3-1 pipes 
  {33,packPipe(1,1,0)},
  {39,packPipe(1,2,0)},
  {58,packPipe(1,1,0)},
  {68,packPipe(1,0,0)},
  {104,packPipe(1,1,0)},

  //3-2 pipes 
  {170,packPipe(1,1,0)},

  //4-1 pipes
  {22,packPipe(1,1,0)},
  {117,packPipe(1,2,0)},
  {133,packPipe(1,2,0)},
  {164,packPipe(1,0,0)},

  //4-2 pipes
  {73,packPipe(1,1,0)},
  {79,packPipe(1,5,0)},
  {85,packPipe(1,1,0)},
  {90,packPipe(1,1,0)},
  {108,packPipe(1,2,0)},
  {132,packPipe(1,0,0)},
  {139,packPipe(1,1,0)},
  {143,packPipe(1,2,0)},
  {181,packPipe(1,5,0)},
  {188,packPipe(4,1,1)},//sideways pipe
  {190,packPipe(4,7,0)},
  {215,packPipe(1,1,0)},

  //4-4 pipes
  {41,packPipe(1,1,0)},

  //5-1 pipes
  {45,packPipe(1,1,0)},
  {52,packPipe(1,1,0)},
  {157,packPipe(5,0,0)},
  {164,packPipe(1,0,0)},
  
  //5-2 pipes
  {56,packPipe(1,1,0)},
  {116,packPipe(1,0,0)},
  {174,packPipe(1,0,0)},

  //6-1 pipes
  {103,packPipe(1,1,0)},

  //6-2 pipes
  {20,packPipe(1,2,0)},
  {29,packPipe(1,2,0)},
  {33,packPipe(6,0,0)},
  {36,packPipe(1,0,0)},
  {38,packPipe(1,0,0)},
  {47,packPipe(1,2,0)},
  {57,packPipe(1,3,0)},
  {63,packPipe(5,0,0)},
  {68,packPipe(1,0,0)},
  {75,packPipe(1,0,0)},
  {81,packPipe(1,1,0)},
  {85,packPipe(1,0,0)},
  {88,packPipe(1,4,0)},
  {95,packPipe(1,1,0)},
  {103,packPipe(1,2,0)},
  {106,packPipe(1,0,0)},
  {112,packPipe(5,1,0)},
  {116,packPipe(1,0,0)},
  {132,packPipe(1,0,0)},
  {136,packPipe(1,0,0)},
  {154,packPipe(1,1,0)},
  {168,packPipe(5,1,0)},
  {175,packPipe(1,2,0)},
  {180,packPipe(1,0,0)},
  {182,packPipe(1,1,0)},
  {184,packPipe(1,2,0)},
  {190,packPipe(1,1,0)},
  {202,packPipe(1,2,0)},
  
  //7-1 pipes
  {77,packPipe(1,1,0)},
  {94,packPipe(1,1,0)},
  {110,packPipe(1,1,0)},
  {116,packPipe(1,0,0)},
  {129,packPipe(1,0,0)},

  //7-2 pipes
  {190,packPipe(5,0,1)},//sideways pipe

  //8-2 pipes
  {132,packPipe(1,0,0)},
  {143,packPipe(1,0,0)},
  {157,packPipe(1,2,0)},
  {164,packPipe(1,0,0)},

  //8-3 pipes
  {54,packPipe(1,2,0)},
  {127,packPipe(1,2,0)},
  {169,packPipe(1,1,0)},
  

  //SUB AREA 1 pipes
  {14,packPipe(1,1,1)},//sideways pipe
  {16,packPipe(1,9,0)},

  //SUB AREA 2 pipes
  {14,packPipe(1,1,1)},//sideways pipe
  {16,packPipe(1,9,0)},


 
};

struct Block
{
  uint8_t xSpot;
  uint8_t ySpotBlockType;
};

constexpr Block blockInfo[] PROGMEM
{
  //1-1 blocks
  {17,packHalf(5,8)},
  {22,packHalf(5,8)},
  {24,packHalf(5,8)},
  {23,packHalf(9,8)},
  {65,packHalf(6,9)},//life block
  {79,packHalf(5,8)},
  {95,packHalf(9,8)},
  {95,packHalf(5,7)},
  {107,packHalf(5,8)},
  {110,packHalf(5,8)},
  {110,packHalf(9,8)},
  {113,packHalf(5,8)},
  {119,packHalf(5,7)},
  {129,packHalf(9,7)},
  {130,packHalf(9,8)},
  {131,packHalf(9,8)},
  {132,packHalf(9,7)},
  {171,packHalf(5,8)},

  //1-2 blocks
  {18,packHalf(2,6)},
  {30,packHalf(6,9)},
  {41,packHalf(6,10)},
  {41,packHalf(7,2)},
  {46,packHalf(6,10)},
  {46,packHalf(7,2)},
  {69,packHalf(6,10)},
  //{138,packHalf(6,2)},

  //1-3 blocks
  {34,packHalf(3,10)},
  {60,packHalf(4,8)},
  {140,packHalf(6,1)},
  {142,packHalf(8,1)},

  //1-4 blocks
  {24,packHalf(8,9)},
  {24,packHalf(9,4)},
  {31,packHalf(8,8)},
  {38,packHalf(8,9)},
  {81,packHalf(11,4)},
  {89,packHalf(11,4)},

  //2-1 blocks
  {69,packHalf(5,7)},
  {162,packHalf(5,7)},
  {171,packHalf(5,8)},
  {173,packHalf(9,7)},

  //2-3 blocks
  {56,packHalf(9,10)},
  {57,packHalf(8,10)},
  {58,packHalf(9,10)},
  {59,packHalf(8,10)},
  {60,packHalf(9,10)},
  {73,packHalf(9,10)},
  {76,packHalf(9,10)},
  {103,packHalf(9,8)},

  //2-4 blocks
  {24,packHalf(7,9)},
  {24,packHalf(11,8)},
  {104,packHalf(3,9)},

  //3-1 blocks
  {17,packHalf(5,8)},
  {20,packHalf(6,8)},
  {23,packHalf(6,8)},
  {62,packHalf(5,7)},
  {114,packHalf(9,8)},
  {118,packHalf(9,8)},
  {152,packHalf(5,8)},
  {152,packHalf(9,8)},
  {157,packHalf(5,8)},
  {157,packHalf(9,8)},

  //3-2 blocks
  {50,packHalf(2,6)},
  {61,packHalf(8,8)},
  {78,packHalf(5,7)},
  {78,packHalf(9,7)},
  {127,packHalf(8,7)},

  //3-3 blocks
  {38,packHalf(8,10)},
  {50,packHalf(11,8)},
  {67,packHalf(8,10)},
  {71,packHalf(8,10)},
  {75,packHalf(8,10)},
  {79,packHalf(11,10)},
  {82,packHalf(9,10)},
  {89,packHalf(9,10)},
  {91,packHalf(9,10)},
  {109,packHalf(4,10)},
  {110,packHalf(8,10)},

  //4-1 blocks
  {26,packHalf(5,8)},
  {26,packHalf(9,8)},
  {42,packHalf(5,10)},
  {45,packHalf(5,10)},
  {65,packHalf(5,8)},
  {65,packHalf(9,8)},
  {67,packHalf(5,8)},
  {67,packHalf(9,8)},
  {221,packHalf(5,7)},

  //4-2 blocks
  {88,packHalf(6,7)},
  
  //4-3 blocks
  {44,packHalf(12,8)},
  {49,packHalf(7,10)},
  {58,packHalf(3,10)},
  {74,packHalf(6,10)},
  {97,packHalf(7,10)},
  {89,packHalf(11,4)},
  {105,packHalf(10,10)},

  //4-4 blocks
  {94,packHalf(7,4)},
  {96,packHalf(7,4)},

  //5-3 blocks
  {34,packHalf(3,10)},
  {60,packHalf(4,8)},
  {140,packHalf(6,1)},
  {142,packHalf(8,1)},

  //5-4 blocks
  {24,packHalf(7,9)},
  {24,packHalf(11,8)},
  {104,packHalf(3,9)},

  //6-3 blocks
  {56,packHalf(11,8)},

  //6-4 blocks
  {24,packHalf(8,9)},
  {24,packHalf(9,4)},
  {31,packHalf(8,8)},
  {38,packHalf(8,9)},
  {81,packHalf(11,4)},
  {89,packHalf(11,4)},

  //7-1 blocks
  {65,packHalf(5,6)},
  {152,packHalf(8,7)},

  //7-3 blocks
  {56,packHalf(9,10)},
  {57,packHalf(8,10)},
  {58,packHalf(9,10)},
  {59,packHalf(8,10)},
  {60,packHalf(9,10)},
  {73,packHalf(9,10)},
  {76,packHalf(9,10)},
  {103,packHalf(9,8)},

  //7-4 blocks
  {35,packHalf(5,4)},
  {102,packHalf(8,2)},
  {106,packHalf(8,2)},
  {141,packHalf(3,4)},

  //8-2 blocks
  {120,packHalf(5,6)},

  //8-3 blocks
  {199,packHalf(3,6)},
  {201,packHalf(5,6)},
  {203,packHalf(7,6)},

};

struct Row
{
  uint8_t xSpot;
  uint8_t xWidth;
  uint8_t ySpotBlockType;
};

constexpr Row rowInfo [] PROGMEM
{
  //1-1 rows
  {21,5,packHalf(5,7)},
  {78,3,packHalf(5,7)},
  {81,8,packHalf(9,7)},
  {92,3,packHalf(9,7)},
  {101,2,packHalf(5,7)},
  {122,3,packHalf(9,7)},
  {130,2,packHalf(5,7)},
  {169,4,packHalf(5,7)},

  //1-2 rows
  {7,132,packHalf(12,7)},
  {11,5,packHalf(5,8)},
  {42,4,packHalf(9,10)},
  {59,4,packHalf(6,10)},
  {77,4,packHalf(5,7)},
  {85,6,packHalf(9,10)},
  {146,6,packHalf(6,7)},
  {162,26,packHalf(12,7)},
  


  //1-3 rows
  {28,3,packHalf(10,10)},
  {38,2,packHalf(12,10)},
  {51,2,packHalf(8,10)},
  {61,4,packHalf(10,10)},
  {86,2,packHalf(9,10)},
  {94,2,packHalf(10,10)},
  {98,2,packHalf(10,10)},
  {114,3,packHalf(10,10)},
  {121,2,packHalf(9,10)},

  //1-4 rows
  {1,160,packHalf(12,4)},
  {36,36,packHalf(5,4)},

  //2-1 rows
  {16,3,packHalf(5,7)},
  {30,3,packHalf(9,7)},
  {54,5,packHalf(5,8)},
  {54,5,packHalf(9,8)},
  {70,4,packHalf(9,7)},
  {80,4,packHalf(5,8)},
  {82,5,packHalf(9,7)},
  {86,3,packHalf(5,8)},
  {93,4,packHalf(9,7)},
  {126,4,packHalf(9,7)},
  {165,5,packHalf(9,7)},
  {186,2,packHalf(5,7)},

  //2-2 rows
  {15,2,packHalf(2,10)},
  {19,3,packHalf(5,5)},
  {28,3,packHalf(9,10)},
  {37,3,packHalf(2,10)},
  {43,2,packHalf(5,5)},
  {68,3,packHalf(4,10)},
  {83,3,packHalf(9,5)},
  {102,3,packHalf(3,10)},
  {103,2,packHalf(5,5)},
  {114,3,packHalf(8,10)},
  {116,2,packHalf(6,5)},
  {132,9,packHalf(9,5)},
  {135,3,packHalf(2,10)},
  {160,3,packHalf(2,10)},
  {160,3,packHalf(5,10)},
  {173,5,packHalf(5,5)},
  {173,5,packHalf(9,5)},
  {181,5,packHalf(5,5)},
  {181,5,packHalf(9,5)},

  //2-3 rows
  {16,48,packHalf(4,12)},
  {70,11,packHalf(4,12)},
  {86,10,packHalf(4,12)},
  {101,5,packHalf(5,12)},
  {123,3,packHalf(4,12)},
  {129,15,packHalf(4,12)},
  {148,8,packHalf(2,12)},
  {161,8,packHalf(4,12)},
  {172,2,packHalf(4,12)},
  {176,2,packHalf(4,12)},
  {180,2,packHalf(4,12)},
  {185,9,packHalf(4,12)},
  {37,4,packHalf(9,10)},
  {74,2,packHalf(10,10)},
  {98,3,packHalf(9,10)},
  {109,3,packHalf(9,10)},
  {134,6,packHalf(9,10)},
  {150,4,packHalf(6,10)},
  {174,6,packHalf(8,10)},



  //2-4 rows
  {19,2,packHalf(5,4)},
  {23,3,packHalf(7,4)},
  {28,2,packHalf(5,4)},
  {38,36,packHalf(5,4)},
  {103,3,packHalf(2,10)},
  {103,3,packHalf(6,10)},
  {121,6,packHalf(1,4)},
  {129,6,packHalf(9,7)},
  {129,20,packHalf(12,4)},

  //3-1 rows
  {27,3,packHalf(5,7)},
  {78,8,packHalf(5,12)},
  {78,8,packHalf(6,13)},
  {91,3,packHalf(9,7)},
  {112,11,packHalf(5,7)},
  {112,10,packHalf(9,7)},
  {130,3,packHalf(6,7)},
  {130,3,packHalf(9,7)},
  {151,3,packHalf(5,7)},
  {151,3,packHalf(9,7)},
  {156,3,packHalf(5,7)},
  {156,3,packHalf(9,7)},
  {167,5,packHalf(5,7)},

  //3-2 rows
  {56,3,packHalf(5,10)},
  {169,4,packHalf(8,10)},

  //3-3 rows
  {32,2,packHalf(2,10)},
  {43,3,packHalf(8,10)},
  {53,3,packHalf(5,10)},
  {57,2,packHalf(12,10)},
  {106,2,packHalf(10,10)},

  //3-4 rows
  {1,160,packHalf(12,4)},
  {43,3,packHalf(5,8)},
  {54,3,packHalf(2,4)},
  {64,3,packHalf(2,4)},
  {80,3,packHalf(2,4)},
  {82,3,packHalf(8,10)},

  //4-1 rows
  {43,2,packHalf(6,10)},
  {91,4,packHalf(5,8)},
  {106,4,packHalf(8,10)},
  {120,4,packHalf(8,10)},
  {136,4,packHalf(8,10)},
  {147,8,packHalf(5,8)},
  {150,2,packHalf(5,7)},
  {149,4,packHalf(9,8)},

  //4-2 rows
  {7,51,packHalf(12,7)},
  {28,3,packHalf(2,10)},
  {28,2,packHalf(5,7)},
  {51,2,packHalf(5,8)},
  {51,2,packHalf(9,8)},
  {55,3,packHalf(5,8)},
  {65,3,packHalf(9,7)},
  {68,48,packHalf(12,7)},
  {77,6,packHalf(5,7)},
  {120,4,packHalf(5,7)},
  {120,3,packHalf(9,7)},
  {120,4,packHalf(12,7)},
  {129,27,packHalf(12,7)},
  {162,11,packHalf(5,7)},
  {163,10,packHalf(6,10)},
  {177,43,packHalf(12,7)},

  //4-3 rows
  {21,3,packHalf(10,10)},
  {25,5,packHalf(6,10)},
  {39,3,packHalf(3,10)},
  {68,3,packHalf(8,10)},
  {71,3,packHalf(12,10)},
  {114,5,packHalf(6,10)},

  //4-4 rows
  {1,147,packHalf(12,4)},
  {39,6,packHalf(8,4)},
  {87,2,packHalf(4,4)},
  {90,2,packHalf(6,4)},
  {92,4,packHalf(4,4)},
  {96,3,packHalf(8,4)},
  {97,48,packHalf(4,4)},
  {101,4,packHalf(8,4)},
  {107,2,packHalf(8,4)},
  {111,34,packHalf(8,4)},
  {153,40,packHalf(12,4)},

  //5-1 rows
  {90,5,packHalf(5,6)},
  {91,3,packHalf(9,7)},
  {149,3,packHalf(5,7)},
  {157,2,packHalf(5,6)},

  //5-2 rows
  {17,3,packHalf(5,6)},
  {22,3,packHalf(10,10)},
  {30,6,packHalf(5,7)},
  {30,3,packHalf(6,10)},
  {30,6,packHalf(9,7)},
  {79,5,packHalf(5,8)},
  {86,3,packHalf(9,7)},
  {87,2,packHalf(10,10)},
  {90,3,packHalf(6,7)},
  {119,8,packHalf(5,7)},
  {119,8,packHalf(9,7)},
  {142,2,packHalf(3,7)},
  {148,3,packHalf(5,7)},
  {154,5,packHalf(9,7)},
  {173,4,packHalf(9,7)},
  {173,2,packHalf(10,10)},

  //5-3 rows
  {28,3,packHalf(10,10)},
  {38,2,packHalf(12,10)},
  {51,2,packHalf(8,10)},
  {61,4,packHalf(10,10)},
  {86,2,packHalf(9,10)},
  {94,2,packHalf(10,10)},
  {98,2,packHalf(10,10)},
  {114,3,packHalf(10,10)},
  {121,2,packHalf(9,10)},

  //5-4 rows
  {19,2,packHalf(5,4)},
  {23,3,packHalf(7,4)},
  {28,2,packHalf(5,4)},
  {38,36,packHalf(5,4)},
  {103,3,packHalf(2,10)},
  {103,3,packHalf(6,10)},
  {121,6,packHalf(1,4)},
  {129,6,packHalf(9,7)},
  {129,20,packHalf(12,4)},

  //6-1 rows
  {17,2,packHalf(5,8)},
  {27,6,packHalf(2,6)},
  {30,5,packHalf(3,6)},
  {33,4,packHalf(4,6)},
  {36,3,packHalf(5,6)},
  {37,2,packHalf(9,7)},
  {42,3,packHalf(5,7)},
  {63,3,packHalf(5,10)},
  {77,2,packHalf(7,10)},
  {84,4,packHalf(2,2)},
  {91,3,packHalf(8,7)},
  {93,3,packHalf(4,7)},
  {106,3,packHalf(6,10)},
  {128,2,packHalf(6,7)},
  {131,2,packHalf(8,7)},
  {131,5,packHalf(2,7)},
  {150,2,packHalf(7,7)},
  {152,2,packHalf(5,7)},
  {153,3,packHalf(3,7)},

  //6-2 rows
  {11,3,packHalf(5,7)},
  {24,3,packHalf(9,7)},
  {33,2,packHalf(6,6)},
  {52,2,packHalf(5,7)},
  {63,2,packHalf(5,6)},
  {68,5,packHalf(9,7)},
  {78,5,packHalf(9,7)},
  {112,2,packHalf(5,6)},
  {120,9,packHalf(9,7)},
  {139,2,packHalf(6,7)},
  {141,2,packHalf(9,7)},
  {145,3,packHalf(5,7)},
  {146,2,packHalf(9,7)},
  {161,3,packHalf(5,7)},
  {161,3,packHalf(9,7)},
  {168,2,packHalf(5,6)},

  //6-3 rows
  {29,2,packHalf(12,10)},
  {44,7,packHalf(10,10)},
  {74,2,packHalf(9,10)},
  {86,3,packHalf(12,10)},
  {101,4,packHalf(6,10)},
  {129,2,packHalf(9,10)},
  {146,2,packHalf(7,10)},
  {155,2,packHalf(11,10)},

  //6-4 rows
  {1,160,packHalf(12,4)},
  {36,36,packHalf(5,4)},

  //7-1 rows
  {28,3,packHalf(9,7)},
  {40,4,packHalf(5,8)},
  {63,5,packHalf(5,7)},
  {83,7,packHalf(5,7)},
  {83,7,packHalf(9,7)},
  {135,5,packHalf(5,7)},
  {135,5,packHalf(9,7)},
  {150,2,packHalf(6,7)},
  {154,2,packHalf(8,7)},

  //7-2 rows
  {15,2,packHalf(2,10)},
  {19,3,packHalf(5,5)},
  {28,3,packHalf(9,10)},
  {37,3,packHalf(2,10)},
  {43,2,packHalf(5,5)},
  {68,3,packHalf(4,10)},
  {83,3,packHalf(9,5)},
  {102,3,packHalf(3,10)},
  {103,2,packHalf(5,5)},
  {114,3,packHalf(8,10)},
  {116,2,packHalf(6,5)},
  {132,9,packHalf(9,5)},
  {135,3,packHalf(2,10)},
  {160,3,packHalf(2,10)},
  {160,3,packHalf(5,10)},
  {173,5,packHalf(5,5)},
  {173,5,packHalf(9,5)},
  {181,5,packHalf(5,5)},
  {181,5,packHalf(9,5)},

  //7-3 rows
  {16,48,packHalf(4,12)},
  {70,11,packHalf(4,12)},
  {86,10,packHalf(4,12)},
  {101,5,packHalf(5,12)},
  {123,3,packHalf(4,12)},
  {129,15,packHalf(4,12)},
  {148,8,packHalf(2,12)},
  {161,8,packHalf(4,12)},
  {172,2,packHalf(4,12)},
  {176,2,packHalf(4,12)},
  {180,2,packHalf(4,12)},
  {185,9,packHalf(4,12)},
  {37,4,packHalf(9,10)},
  {74,2,packHalf(10,10)},
  {98,3,packHalf(9,10)},
  {109,3,packHalf(9,10)},
  {134,6,packHalf(9,10)},
  {150,4,packHalf(6,10)},
  {174,6,packHalf(8,10)},

  //7-4 rows
  {1,224,packHalf(12,4)},
  {55,13,packHalf(4,4)},
  {56,11,packHalf(8,4)},
  {71,18,packHalf(5,4)},
  {71,19,packHalf(6,4)},
  {71,20,packHalf(7,4)},
  {71,22,packHalf(8,4)},
  {100,11,packHalf(8,4)},
  {119,3,packHalf(8,4)},
  {120,3,packHalf(4,4)},
  {124,7,packHalf(8,4)},
  {125,7,packHalf(4,4)},
  {133,3,packHalf(8,4)},
  {134,3,packHalf(4,4)},
  {138,16,packHalf(8,4)},
  {140,2,packHalf(2,4)},
  
  //8-2 rows
  {30,4,packHalf(5,8)},
  {44,33,packHalf(9,7)},
  {78,2,packHalf(5,7)},
  {100,2,packHalf(5,7)},
  {111,2,packHalf(5,7)},
  {119,3,packHalf(5,7)},

  //8-3 rows
  {61,8,packHalf(5,7)},
  {61,8,packHalf(9,7)},
  {116,8,packHalf(5,7)},
  {116,8,packHalf(9,7)},
  {205,2,packHalf(9,6)},
  
  

  //SUB AREA 1 rows
  {5,7,packHalf(5,10)},
  {5,7,packHalf(7,10)},
  {6,5,packHalf(9,10)},
  {5,7,packHalf(12,7)},

  //SUB AREA 2 rows
  {4,9,packHalf(2,10)},
  {4,10,packHalf(5,7)},
  {5,8,packHalf(6,10)},

  

};

struct Column 
{
  uint8_t xSpot;
  uint8_t ySpotyHeight;
  uint8_t blockType;
};

constexpr Column columnInfo [] PROGMEM
{
  //1-2 columns
  {1,packHalf(2,11),7},
  {20,packHalf(2,2),6},
  {22,packHalf(2,3),6},
  {24,packHalf(2,4),6},
  {26,packHalf(2,4),6},
  {28,packHalf(2,3),6},
  {32,packHalf(2,3),6},
  {34,packHalf(2,2),6},
  {68,packHalf(5,5),7},

  //1-4 columns
  {1,packHalf(5,3),4},

  //2-1 columns
  {35,packHalf(2,4),6},
  {36,packHalf(2,2),6},
  {155,packHalf(2,3),6},

  //2-2 columns
  {12,packHalf(2,3),14},
  {34,packHalf(2,5),14},
  {43,packHalf(6,2),14},
  {51,packHalf(2,4),14},
  {65,packHalf(2,3),5},
  {66,packHalf(2,5),5},
  {72,packHalf(2,5),5},
  {73,packHalf(2,3),5},
  {84,packHalf(10,2),14},
  {90,packHalf(2,3),14},
  {103,packHalf(6,4),14},
  {121,packHalf(2,4),14},
  {130,packHalf(2,4),5},
  {131,packHalf(2,2),5},
  {141,packHalf(2,4),5},
  {142,packHalf(2,2),5},
  {148,packHalf(2,2),14},
  {150,packHalf(2,3),14},
  {157,packHalf(2,8),5},
  {165,packHalf(2,8),5},
  {174,packHalf(10,2),14},

  //2-3 columns
  {15,packHalf(2,3),6},
  {32,packHalf(1,4),6},
  {48,packHalf(1,4),6},
  {64,packHalf(1,4),6},
  {69,packHalf(1,4),6},
  {80,packHalf(1,4),6},
  {85,packHalf(1,4),6},
  {96,packHalf(1,4),6},
  {100,packHalf(1,5),6},
  {106,packHalf(1,5),6},
  {128,packHalf(1,4),6},
  {144,packHalf(1,4),6},
  {147,packHalf(1,2),6},
  {156,packHalf(1,2),6},
  {160,packHalf(1,4),6},
  {169,packHalf(1,4),6},
  {184,packHalf(1,4),6},

  //2-4 columns
  {1,packHalf(5,3),4},

  //3-1 columns
  {86,packHalf(2,4),6},
  {89,packHalf(2,4),6},
  {90,packHalf(2,2),6},
  {175,packHalf(2,3),6},
  {176,packHalf(2,6),6},

  //3-2 columns
  {61,packHalf(2,3),6},
  {76,packHalf(2,2),6},
  {80,packHalf(2,2),6},
  {127,packHalf(2,2),6},

  //3-4 columns
  {1,packHalf(5,3),4},

  //4-1 columns
  {104,packHalf(2,3),6},
  {190,packHalf(2,3),6},

  //4-2 columns
  {1,packHalf(2,11),7},
  {161,packHalf(7,2),7},

  //4-4 columns
  {1,packHalf(5,3),4},
  {25,packHalf(5,4),2},
  {27,packHalf(5,4),2},
  {29,packHalf(5,4),2},
  {31,packHalf(5,4),2},
  {33,packHalf(5,4),2},
  {35,packHalf(5,4),2},
  {91,packHalf(1,4),4},
  {95,packHalf(5,2),4},
  {106,packHalf(5,4),4},
  {145,packHalf(5,5),4},

  //5-1 columns
  {90,packHalf(2,3),6},
  {117,packHalf(2,3),6},
  {148,packHalf(2,4),6},

  //5-2 columns
  {50,packHalf(2,2),6},
  {69,packHalf(2,5),6},
  {130,packHalf(2,3),6},
  {186,packHalf(1,4),1},
  {189,packHalf(1,7),1},

  //5-4 columns
  {1,packHalf(5,3),4},

  //6-1 columns
  {87,packHalf(2,4),2},

  //6-2 columns
  {157,packHalf(2,4),6},
  {158,packHalf(2,2),6},

  //6-4 columns
  {1,packHalf(5,3),4},

  //7-1 columns
  {142,packHalf(2,3),6},

  //7-2 columns
  {12,packHalf(2,3),14},
  {34,packHalf(2,5),14},
  {43,packHalf(6,2),14},
  {51,packHalf(2,4),14},
  {65,packHalf(2,3),5},
  {66,packHalf(2,5),5},
  {72,packHalf(2,5),5},
  {73,packHalf(2,3),5},
  {84,packHalf(10,2),14},
  {90,packHalf(2,3),14},
  {103,packHalf(6,4),14},
  {121,packHalf(2,4),14},
  {130,packHalf(2,4),5},
  {131,packHalf(2,2),5},
  {141,packHalf(2,4),5},
  {142,packHalf(2,2),5},
  {148,packHalf(2,2),14},
  {150,packHalf(2,3),14},
  {157,packHalf(2,8),5},
  {165,packHalf(2,8),5},
  {174,packHalf(10,2),14},

  //7-3 columns
  {15,packHalf(2,3),6},
  {32,packHalf(1,4),6},
  {48,packHalf(1,4),6},
  {64,packHalf(1,4),6},
  {69,packHalf(1,4),6},
  {80,packHalf(1,4),6},
  {85,packHalf(1,4),6},
  {96,packHalf(1,4),6},
  {100,packHalf(1,5),6},
  {106,packHalf(1,5),6},
  {128,packHalf(1,4),6},
  {144,packHalf(1,4),6},
  {147,packHalf(1,2),6},
  {156,packHalf(1,2),6},
  {160,packHalf(1,4),6},
  {169,packHalf(1,4),6},
  {184,packHalf(1,4),6},

  //7-4 columns
  {1,packHalf(5,3),4},
  {138,packHalf(5,3),4},

  //8-2 columns
  {22,packHalf(1,6),1},
  {203,packHalf(1,5),1},

  //8-3 columns
  {96,packHalf(2,3),6},
  {196,packHalf(2,2),6},


  //SUB AREA 1 columns
  {1,packHalf(2,11),7},

  //SUB AREA 2 columns
  {1,packHalf(2,11),7},
  
};

struct Mushroom
{
  uint8_t xSpot;
  uint8_t mushHeightxWidth;
  bool mushType;
};

constexpr Mushroom mushInfo[] PROGMEM
{
  
  //1-3 mushrooms
  {20, packHalf(0,2), true},
  {28, packHalf(8,3), true},
  {26, packHalf(4,6), true},
  {34, packHalf(1,1), true},
  {37, packHalf(5,3), true},
  {42, packHalf(9,5), true},
  {52, packHalf(0,2), true},
  {62, packHalf(8,2), true},
  {61, packHalf(0,3), true},
  {67, packHalf(0,3), true},
  {72, packHalf(4,1), true},
  {78, packHalf(7,4), true},
  {100, packHalf(2,2), true},
  {106, packHalf(6,6), true},
  {115, packHalf(0,1), true},
  {118, packHalf(4,2), true},
  {124, packHalf(4,2), true},


  //2-3 mushrooms
  {10, packHalf(0,6), true},
  {114, packHalf(0,6), true},
  {194, packHalf(0,11), true},

  //3-3 mushrooms DO EVERY ONE OF THESE
  {20, packHalf(3,3), true},
  {24, packHalf(6,4), true},
  {32, packHalf(0,1), true},
  {38, packHalf(1,5), true},
  {45, packHalf(4,2), true},
  {49, packHalf(6,4), true},
  {48, packHalf(2,8), true},
  {57, packHalf(10,2), true},
  {67, packHalf(6,1), true},
  {71, packHalf(6,1), true},
  {75, packHalf(6,1), true},
  {79, packHalf(9,1), true},
  {67, packHalf(0,14), true},
  {86, packHalf(2,2), true},
  {99, packHalf(4,1), true},
  {106, packHalf(8,2), true},
  {110, packHalf(6,1), true},
  {109, packHalf(2,3), true},
  {118, packHalf(0,1), true},
  {121, packHalf(3,10), true},


 
  //CONVERT THE REST
  //4-3 mushrooms
  {19, packHalf(0,5), false},
  {22, packHalf(8,5), false},
  {27, packHalf(4,7), false},
  {34, packHalf(9,3), false},
  {42, packHalf(8,5), false},
  {40, packHalf(1,7), false},
  {46, packHalf(4,3), false},
  {53, packHalf(5,3), false},
  {69, packHalf(6,3), false},
  {68, packHalf(0,5), false},
  {72, packHalf(10,3), false},
  {74, packHalf(4,3), false},
  {77, packHalf(8,5), false},
  {86, packHalf(4,3), false},
  {101, packHalf(2,3), false},
  {107, packHalf(3,3), false},
  {116, packHalf(4,5), false},
  {119, packHalf(7,3), false},
  {125, packHalf(0,7), false},
  {133, packHalf(3,5), false},

  //5-3 mushrooms
  {20, packHalf(0,2), true},
  {28, packHalf(8,3), true},
  {26, packHalf(4,6), true},
  {34, packHalf(1,1), true},
  {37, packHalf(5,3), true},
  {42, packHalf(9,5), true},
  {52, packHalf(0,2), true},
  {62, packHalf(8,2), true},
  {61, packHalf(0,3), true},
  {67, packHalf(0,3), true},
  {72, packHalf(4,1), true},
  {78, packHalf(7,4), true},
  {100, packHalf(2,2), true},
  {106, packHalf(6,6), true},
  {115, packHalf(0,1), true},
  {118, packHalf(4,2), true},
  {124, packHalf(4,2), true},

  //6-3 mushrooms
  {20, packHalf(0,1), true},
  {23, packHalf(4,1), true},
  {26, packHalf(0,1), true},
  {33, packHalf(4,2), true},
  {39, packHalf(0,1), true},
  {45, packHalf(0,1), true},
  {51, packHalf(2,2), true},
  {67, packHalf(4,3), true},
  {87, packHalf(10,1), true},
  {87, packHalf(3,3), true},
  {92, packHalf(5,1), true}, 
  {95, packHalf(0,1), true},
  {99, packHalf(0,2), true},
  {105, packHalf(0,1), true},
  {109, packHalf(4,3), true},
  {115, packHalf(0,3), true},
  {125, packHalf(0,1), true},
  {134, packHalf(8,1), true},
  {134, packHalf(0,2), true},
  {137, packHalf(4,2), true},
  {158, packHalf(8,1), true},

  //7-3 mushrooms
  {10, packHalf(0,6), true},
  {114, packHalf(0,6), true},
  {194, packHalf(0,11), true},


};



struct Stairs
{
  uint8_t xSpot;
  uint8_t faceRightBlockWidthBlockTypeExtraxSpot;
};

constexpr Stairs stairInfo [] PROGMEM
{
  //1-1 stairs
  {135,createPackedStair(0,1,6,0)},
  {141,createPackedStair(1,1,6,0)},
  {149,createPackedStair(0,2,6,1)},
  {156,createPackedStair(1,1,6,0)},


  //1-2 stairs
  {134,createPackedStair(0,2,6,1)},

  //1-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //2-1 stairs
  {21,createPackedStair(0,2,6,0)},

  //2-2 stairs
  {186,createPackedStair(0,4,5,0)},

  //2-3 stairs
  {11,createPackedStair(0,1,6,1)},
  {194,createPackedStair(1,1,6,1)},

  //2-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //3-1 stairs
  {74,createPackedStair(0,1,6,0)},
  {137,createPackedStair(0,3,6,0)},

  //3-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //4-2 stairs
  {103,createPackedStair(0,0,6,0)},
  {153,createPackedStair(0,0,6,0)},
  {174,createPackedStair(0,1,6,0)},

  //4-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //5-2 stairs
  {13,createPackedStair(0,1,6,0)},
  {45,createPackedStair(0,2,6,0)},
  {63,createPackedStair(0,1,6,0)},

  //5-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //6-1 stairs
  {70,createPackedStair(0,2,6,1)},
  {84,createPackedStair(0,4,6,0)},
  {123,createPackedStair(0,2,6,0)},
  {144,createPackedStair(0,3,6,0)},

  //6-2 stairs
  {150,createPackedStair(0,0,6,0)},

  //6-4 stairs
  {2,createPackedStair(1,4,4,1)},

  //7-1 stairs
  {154,createPackedStair(0,3,6,0)},

  //7-2 stairs
  {186,createPackedStair(0,4,5,0)},

  //7-3 stairs
  {11,createPackedStair(0,1,6,1)},
  {194,createPackedStair(1,1,6,1)},
  
  //7-4 stairs
  {2,createPackedStair(1,4,4,1)},
  {33,createPackedStair(0,4,4,0)},

  //8-2 stairs
  {18,createPackedStair(0,6,6,1)},
  {183,createPackedStair(0,2,6,0)},
};




struct Rectangle
{
  uint8_t xSpot;
  uint8_t ySpotBlockHeight;
  uint8_t blockWidth;
  uint8_t blockType;
};

constexpr Rectangle rectInfo [] PROGMEM
{

  //1-2 rectangles
  {40,packHalf(5,3),8,7},
  {43,packHalf(5,2),2,2},
  {53,packHalf(5,7),12,7},
  {53,packHalf(10,2),2,2},
  {55,packHalf(3,3),2,7},
  {55,packHalf(6,4),8,2},
  {57,packHalf(5,7),2,2},
  {67,packHalf(10,2),4,7},
  {69,packHalf(5,2),2,7},
  {73,packHalf(5,5),2,7},
  {77,packHalf(10,2),4,7},
  {85,packHalf(6,2),6,7},
  {123,packHalf(2,3),2,7},
  {161,packHalf(2,3),17,7},
  {171,packHalf(5,8),7,7},
  {191,packHalf(2,11),2,7},//after warp pipes

  //1-3 rectangles
  {136,packHalf(2,3),3,1},
  
  //1-4 rectangles
  {1,packHalf(10,2),24,7},
  {38,packHalf(9,3),34,4},
  {98,packHalf(10,2),31,4},
  {105,packHalf(2,10),19,2},
  {117,packHalf(2,3),4,4},

  //2-1 rectangles
  {191,packHalf(2,10),2,6},

  //2-2 rectangles
  {79,packHalf(2,3),2,5},
  {79,packHalf(10,3),2,5},
  {189,packHalf(9,4),2,5},
  {191,packHalf(1,12),2,5},

  //2-4 rectangles
  {1,packHalf(10,3),16,4},
  {35,packHalf(2,3),46,2},
  {100,packHalf(2,3),9,2},
  {35,packHalf(9,4),49,4},
  {94,packHalf(10,3),6,4},
  {116,packHalf(10,3),13,4},

  //3-4 rectangles
  {1,packHalf(10,2),16,4},
  {36,packHalf(2,3),54,2},
  {36,packHalf(10,2),11,4},
  {54,packHalf(10,2),3,4},
  {64,packHalf(10,2),3,4},
  {80,packHalf(10,2),3,4},
  {91,packHalf(10,2),6,4},
  {112,packHalf(10,2),17,4},
  {117,packHalf(2,3),2,2},

  //4-2 rectangles
  {21,packHalf(9,3),28,7},
  {23,packHalf(3,3),5,7},
  {31,packHalf(2,4),18,7},
  {112,packHalf(2,3),2,6},
  {161,packHalf(9,4),16,7},
  {186,packHalf(2,3),6,7},
  {192,packHalf(2,10),18,7},
  {223,packHalf(2,11),2,7},

  //4-4 rectangles
  {1,packHalf(10,2),6,4},
  {17,packHalf(2,3),142,2},
  {19,packHalf(5,4),20,4},
  {45,packHalf(5,4),31,4},
  {78,packHalf(2,3),3,4},
  {78,packHalf(9,3),3,4},
  {146,packHalf(10,2),2,4},
  {153,packHalf(2,3),4,4},

  //5-1 rectangles
  {188,packHalf(2,7),2,1},
  {190,packHalf(2,2),2,1},

  //5-2 rectangles
  {70,packHalf(2,6),2,6},

  //5-3 rectangles
  {136,packHalf(2,3),3,1},

  //5-4 rectangles
  {1,packHalf(10,3),16,4},
  {35,packHalf(2,3),46,2},
  {100,packHalf(2,3),9,2},
  {35,packHalf(9,4),49,4},
  {94,packHalf(10,3),6,4},
  {116,packHalf(10,3),13,4},

  //6-1 rectangles
  {175,packHalf(1,8),2,2},

  //6-4 rectangles
  {1,packHalf(10,2),24,7},
  {38,packHalf(9,3),34,4},
  {98,packHalf(10,2),31,4},
  {105,packHalf(2,10),19,2},
  {117,packHalf(2,3),4,4},

  //7-2 rectangles
  {79,packHalf(2,3),2,5},
  {79,packHalf(10,3),2,5},
  {189,packHalf(9,4),2,5},
  {191,packHalf(1,12),2,5},

  //7-4 rectangles
  {1,packHalf(10,2),16,4},
  {29,packHalf(10,2),4,4},
  {33,packHalf(2,3),61,2},
  {40,packHalf(5,4),11,4},
  {71,packHalf(5,4),18,4},
  {97,packHalf(2,3),45,2},
  {111,packHalf(5,4),6,4},

  //8-2 rectangles
  {205,packHalf(1,8),2,1},

  //8-3 rectangles
  {25,packHalf(2,5),8,60},
  {38,packHalf(2,5),14,60},
  {80,packHalf(2,5),6,60},
  {89,packHalf(2,5),6,60},
  {98,packHalf(2,5),10,60},
  {133,packHalf(2,5),34,60},
  {173,packHalf(2,5),20,60},
  
  {110,packHalf(2,4),2,6},
  {198,packHalf(1,9),11,1},

  //SUB AREA 1 rectangles
  {5,packHalf(2,3),7,7},

  //SUB AREA 2 rectangles
  {4,packHalf(9,4),10,7},
  {14,packHalf(4,9),2,7},
 
 
};
