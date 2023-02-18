int buildPIDValueMessage(byte *returnBuf, uint8_t& returnByteCount, uint8_t* requestedPIDList, const uint8_t requestedPIDCount, const uint8_t returnServiceMode)
{
  returnBuf[1] = returnServiceMode;
  uint8_t byteOffset = 2;

  for(uint8_t i = 0; i < requestedPIDCount; i++)
  {
    uint8_t requestedPID = requestedPIDList[i];
    const byte valByteLength = pgm_read_byte(PIDByteLengthMap + requestedPID);
    if (valByteLength == 0)
      return PID_NOT_AVAILABLE;

    const byte returnByteLength = valByteLength + 2; // PID data length + PIDcode(1byte) + serviceModde(1byte)
    returnBuf[0] = returnByteLength;

    const unsigned int PIDAddressOffset = pgm_read_word(PIDAddressMap + requestedPID);
    for (int i = 0; i < valByteLength; i++)
      returnBuf[i + 3] = PID_Value_Map[PIDAddressOffset + i];

  }

  return NOERROR;
}

void _buildAvailablePIDMessage(byte *returnBuf, const uint8_t requestedPID, const uint8_t returnServiceMode)
{
  const byte valByteLength = 4;
  const byte returnByteLength = valByteLength + 2;
  const int availableMapOffset = (requestedPID / 0x20) * 4;
  returnBuf[0] = returnByteLength;
  returnBuf[1] = returnServiceMode;
  returnBuf[2] = requestedPID;
  returnBuf[3] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset);
  returnBuf[4] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 1);
  returnBuf[5] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 2);
  returnBuf[6] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 3);
}
