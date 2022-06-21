#include "console.h";
#include "Tetris.h";
using namespace std;

Block block;
char mainMap[HEIGHT][WEIGHT];// 메인 맵
int arr[7] = { 0, };		 // 랜덤 수가 들어갈 배열
int arrCount = 6;			 // 랜덤 수 구하기 위한 카운트
int random = 0;				 // 랜덤 수 구하기 위한 값
int randomNum;				 // 랜덤 수
int clearLine = 0;			 // 클리어한 라인 수 이거 기반으로 스킬 쓸 수 있음
clock_t checkTime = 0;		 // 블럭 내리기 위해 쓰는 변수
int score = 0;				 // 스코어 

// bgm
MCI_OPEN_PARMS Openbgm;
MCI_PLAY_PARMS Playbgm;

// effect
MCI_OPEN_PARMS Openeffect;
MCI_PLAY_PARMS Playeffect;

UINT dwID;
UINT dwID2;
void Playingbgm()
{
	Openbgm.lpstrElementName = L"AudioSource/hipjazz.mp3";
	Openbgm.lpstrDeviceType = L"Mpegvideo"; // Wav = waveaudio	
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&Openbgm);
	dwID = Openbgm.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&Playbgm);
}

void Playingeffect()
{
	mciSendCommand(dwID2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&Openeffect);
	Openeffect.lpstrElementName = TEXT("AudioSouorce/pickupCoin.wav");
	Openeffect.lpstrDeviceType = TEXT("waveaudio");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&Openeffect);
	dwID2 = Openeffect.wDeviceID;
	mciSendCommand(dwID2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&Playeffect);
}

void Game()
{
	arrCount = 6;		
	random = 0;			
	randomNum;			
	clearLine = 25;		
	checkTime = 0;		
	score = 0;

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
			Sleep(100);
			if (GetAsyncKeyState(0x58) & 0x8000) // X 우회전
			{
				Sleep(10);
				gotoxy(0, 0);
				TurnBlock(mainMap, &block, false);
			}

			if (GetAsyncKeyState(0x5A) & 0x8000) // Z 좌회전
			{
				Sleep(10);
				gotoxy(0, 0);
				TurnBlock(mainMap, &block, true);
			}

			if (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
			{
				int tem = 0;
				tem = clearLine / 5;
				clearLine = clearLine / 5;
				if (tem >= 1)
				{
					for (int i = 0; i < tem; i++)
					{
						ClearBlock(mainMap, 23);
						score += 1000;
						system("cls");
					}
					Playingeffect();
				}
			}

			if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			{
				while (ReachBlock(mainMap, &block) == false)
				{
					DownBlock(mainMap, &block);
				}
				BindBlock(mainMap, &block);
				DrawMapAndBlock(mainMap);
				Sleep(10);
				break;
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				MoveLeftBlock(mainMap, &block);
				gotoxy(0, 0);
				DrawMapAndBlock(mainMap);
				Sleep(10);
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				MoveRightBlock(mainMap, &block);
				gotoxy(0, 0);
				DrawMapAndBlock(mainMap);
				Sleep(10);
			}

			if (checkTime == 0)
			{
				checkTime = DelayStart();
			}
			if (Delay(checkTime, 500))
			{
				checkTime = 0;

				if (ReachBlock(mainMap, &block) == true)
				{
					BindBlock(mainMap, &block);
					gotoxy(0, 0);
					DrawMapAndBlock(mainMap);
					break;
				}

				DownBlock(mainMap, &block);
				gotoxy(0, 0);
				DrawMapAndBlock(mainMap);

				cout << endl;
				cout << "지운 라인 수: " << clearLine << endl;
				cout << "좌우 이동 화살표 <- / ->" << endl;
				cout << "좌우 회전 Z / X" << endl;
				cout << "바로 내리기 Space" << endl;
				cout << "아이템1 Ctrl (지운 라인 수 나누기 5만큼 라인을 지움)" << endl;
			}
		}
		if (CheckBlock(mainMap) == true)
			break;

		int tempLine = ClearBlockLine(mainMap);
		if (tempLine != 0)
		{
			while (true)
			{
				int tempLine = ClearBlockLine(mainMap);
				if (tempLine != 0)
				{
					ClearBlock(mainMap, tempLine);
					clearLine++;
					score += 1000;
				}
				else
					break;
			}
			Playingeffect();
		}
		else
		{

		}
		Sleep(250);
	}
	system("cls");
}

void GameEnd()
{
	char is = _setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L" _______  _______  __   __  _______  _______  __    _  ______  " << endl;
	wcout << L"|       ||   _   ||  |_|  ||       ||       ||  |  | ||      | " << endl;
	wcout << L"|    ___||  |_|  ||       ||    ___||    ___||   |_| ||  _    |" << endl;
	wcout << L"|   | __ |       ||       ||   |___ |   |___ |       || | |   |" << endl;
	wcout << L"|   ||  ||       ||       ||    ___||    ___||  _    || |_|   |" << endl;
	wcout << L"|   |_| ||   _   || ||_|| ||   |___ |   |___ | | |   ||       |" << endl;
	wcout << L"|_______||__| |__||_|   |_||_______||_______||_|  |__||______| " << endl;
	char isa = _setmode(_fileno(stdout), _O_TEXT);

	cout << endl;
	cout << "점수 : " << score << endl << endl << endl;
	cout << "다시하기 -> R" << endl << "끝내기 -> ESC" << endl;
}

int main(void)
{
	CursorView();
	fullscreen();
	Playingbgm();

	char is = _setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L" ______  __                            ________         __                     " << endl;
	wcout << L"/      |/  |                          /        |       /  |                    " << endl;
	wcout << L"$$$$$$/_$$ |_     ______   _____  ____$$$$$$$$/______  $$/   ______    _______ " << endl;
	wcout << L"  $$ |/ $$   |   /      \\ /     \\/    \\  $$ | /      \\ /  | /      \\  /       |" << endl;
	wcout << L"  $$ |$$$$$$/   /$$$$$$  |$$$$$$ $$$$  | $$ |/$$$$$$  |$$ |/$$$$$$  |/$$$$$$$/ " << endl;
	wcout << L"  $$ |  $$ | __ $$    $$ |$$ | $$ | $$ | $$ |$$ |  $$/ $$ |$$    $$ |$$      \\ " << endl;
	wcout << L" _$$ |_ $$ |/  |$$$$$$$$/ $$ | $$ | $$ | $$ |$$ |      $$ |$$$$$$$$/  $$$$$$  |" << endl;
	wcout << L"/ $$   |$$  $$/ $$       |$$ | $$ | $$ | $$ |$$ |      $$ |$$       |/     $$/ " << endl;
	wcout << L"$$$$$$/  $$$$/   $$$$$$$/ $$/  $$/  $$/  $$/ $$/       $$/  $$$$$$$/ $$$$$$$/  " << endl;
	char isa = _setmode(_fileno(stdout), _O_TEXT);

	cout << endl << endl;
	cout << "게임을 시작하려면 R키를 누르세요!" << endl << endl;
	cout << "게임을 종료하려면 Esc키를 누르세요!" << endl << endl;
                                                                               
	while (true)
	{
		_getch();

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			cout << "게임을 종료합니다.";
			exit(0);
		}

		if (GetAsyncKeyState(0x52) & 0x8000)
		{
			system("cls");
			Game();
			GameEnd();
		}
	}

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