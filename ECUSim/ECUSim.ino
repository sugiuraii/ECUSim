#include "ECUSim.h"
#include "PIDUpdateSerialControl.h"
#include "CANMesasgeHandle.h"

byte PID_Value_Map[PIDMemSize];
MCP_CAN CAN(10); // CAN CS: pin 10

void setup()
{
  Serial.begin(115200);
  Serial.println(F("------------------- Arduino setup start ---------------------------"));
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

