#include "ECUSim.h"
#include "PIDUpdateSerialControl.h"
#include "CANMesasgeHandle.h"

byte PID_Value_Map[PIDMemSize];
MCP_CAN CAN(10); // CAN CS: pin 10

INT32U tx_can_id = 0x7E0;
INT32U rx_can_id = 0x7E8;

void setup()
{
  Serial.begin(115200);
  initializePIDValueMap();
  initializeCAN();
}

void loop()
{
  if (Serial.available() >= SERIAL_MSG_LENGTH)
    parsePIDUPdateMessage();
  if (CAN.checkReceive() == CAN_MSGAVAIL)
    handleCANMessage();
}

