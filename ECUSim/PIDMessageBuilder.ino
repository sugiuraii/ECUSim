#include "PIDMessageBuilder.h"

void fillValueBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill);
void fillAvailablePIDBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill);

int  buildPIDValueMessage(byte* const returnBuf, uint8_t& returnByteCount, const uint8_t* requestedPIDList, const uint8_t requestedPIDCount, const uint8_t returnServiceMode)
{
  returnBuf[0] = returnServiceMode;
  uint8_t byteOffset = 1;

  for(uint8_t i = 0; i < requestedPIDCount; i++)
  {
    const uint8_t requestedPID = requestedPIDList[i];
    if ((requestedPID % 0x20) == 0) // Return supported PID flag mode (=> get data from PIDAvailableFlagMap in PROGMEM)
      fillAvailablePIDBytes(returnBuf, requestedPID, byteOffset, byteOffset);
    else // Return value mode (=> get data from PID_Value_Map in RAM)
      fillValueBytes(returnBuf, requestedPID, byteOffset, byteOffset);
  }
  
  // Finally, set returnByteCount
  returnByteCount = byteOffset;

  // Check, at least one PID is available or not
  if(byteOffset == 2) // Offset is not changed
    return PID_NOT_AVAILABLE;
  else
    return NOERROR;
}

void fillValueBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill)
{
    const uint8_t valByteLength = pgm_read_byte(PIDByteLengthMap + requestedPID);
    if (valByteLength == 0) // Skip build return byte when PID is not available
    {
      byteOffsetAfterFill = byteOffsetToFill;
      return;
    }

    // Fill requested PID to 1st byte
    returnBuf[byteOffsetToFill] = requestedPID;

    // Fill return value bytes
    const unsigned int PIDAddressOffset = pgm_read_word(PIDAddressMap + requestedPID);
    for (uint8_t i = 0; i < valByteLength; i++)
      returnBuf[byteOffsetToFill + 1 + i] = PID_Value_Map[PIDAddressOffset + i];

    // Finally, set byteOffseytAfterFill
    byteOffsetAfterFill = byteOffsetToFill + 1 + valByteLength;
}

void fillAvailablePIDBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill)
{
  // Fill requested PID
  returnBuf[byteOffsetToFill] = requestedPID;

  const int availableMapOffset = (requestedPID / 0x20) * 4;

  returnBuf[byteOffsetToFill + 1] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset);
  returnBuf[byteOffsetToFill + 2] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 1);
  returnBuf[byteOffsetToFill + 3] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 2);
  returnBuf[byteOffsetToFill + 4] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 3);
  byteOffsetAfterFill = byteOffsetToFill + 5;
}
