# ECUSim
 * This is a ecu simulator for OBDII scantool like ELM327.
 * This sketch can respond OBDII CAN message with using MCP2515 CAN controller board.

# Demonstration
![Demo](https://user-images.githubusercontent.com/25734871/113512905-e5a4fb00-95a1-11eb-9434-9f92c7a85266.gif)

# Dependency
* As for MCP2515 controll library, this depends on [coryjfowler/MCP_CAN_lib](https://github.com/coryjfowler/MCP_CAN_lib).
* ISO-TP library [altelch/iso-tp](https://github.com/altelch/iso-tp) is also used. 

# Hardwares need to run the sketch
 * Arduino Uno or its compatilble boards.
 * MCP2515 CAN controller board.
 * Connection Arduino <-> MCP2515 board
     - This sketch does not use interrupt. No need to connect INT and D2 pin.

![Wiring](Wiring.svg)
    
# Install
 * Before the install, please modify the argument of `CAN.begin(CAN_250KBPS, MCP_8MHZ)` in `CANMessageHandle.ino`, follwoing CAN speed and the frequency of XTAL of MCP2515 board.
 * And please install[coryjfowler/MCP_CAN_lib](https://github.com/coryjfowler/MCP_CAN_lib) MCP2515 library and [altelch/iso-tp](https://github.com/altelch/iso-tp) ISO-TP library.
    * Get zip file of repository and install on Arduino IDE. 
 * After setting the parameter above, compile `ECUSim.ino` and flash to arduino board.

# GUI fronend
- GUI frontend is available on [sugiuraii/ECUSimGUI](https://github.com/sugiuraii/ECUSimGUI).
- You can control PID sensor value by GUI fronted, by using the program above.

# Features
 * [x] Sends value back on PID request of service 0x01
 * [x] Control PID sensor values by serial port (using PC GUI program)
 * [X] Responds ECU ID
 * [X] Responds 6PIDS request by single message (J1939)

# Control PID sensor values via serial port
After the CAN initialization (Serial message by "CAN BUS Shield init ok!"), the arduino board wait PID sensor value update message on seial port.
The update serial scommand consists with 10 character and LF(\n).
 * The first 2 characters select (hexadecimal) PID.
 * The following 8 characters set the sensor value of PID.
    * Plesase fill 8 character regardless of the number of value bytes. See the example below.
## Example
- Set PID 0x04(= Calculated engine load) to 60.0% (153 in decimal, 0x99 in hexadecimal)
    - -> Send "0499000000\n" via serial port (latter 3 bytes are ignored.)
- Set PID 0x0C(= Engine speed rpm) to 5745rpm (22980 in decimal, 0x59C4 in hexadecimal)
    - -> Send "0C59C40000\n" via serial port (latter 2 bytes are ignored.)
- Note that PIDs of "Supported PID" (such as 0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0 and 0xE0) are automatically calculated on compling the sketch. You don't have to set by serial port command. 

# Enable/disable debug message
You can enable/disable error or debug message on `ECUSim.h`.
```
constexpr bool PIDSET_DEBUG = false;
constexpr bool PIDSET_ERROR = true;
constexpr bool CANMSG_DEBUG = false;
constexpr bool CANMSG_ERROR = true;
constexpr bool CANMSG_FATAL = true;
```

# Supported PID's
See `PIDMap_Definition.h`
## Enable/disable PID
Edit `constexpr unsigned char _PID_BYTE_LENGTH[256]` in `PIDMap_Definition.h`. This array stores the data byte length of each PIDs. By setting byte length to zero, you can disable PID.
```
constexpr unsigned char _PID_BYTE_LENGTH[256] =
    {
        0, // PID:0x00 (refer PIDAvailableFlagMap in PROGMEM)
        4, // PID:0x01
        2, // PID:0x02
        2, // PID:0x03 // <- Set PID data byte length to enable PID, set zero to disable PID.
        1, // PID:0x04
        1, // PID:0x05
        1, // PID:0x06
```
# Sources
* [odbII PID's (wikipedia)](https://en.wikipedia.org/wiki/OBD-II_PIDs)

# License
MIT License
