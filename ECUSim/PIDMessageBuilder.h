#pragma once

constexpr int NOERROR = 0;
constexpr int PID_NOT_AVAILABLE = -1;

int  buildPIDValueMessage(byte* const returnBuf, uint8_t& returnByteCount, const uint8_t* requestedPIDList, const uint8_t requestedPIDCount, const uint8_t returnServiceMode);

