#include <Arduboy2.h>
#include "graphics.h"
#include "level_Data.h"

Arduboy2 arduboy;

//Sprites sprites;


//SUPER ARDU BROS.
//Created for the Arduboy system

#define WORLD_WIDTH 17
#define WORLD_HEIGHT 8



//all of my variables
uint8_t mapx = 0;
uint8_t level = 0;
uint8_t sky = 0;
uint8_t ground = 11;
uint8_t midBlock = 4;
uint8_t velocity = 0;
uint8_t worldTime = 250;
uint8_t slowRun = 255;
uint8_t slowRunCountdown = 8;
uint8_t levelType = 0;
uint8_t speedChange = 8;
uint8_t levelTimer = 255;
uint8_t coins = 0;
int screenx = 0;
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




//where data
uint8_t tempScanner[7] = {0,0,0,0,0,0,0};

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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
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
  gameloop();
  arduboy.display();
}

void drawGround()
  {  
    if(mapx == 0)
    {
      for(uint8_t i = 0; i < 17;i++)
      {
        world[7][i] = levelInfo[level][0]%10;
      }
    }

  //draws ground until spacePosition is reached (after the first 16 blocks)
    if(mapx>0)
    {
      world[7][16] = levelInfo[level][0]%10;
    }
}

void buildGaps(uint8_t spacePosition, uint8_t spaceWidth)
{ 
  if(mapx >= spacePosition-1)
  {
    if(mapx - spacePosition + 1 < spaceWidth)
    {
      world[7][16] = sky; 
    }
  }
}

void buildStairs(uint8_t xSpot, uint8_t faceRightBlockWidthBlockType)
{
  //can probably limit this int
  uint8_t z = mapx - xSpot+2;
  //uint8_t w = xSpot - mapx;
  
  if(mapx >= xSpot-2)
  {
    if(faceRightBlockWidthBlockType/10/10 == 1)
    {
      for(uint8_t j = 0; j < z; j++)//vertical columns
      { 
        if(z <= 3+faceRightBlockWidthBlockType/10%10)
        {
          world[6 - j][16] = faceRightBlockWidthBlockType%10;
        }
      }
    }
    else if(faceRightBlockWidthBlockType/10/10 == 2)
    {
      if(mapx >= xSpot-1)
      {
        for(uint8_t j = 4+faceRightBlockWidthBlockType/10%10; j > z; j--)//vertical columns
        { 
          if(z <= 4+faceRightBlockWidthBlockType/10%10)
          {
            world[j-6+(7-faceRightBlockWidthBlockType/10%10)][16] = sky;
            world[j-5+(7-faceRightBlockWidthBlockType/10%10)][16] = faceRightBlockWidthBlockType%10;
          }
        }
      }
    }
  }

  //this can be cleaned up a lot...this if statement used to be an else if inside of the above for loop
  if(faceRightBlockWidthBlockType/10/10 == 1)
  {
    if(z==3+faceRightBlockWidthBlockType/10%10+1)
    {
      for(uint8_t i = 0; i < 7; i++)
      {
        world[i][16] = sky;
      }
    }
  }
  else if(faceRightBlockWidthBlockType/10/10 == 2)
  {
    if(z==3+faceRightBlockWidthBlockType/10%10+1)
    {
      for(uint8_t i = 0; i < 7; i++)
      {
        world[i][16] = sky;
      }
    }
  }
}

void buildBlock(uint8_t xSpot, uint8_t blockTypeySpot)
{
  //builds a square section of blocks out of x,y,w,h,and type
  if(mapx == xSpot-1)
  {
    world[8-blockTypeySpot%10][16] = (blockTypeySpot/10)-10;
  }
  else if(mapx == xSpot)
  {
    world[8-blockTypeySpot%10][16] = sky;
  }
}

void buildBlocks(uint8_t xSpot, uint8_t ySpotBlockHeight, uint8_t blockWidth, uint8_t blockType)
{  
  //builds a square section of blocks out of x,y,w,h,and type
  if(mapx >= xSpot - 1)
  {
    for(uint8_t i = ySpotBlockHeight%10; i > 0; i--)//vertical
    {  
      for(uint8_t j = 0; j < blockWidth + 1; j++)//horizontal
      {  
        if(mapx< xSpot -1 + blockWidth)
        {
          world[9-ySpotBlockHeight/10%10 - i][16] = blockType;
        }
        else if(mapx == xSpot -1 + blockWidth)
        {
          world[9-ySpotBlockHeight/10%10 - i][16] = sky;
        }
      }
    }
  }
}

void buildRow(uint8_t xSpot, uint8_t xWidth, uint8_t blockTypeySpot)
{
  //builds a horizontal row of blocks
  if(mapx >= xSpot-1)
  {
    if(mapx - xSpot + 1 < xWidth)
    {
      world[8-blockTypeySpot%10][16] = (blockTypeySpot/10)-10;
    }
    else if(mapx - xSpot + 1 == xWidth)
    {
      world[8-blockTypeySpot%10][16] = sky;
    }
  }
}

void buildColumn(uint8_t xSpot, uint8_t yHeight, uint8_t blockTypeySpot)
{
  //builds a vertical column
  if(mapx == xSpot-1)
  {
    for(uint8_t i = 0; i < yHeight; i++)
    {
      world[8-(i+blockTypeySpot%10)][16] = (blockTypeySpot/10)-10;
    }
  }

  //makes white
  else if(mapx == xSpot)
  {
    for(uint8_t i = 0; i < yHeight; i++)
    {
      world[8-(i+blockTypeySpot%10)][16] = sky;
    }     
  }
}


//What happens every time a level is loaded
void newLevel()
{
  sky = levelInfo[level][0]/10%10;
  levelTimer = 250;
  mapx = 0;
  tempLoop = true;
  
  for(uint8_t x = 0;x<7;x++)
  {
    tempScanner[x] = 0;
  }
}


void endLevel()
{
  buildBlocks(levelInfo[level][1],132,5,7);
  buildRow(levelInfo[level][1],2,125);
}


//makes pipes, kinda messy...
void buildPipe(uint8_t xSpot, uint8_t pipeHeightySpot)
{  
  uint8_t tempHeight = pipeHeightySpot/10%10;
  uint8_t tempySpot = (pipeHeightySpot%10);
  if(mapx == xSpot - 1)
  {
    for(uint8_t i = 0; i < tempHeight + 2; i++)
    {
      world[7 - i - tempySpot][16] = 15;
    }
    world[7 - tempHeight-1 - tempySpot][16] = 17;
  }
  
  else if(mapx == xSpot)
  {
    for(int i = 0; i < tempHeight + 2; i++)
    {
      world[7 - i - tempySpot][16] = 16; 
      world[7 - tempHeight-1 - tempySpot][16] = 18;
    }
  }
  else if(mapx==xSpot + 1)
  {
    for(int i = 0; i < tempHeight + 1; i++)
    {
        world[7 - i - tempySpot][16] = sky;
        world[7 - tempHeight-1 - tempySpot][16] = sky;
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
      for(uint8_t y = 0; y < 7; y++)
      {
        tempScanner[y] += pgm_read_byte(&objectList[x][y]);
      }
      buildSky();
    }
    tempLoop = false;
  }
  
  buildClouds();
  drawGround();
  
  //gaps
  for(uint8_t y = tempScanner[0] - pgm_read_byte(&objectList[level][0]); y<tempScanner[0];y++)
  {
    buildGaps(pgm_read_byte(&gapInfo[y][0]),pgm_read_byte(&gapInfo[y][1]));
  }

  //blocks
  for(uint8_t y = tempScanner[6] - pgm_read_byte(&objectList[level][6]); y<tempScanner[6];y++)
  {
    buildBlocks(pgm_read_byte(&rectInfo[y][0]),pgm_read_byte(&rectInfo[y][1]),pgm_read_byte(&rectInfo[y][2]),pgm_read_byte(&rectInfo[y][3]));
  }

  //pipes
  for(uint8_t y = tempScanner[1] - pgm_read_byte(&objectList[level][1]); y<tempScanner[1];y++)
  {
    buildPipe(pgm_read_byte(&pipeInfo[y][0]),pgm_read_byte(&pipeInfo[y][1]));
  }

  //stairs
  for(uint8_t y = tempScanner[5] - pgm_read_byte(&objectList[level][5]); y<tempScanner[5];y++)
  {
    buildStairs(pgm_read_byte(&stairInfo[y][0]),pgm_read_byte(&stairInfo[y][1]));
  }

  //row
  for(uint8_t y = tempScanner[3] - pgm_read_byte(&objectList[level][3]); y<tempScanner[3];y++)
  {
    buildRow(pgm_read_byte(&rowInfo[y][0]),pgm_read_byte(&rowInfo[y][1]),pgm_read_byte(&rowInfo[y][2]));
  }

  //column
  for(uint8_t y = tempScanner[4] - pgm_read_byte(&objectList[level][4]); y<tempScanner[4];y++)
  {
    buildColumn(pgm_read_byte(&columnInfo[y][0]),pgm_read_byte(&columnInfo[y][1]),pgm_read_byte(&columnInfo[y][2]));
  }

  //single block
  for(uint8_t y = tempScanner[2] - pgm_read_byte(&objectList[level][2]); y<tempScanner[2];y++)
  {
    buildBlock(pgm_read_byte(&blockInfo[y][0]),pgm_read_byte(&blockInfo[y][1]));
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
      playerx++;
    }

    if(playerx-screenx >= 56)
    {
      screenx++;
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

  if(arduboy.pressed(LEFT_BUTTON))
  {
    if(canMove == true)
    {
      if(playerx-screenx > 0)
      {
        playerx--;
      }
    }  
  }

  if(arduboy.justPressed(UP_BUTTON))
  {
    level++;
    newLevel();

    //resets from level 32 (31) to 1 (0)
    if(level > 31)
    {
      level = 0;
    }  
  }

  if(arduboy.justPressed(DOWN_BUTTON))
  {
    if(level == 0)
    {
      level = 32;
    }
    level--;
    newLevel();
  }

  if(arduboy.pressed(B_BUTTON))
  { 
    playery -= 3;
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
  //constant clock for the game world
  worldTime--;
  
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
  if(world[playery / 8+2][(playerx-screenx) / 8] == sky)
  {
    isGrounded = false;
    playery++;
    gravityCount();
  }
  else if(playery>=48)
  {
    playery++;
  }

  if(world[playery / 8+2][(playerx-screenx) / 8] != sky)
  {
    if(playery > 0)
    {
      isGrounded = true;
      gravity = 0;
      plusJump = 0;
    }
  }
  
  //for being able to move right
  if(world[playery / 8+1][(playerx-screenx) / 8+2] != sky)
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
    for (uint8_t y = 0; y < 8; y++)
    {
      for (uint8_t x = 0; x < 17; x++)
      {
        //world[y][x] = levelInfo[level] / 100;
      world[y][x] = sky;
        //  Sprites::drawOverwrite(y, x, tiles, sky);
      }
    }

  //builds clouds
  Sprites::drawOverwrite(31, 21, cloudFull, 0);

  //builds bushes
}


void buildClouds()
{
  //builds clouds
  Sprites::drawOverwrite(31, 21, cloudFull, 0);
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
      Sprites::drawOverwrite(x * 8 - screenx % 8, y * 8, tiles, world[y][x]);
    }
  }

  //prints timer
  arduboy.setCursor(100,0);
  arduboy.print(levelTimer);

  //buildSky();
  piper();
  endLevel();
  
  //prints player
  Sprites::drawOverwrite(playerx-screenx,playery,playerBig,0);



  arduboy.setCursor(0,0);
  arduboy.print("MAP x = ");
  
  arduboy.print(mapx);
  
  arduboy.setCursor(64,0);
  arduboy.print(isGrounded);
  arduboy.print(isFalling);
  
  arduboy.setCursor(12,40);
  arduboy.print(objectList[level - 1][1]);
  
  arduboy.setCursor(12,20);
  arduboy.print(level);

  //arduboy.setCursor(60,20);
  //arduboy.print(temp);

  //arduboy.setCursor(85,40);
  //arduboy.print(tempScanner[1]);

  //arduboy.setCursor(85,30);
  //arduboy.print(678/10%10);
 
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


void gameplay()
{
  controls();
  collision();
  graphics();
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
