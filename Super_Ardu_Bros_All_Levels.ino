#include <Arduboy2.h>
#include "graphics.h"
#include "level_Data.h"
#include "objectList.h"
#include "byteFunctions.h"

Arduboy2 arduboy;

//Sprites sprites;


//SUPER ARDU BROS.
//Created for the Arduboy system

#define WORLD_WIDTH 17
#define WORLD_HEIGHT 13



//all of my variables
uint16_t mapx = 0;
int screeny = -40;
int screenx = 0;
//uint8_t screeny = 0;
uint8_t screenynegative = 8;

//change to 0 on start
uint8_t level = 0;


uint8_t sky = 0;
//uint8_t ground = 11;
//uint8_t midBlock = 4;
uint8_t velocity = 0;
uint8_t worldTime = 250;
uint8_t slowRun = 255;
uint8_t slowRunCountdown = 8;
uint8_t levelType = 0;
uint8_t speedChange = 8;
uint8_t levelTimer = 255;
uint8_t coins = 0;

int playerx = 16;
int realplayerx = 0;
int playery = 40;
int gamestate = 0;
uint8_t gravity = 0;
bool canMove = true;
bool isGrounded = true;
bool isFalling = true;
uint8_t plusJump = 0;
uint8_t levelThemeBlocks;

bool tempLoop;

uint8_t tempSpace = 15;




//where data
uint16_t tempScanner[8] = {0,0,0,0,0,0,0,0};

//WORLD ARRAY
//This is where numbers are changed
//The numbers displayed in this world array tell what tiles should be drawn
//For example, the tiles on here correspond to the title screen
//Each function calls for these numbers to change, that's how graphics are built
//The final column on the right is the only one changed, it scrolls to the left
uint8_t world[WORLD_HEIGHT][WORLD_WIDTH] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
  {1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
  {1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
  {1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,27,28,1,1,1,1,1,1,1,1,1,1,24,25,1,1},
  {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void setup() {
  //runs once, sets framerate
  arduboy.begin();
  arduboy.setFrameRate(60);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(!(arduboy.nextFrame())) 
  {
    return;
  }
  arduboy.pollButtons();
  //constant clock for the game world
  worldTime--;
  gameloop();
  arduboy.display();
}

void buildGround()
  {  

    //remove most of this
    if(mapx == 0)
    {
      if(pgm_read_byte(&levelInfo[level].tallFloor) == true)
      {
        for(uint8_t i = 0; i < 17;i++)
        {
          for(uint8_t j = 12;j > 8; j--)
          {
            world[j][i] = pgm_read_byte(&levelInfo[level].themeInfo)%10;
          }
        }
      }
      else
      {
        for(uint8_t i = 0; i < 17;i++)
        {
          world[12][i] = pgm_read_byte(&levelInfo[level].themeInfo)%10;
        }
      }
      
    }

  //draws ground until spacePosition is reached (after the first 16 blocks)
    if(mapx>0)
    {
      if(pgm_read_byte(&levelInfo[level].tallFloor) == true)
      {
        
          for(uint8_t j = 12;j > 8; j--)
          {
            world[j][16] = pgm_read_byte(&levelInfo[level].themeInfo)%10;
          }
        
      }
      else
      {
        
          world[12][16] = pgm_read_byte(&levelInfo[level].themeInfo)%10;
        
      }
    }
}

void buildGaps(uint8_t xSpot, uint8_t gapWidth)
{
  if(mapx >= xSpot-1)
  {
    if(mapx - xSpot + 1 < gapWidth)
    {
      if(pgm_read_byte(&levelInfo[level].tallFloor) == true)
      {
        
          for(uint8_t j = 12;j > 7; j--)
          {
            world[j][16] = sky;
          }
          
        
      }
      else
      {
        
          world[12][16] = sky;
        
      }
      
    }
    //THIS MAKES RIGHT EDGE OF GAPS
    if(mapx - xSpot+2 == gapWidth)
      {
        world[12][16] = 57;
      }
  }
}



void buildStairs(uint8_t xSpot, uint8_t faceRightBlockWidthBlockType)
{
  uint8_t faceRight = extractStairDirection(faceRightBlockWidthBlockType);
  uint8_t blockWidth = extractStairWidth(faceRightBlockWidthBlockType);
  uint8_t blockType = extractTypeWidth(faceRightBlockWidthBlockType);
  uint8_t extraxSpot = extractExtraxSpot(faceRightBlockWidthBlockType);
  
  
  //can probably limit this int
  uint8_t z = mapx - xSpot+2;
  //uint8_t w = xSpot - mapx;
  
  if(mapx >= xSpot-2)
  {
    if(faceRight == 0)
    {
      for(uint8_t j = 0; j < z; j++)//vertical columns
      { 
        if(z <= 3+blockWidth)
        {
          world[11 - j][16] = blockType;
        }
      }
      
      //cuts off the top block
      if(extraxSpot == 1 && mapx == xSpot + blockWidth +1 )
      {
      
          world[9-blockWidth][16] = sky;
        
      }
    }

    
    else if(faceRight == 1)
    {
      if(mapx >= xSpot-1)
      {
        for(uint8_t j = 4+blockWidth; j > z; j--)//vertical columns
        { 
          if(z <= 4+blockWidth)
          {
            //world[j-1+(7-blockWidth)][16] = sky;
            world[j+(7-blockWidth)][16] = blockType;
          }
        }

        //cuts off the top block
        if(extraxSpot == 1 && mapx  == xSpot-1)
        {
          world[9-blockWidth][16] = sky;
        }
      }
    }

    
   
   
        
   
  }

  //this can be cleaned up a lot...this if statement used to be an else if inside of the above for loop
  
}

void buildBlock(uint8_t xSpot, uint8_t ySpotBlockType)
//builds a single block.
{

  uint8_t blockType = extract2ndHalf(ySpotBlockType);
  uint8_t ySpot = extract1stHalf(ySpotBlockType);


  //builds a square section of blocks out of x,y,w,h,and type
  if(mapx == xSpot-1)
  {
    world[13-ySpot][16] = blockType;
  }
}

void buildRects(uint8_t xSpot, uint8_t ySpotBlockHeight, uint8_t blockWidth, uint8_t blockType)
{  
  
  uint8_t ySpot = extract1stHalf(ySpotBlockHeight);
  uint8_t blockHeight = extract2ndHalf(ySpotBlockHeight);
  
  

  
  //builds a square section of blocks out of x,y,w,h,and type
  if(mapx >= xSpot - 1)
  {
    for(uint8_t i = blockHeight; i > 0; i--)//vertical
    {  
      for(uint8_t j = 0; j < blockWidth + 1; j++)//horizontal
      {  
        if(mapx< xSpot -1 + blockWidth)
        {
          world[14-(ySpot + i)][16] = blockType;
          //for castles
          if(blockType == 60)
          {
            world[14-(ySpot + blockHeight)][16] = 15;
          }
          
        }  
      }
    }
    
  }
}

void buildRow(uint8_t xSpot, uint8_t xWidth, uint8_t ySpotBlockType)
{
  uint8_t blockType = extract2ndHalf(ySpotBlockType);
  uint8_t ySpot = extract1stHalf(ySpotBlockType);
  
  
  
  //builds a horizontal row of blocks
  if(mapx >= xSpot-1)
  {
    if(mapx - xSpot + 1 < xWidth)
    {

        world[13-ySpot][16] = blockType;
      
    }
  }
}

void buildColumn(uint8_t xSpot, uint8_t yHeightySpot, uint8_t blockType)
{
  uint8_t yHeight = extract2ndHalf(yHeightySpot);
  uint8_t ySpot = extract1stHalf(yHeightySpot);
  
  //builds a vertical column
  if(mapx == xSpot-1)
  {
    for(uint8_t i = 0; i < yHeight; i++)
    {
      world[13-(i+ySpot)][16] = blockType;
      
    }
    
  }
}


//What happens every time a level is loaded
void newLevel()
{
  
  //arduboy.clear;
  sky = pgm_read_byte(&levelInfo[level].themeInfo)/10%10;
  levelTimer = 250;
  mapx = 0;
  playerx = 16;
  screenx = 0;
  screeny = -40;
  tempSpace = 9;
  tempLoop = true;
  
  for(uint8_t x = 0;x<8;x++)
  {
    tempScanner[x] = 0;
  }




/*
  for(uint8_t moveShift = 0; moveShift < 144; moveShift++)
  {
    playerx++;

    
  }
  if(playerx-screenx >= 56)
    {
      screenx++;
      scrollLeft();
    }
  */
}


void buildCastle(uint8_t xSpot)
{
  if(pgm_read_byte(&levelInfo[level+1].themeInfo)%10 == 4)
  {
    buildRects(xSpot,packHalf(2,6),9,60);
    buildRects(xSpot+2,packHalf(8,3),5,60);

    buildBlock(xSpot+2,packHalf(2,2));
    buildBlock(xSpot+4,packHalf(2,2));
    buildBlock(xSpot+6,packHalf(2,2));
    buildBlock(xSpot+3,packHalf(5,2));
    buildBlock(xSpot+5,packHalf(5,2));

    //buildRow(xSpot,9,packHalf(7,15));
    //buildRow(xSpot+2,5,packHalf(10,15));
  }

  else
  {
    //castle
    buildRects(xSpot+1,packHalf(2,3),5,60);
    buildRects(xSpot+2,packHalf(5,2),3,60);

    buildBlock(xSpot+3,packHalf(2,2));
  }
  
  
  
}


void endLevel()
{

  if(pgm_read_byte(&levelInfo[level].themeInfo)%10 == 3)
  {
    
    buildStairs(pgm_read_byte(&levelInfo[level].endSpot),createPackedStair(0,6,6,1));
    
    //flag pole block
    buildBlock(pgm_read_byte(&levelInfo[level].endSpot) + 17,packHalf(2,6));


    buildCastle(pgm_read_byte(&levelInfo[level].endSpot) + 20);

    
    if(mapx >= pgm_read_byte(&levelInfo[level].endSpot)-1)
    {
    // world[16][11] = 6;
      arduboy.drawFastVLine(124+pgm_read_byte(&levelInfo[level].endSpot)*8-screenx,8+screeny,72,BLACK);
    }
  }

  else if(pgm_read_byte(&levelInfo[level].themeInfo)%10 == 4)
  {
    //builds bowser bridge
    //gap
    buildGaps(pgm_read_byte(&levelInfo[level].endSpot),13);

    buildRow(pgm_read_byte(&levelInfo[level].endSpot)+13,3,packHalf(5,4));
    
    buildRects(pgm_read_byte(&levelInfo[level].endSpot),packHalf(4,1),13,53);
    buildRects(pgm_read_byte(&levelInfo[level].endSpot)+14,packHalf(9,3),2,4);
    buildRects(pgm_read_byte(&levelInfo[level].endSpot)+16,packHalf(2,10),16,2);

    
    buildBlock(pgm_read_byte(&levelInfo[level].endSpot)+13,packHalf(6,6));

 
    

  }
  
  
}


//makes pipes, kinda messy...
void buildPipe(uint8_t xSpot, uint8_t ySpotPipeHeightSideways)
{  

  uint8_t ySpot = extractPipeySpot(ySpotPipeHeightSideways);
  uint8_t pipeHeight = extractPipeHeight(ySpotPipeHeightSideways);
  uint8_t sideways = extractSideways(ySpotPipeHeightSideways);

  if(sideways == 0)
  {
    if(mapx == xSpot - 1)
    {
      for(uint8_t i = 0; i < pipeHeight + 2; i++)
      {
        world[12 - i - ySpot][16] = 16;
      }
      if(pipeHeight < 9)
      {
        world[12 - pipeHeight-1 - ySpot][16] = 18;
      }
      
    }
  
    else if(mapx == xSpot)
    {
      for(int i = 0; i < pipeHeight + 2; i++)
      {
        world[12 - i - ySpot][16] = 17; 
        if(pipeHeight < 9)
        {
          world[12 - pipeHeight-1 - ySpot][16] = 19;
        }
        
      }
    }
  }

  else if(sideways == 1)
  {
    if(mapx == xSpot - 1)
    {
      world[12 - ySpot][16] = 39;
      world[11 - ySpot][16] = 41;
    }
    else if(mapx == xSpot && pipeHeight > 0)
    {
      world[12 - ySpot][16] = 40;
      world[11 - ySpot][16] = 42;
    }
  }
  
}

void buildMush(uint8_t xSpot, uint8_t mushHeightxWidth, bool mushType)
{  
  uint8_t mushHeight = extract1stHalf(mushHeightxWidth);
  uint8_t mushWidth = extract2ndHalf(mushHeightxWidth);
  

  if(mushType == true)
  {
    if(mapx == xSpot - 2)
    {
      world[13-(mushHeight+1)][16] = 31;
    }
    
  else if(mapx >= xSpot - 1)
  {
    for(uint8_t i = mushHeight+1; i > 0; i--)//vertical
    {  
      for(uint8_t j = 0; j < mushWidth + 1; j++)//horizontal
      {  
        if(mapx< xSpot -1 + mushWidth)
        {
          world[14-(i)][16] = 30;
          world[13-(mushHeight+1)][16] = 32;
        }  
      }
    }
    if(mapx == xSpot-1+mushWidth)
    {
      world[13-(mushHeight+1)][16] = 33;
    }
  }
  
  }



  if(mushType == false)
  {
    //oh god...
    
    uint8_t newWidth = (mushWidth)-2;
    
    if(mapx == xSpot -1- (mushWidth)/2)
    {
      world[13-(mushHeight+1)][16] = 35;
    }
    
  else if(mapx >= xSpot- (mushWidth)/2)
  {

    if(mapx -1  == xSpot-1+(newWidth)/2-(mushWidth)/2)
    {
      for(uint8_t i = mushHeight+1; i > 0; i--)//vertical
      { 
        world[14-(i)][16] = 34;
      }
   }
    
   
        if(mapx-1< xSpot -1+ newWidth - (mushWidth)/2)
        {
          world[13-(mushHeight+1)][16] = 36;
        }  
      
    
    if(mapx == xSpot+newWidth-(mushWidth)/2)
    {
      world[13-(mushHeight+1)][16] = 37;
    }
  }
  
  }
}

//Most important thing, this piper function is in charge of:
//calling functions depending on the data for that level
//It links the mega array data to each build function type, like for pipes below
//Really the pipes are the only things I'm trying to get to work right now

void piper()
{
  uint8_t levelChange = 0;
  
  //if a new level is loaded, I want this to run once
  //if(levelChange != level){
    
  if(tempLoop == true)
  {
    for( uint8_t x = 0; x <= level; x++)
    {
      for(uint8_t y = 0; y < 8; y++)
      {
        tempScanner[y] += pgm_read_byte(&objectList[x][y]);
      }
      buildSky();
    }
    tempLoop = false;
  }

/*
  if(level == 26)
  {



    
    tempScanner[0] = 20;
    tempScanner[1] = 23;
    tempScanner[2] = 47;
    tempScanner[3] = 77;
    tempScanner[4] = 51;
    tempScanner[5] = 10;
    tempScanner[6] = 27;
    tempScanner[7] = 20;
  }

  if(level == 18)
  {
    tempScanner[0] = 9;
    tempScanner[1] = 14;
    tempScanner[2] = 29;
    tempScanner[3] = 25;
    tempScanner[4] = 9;
    tempScanner[5] = 5;
    tempScanner[6] = 17;
    tempScanner[7] = 17;
  }
*/



  //clears the column before anything else can be put there
  
  //CLEAR SEAM
  for(uint8_t i = 0;i<12; i++)
  {
    world[i][16] = sky;
  }

  
  
  
  buildBG();
  
 
  
  
  endLevel();
  

  //stairs
  for(uint16_t y = tempScanner[5] - pgm_read_byte(&objectList[level][5]); y<tempScanner[5];y++)
  {
    buildStairs(pgm_read_byte(&stairInfo[y].xSpot),pgm_read_byte(&stairInfo[y].faceRightBlockWidthBlockTypeExtraxSpot));
  }

  
  
  buildGround();
  

   //gaps
  for(uint8_t y = tempScanner[0] - pgm_read_byte(&objectList[level][0]); y<tempScanner[0];y++)
  {
    buildGaps(pgm_read_byte(&gapInfo[y].xSpot),pgm_read_byte(&gapInfo[y].gapWidth));
  }

  //mushrooms
  for(uint8_t y = tempScanner[7] - pgm_read_byte(&objectList[level][7]); y<tempScanner[7];y++)
  {
    buildMush(pgm_read_byte(&mushInfo[y].xSpot),pgm_read_byte(&mushInfo[y].mushHeightxWidth),pgm_read_byte(&mushInfo[y].mushType));
  }
  

  //rects
  for(uint8_t y = tempScanner[6] - pgm_read_byte(&objectList[level][6]); y<tempScanner[6];y++)
  {
    buildRects(pgm_read_byte(&rectInfo[y].xSpot),pgm_read_byte(&rectInfo[y].ySpotBlockHeight),pgm_read_byte(&rectInfo[y].blockWidth),pgm_read_byte(&rectInfo[y].blockType));
  }

  //row
  for(uint16_t y = tempScanner[3] - pgm_read_byte(&objectList[level][3]); y<tempScanner[3];y++)
  {
    buildRow(pgm_read_byte(&rowInfo[y].xSpot),pgm_read_byte(&rowInfo[y].xWidth),pgm_read_byte(&rowInfo[y].ySpotBlockType));
  }

  //pipes
  for(uint8_t y = tempScanner[1] - pgm_read_byte(&objectList[level][1]); y<tempScanner[1];y++)
  {
    buildPipe(pgm_read_byte(&pipeInfo[y].xSpot),pgm_read_byte(&pipeInfo[y].ySpotPipeHeightSideways));
  }

  //column
  for(uint8_t y = tempScanner[4] - pgm_read_byte(&objectList[level][4]); y<tempScanner[4];y++)
  {
    buildColumn(pgm_read_byte(&columnInfo[y].xSpot),pgm_read_byte(&columnInfo[y].ySpotyHeight),pgm_read_byte(&columnInfo[y].blockType));
  }

  //single block
  for(uint8_t y = tempScanner[2] - pgm_read_byte(&objectList[level][2]); y<tempScanner[2];y++)
  {
    buildBlock(pgm_read_byte(&blockInfo[y].xSpot),pgm_read_byte(&blockInfo[y].ySpotBlockType));
  }
}


void blockFlicker()
{
  //yo make this consistent. use worldtime
//MAKES GREY
for(uint8_t i = 0; i < 17; i++)
{
  for(uint8_t j = 0; j < 13; j++)
  {
    if(world[j][i] == 0)
    {
      world[j][i] = 29;
    }

    else if(world[j][i] == 29)
    {
      world[j][i] = 0;
    }


    if(mapx > pgm_read_byte(&levelInfo[level].endSpot))
    {
      if(world[j][i] == 2)
      {
      //  world[j-1][i] = 56;
      }
    }


    if(world[j][i] == 7)
    {
      world[j][i] = 63;
    }

    else if(world[j][i] == 63)
    {
      world[j][i] = 64;
    }

     else if(world[j][i] == 64)
    {
      world[j][i] = 63;
    }

    if(world[j][i] == 60)
    {
      world[j][i] = 61;
    }

    else if(world[j][i] == 61)
    {
      world[j][i] = 60;
    }


    //for block 6
    if(world[j][i] == 6)
    {
      world[j][i] = 55;
    }

    else if(world[j][i] == 55)
    {
      world[j][i] = 6;
    }

    if(world[j][i] == 15)
    {
      world[j][i] = 62;
    }

    else if(world[j][i] == 62)
    {
      world[j][i] = 15;
    }

/*
    //for block 6 (This looks awesome!)
    if(world[j][i] == 6)
    {
      world[j][i] = 58;
    }

    else if(world[j][i] == 58)
    {
      world[j][i] = 59;
    }

    else if(world[j][i] == 59)
    {
      world[j][i] = 58;
    }

*/

    

    //for bridges
    if(world[j][i] == 12)
    {
      world[j-1][i] = 54;
    }

    

    //for coins
    if(sky == 2)
    {
      if(world[j][i] == 10)
      {
        world[j][i] = 46;
      }
    }
    


    /*
    if(world[j][i] == 8)
    {
      world[j][i] = 51;
    }

    else if(world[j][i] == 51)
    {
      world[j][i] = 52;
    }

    else if(world[j][i] == 52)
    {
      world[j][i] = 51;
    }
    */
    

    /*
    if(world[j][i] == 22 || 23 || 24 || 25)
    {
      world[j][i] = sky;
    }

    else if(world[j][i] == 29)
    {
      world[j][i] = 0;
    }
    */
  }
}
}




//scrolls the numbers in the world array to the left one place

void scrollLeft()
{
  if(screenx % speedChange == 0)
  {
    mapx++;
    for(size_t x = 1; x < WORLD_WIDTH; ++x)
    {
      for(size_t y = 0; y < WORLD_HEIGHT; ++y)
      {
        world[y][x - 1] = world[y][x];  
      }
    }
  }  
}

void scrollUp()
{
 // if(screenx % speedChange == 0)
//  {
  //  mapx++;
    for(size_t x = 1; x < WORLD_WIDTH; ++x)
    {
      for(size_t y = 0; y < WORLD_HEIGHT; ++y)
      {
        world[y-1][x] = world[y][x];  
      }
    }
 // }  
}

//Takes button inputs
void controls()
{
  if(arduboy.pressed(RIGHT_BUTTON))
  {
    if(canMove == true)
    {
      if(worldTime % 3 == 0)
      {
        if(slowRunCountdown > 1)
        {
          slowRunCountdown--;
        }
      }
 
    if(slowRun%slowRunCountdown == 0)
    {
      playerx+=2;
    }

    if(playerx-screenx >= 56)
    {
      screenx+=2;
      scrollLeft();
    }
    }
  }
  else
  {
    if(slowRunCountdown < 8)
    {
      slowRunCountdown++;
    }
  }

  if(screeny == 8)
  {
    //screeny++;
    //screeny = 0;
  }

  if(screenynegative == 0)
  {
    //screeny--;
    //screeny = 8;
  }

   

  if(arduboy.pressed(LEFT_BUTTON))
  {
    if(canMove == true)
    {
      if(playerx-screenx > 0)
      {
        playerx-=2;
      }
    }  
  }

  if(arduboy.justPressed(UP_BUTTON))
  {
    

    //resets from level 32 (31) to 1 (0)
    if(level == 39)
    {
      level = 0;
    }  
    level++;
    newLevel();
  }

  if(arduboy.justPressed(DOWN_BUTTON))
  {
    if(level == 0)
    {
      level = 40;
    }
    level--;
    newLevel();
  }

  if(arduboy.pressed(B_BUTTON))
  { 
    if(playery-32-screeny <= 0)
    {
      /*
      if(screeny < 32)
      {
        screeny++;
      }
      */
      if(screeny < 0)
      {
        screeny++;
      }
    }
    playery -= 3;
  }

  if(playery-screeny >= 8)
    {
      if(screeny > 0)
      {
       // screeny--;
      }
  
    }

    if(playery > 32){
      if(screeny > -32)
      {
         screeny--;
      }
     
    }

  if(arduboy.pressed(A_BUTTON))
  { 
  /*
    if(screeny > 0)
    {
     screeny--;
    }
    
    if(screeny > -32)
    {
      screeny--;
      }

      */
      playery += 3;
  }

  if(arduboy.pressed(B_BUTTON))
  { 
    //screeny--;
  }
}


void testControls()
{
  if(arduboy.pressed(RIGHT_BUTTON))
  {
    if(canMove == true)
    {
      screenx+=4;
      scrollLeft();
    }
  }
  else
  {
    if(slowRunCountdown < 8)
    {
      slowRunCountdown++;
    }
  }

  if(screeny == 8)
  {
    //screeny++;
    //screeny = 0;
  }

  if(screenynegative == 0)
  {
    //screeny--;
    //screeny = 8;
  }

   

  if(arduboy.pressed(LEFT_BUTTON))
  {
    if(canMove == true)
    {
      if(playerx-screenx > 0)
      {
    //    playerx-=4;
      }
    }  
  }

  if(arduboy.justPressed(UP_BUTTON))
  {
    

    //resets from level 32 (31) to 1 (0)
    if(level == 39)
    {
      level = 0;
    }  
    level++;
    newLevel();
  }

  if(arduboy.justPressed(DOWN_BUTTON))
  {
    if(level == 0)
    {
      level = 40;
    }
    level--;
    newLevel();
  }

  if(arduboy.pressed(B_BUTTON))
  { 
   
      /*
      if(screeny < 32)
      {
        screeny++;
      }
      */
      if(screeny < 0)
      {
        screeny+=2;
      }
    
    //playery -= 3;
  }


   

  if(arduboy.pressed(A_BUTTON))
  { 
  /*
    if(screeny > 0)
    {
     screeny--;
    }
    
    if(screeny > -32)
    {
      screeny--;
      }
  
      */

      if(screeny > -40)
      {
        screeny-=2;
      }

      
      //playery += 3;
  }

  if(arduboy.pressed(B_BUTTON))
  { 
    //screeny--;
  }
}


void gravityCount()
{
  if(plusJump<5)
  {
    gravity++;
    if(gravity % 10 == 0)
    {
      plusJump++;
    }
  }
  playery += plusJump;
}




//makes the player collide with blocks, super bad right now
void collision()
{
  
  
  //level timer
  if(worldTime%25 == 0)
  {
    levelTimer--;
  }

  if(levelTimer == 0)
  {
    levelTimer = 250;
  }

  //yoooo make one of these into its own function so you can call it and replace block to check
  if(world[playery / 8+6][(playerx-screenx) / 8] == sky)
  {
    isGrounded = false;
    playery++;
    gravityCount();
  }
  else if(playery>=48)
  {
    playery++;
  }

  if(world[playery/ 8+6][(playerx-screenx) / 8] != sky)
  {
    if(playery > 0)
    { 
      isGrounded = true;
      gravity = 0;
      plusJump = 0;
    }
  }
  
  //for being able to move right
  if(world[playery / 8+4][(playerx-screenx) / 8+2] != sky)
  {
    if(playery>0)
    {
      canMove = false;
    }
  }

  //for mario's top half's collision. Make it so that you can lock y and x movement separately.
  /*
  else if(world[playery / 8+2][(playerx-screenx) / 8+2] != sky){
    if(playery>0){
      canMove = false;
    }
    
  }
  */
  
  else
  {
    canMove = true;
  }
  if(world[playery / 8][(playerx-screenx) / 8] == 11)
  {
    coins++;
    world[playery / 8][(playerx-screenx) / 8] = sky;
  }
  if(playery == 80)
  {
    newLevel();
    playery = 40;
  }

  if(plusJump)
  {
    isFalling = true;
  }
  else
  {
    isFalling = false;
  }
}

void buildSky()
{
  //builds sky
  //if(tempLoop == true){
    for (uint8_t y = 0; y < 12; y++)
    {
      for (uint8_t x = 0; x < 17; x++)
      {
        //world[y][x] = levelInfo[level] / 100;
      world[y][x] = sky;
        //  Sprites::drawOverwrite(y, x, tiles, sky);
      }
    }

  //Sprites::drawOverwrite(31, 21, cloudFull, 0);
  

  //builds bushes
}


void buildBG()
{
  //for underwater levels, change to wave block
  if(sky == 0)
  {
    for(uint8_t x = 0; x < 17; x++)
    {
      if(world[1][x] == 0 || world[1][x] == 29)
      {
        world[1][x] = 26;
      }
      
    }
  }
  
  //for castles, add lava
  if(pgm_read_byte(&levelInfo[level].themeInfo)%10 == 4)
  {
    //for(uint8_t x = 0; x < 17; x++)
    //{
      if(world[12][15] == 2)
      {
        world[12][15] = 26;
      }
      
    //}
  }
  

  //builds clouds

  

  //try to do every 5-10 tiles


  uint8_t cloudState = 0;

  switch(cloudState)
  {
    case 0:
      
    break;
    
  }

  if(mapx ==tempSpace - 1)
  {
    world[5][16] = 22;
    world[4][16] = 24;

    world[11][16] = 24;
  }
  if(mapx == tempSpace)
  {
    world[5][16] = 23;
    world[4][16] = 25;

    world[11][16] = 25;
    
  }
  if(mapx == tempSpace+1)
  {
    tempSpace += 11;
    cloudState++;
    
  }

  
}


//This displays the numbers in the world as tiles
//It also displays player sprites and numbers
void graphics()
{
  const int tileswide = WIDTH / 8 + 1;
  const int tilestall = HEIGHT / 8 + 1;

  for (uint8_t y = 0; y < tilestall; y++)
  {
    for (uint8_t x = 0; x < tileswide; x++)
    {
      const int tiley = y - (screeny) / 8; //check the 8* part and screeny below
      Sprites::drawOverwrite(x * 8 - screenx % 8, y * 8 + screeny % 8, tiles, world[tiley][x]);
    }
  }

  //prints timer
  arduboy.setCursor(100,0);
  arduboy.print(levelTimer);

  //buildSky();
  piper();

  blockFlicker();

  //buildColumn(2,202,6);
  
  //prints player
  Sprites::drawOverwrite(playerx-screenx,playery,playerBig,0);

  

  arduboy.setCursor(0,0);
  arduboy.print("MAPx:");
  arduboy.print(mapx);
  
  arduboy.setCursor(0,10);
  arduboy.print("SCRy:");
  arduboy.print(screeny);
  
  
  arduboy.setCursor(64,0);
  arduboy.print(isGrounded);
  arduboy.print(isFalling);
  
  arduboy.setCursor(12,20);
  arduboy.print(level);

 

  //arduboy.setCursor(60,20);
  //arduboy.print(screeny);



  uint8_t testi(packPipe(7,4,1));

  uint8_t testy(extractSideways(testi));

  arduboy.setCursor(60,20);
  //arduboy.print(testi);

  
  arduboy.setCursor(80,20);
  //arduboy.print(testy);

  //arduboy.setCursor(80,20);
  //arduboy.print(playerx);

  //arduboy.setCursor(100,20);
  //arduboy.print(screenx);


/*
  arduboy.setCursor(8,30);
  arduboy.print(tempScanner[0]);

  arduboy.setCursor(40,30);
  arduboy.print(tempScanner[1]);

  arduboy.setCursor(72,30);
  arduboy.print(tempScanner[2]);

  arduboy.setCursor(104,30);
  arduboy.print(tempScanner[3]);

  arduboy.setCursor(8,40);
  arduboy.print(tempScanner[4]);

  arduboy.setCursor(40,40);
  arduboy.print(tempScanner[5]);

  arduboy.setCursor(72,40);
  arduboy.print(tempScanner[6]);

  arduboy.setCursor(104,40);
  arduboy.print(tempScanner[7]);

  */



  //arduboy.setCursor(85,30);
  //arduboy.print(678/10%10);

  //arduboy.setCursor(85,30);
  //arduboy.print(678/100);


  //buildMush(5, 51, true);


/*
  uint8_t tweak = 78;

  if(tweak/100 == 0)
  {
    arduboy.print("y");
  }
  else
  {
    arduboy.print("n");
  }

  */
 
}

void titleScreen()
{
  for (uint8_t y = 0; y < 8; y++)
  {
    for (uint8_t x = 0; x < 16; x++)
    {
      Sprites::drawOverwrite(x * 8, y * 8, tiles, world[y][x]);
    }
  }

  //these make up the bolts and period. They use too much!!!
  arduboy.drawPixel(26,10,WHITE);
  arduboy.drawPixel(101,10,WHITE);
  arduboy.drawPixel(26,37,WHITE);
  arduboy.drawPixel(101,37,WHITE);
  arduboy.fillRect(97,33,3,3,WHITE);
  
  Sprites::drawOverwrite(30, 10, logoSuper, 0);
  //Sprites::drawOverwrite(30, 21, logoMarioBros, 0);
  //Sprites::drawOverwrite(68, 20, logoMarioBros, 1);
  Sprites::drawOverwrite(31, 21, logoArduBros, 0);
  Sprites::drawOverwrite(67, 21, logoArduBros, 1);

  


  
  if(arduboy.justPressed(B_BUTTON))
  {
    gamestate = 2;
    newLevel();
  }
}


void loading()
{
  if(mapx < 16)
  {

    //mapx++;
    
    
    screenx+=8;
    
    playerx+=8;
    scrollLeft();
  }

  if(level == 28)
  {
    if(mapx == 255)
    {
      level++;
      newLevel();
    }
  }
  
}

void gameplay()
{
  //controls();
  testControls();
  //collision();
  graphics();
  loading();
}


//Overall, gameloop is in charge of where your game should be. Doesn't really matter
void gameloop()
{
  switch(gamestate)
  {
    case 0:
      titleScreen();
      break;

    case 1:
      //midScreen();
      break;

    case 2:
      gameplay();
      break;
    
    case 3:
      //pause screen
      //pauseScreen();
      break;
  }
}
