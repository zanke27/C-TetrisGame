#include "console.h";
#include "Tetris.h";
using namespace std;

char mainMap[HEIGHT][WEIGHT];
int main(void)
{
	SetMap(mainMap);
	DrawMapAndObject(mainMap);

	//while (true)
	//{
	//	DrawMapAndObject(mainMap);
	//	while (true)
	//	{
	//		DrawMapAndObject(mainMap);
	//		Sleep(500);
	//		// �������� �Լ�
	//		// if break�Լ�
	//	}
	//	// ���� ���� �ö󰬴��� üũ
	//}
}