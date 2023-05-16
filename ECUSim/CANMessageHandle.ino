#include "CANMesasgeHandle.h"
#include "PIDMessageBuilder.h"
#include "AVRFreeRAM.h"

IsoTp isotp(&CAN, 0);

constexpr int RETURN_MSGBUILD_BUF_LENGTH = 128;
constexpr int PID_LIST_LENGTH = 6;

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
}

void handleCANMessage()
{
  unsigned long canMsgHandleStartTime;
  if (CANMSG_TIME_MEAS)
    canMsgHandleStartTime = micros();

  if (CANMSG_DEBUG)
    Serial.println(F("CAN message handle start."));

  byte receivedCANBuf[CAN_PAYLOAD_LENGTH];
  unsigned long canId;
  unsigned char len;
  uint8_t recvResult;

  recvResult = CAN.readMsgBuf(&canId, &len, receivedCANBuf);

  if (len > CAN_PAYLOAD_LENGTH)
  {
    if (CANMSG_FATAL)
      Serial.println(F("FATAL: CAN read message length exceed CAN_PAYLOAD_LENGTH."));

    return;
  }

  if(CANMSG_ERROR)
  {
    if(recvResult != CAN_OK) {
      Serial.print(F("ERROR: CAN message receive is failed. Return of readMsgBuf : "));
      Serial.println(recvResult);
    }
  }

  if (CANMSG_DEBUG)
  {
    Serial.print(F("MCP read result code: "));
    Serial.println(recvResult);
    Serial.print(F("Msg from canId: "));
    Serial.print(canId, HEX);
    Serial.print(F(" Msg length: "));
    Serial.print(len);
    Serial.print(F(" Msg content: "));
    for(int i = 0; i < CAN_PAYLOAD_LENGTH; i++)
    {
      Serial.print(receivedCANBuf[i], HEX);
      if (i == CAN_PAYLOAD_LENGTH - 1)
        Serial.println();
      else
        Serial.print(",");
    }
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
  const uint8_t queryMessageLength = receivedCANBuf[0];
  const uint8_t serviceMode = receivedCANBuf[1];
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
  uint8_t requestedPIDList[PID_LIST_LENGTH];
  const uint8_t requestedPIDCount = queryMessageLength - 1; // Exclude service mode from query length
  for(uint8_t i = 0; i < requestedPIDCount; i++)
    requestedPIDList[i] = receivedCANBuf[i + 2];

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
  byte returnMessageBuf[RETURN_MSGBUILD_BUF_LENGTH];
  uint8_t returnByteCount;

  int pidValMessageResult = buildPIDValueMessage(returnMessageBuf, returnByteCount, requestedPIDList, requestedPIDCount, returnServiceMode);
  if (pidValMessageResult == PID_NOT_AVAILABLE)
  {
    if (CANMSG_ERROR)
      Serial.println(F("ERROR: CAN query PID is not supported."));
    return;
  }

  // Send CAN return message.
  struct Message_t txMsg;
  uint8_t sendResult;
  txMsg.len = returnByteCount;
  txMsg.rx_id = ECU_CAN_ID;
  txMsg.tx_id = ECU_CAN_RESPONSE_ID;
  txMsg.Buffer = returnMessageBuf;
  sendResult = isotp.send(&txMsg);

  if(CANMSG_ERROR)
  {
    if(sendResult != CAN_OK) {
      Serial.print(F("ERROR: CAN message send is failed. Return of sendMsg : "));
      Serial.println(sendResult);
    }
  }

  if(CANMSG_TIME_MEAS)
  {
    Serial.print(F("CAN message handle time (micros): "));
    Serial.println(micros() - canMsgHandleStartTime);
  }
  if (CANMSG_DEBUG)
  {
    Serial.print(F("Return. Value (with padding): "));
    for (int i = 0; i < returnByteCount; i++)
    {
      Serial.print(returnMessageBuf[i], HEX);
      if (i == returnByteCount - 1)
        Serial.println();
      else
        Serial.print(",");
    }

    Serial.print(F("MCP send result code :"));
    Serial.println(sendResult);
  }

  if(CANMSG_FREERAM_MEAS)
    display_freeram();
}
