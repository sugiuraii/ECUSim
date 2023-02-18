#include "ECUSim.h"
#include "PIDUpdateSerialControl.h"
#include "CANMesasgeHandle.h"

byte PID_Value_Map[PIDMemSize];
MCP_CAN CAN(10); // CAN CS: pin 10
IsoTp isotp(&CAN, 0);
struct Message_t txMsg, rxMsg;

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

