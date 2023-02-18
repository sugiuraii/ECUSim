int  buildPIDValueMessage(byte* const returnBuf, uint8_t& returnByteCount, const uint8_t* requestedPIDList, const uint8_t requestedPIDCount, const uint8_t returnServiceMode)
{
  returnBuf[1] = returnServiceMode;
  uint8_t byteOffset = 2;

  for(uint8_t i = 0; i < requestedPIDCount; i++)
  {
    uint8_t requestedPID = requestedPIDList[i];
    const uint8_t valByteLength = pgm_read_byte(PIDByteLengthMap + requestedPID);

    if (valByteLength == 0) // Skip build return byte when PID is not available
      continue;

    // Fill requested PID
    returnBuf[byteOffset] = requestedPID;
    byteOffset++;

    // Fill return value bytes
    const unsigned int PIDAddressOffset = pgm_read_word(PIDAddressMap + requestedPID);
    for (int i = 0; i < valByteLength; i++)
    {
      returnBuf[byteOffset] = PID_Value_Map[PIDAddressOffset + i];
      byteOffset++;
    }
  }

  // Finally, set returnByteCount
  returnByteCount = returnByteCount;
  
  // Check, at least one PID is available or not
  if(byteOffset == 2) // Offset is not changed
    return PID_NOT_AVAILABLE;
  else
    return NOERROR;
}

void fillAvailablePIDBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill)
{
  const int availableMapOffset = (requestedPID / 0x20) * 4;
  returnBuf[byteOffsetToFill] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset);
  returnBuf[byteOffsetToFill + 1] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 1);
  returnBuf[byteOffsetToFill + 2] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 2);
  returnBuf[byteOffsetToFill + 3] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 3);
  byteOffsetAfterFill = byteOffsetToFill + 4;
}
