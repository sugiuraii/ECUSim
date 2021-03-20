#include "ECUSim.h"
#include "PIDUpdateSerialControl.h"
#include "CANMesasgeHandle.h"

byte PID_Value_Map[PIDMemSize];
mcp2515_can CAN(10); // CAN CS: pin 10

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

