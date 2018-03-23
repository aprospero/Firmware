/*This file is part of the Maslow Control Software.

The Maslow Control Software is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Maslow Control Software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the Maslow Control Software.  If not, see <http://www.gnu.org/licenses/>.

Copyright 2014-2017 Bar Smith*/

#ifndef gcode_h
#define gcode_h

// Define line flags. Includes comment type tracking and line overflow detection.
#define LINE_FLAG_COMMENT_PARENTHESES bit(0)
#define LINE_FLAG_COMMENT_SEMICOLON bit(1)

void initGCode();
void initCommandString(size_t maxSize);
void gcodeExecuteLoop();
void readSerialCommands();
int  getInBufferFree();
int  getInBufferUsed();
String gcodeBufferReadline();
int   findEndOfNumber(const String&, const int&);
float extractGcodeValue(const String&, char, const float&);
byte  executeBcodeLine(const String&);
void  executeGcodeLine(const String&);
void  executeMcodeLine(const String&);
void  executeOtherCodeLine(const String&);
int   findNextGM(const String&, const int&);
void  sanitizeCommandString(String&);
byte  interpretCommandString(String&);
void  G1(const String&, int);
void  G2(const String&, int);
void  G10(const String&);
void  G38(const String&);
void  setInchesToMillimetersConversion(float);

#endif
