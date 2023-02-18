#pragma once

int  buildPIDValueMessage(byte* const returnBuf, uint8_t& returnByteCount, const uint8_t* requestedPIDList, const uint8_t requestedPIDCount, const uint8_t returnServiceMode);
void fillValueBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill);
void fillAvailablePIDBytes(byte* const returnBuf, const uint8_t requestedPID, const uint8_t byteOffsetToFill, uint8_t& byteOffsetAfterFill);

