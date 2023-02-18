#include "CANMesasgeHandle.h"
#include "PIDMessageBuilder.h"

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
  unsigned long canMsgHandleStartTime;
  if (CANMSG_TIME_MEAS)
    canMsgHandleStartTime = micros();

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

  // Ignore query if the ID do not match with this ECU ID (or 0x7DF(send to all ECU))
  if((canId != 0x7DF) && (canId != ECU_CAN_ID))
  {
    if (CANMSG_DEBUG)
      Serial.println(F("CAM ID do not match with this ECU's ID."));
    
    return;
  }

  // Wait time
  if(ECU_WAIT > 0)
    delay(ECU_WAIT);

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
  byte returnBuf[8];
  uint8_t requestedPIDList[1] = {requestedPID};
  uint8_t returnByteCount;
  const uint8_t requestedPIDCount = 1;

  int pidValMessageResult = buildPIDValueMessage(returnBuf, returnByteCount, requestedPIDList, requestedPIDCount, returnServiceMode);
  if (pidValMessageResult == PID_NOT_AVAILABLE)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query PID is not supported."));
    return;
  }

  // Send CAN return message.
  CAN.sendMsgBuf(ECU_CAN_RESPONSE_ID, 0, 8, returnBuf);
  if(CANMSG_TIME_MEAS)
    Serial.print(F("CAN message handle time (micros): "));
    Serial.println(micros() - canMsgHandleStartTime);
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
