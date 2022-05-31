#include "console.h"

void gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

// 배경은 글자 색의 16배 (예: 2(글자) -> 32(배경))
// 0: 검은색, 1: 파란색, 2: 녹색, 3: 청록색, 4: 빨간색, 5: 자주색, 6: 노란색, 7: 흰색 8: 회색, 9: 연한파란색,
// A: 연한 녹색, B: 연한 청록색, C: 연한 빨간색, D: 연한 자주색, E: 연한 노란색, F: 밝은 흰색(기본)
void setcolor(int color, int bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}