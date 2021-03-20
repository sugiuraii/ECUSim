#ifndef PIDMAP_DEFINITION_H
#define PIDMAP_DEFINITION_H

#include <avr/pgmspace.h>

// Define byte length of each PIDS
// Set 0 to disable PID
// (Currently, PID with max 4 bytes are supported.)
constexpr unsigned char _PID_BYTE_LENGTH[256] =
    {
        0, // PID:0x00 (refer PIDAvailableFlagMap in PROGMEM)
        4, // PID:0x01
        2, // PID:0x02
        2, // PID:0x03
        1, // PID:0x04
        1, // PID:0x05
        1, // PID:0x06
        1, // PID:0x07
        1, // PID:0x08
        1, // PID:0x09
        1, // PID:0x0A
        1, // PID:0x0B
        2, // PID:0x0C
        1, // PID:0x0D
        1, // PID:0x0E
        1, // PID:0x0F
        2, // PID:0x10
        1, // PID:0x11
        1, // PID:0x12
        1, // PID:0x13
        2, // PID:0x14
        2, // PID:0x15
        2, // PID:0x16
        2, // PID:0x17
        2, // PID:0x18
        2, // PID:0x19
        2, // PID:0x1A
        2, // PID:0x1B
        1, // PID:0x1C
        1, // PID:0x1D
        1, // PID:0x1E
        2, // PID:0x1F
        0, // PID:0x20 (refer PIDAvailableFlagMap in PROGMEM)
        2, // PID:0x21
        2, // PID:0x22
        2, // PID:0x23
        4, // PID:0x24
        4, // PID:0x25
        4, // PID:0x26
        4, // PID:0x27
        4, // PID:0x28
        4, // PID:0x29
        4, // PID:0x2A
        4, // PID:0x2B
        1, // PID:0x2C
        1, // PID:0x2D
        1, // PID:0x2E
        1, // PID:0x2F
        1, // PID:0x30
        2, // PID:0x31
        2, // PID:0x32
        1, // PID:0x33
        4, // PID:0x34
        4, // PID:0x35
        4, // PID:0x36
        4, // PID:0x37
        4, // PID:0x38
        4, // PID:0x39
        4, // PID:0x3A
        4, // PID:0x3B
        2, // PID:0x3C
        2, // PID:0x3D
        2, // PID:0x3E
        2, // PID:0x3F
        0, // PID:0x40 (refer PIDAvailableFlagMap in PROGMEM)
        4, // PID:0x41
        2, // PID:0x42
        2, // PID:0x43
        2, // PID:0x44
        1, // PID:0x45
        1, // PID:0x46
        1, // PID:0x47
        1, // PID:0x48
        1, // PID:0x49
        1, // PID:0x4A
        1, // PID:0x4B
        1, // PID:0x4C
        2, // PID:0x4D
        2, // PID:0x4E
        4, // PID:0x4F
        4, // PID:0x50
        1, // PID:0x51
        1, // PID:0x52
        2, // PID:0x53
        2, // PID:0x54
        2, // PID:0x55
        2, // PID:0x56
        2, // PID:0x57
        2, // PID:0x58
        2, // PID:0x59
        1, // PID:0x5A
        1, // PID:0x5B
        1, // PID:0x5C
        2, // PID:0x5D
        2, // PID:0x5E
        1, // PID:0x5F
        0, // PID:0x60 (refer PIDAvailableFlagMap in PROGMEM)
        1, // PID:0x61
        1, // PID:0x62
        2, // PID:0x63
        0, // PID:0x64
        2, // PID:0x65
        0, // PID:0x66
        3, // PID:0x67
        0, // PID:0x68
        0, // PID:0x69
        0, // PID:0x6A
        0, // PID:0x6B
        0, // PID:0x6C
        0, // PID:0x6D
        0, // PID:0x6E
        3, // PID:0x6F
        0, // PID:0x70
        0, // PID:0x71
        0, // PID:0x72
        0, // PID:0x73
        0, // PID:0x74
        0, // PID:0x75
        0, // PID:0x76
        0, // PID:0x77
        0, // PID:0x78
        0, // PID:0x79
        0, // PID:0x7A
        0, // PID:0x7B
        0, // PID:0x7C
        1, // PID:0x7D
        1, // PID:0x7E
        0, // PID:0x7F
        0, // PID:0x80 (refer PIDAvailableFlagMap in PROGMEM)
        0, // PID:0x81
        0, // PID:0x82
        0, // PID:0x83
        1, // PID:0x84
        0, // PID:0x85
        0, // PID:0x86
        0, // PID:0x87
        0, // PID:0x88
        0, // PID:0x89
        0, // PID:0x8A
        0, // PID:0x8B
        0, // PID:0x8C
        1, // PID:0x8D
        1, // PID:0x8E
        0, // PID:0x8F
        3, // PID:0x90
        0, // PID:0x91
        2, // PID:0x92
        3, // PID:0x93
        0, // PID:0x94
        0, // PID:0x95
        0, // PID:0x96
        0, // PID:0x97
        0, // PID:0x98
        0, // PID:0x99
        0, // PID:0x9A
        4, // PID:0x9B
        0, // PID:0x9C
        4, // PID:0x9D
        2, // PID:0x9E
        0, // PID:0x9F
        0, // PID:0xA0 (refer PIDAvailableFlagMap in PROGMEM)
        0, // PID:0xA1
        2, // PID:0xA2
        0, // PID:0xA3
        4, // PID:0xA4
        4, // PID:0xA5
        4, // PID:0xA6
        4, // PID:0xA7
        4, // PID:0xA8
        4, // PID:0xA9
        4, // PID:0xAA
        4, // PID:0xAB
        4, // PID:0xAC
        4, // PID:0xAD
        4, // PID:0xAE
        4, // PID:0xAF
        4, // PID:0xB0
        4, // PID:0xB1
        4, // PID:0xB2
        4, // PID:0xB3
        4, // PID:0xB4
        4, // PID:0xB5
        4, // PID:0xB6
        4, // PID:0xB7
        4, // PID:0xB8
        4, // PID:0xB9
        4, // PID:0xBA
        4, // PID:0xBB
        4, // PID:0xBC
        4, // PID:0xBD
        4, // PID:0xBE
        4, // PID:0xBF
        0, // PID:0xC0 (refer PIDAvailableFlagMap in PROGMEM)
        4, // PID:0xC1
        4, // PID:0xC2
        0, // PID:0xC3
        0, // PID:0xC4
        0, // PID:0xC5
        0, // PID:0xC6
        0, // PID:0xC7
        0, // PID:0xC8
        0, // PID:0xC9
        0, // PID:0xCA
        0, // PID:0xCB
        0, // PID:0xCC
        0, // PID:0xCD
        0, // PID:0xCE
        0, // PID:0xCF
        0, // PID:0xD0
        0, // PID:0xD1
        0, // PID:0xD2
        0, // PID:0xD3
        0, // PID:0xD4
        0, // PID:0xD5
        0, // PID:0xD6
        0, // PID:0xD7
        0, // PID:0xD8
        0, // PID:0xD9
        0, // PID:0xDA
        0, // PID:0xDB
        0, // PID:0xDC
        0, // PID:0xDD
        0, // PID:0xDE
        0, // PID:0xDF
        0, // PID:0xE0 (refer PIDAvailableFlagMap in PROGMEM)
        0, // PID:0xE1
        0, // PID:0xE2
        0, // PID:0xE3
        0, // PID:0xE4
        0, // PID:0xE5
        0, // PID:0xE6
        0, // PID:0xE7
        0, // PID:0xE8
        0, // PID:0xE9
        0, // PID:0xEA
        0, // PID:0xEB
        0, // PID:0xEC
        0, // PID:0xED
        0, // PID:0xEE
        0, // PID:0xEF
        0, // PID:0xF0
        0, // PID:0xF1
        0, // PID:0xF2
        0, // PID:0xF3
        0, // PID:0xF4
        0, // PID:0xF5
        0, // PID:0xF6
        0, // PID:0xF7
        0, // PID:0xF8
        0, // PID:0xF9
        0, // PID:0xFA
        0, // PID:0xFB
        0, // PID:0xFC
        0, // PID:0xFD
        0, // PID:0xFE
        0  // PID:0xFF
};

/* --- Create available PID flag map --- */
/* --- Do not edit --- */
constexpr unsigned char calcAvailablePIDFlag(int pidOffset);
constexpr unsigned char calcAvailablePIDFlag_internal(int pidOffset, int bitIndex, int lastBitIndex);

constexpr unsigned char calcAvailablePIDFlag(int pidOffset)
{
    return (pidOffset == 0xF9)?calcAvailablePIDFlag_internal(pidOffset, 0, 6):calcAvailablePIDFlag_internal(pidOffset, 0, 7);
}

constexpr unsigned char calcAvailablePIDFlag_internal(int pidOffset, int bitIndex, int lastBitIndex)
{
    return (bitIndex == lastBitIndex) ? (_PID_BYTE_LENGTH[pidOffset + bitIndex] > 0) : (((_PID_BYTE_LENGTH[pidOffset + bitIndex] > 0) << (lastBitIndex - bitIndex)) | calcAvailablePIDFlag_internal(pidOffset, bitIndex + 1, lastBitIndex));
}

PROGMEM const unsigned char PIDAvailableFlagMap[32] = 
{
    calcAvailablePIDFlag(0x01), calcAvailablePIDFlag(0x09), calcAvailablePIDFlag(0x11), (unsigned char)(calcAvailablePIDFlag(0x19) | 0x01),
    calcAvailablePIDFlag(0x21), calcAvailablePIDFlag(0x29), calcAvailablePIDFlag(0x31), (unsigned char)(calcAvailablePIDFlag(0x39) | 0x01),
    calcAvailablePIDFlag(0x41), calcAvailablePIDFlag(0x49), calcAvailablePIDFlag(0x51), (unsigned char)(calcAvailablePIDFlag(0x59) | 0x01),
    calcAvailablePIDFlag(0x61), calcAvailablePIDFlag(0x69), calcAvailablePIDFlag(0x71), (unsigned char)(calcAvailablePIDFlag(0x79) | 0x01),
    calcAvailablePIDFlag(0x81), calcAvailablePIDFlag(0x89), calcAvailablePIDFlag(0x91), (unsigned char)(calcAvailablePIDFlag(0x99) | 0x01),
    calcAvailablePIDFlag(0xA1), calcAvailablePIDFlag(0xA9), calcAvailablePIDFlag(0xB1), (unsigned char)(calcAvailablePIDFlag(0xB9) | 0x01),
    calcAvailablePIDFlag(0xC1), calcAvailablePIDFlag(0xC9), calcAvailablePIDFlag(0xD1), (unsigned char)(calcAvailablePIDFlag(0xD9) | 0x01),
    calcAvailablePIDFlag(0xE1), calcAvailablePIDFlag(0xE9), calcAvailablePIDFlag(0xF1), calcAvailablePIDFlag(0xF9)
};

/* ---- Create PID byte length and memory address (to store pid value) map, and save to PROGMEM ---- */
/* ---- Do not edit --*/
constexpr unsigned int calcPIDMemAddress(int pid);
constexpr unsigned int calcPIDMemAddress_internal(int currentPID, int targetPID);

constexpr unsigned int calcPIDMemAddress(int pid)
{
    return (pid == 0x00) ? 0 : (calcPIDMemAddress_internal(0, pid - 1) + 1);
}

constexpr unsigned int calcPIDMemAddress_internal(int currentPID, int targetPID)
{
    return (currentPID == targetPID) ? _PID_BYTE_LENGTH[currentPID] : (_PID_BYTE_LENGTH[currentPID] + calcPIDMemAddress_internal(currentPID + 1, targetPID));
}

PROGMEM const unsigned char PIDByteLengthMap[256] =
    {
        _PID_BYTE_LENGTH[0x00],
        _PID_BYTE_LENGTH[0x01],
        _PID_BYTE_LENGTH[0x02],
        _PID_BYTE_LENGTH[0x03],
        _PID_BYTE_LENGTH[0x04],
        _PID_BYTE_LENGTH[0x05],
        _PID_BYTE_LENGTH[0x06],
        _PID_BYTE_LENGTH[0x07],
        _PID_BYTE_LENGTH[0x08],
        _PID_BYTE_LENGTH[0x09],
        _PID_BYTE_LENGTH[0x0A],
        _PID_BYTE_LENGTH[0x0B],
        _PID_BYTE_LENGTH[0x0C],
        _PID_BYTE_LENGTH[0x0D],
        _PID_BYTE_LENGTH[0x0E],
        _PID_BYTE_LENGTH[0x0F],
        _PID_BYTE_LENGTH[0x10],
        _PID_BYTE_LENGTH[0x11],
        _PID_BYTE_LENGTH[0x12],
        _PID_BYTE_LENGTH[0x13],
        _PID_BYTE_LENGTH[0x14],
        _PID_BYTE_LENGTH[0x15],
        _PID_BYTE_LENGTH[0x16],
        _PID_BYTE_LENGTH[0x17],
        _PID_BYTE_LENGTH[0x18],
        _PID_BYTE_LENGTH[0x19],
        _PID_BYTE_LENGTH[0x1A],
        _PID_BYTE_LENGTH[0x1B],
        _PID_BYTE_LENGTH[0x1C],
        _PID_BYTE_LENGTH[0x1D],
        _PID_BYTE_LENGTH[0x1E],
        _PID_BYTE_LENGTH[0x1F],
        _PID_BYTE_LENGTH[0x20],
        _PID_BYTE_LENGTH[0x21],
        _PID_BYTE_LENGTH[0x22],
        _PID_BYTE_LENGTH[0x23],
        _PID_BYTE_LENGTH[0x24],
        _PID_BYTE_LENGTH[0x25],
        _PID_BYTE_LENGTH[0x26],
        _PID_BYTE_LENGTH[0x27],
        _PID_BYTE_LENGTH[0x28],
        _PID_BYTE_LENGTH[0x29],
        _PID_BYTE_LENGTH[0x2A],
        _PID_BYTE_LENGTH[0x2B],
        _PID_BYTE_LENGTH[0x2C],
        _PID_BYTE_LENGTH[0x2D],
        _PID_BYTE_LENGTH[0x2E],
        _PID_BYTE_LENGTH[0x2F],
        _PID_BYTE_LENGTH[0x30],
        _PID_BYTE_LENGTH[0x31],
        _PID_BYTE_LENGTH[0x32],
        _PID_BYTE_LENGTH[0x33],
        _PID_BYTE_LENGTH[0x34],
        _PID_BYTE_LENGTH[0x35],
        _PID_BYTE_LENGTH[0x36],
        _PID_BYTE_LENGTH[0x37],
        _PID_BYTE_LENGTH[0x38],
        _PID_BYTE_LENGTH[0x39],
        _PID_BYTE_LENGTH[0x3A],
        _PID_BYTE_LENGTH[0x3B],
        _PID_BYTE_LENGTH[0x3C],
        _PID_BYTE_LENGTH[0x3D],
        _PID_BYTE_LENGTH[0x3E],
        _PID_BYTE_LENGTH[0x3F],
        _PID_BYTE_LENGTH[0x40],
        _PID_BYTE_LENGTH[0x41],
        _PID_BYTE_LENGTH[0x42],
        _PID_BYTE_LENGTH[0x43],
        _PID_BYTE_LENGTH[0x44],
        _PID_BYTE_LENGTH[0x45],
        _PID_BYTE_LENGTH[0x46],
        _PID_BYTE_LENGTH[0x47],
        _PID_BYTE_LENGTH[0x48],
        _PID_BYTE_LENGTH[0x49],
        _PID_BYTE_LENGTH[0x4A],
        _PID_BYTE_LENGTH[0x4B],
        _PID_BYTE_LENGTH[0x4C],
        _PID_BYTE_LENGTH[0x4D],
        _PID_BYTE_LENGTH[0x4E],
        _PID_BYTE_LENGTH[0x4F],
        _PID_BYTE_LENGTH[0x50],
        _PID_BYTE_LENGTH[0x51],
        _PID_BYTE_LENGTH[0x52],
        _PID_BYTE_LENGTH[0x53],
        _PID_BYTE_LENGTH[0x54],
        _PID_BYTE_LENGTH[0x55],
        _PID_BYTE_LENGTH[0x56],
        _PID_BYTE_LENGTH[0x57],
        _PID_BYTE_LENGTH[0x58],
        _PID_BYTE_LENGTH[0x59],
        _PID_BYTE_LENGTH[0x5A],
        _PID_BYTE_LENGTH[0x5B],
        _PID_BYTE_LENGTH[0x5C],
        _PID_BYTE_LENGTH[0x5D],
        _PID_BYTE_LENGTH[0x5E],
        _PID_BYTE_LENGTH[0x5F],
        _PID_BYTE_LENGTH[0x60],
        _PID_BYTE_LENGTH[0x61],
        _PID_BYTE_LENGTH[0x62],
        _PID_BYTE_LENGTH[0x63],
        _PID_BYTE_LENGTH[0x64],
        _PID_BYTE_LENGTH[0x65],
        _PID_BYTE_LENGTH[0x66],
        _PID_BYTE_LENGTH[0x67],
        _PID_BYTE_LENGTH[0x68],
        _PID_BYTE_LENGTH[0x69],
        _PID_BYTE_LENGTH[0x6A],
        _PID_BYTE_LENGTH[0x6B],
        _PID_BYTE_LENGTH[0x6C],
        _PID_BYTE_LENGTH[0x6D],
        _PID_BYTE_LENGTH[0x6E],
        _PID_BYTE_LENGTH[0x6F],
        _PID_BYTE_LENGTH[0x70],
        _PID_BYTE_LENGTH[0x71],
        _PID_BYTE_LENGTH[0x72],
        _PID_BYTE_LENGTH[0x73],
        _PID_BYTE_LENGTH[0x74],
        _PID_BYTE_LENGTH[0x75],
        _PID_BYTE_LENGTH[0x76],
        _PID_BYTE_LENGTH[0x77],
        _PID_BYTE_LENGTH[0x78],
        _PID_BYTE_LENGTH[0x79],
        _PID_BYTE_LENGTH[0x7A],
        _PID_BYTE_LENGTH[0x7B],
        _PID_BYTE_LENGTH[0x7C],
        _PID_BYTE_LENGTH[0x7D],
        _PID_BYTE_LENGTH[0x7E],
        _PID_BYTE_LENGTH[0x7F],
        _PID_BYTE_LENGTH[0x80],
        _PID_BYTE_LENGTH[0x81],
        _PID_BYTE_LENGTH[0x82],
        _PID_BYTE_LENGTH[0x83],
        _PID_BYTE_LENGTH[0x84],
        _PID_BYTE_LENGTH[0x85],
        _PID_BYTE_LENGTH[0x86],
        _PID_BYTE_LENGTH[0x87],
        _PID_BYTE_LENGTH[0x88],
        _PID_BYTE_LENGTH[0x89],
        _PID_BYTE_LENGTH[0x8A],
        _PID_BYTE_LENGTH[0x8B],
        _PID_BYTE_LENGTH[0x8C],
        _PID_BYTE_LENGTH[0x8D],
        _PID_BYTE_LENGTH[0x8E],
        _PID_BYTE_LENGTH[0x8F],
        _PID_BYTE_LENGTH[0x90],
        _PID_BYTE_LENGTH[0x91],
        _PID_BYTE_LENGTH[0x92],
        _PID_BYTE_LENGTH[0x93],
        _PID_BYTE_LENGTH[0x94],
        _PID_BYTE_LENGTH[0x95],
        _PID_BYTE_LENGTH[0x96],
        _PID_BYTE_LENGTH[0x97],
        _PID_BYTE_LENGTH[0x98],
        _PID_BYTE_LENGTH[0x99],
        _PID_BYTE_LENGTH[0x9A],
        _PID_BYTE_LENGTH[0x9B],
        _PID_BYTE_LENGTH[0x9C],
        _PID_BYTE_LENGTH[0x9D],
        _PID_BYTE_LENGTH[0x9E],
        _PID_BYTE_LENGTH[0x9F],
        _PID_BYTE_LENGTH[0xA0],
        _PID_BYTE_LENGTH[0xA1],
        _PID_BYTE_LENGTH[0xA2],
        _PID_BYTE_LENGTH[0xA3],
        _PID_BYTE_LENGTH[0xA4],
        _PID_BYTE_LENGTH[0xA5],
        _PID_BYTE_LENGTH[0xA6],
        _PID_BYTE_LENGTH[0xA7],
        _PID_BYTE_LENGTH[0xA8],
        _PID_BYTE_LENGTH[0xA9],
        _PID_BYTE_LENGTH[0xAA],
        _PID_BYTE_LENGTH[0xAB],
        _PID_BYTE_LENGTH[0xAC],
        _PID_BYTE_LENGTH[0xAD],
        _PID_BYTE_LENGTH[0xAE],
        _PID_BYTE_LENGTH[0xAF],
        _PID_BYTE_LENGTH[0xB0],
        _PID_BYTE_LENGTH[0xB1],
        _PID_BYTE_LENGTH[0xB2],
        _PID_BYTE_LENGTH[0xB3],
        _PID_BYTE_LENGTH[0xB4],
        _PID_BYTE_LENGTH[0xB5],
        _PID_BYTE_LENGTH[0xB6],
        _PID_BYTE_LENGTH[0xB7],
        _PID_BYTE_LENGTH[0xB8],
        _PID_BYTE_LENGTH[0xB9],
        _PID_BYTE_LENGTH[0xBA],
        _PID_BYTE_LENGTH[0xBB],
        _PID_BYTE_LENGTH[0xBC],
        _PID_BYTE_LENGTH[0xBD],
        _PID_BYTE_LENGTH[0xBE],
        _PID_BYTE_LENGTH[0xBF],
        _PID_BYTE_LENGTH[0xC0],
        _PID_BYTE_LENGTH[0xC1],
        _PID_BYTE_LENGTH[0xC2],
        _PID_BYTE_LENGTH[0xC3],
        _PID_BYTE_LENGTH[0xC4],
        _PID_BYTE_LENGTH[0xC5],
        _PID_BYTE_LENGTH[0xC6],
        _PID_BYTE_LENGTH[0xC7],
        _PID_BYTE_LENGTH[0xC8],
        _PID_BYTE_LENGTH[0xC9],
        _PID_BYTE_LENGTH[0xCA],
        _PID_BYTE_LENGTH[0xCB],
        _PID_BYTE_LENGTH[0xCC],
        _PID_BYTE_LENGTH[0xCD],
        _PID_BYTE_LENGTH[0xCE],
        _PID_BYTE_LENGTH[0xCF],
        _PID_BYTE_LENGTH[0xD0],
        _PID_BYTE_LENGTH[0xD1],
        _PID_BYTE_LENGTH[0xD2],
        _PID_BYTE_LENGTH[0xD3],
        _PID_BYTE_LENGTH[0xD4],
        _PID_BYTE_LENGTH[0xD5],
        _PID_BYTE_LENGTH[0xD6],
        _PID_BYTE_LENGTH[0xD7],
        _PID_BYTE_LENGTH[0xD8],
        _PID_BYTE_LENGTH[0xD9],
        _PID_BYTE_LENGTH[0xDA],
        _PID_BYTE_LENGTH[0xDB],
        _PID_BYTE_LENGTH[0xDC],
        _PID_BYTE_LENGTH[0xDD],
        _PID_BYTE_LENGTH[0xDE],
        _PID_BYTE_LENGTH[0xDF],
        _PID_BYTE_LENGTH[0xE0],
        _PID_BYTE_LENGTH[0xE1],
        _PID_BYTE_LENGTH[0xE2],
        _PID_BYTE_LENGTH[0xE3],
        _PID_BYTE_LENGTH[0xE4],
        _PID_BYTE_LENGTH[0xE5],
        _PID_BYTE_LENGTH[0xE6],
        _PID_BYTE_LENGTH[0xE7],
        _PID_BYTE_LENGTH[0xE8],
        _PID_BYTE_LENGTH[0xE9],
        _PID_BYTE_LENGTH[0xEA],
        _PID_BYTE_LENGTH[0xEB],
        _PID_BYTE_LENGTH[0xEC],
        _PID_BYTE_LENGTH[0xED],
        _PID_BYTE_LENGTH[0xEE],
        _PID_BYTE_LENGTH[0xEF],
        _PID_BYTE_LENGTH[0xF0],
        _PID_BYTE_LENGTH[0xF1],
        _PID_BYTE_LENGTH[0xF2],
        _PID_BYTE_LENGTH[0xF3],
        _PID_BYTE_LENGTH[0xF4],
        _PID_BYTE_LENGTH[0xF5],
        _PID_BYTE_LENGTH[0xF6],
        _PID_BYTE_LENGTH[0xF7],
        _PID_BYTE_LENGTH[0xF8],
        _PID_BYTE_LENGTH[0xF9],
        _PID_BYTE_LENGTH[0xFA],
        _PID_BYTE_LENGTH[0xFB],
        _PID_BYTE_LENGTH[0xFC],
        _PID_BYTE_LENGTH[0xFD],
        _PID_BYTE_LENGTH[0xFE],
        _PID_BYTE_LENGTH[0xFF]};

PROGMEM const unsigned int PIDAddressMap[256] =
    {
        calcPIDMemAddress(0x00),
        calcPIDMemAddress(0x01),
        calcPIDMemAddress(0x02),
        calcPIDMemAddress(0x03),
        calcPIDMemAddress(0x04),
        calcPIDMemAddress(0x05),
        calcPIDMemAddress(0x06),
        calcPIDMemAddress(0x07),
        calcPIDMemAddress(0x08),
        calcPIDMemAddress(0x09),
        calcPIDMemAddress(0x0A),
        calcPIDMemAddress(0x0B),
        calcPIDMemAddress(0x0C),
        calcPIDMemAddress(0x0D),
        calcPIDMemAddress(0x0E),
        calcPIDMemAddress(0x0F),
        calcPIDMemAddress(0x10),
        calcPIDMemAddress(0x11),
        calcPIDMemAddress(0x12),
        calcPIDMemAddress(0x13),
        calcPIDMemAddress(0x14),
        calcPIDMemAddress(0x15),
        calcPIDMemAddress(0x16),
        calcPIDMemAddress(0x17),
        calcPIDMemAddress(0x18),
        calcPIDMemAddress(0x19),
        calcPIDMemAddress(0x1A),
        calcPIDMemAddress(0x1B),
        calcPIDMemAddress(0x1C),
        calcPIDMemAddress(0x1D),
        calcPIDMemAddress(0x1E),
        calcPIDMemAddress(0x1F),
        calcPIDMemAddress(0x20),
        calcPIDMemAddress(0x21),
        calcPIDMemAddress(0x22),
        calcPIDMemAddress(0x23),
        calcPIDMemAddress(0x24),
        calcPIDMemAddress(0x25),
        calcPIDMemAddress(0x26),
        calcPIDMemAddress(0x27),
        calcPIDMemAddress(0x28),
        calcPIDMemAddress(0x29),
        calcPIDMemAddress(0x2A),
        calcPIDMemAddress(0x2B),
        calcPIDMemAddress(0x2C),
        calcPIDMemAddress(0x2D),
        calcPIDMemAddress(0x2E),
        calcPIDMemAddress(0x2F),
        calcPIDMemAddress(0x30),
        calcPIDMemAddress(0x31),
        calcPIDMemAddress(0x32),
        calcPIDMemAddress(0x33),
        calcPIDMemAddress(0x34),
        calcPIDMemAddress(0x35),
        calcPIDMemAddress(0x36),
        calcPIDMemAddress(0x37),
        calcPIDMemAddress(0x38),
        calcPIDMemAddress(0x39),
        calcPIDMemAddress(0x3A),
        calcPIDMemAddress(0x3B),
        calcPIDMemAddress(0x3C),
        calcPIDMemAddress(0x3D),
        calcPIDMemAddress(0x3E),
        calcPIDMemAddress(0x3F),
        calcPIDMemAddress(0x40),
        calcPIDMemAddress(0x41),
        calcPIDMemAddress(0x42),
        calcPIDMemAddress(0x43),
        calcPIDMemAddress(0x44),
        calcPIDMemAddress(0x45),
        calcPIDMemAddress(0x46),
        calcPIDMemAddress(0x47),
        calcPIDMemAddress(0x48),
        calcPIDMemAddress(0x49),
        calcPIDMemAddress(0x4A),
        calcPIDMemAddress(0x4B),
        calcPIDMemAddress(0x4C),
        calcPIDMemAddress(0x4D),
        calcPIDMemAddress(0x4E),
        calcPIDMemAddress(0x4F),
        calcPIDMemAddress(0x50),
        calcPIDMemAddress(0x51),
        calcPIDMemAddress(0x52),
        calcPIDMemAddress(0x53),
        calcPIDMemAddress(0x54),
        calcPIDMemAddress(0x55),
        calcPIDMemAddress(0x56),
        calcPIDMemAddress(0x57),
        calcPIDMemAddress(0x58),
        calcPIDMemAddress(0x59),
        calcPIDMemAddress(0x5A),
        calcPIDMemAddress(0x5B),
        calcPIDMemAddress(0x5C),
        calcPIDMemAddress(0x5D),
        calcPIDMemAddress(0x5E),
        calcPIDMemAddress(0x5F),
        calcPIDMemAddress(0x60),
        calcPIDMemAddress(0x61),
        calcPIDMemAddress(0x62),
        calcPIDMemAddress(0x63),
        calcPIDMemAddress(0x64),
        calcPIDMemAddress(0x65),
        calcPIDMemAddress(0x66),
        calcPIDMemAddress(0x67),
        calcPIDMemAddress(0x68),
        calcPIDMemAddress(0x69),
        calcPIDMemAddress(0x6A),
        calcPIDMemAddress(0x6B),
        calcPIDMemAddress(0x6C),
        calcPIDMemAddress(0x6D),
        calcPIDMemAddress(0x6E),
        calcPIDMemAddress(0x6F),
        calcPIDMemAddress(0x70),
        calcPIDMemAddress(0x71),
        calcPIDMemAddress(0x72),
        calcPIDMemAddress(0x73),
        calcPIDMemAddress(0x74),
        calcPIDMemAddress(0x75),
        calcPIDMemAddress(0x76),
        calcPIDMemAddress(0x77),
        calcPIDMemAddress(0x78),
        calcPIDMemAddress(0x79),
        calcPIDMemAddress(0x7A),
        calcPIDMemAddress(0x7B),
        calcPIDMemAddress(0x7C),
        calcPIDMemAddress(0x7D),
        calcPIDMemAddress(0x7E),
        calcPIDMemAddress(0x7F),
        calcPIDMemAddress(0x80),
        calcPIDMemAddress(0x81),
        calcPIDMemAddress(0x82),
        calcPIDMemAddress(0x83),
        calcPIDMemAddress(0x84),
        calcPIDMemAddress(0x85),
        calcPIDMemAddress(0x86),
        calcPIDMemAddress(0x87),
        calcPIDMemAddress(0x88),
        calcPIDMemAddress(0x89),
        calcPIDMemAddress(0x8A),
        calcPIDMemAddress(0x8B),
        calcPIDMemAddress(0x8C),
        calcPIDMemAddress(0x8D),
        calcPIDMemAddress(0x8E),
        calcPIDMemAddress(0x8F),
        calcPIDMemAddress(0x90),
        calcPIDMemAddress(0x91),
        calcPIDMemAddress(0x92),
        calcPIDMemAddress(0x93),
        calcPIDMemAddress(0x94),
        calcPIDMemAddress(0x95),
        calcPIDMemAddress(0x96),
        calcPIDMemAddress(0x97),
        calcPIDMemAddress(0x98),
        calcPIDMemAddress(0x99),
        calcPIDMemAddress(0x9A),
        calcPIDMemAddress(0x9B),
        calcPIDMemAddress(0x9C),
        calcPIDMemAddress(0x9D),
        calcPIDMemAddress(0x9E),
        calcPIDMemAddress(0x9F),
        calcPIDMemAddress(0xA0),
        calcPIDMemAddress(0xA1),
        calcPIDMemAddress(0xA2),
        calcPIDMemAddress(0xA3),
        calcPIDMemAddress(0xA4),
        calcPIDMemAddress(0xA5),
        calcPIDMemAddress(0xA6),
        calcPIDMemAddress(0xA7),
        calcPIDMemAddress(0xA8),
        calcPIDMemAddress(0xA9),
        calcPIDMemAddress(0xAA),
        calcPIDMemAddress(0xAB),
        calcPIDMemAddress(0xAC),
        calcPIDMemAddress(0xAD),
        calcPIDMemAddress(0xAE),
        calcPIDMemAddress(0xAF),
        calcPIDMemAddress(0xB0),
        calcPIDMemAddress(0xB1),
        calcPIDMemAddress(0xB2),
        calcPIDMemAddress(0xB3),
        calcPIDMemAddress(0xB4),
        calcPIDMemAddress(0xB5),
        calcPIDMemAddress(0xB6),
        calcPIDMemAddress(0xB7),
        calcPIDMemAddress(0xB8),
        calcPIDMemAddress(0xB9),
        calcPIDMemAddress(0xBA),
        calcPIDMemAddress(0xBB),
        calcPIDMemAddress(0xBC),
        calcPIDMemAddress(0xBD),
        calcPIDMemAddress(0xBE),
        calcPIDMemAddress(0xBF),
        calcPIDMemAddress(0xC0),
        calcPIDMemAddress(0xC1),
        calcPIDMemAddress(0xC2),
        calcPIDMemAddress(0xC3),
        calcPIDMemAddress(0xC4),
        calcPIDMemAddress(0xC5),
        calcPIDMemAddress(0xC6),
        calcPIDMemAddress(0xC7),
        calcPIDMemAddress(0xC8),
        calcPIDMemAddress(0xC9),
        calcPIDMemAddress(0xCA),
        calcPIDMemAddress(0xCB),
        calcPIDMemAddress(0xCC),
        calcPIDMemAddress(0xCD),
        calcPIDMemAddress(0xCE),
        calcPIDMemAddress(0xCF),
        calcPIDMemAddress(0xD0),
        calcPIDMemAddress(0xD1),
        calcPIDMemAddress(0xD2),
        calcPIDMemAddress(0xD3),
        calcPIDMemAddress(0xD4),
        calcPIDMemAddress(0xD5),
        calcPIDMemAddress(0xD6),
        calcPIDMemAddress(0xD7),
        calcPIDMemAddress(0xD8),
        calcPIDMemAddress(0xD9),
        calcPIDMemAddress(0xDA),
        calcPIDMemAddress(0xDB),
        calcPIDMemAddress(0xDC),
        calcPIDMemAddress(0xDD),
        calcPIDMemAddress(0xDE),
        calcPIDMemAddress(0xDF),
        calcPIDMemAddress(0xE0),
        calcPIDMemAddress(0xE1),
        calcPIDMemAddress(0xE2),
        calcPIDMemAddress(0xE3),
        calcPIDMemAddress(0xE4),
        calcPIDMemAddress(0xE5),
        calcPIDMemAddress(0xE6),
        calcPIDMemAddress(0xE7),
        calcPIDMemAddress(0xE8),
        calcPIDMemAddress(0xE9),
        calcPIDMemAddress(0xEA),
        calcPIDMemAddress(0xEB),
        calcPIDMemAddress(0xEC),
        calcPIDMemAddress(0xED),
        calcPIDMemAddress(0xEE),
        calcPIDMemAddress(0xEF),
        calcPIDMemAddress(0xF0),
        calcPIDMemAddress(0xF1),
        calcPIDMemAddress(0xF2),
        calcPIDMemAddress(0xF3),
        calcPIDMemAddress(0xF4),
        calcPIDMemAddress(0xF5),
        calcPIDMemAddress(0xF6),
        calcPIDMemAddress(0xF7),
        calcPIDMemAddress(0xF8),
        calcPIDMemAddress(0xF9),
        calcPIDMemAddress(0xFA),
        calcPIDMemAddress(0xFB),
        calcPIDMemAddress(0xFC),
        calcPIDMemAddress(0xFD),
        calcPIDMemAddress(0xFE),
        calcPIDMemAddress(0xFF)};

constexpr unsigned int PIDMemSize = calcPIDMemAddress(0xFF) + _PID_BYTE_LENGTH[0xFF];

#endif