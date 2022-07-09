
#pragma once

// For uint8_t
#include <stdint.h>

// For PROGMEM
#include <avr/pgmspace.h>



//For stairs
constexpr uint8_t stairDirectionShift = 7;
constexpr uint8_t stairDirectionSize = 1;
constexpr uint8_t stairDirectionMask = ((1 << stairDirectionSize) - 1);

constexpr uint8_t stairWidthShift = 4;
constexpr uint8_t stairWidthSize = 3;
constexpr uint8_t stairWidthMask = ((1 << stairWidthSize) - 1);

constexpr uint8_t stairTypeShift = 1;
constexpr uint8_t stairTypeSize = 3;
constexpr uint8_t stairTypeMask = ((1 << stairTypeSize) - 1);

constexpr uint8_t stairExtraShift = 0;
constexpr uint8_t stairExtraSize = 1;
constexpr uint8_t stairExtraMask = ((1 << stairExtraSize) - 1);


constexpr uint8_t extractStairDirection(uint8_t packedStair)
{
  return ((packedStair >> stairDirectionShift) & stairDirectionMask);
}

constexpr uint8_t extractStairWidth(uint8_t packedStair)
{
  return ((packedStair >> stairWidthShift) & stairWidthMask);
}

constexpr uint8_t extractTypeWidth(uint8_t packedStair)
{
  return ((packedStair >> stairTypeShift) & stairTypeMask);
}

constexpr uint8_t extractExtraxSpot(uint8_t packedStair)
{
  return ((packedStair >> stairExtraShift) & stairExtraMask);
}


constexpr uint8_t createPackedStair(uint8_t stairDirection, uint8_t stairWidth, uint8_t stairType,uint8_t extraxSpot)
{
  // Note: The values are masked before being shifted just to make sure that
  // the input values aren't outside the acceptable range.
  // E.g. without the masking, a `stairWidth` value of 16
  // would cause the stairs to face to the right.

  return
    ((stairDirection & stairDirectionMask) << stairDirectionShift) |
    ((stairWidth & stairWidthMask) << stairWidthShift) |
    ((stairType & stairTypeMask) << stairTypeShift) |
    ((extraxSpot & stairExtraMask) << stairExtraShift);

};





//For blocks CHANGE THESE TO MAKE MORE SENSE
constexpr uint8_t blockySpotShift = 4;
constexpr uint8_t blockySpotSize = 4;
constexpr uint8_t blockySpotMask = ((1 << blockySpotSize) - 1);

constexpr uint8_t blockTypeShift = 0;
constexpr uint8_t blockTypeSize = 4;
constexpr uint8_t blockTypeMask = ((1 << blockTypeSize) - 1);


constexpr uint8_t extract1stHalf(uint8_t packedBlock)
{
  return ((packedBlock >> blockySpotShift) & blockySpotMask);
}

constexpr uint8_t extract2ndHalf(uint8_t packedBlock)
{
  return ((packedBlock >> blockTypeShift) & blockTypeMask);
}

constexpr uint8_t packHalf(uint8_t ySpot, uint8_t blockType)
{
  // Note: The values are masked before being shifted just to make sure that
  // the input values aren't outside the acceptable range.
  // E.g. without the masking, a `stairWidth` value of 16
  // would cause the stairs to face to the right.

  return
    ((ySpot & blockySpotMask) << blockySpotShift) |
    ((blockType & blockTypeMask) << blockTypeShift);
};


//For pipes
constexpr uint8_t sidewaysShift = 0;
constexpr uint8_t sidewaysSize = 1;
constexpr uint8_t sidewaysMask = ((1 << sidewaysSize) - 1);

constexpr uint8_t ySpotShift = 1;
constexpr uint8_t ySpotSize = 3;
constexpr uint8_t ySpotMask = ((1 << ySpotSize) - 1);

constexpr uint8_t pipeHeightShift = 4;
constexpr uint8_t pipeHeightSize = 4;
constexpr uint8_t pipeHeightMask = ((1 << pipeHeightSize) - 1);






constexpr uint8_t extractSideways(uint8_t packedPipe)
{
  return ((packedPipe >> sidewaysShift) & sidewaysMask);
}

constexpr uint8_t extractPipeySpot(uint8_t packedPipe)
{
  return ((packedPipe >> ySpotShift) & ySpotMask);
}

constexpr uint8_t extractPipeHeight(uint8_t packedPipe)
{
  return ((packedPipe >> pipeHeightShift) & pipeHeightMask);
}


constexpr uint8_t packPipe(uint8_t ySpot, uint8_t pipeHeight, uint8_t sideways)
{
  // Note: The values are masked before being shifted just to make sure that
  // the input values aren't outside the acceptable range.
  // E.g. without the masking, a `stairWidth` value of 16
  // would cause the stairs to face to the right.

  return
    ((sideways & sidewaysMask) << sidewaysShift) |
    ((ySpot & ySpotMask) << ySpotShift) |
    ((pipeHeight & pipeHeightMask) << pipeHeightShift);

};
