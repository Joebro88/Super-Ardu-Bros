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
const uint8_t levelInfo[32][2] {
  {113,183},
  123,
  113,
  124,
  113,
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

const uint8_t gapInfo [8][2] PROGMEM  {
  {54,2},
  {71,3},
  {138,2},//end 1-1
  {65,3},
  {105,2},
  {109,2},
  {123,7},
  {139,7},
  
};

//first int is the x position of the pipe
//second int is split(1st place does nothing)
//second place can be 0-4, tells how tall the pipe will be
//third place can be 0-9, tells where the y position of the pipe starts
const uint8_t pipeInfo [115][2] PROGMEM {
  {13,101},//for example, 101 = a pipe with a height of 0 and y position of 1
  {23,111},
  {31,121},
  {42,121},
  {148,101},
  {164,101},//ends 1-1
  {88,111},
  {94,121},
  {100,101},
  {155,143},//ends 1-2,1-3, and 1-4
  {47,121},
  {75,121},
  {104,121},
  {116,101},
  {123,121},
  {127,111},
  {131,131},
  {167,111},//ends 2-1, 2-2, 2-3, and 2-4 //LAST DONE RN
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

const uint8_t blockInfo [31][2] PROGMEM {
  //{0,4,14},
  {1,184},
  {5,174},
  {6,184},
  {7,174},
  {8,184},
  {9,174},
  {7,187},
  {49,195},//life block
  {62,174},
  {63,184},
  {64,174},
  {79,187},//question block
  {79,174},
  {91,184},
  {94,184},
  {94,187},
  {97,184},
  {103,174},
  {113,177},
  {114,187},
  {115,187},
  {116,177},
  {137,116},
  {155,184},
  {156,174},
  {172,118},//end 1-1
  {2,162},
  {14,196},
  {24,175},
  {27,124},
  {29,175},

};

const uint8_t rowInfo [7][3] PROGMEM {
  {65,8,177},
  {76,3,177},
  {85,2,174},
  {106,3,177},
  {114,2,174},
  {153,2,174},//ends 1-1
  {100,100,178},
};

const uint8_t columnInfo [8][3] PROGMEM {
  {4,2,162},//starts 1-2
  {6,3,162},
  {8,4,162},
  {10,4,162},
  {12,3,162},
  {16,3,162},
  {18,2,162},
  {41,4,124},
};

const uint8_t stairInfo [6][2] PROGMEM {
  {119,116},
  {125,216},
  {133,126},
  {140,216},
  {166,146},//end 1-1
  {118,126},
};

const uint8_t rectInfo [4][4] PROGMEM {
  {24,142,8,7},
  {37,146,12,7},
  {39,152,7,2},
  {146,122,20,7},
};

//this is an array for the entire game. It tells how many objects are in each level
//3 gaps in the first level, 6 pipes in the first level
//the other numbers don't matter right now
const uint8_t objectList [32][7] PROGMEM {
  //gap,pipe,block,row,column,stairs,rectangle
  {3,6,26,6,0,5,0},//1-1
  {5,4,5,1,8,1,4},
  {1,0,0,0,0,0,0},
  {3,0,0,0,0,0,0},
  {5,8,1,1,1,1,1},//2-1
  {0,0,1,1,1,1,1},
  {0,0,1,1,1,1,1},
  {0,0,1,1,1,1,1},
  {0,5,1,1,1,1,1},//3-1
  {0,0,1,1,1,1,1},
  {0,0,1,1,1,1,1},
  {0,0,1,1,1,1,1},
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
