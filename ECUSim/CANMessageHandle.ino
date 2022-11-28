#include "CANMesasgeHandle.h"

int buildPIDValueMessage(byte *returnBuf, uint8_t requestedPID);
void buildAvailablePIDMessage(byte *returnBuf, uint8_t requestedPID);

constexpr int NOERROR = 0;
constexpr int PID_NOT_AVAILABLE = -1;

void initializeCAN()
{
  bool initSucess = false;
  while (!initSucess)
  {
    if (CAN_OK == CAN.begin(CAN_250KBPS, MCP_8MHz)) // init can bus : baudrate = 250k
    {
      Serial.println(F("CAN BUS Shield init ok!"));
      initSucess = true;
    }
    else
    {
      Serial.println(F("CAN BUS Shield init fail"));
      Serial.println(F("Init CAN BUS Shield again"));
      delay(100);
      initSucess = false;
    }
  }
}

void handleCANMessage()
{
  if (CANMSG_DEBUG)
    Serial.println(F("CAN message handle start."));

  byte canBuf[CAN_PAYLOAD_LENGTH];
  unsigned long canId;
  unsigned char len;

  CAN.readMsgBufID(&canId, &len, canBuf);

  if (len > CAN_PAYLOAD_LENGTH)
  {
    if (CANMSG_FATAL)
      Serial.println(F("FATAL: CAN read message length exceed CAN_PAYLOAD_LENGTH."));

    return;
  }
  if (CANMSG_DEBUG)
  {
    Serial.print(F("Msg from canId: "));
    Serial.println(canId, HEX);
  }

  const uint8_t queryMessageLength = canBuf[0];
  const uint8_t serviceMode = canBuf[1];
  if (queryMessageLength != 2)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query message byte length is not 2."));

    return;
  }
  if (serviceMode != 0x01)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query service mode needs to be 1 (show current data)."));

    return;
  }

  const uint8_t requestedPID = canBuf[2];
  if (CANMSG_DEBUG)
  {
    Serial.print(F("PID query: "));
    Serial.println(requestedPID, HEX);
  }

  // Build up CAN return message
  const uint8_t returnServiceMode = serviceMode + 0x40;
  byte returnBuf[8] = {0x00, returnServiceMode, requestedPID, 0x00, 0x00, 0x00, 0x00, 0x00};

  if ((requestedPID % 0x20) == 0) // Return supported PID flag mode (=> get data from PIDAvailableFlagMap in PROGMEM)
    buildAvailablePIDMessage(returnBuf, requestedPID);
  else // Return value mode (=> get data from PID_Value_Map in RAM)
  {
    int pidValMessageResult = buildPIDValueMessage(returnBuf, requestedPID);
    if (pidValMessageResult == PID_NOT_AVAILABLE)
    {
      if (CANMSG_ERROR)
        Serial.println(F("ERROR: CAN query PID is not supported."));
      return;
    }
  }

  // Send CAN return message.
  CAN.sendMsgBuf(ECU_CAN_RESPONSE_ID, 0, 8, returnBuf);

  if (CANMSG_DEBUG)
  {
    Serial.print(F("Return byte length: "));
    Serial.println(returnBuf[0], DEC);
    Serial.print(F("Return service mode: "));
    Serial.println(returnBuf[1], HEX);
    Serial.print(F("Return PID: "));
    Serial.println(returnBuf[2], HEX);
    Serial.print(F("Return. Value (with padding): "));
    for (int i = 3; i < 8; i++)
    {
      Serial.print(returnBuf[i], HEX);
      if (i == 7)
        Serial.println();
      else
        Serial.print(",");
    }
  }
}

int buildPIDValueMessage(byte *returnBuf, uint8_t requestedPID)
{
  const byte valByteLength = pgm_read_byte(PIDByteLengthMap + requestedPID);
  if (valByteLength == 0)
    return PID_NOT_AVAILABLE;

  const byte returnByteLength = valByteLength + 2; // PID data length + PIDcode(1byte) + serviceModde(1byte)
  returnBuf[0] = returnByteLength;

  const unsigned int PIDAddressOffset = pgm_read_word(PIDAddressMap + requestedPID);
  for (int i = 0; i < valByteLength; i++)
    returnBuf[i + 3] = PID_Value_Map[PIDAddressOffset + i];

  return NOERROR;
}

void buildAvailablePIDMessage(byte *returnBuf, uint8_t requestedPID)
{
  const byte valByteLength = 4;
  const byte returnByteLength = valByteLength + 2;
  int availableMapOffset = (requestedPID / 0x20) * 4;
  returnBuf[0] = returnByteLength;
  returnBuf[3] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset);
  returnBuf[4] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 1);
  returnBuf[5] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 2);
  returnBuf[6] = pgm_read_byte(PIDAvailableFlagMap + availableMapOffset + 3);
}