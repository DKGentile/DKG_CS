#include "coordinates.h"

void Coordinates::ReadScreenShot()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	COORD dwBufferCoord = { 0, 0 };
	SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

	ReadConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);


}

void Coordinates::RefreshArea(int x1, int y1, int x2, int y2)
{
	SMALL_RECT rcRegion = { x1,y1,x2,y2 };
	COORD dwBufferSize = { x2 - x1,y2 - y1 };
	COORD dwBufferCoord = { x1,y1 };

	//buffer[5][10].Char.AsciiChar = 'H';
	//buffer[5][10].Attributes = 0x0E;
	//buffer[5][11].Char.AsciiChar = 'i';
	//buffer[5][11].Attributes = 0x0B;
	//buffer[5][12].Char.AsciiChar = '!';
	//buffer[5][12].Attributes = 0x0A;

	WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}