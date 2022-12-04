#ifndef ECUSIM_H
#define ECUSIM_H

#include "mcp2515_can.h"
#include <SPI.h>
#include <avr/pgmspace.h>
#include "PIDMap_Definition.h"

// ECU (this controller) CAN ID
constexpr unsigned long ECU_CAN_ID = 0x7E0;
constexpr unsigned long ECU_CAN_RESPONSE_ID = ECU_CAN_ID + 0x008;

// ECU response(reply wait in ms)
constexpr int ECU_WAIT = 0; 

// Debug message serial out switch
constexpr bool PIDSET_DEBUG = false;
constexpr bool PIDSET_ERROR = true;
constexpr bool CANMSG_DEBUG = false;
constexpr bool CANMSG_TIME_MEAS = false;
constexpr bool CANMSG_ERROR = true;
constexpr bool CANMSG_FATAL = true;

extern byte PID_Value_Map[];
extern mcp2515_can CAN;

constexpr int SERIAL_MSG_LENGTH = 11;
constexpr int CAN_PAYLOAD_LENGTH = 8;


#endif