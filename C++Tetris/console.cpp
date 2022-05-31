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

// ����� ���� ���� 16�� (��: 2(����) -> 32(���))
// 0: ������, 1: �Ķ���, 2: ���, 3: û�ϻ�, 4: ������, 5: ���ֻ�, 6: �����, 7: ��� 8: ȸ��, 9: �����Ķ���,
// A: ���� ���, B: ���� û�ϻ�, C: ���� ������, D: ���� ���ֻ�, E: ���� �����, F: ���� ���(�⺻)
void setcolor(int color, int bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}