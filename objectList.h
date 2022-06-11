#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>



//This is an array for the entire game. It tells how many objects are in each level
//3 gaps in the first level, 6 pipes in the first level, etc.
//The order is listed below.

constexpr uint8_t objectList [32][7] PROGMEM {
  //gap,pipe,block,row,column,stairs,rectangle
  {3,6,21,7,0,5,1},//1-1
  {5,7,8,8,9,1,16},
  {1,0,0,0,0,0,0},
  {3,0,6,2,0,1,6},
  {4,8,4,12,3,1,1},//2-1
  {3,0,0,19,21,1,4},
  {1,0,0,6,15,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},//3-1
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0},
  {5,4,1,1,1,1,1},//4-1
  {5,10,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,1,1,1,1,1,1},
  {5,4,1,1,1,1,1},//5-1
  {5,3,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,1,1,1,1,1,1},//6-1
  {5,28,1,1,1,1,1},//WTF
  {5,0,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,5,1,1,1,1,1},//7-1
  {5,0,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,0,1,1,1,1,1},
  {5,12,1,1,1,1,1},//8-1
  {5,4,1,1,1,1,1},
  {5,3,1,1,1,1,1},
  {5,16,1,1,1,1,1},
};
