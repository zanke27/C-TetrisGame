#include "console.h";
#include "Tetris.h";
using namespace std;

Block block;
char mainMap[HEIGHT][WEIGHT];
int arr[7] = { 0, };
int arrCount = 6;
int random = 0;
int randomNum;
int main(void)
{
	//fullscreen();
	SetMap(mainMap);
	for (int i = 0; i < 7; i++)
		arr[i] = (i + 1);
	while (true)
	{
		srand((unsigned int)time(NULL));

		if (arrCount == 0)
		{
			randomNum = arr[0];
			arrCount = 6;
			for (int i = 0; i < 7; i++)
				arr[i] = (i + 1);
		}
		else
		{
			random = rand() % arrCount;
			randomNum = arr[random];

			int temp = arr[random];
			arr[random] = arr[arrCount];
			arr[arrCount] = temp;

			arrCount--;
		}

		SpawnBlock(mainMap, &block, randomNum + 1);
		while (true)
		{
			gotoxy(0, 0);
			if (ReachBlock(mainMap, &block) == true)
			{
				bindBlock(mainMap, &block);
				break;
			}
			DownBlock(mainMap, &block);
			DrawMapAndBlock(mainMap);

			if (GetAsyncKeyState(VK_LEFT))
				MoveLeftBlock(mainMap, &block);
			if (GetAsyncKeyState(VK_RIGHT))
				MoveRightBlock(mainMap, &block);

			if (GetAsyncKeyState(0x52) & 0x8001) // 0x52 = R
				TurnBlock(mainMap, &block);

			for (int i = 1; i < HEIGHT ; i++)
			{
				for (int j = 0; j < WEIGHT; j++)
				{
					cout << mainMap[i][j];
				}
				cout << endl;
			}

			Sleep(100);
			//system("cls");
		}
		if (CheckBlock(mainMap) == true)
			break;
	}
	system("cls");
	cout << "Game End" << endl;

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