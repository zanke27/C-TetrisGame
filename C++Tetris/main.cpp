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
	//		// 내려가는 함수
	//		// if break함수
	//	}
	//	// 일정 위로 올라갔는지 체크
	//}
}