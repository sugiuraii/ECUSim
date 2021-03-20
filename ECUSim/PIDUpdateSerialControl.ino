#include "PIDUpdateSerialControl.h"

void flushSerialInbuf();
int parseOneByteHex(char *hexChars, byte *ret);

void initializePIDValueMap()
{
  for (int i = 0; i < PIDMemSize; i++)
    PID_Value_Map[i] = 0;
}

void flushSerialInbuf()
{
  if (PIDSET_ERROR)
    Serial.println(F("Flush serial port input buffer.."));

  while (Serial.read() != -1)
    Serial.read();

  if (PIDSET_ERROR)
    Serial.println(F("Flush serial port input buffer finished."));
}

void parsePIDUPdateMessage()
{

  if (PIDSET_DEBUG)
    Serial.println(F("PID update start."));

  char serialBuf[SERIAL_MSG_LENGTH];

  // Store serial data to serialBuf.
  for (int i = 0; i < SERIAL_MSG_LENGTH; i++)
    serialBuf[i] = (char)Serial.read();

  // Check delimiter
  if (serialBuf[SERIAL_MSG_LENGTH - 1] != '\n')
  {
    if (PIDSET_ERROR)
      Serial.println(F("ERROR: Input meassage is not finished with LF."));

    flushSerialInbuf();
    return;
  }

  // Parse serialBuf
  byte pidToSet;
  unsigned int pidMemAddress;
  byte valByteLength;
  byte valToSet[4];
  for (int i = 0; i < SERIAL_MSG_LENGTH - 1; i += 2) // Ignore last byte of serialBuf (by setting i < SERIAL_MSG_LENGHT - 1, instead of i < SERIAL_MSG_LENGHT), since the last byte shold be LF.
  {
    char parseBuf[2];
    parseBuf[0] = serialBuf[i];
    parseBuf[1] = serialBuf[i + 1];
    byte parsedVal = 0;
    if (parseOneByteHex(parseBuf, &parsedVal) != 0)
    {
      if (PIDSET_ERROR)
        Serial.println(F("ERROR: Message parse is failed."));

      flushSerialInbuf();
      return;
    }
    // Store parsed result
    switch (i)
    {
    case 0:
      pidToSet = parsedVal;
      valByteLength = pgm_read_byte(PIDByteLengthMap + pidToSet);
      pidMemAddress = pgm_read_word(PIDAddressMap + pidToSet);
      if (PIDSET_DEBUG)
      {
        Serial.print(F("PID:"));
        Serial.println(pidToSet, HEX);
        Serial.print(F("ByteLength:"));
        Serial.println(valByteLength, DEC);
      }

      if (valByteLength == 0)
      {
        if (PIDSET_ERROR)
          Serial.println(F("ERROR: Selected PID is not supported."));

        return;
      }
      break;
    default:
      int valToSetIndex = i / 2 - 1;
      valToSet[valToSetIndex] = parsedVal;
      break;
    }
  }

  // Finally, update PID map
  for (int i = 0; i < valByteLength; i++)
    PID_Value_Map[pidMemAddress + i] = valToSet[i];

  if (PIDSET_DEBUG)
  {
    Serial.print(F("SetVaule:"));
    for (int i = 0; i < valByteLength; i++)
    {
      Serial.print(PID_Value_Map[pidMemAddress + i], HEX);
      if (i != valByteLength - 1)
        Serial.print(F(","));
      else
        Serial.println();
    }
    Serial.println(F("PID set Ok"));
  }
}

int parseOneByteHex(char *hexChars, byte *ret)
{
  byte val = 0;
  for (int i = 0; i < 2; i++)
  {
    byte baseVal = 1 << 4 * (1 - i);
    if (hexChars[i] >= '0' && hexChars[i] <= '9')
      val += (hexChars[i] - '0') * baseVal;
    else if (hexChars[i] >= 'a' && hexChars[i] <= 'f')
      val += (hexChars[i] - 'a' + 10) * baseVal;
    else if (hexChars[i] >= 'A' && hexChars[i] <= 'F')
      val += (hexChars[i] - 'A' + 10) * baseVal;
    else
      return -1;
  }

  *ret = val;
  return 0;
}