#include "CANMesasgeHandle.h"
#include "PIDMessageBuilder.h"

IsoTp isotp(&CAN, 0);
struct Message_t txMsg, rxMsg;

void initializeCAN()
{
  bool initSucess = false;
  while (!initSucess)
  {
    if (CAN_OK == CAN.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ)) // init can bus : baudrate = 250k
    {
      Serial.println(F("CAN BUS Shield init ok!"));
      initSucess = true;
      CAN.setMode(MCP_NORMAL);   
    }
    else
    {
      Serial.println(F("CAN BUS Shield init fail"));
      Serial.println(F("Init CAN BUS Shield again"));
      delay(100);
      initSucess = false;
    }
  }

  // buffers
  txMsg.Buffer = (uint8_t *)calloc(MAX_MSGBUF, sizeof(uint8_t));
  rxMsg.Buffer = (uint8_t *)calloc(MAX_MSGBUF, sizeof(uint8_t));
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

  CAN.readMsgBuf(&canId, &len, canBuf);

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

  // Get query message length and check service mode.
  const uint8_t queryMessageLength = canBuf[0];
  const uint8_t serviceMode = canBuf[1];
  if (serviceMode != 0x01)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query service mode needs to be 1 (show current data)."));

    return;
  }

  if(queryMessageLength < 2 || queryMessageLength > 7)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query message length needs to be between 2 and 7 (1 to 6 PIDs)."));

    return;
  }

  // Get query PID codes
  uint8_t requestedPIDList[6];
  const uint8_t requestedPIDCount = queryMessageLength - 1; // Exclude service mode from query length
  for(uint8_t i = 0; i < requestedPIDCount; i++)
    requestedPIDList[i] = canBuf[i + 2];

  if (CANMSG_DEBUG)
  {
    Serial.print(F("PID query: "));
    for(uint8_t i = 0; i < requestedPIDCount; i++)
    {
      Serial.print(requestedPIDList[i], HEX);
      if(i == requestedPIDCount - 1)
        Serial.println();
      else
        Serial.print(F(","));
    }
  }

  // Build up CAN return message
  const uint8_t returnServiceMode = serviceMode + 0x40;
  byte returnBuf[64];
  uint8_t returnByteCount;

  int pidValMessageResult = buildPIDValueMessage(returnBuf, returnByteCount, requestedPIDList, requestedPIDCount, returnServiceMode);
  if (pidValMessageResult == PID_NOT_AVAILABLE)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query PID is not supported."));
    return;
  }

  // Send CAN return message.
  // send
  txMsg.len = returnByteCount;
  txMsg.tx_id = rx_can_id;
  txMsg.rx_id = tx_can_id;
  memcpy(txMsg.Buffer,returnBuf,returnByteCount);
  isotp.send(&txMsg);

  if(CANMSG_TIME_MEAS)
    Serial.print(F("CAN message handle time (micros): "));
    Serial.println(micros() - canMsgHandleStartTime);
  if (CANMSG_DEBUG)
  {
    Serial.print(F("Return. Value (with padding): "));
    for (int i = 0; i < returnByteCount; i++)
    {
      Serial.print(returnBuf[i], HEX);
      if (i == returnByteCount - 1)
        Serial.println();
      else
        Serial.print(",");
    }
  }
}
