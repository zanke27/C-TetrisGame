#include "console.h"
#include "Tetris.h"

// 0: 검은 배경, 1: 벽, 2: ㅡ 블럭, 3: ㄱ 블럭, 4: 역 ㄱ 블럭, 5: ㄱㄴ 블럭, 6: 역 ㄱㄴ 블럭, 7: ㅜ 블럭, 8: ㅁ 블럭 
void SetMap(char Map[HEIGHT][WEIGHT])
{
	strcpy_s(Map[0],  "100000000001");
	strcpy_s(Map[1],  "100000000001");
	strcpy_s(Map[2],  "1LLLLLLLLLL1");
	strcpy_s(Map[3],  "100000000001");
	strcpy_s(Map[4],  "100000000001");
	strcpy_s(Map[5],  "100000000001");
	strcpy_s(Map[6],  "100000000001");
	strcpy_s(Map[7],  "100000000001");
	strcpy_s(Map[8],  "100000000001");
	strcpy_s(Map[9],  "100000000001");
	strcpy_s(Map[10], "100000000001");
	strcpy_s(Map[11], "100000000001");
	strcpy_s(Map[12], "100000000001");
	strcpy_s(Map[13], "100000000001");
	strcpy_s(Map[14], "100000000001");
	strcpy_s(Map[15], "100000000001");
	strcpy_s(Map[16], "100000000001");
	strcpy_s(Map[17], "100000000001");
	strcpy_s(Map[18], "100000000001");
	strcpy_s(Map[19], "100000000001");
	strcpy_s(Map[20], "100000000001");
	strcpy_s(Map[21], "100000000001");
	strcpy_s(Map[22], "100000000001");
	strcpy_s(Map[23], "111111111111");
}

void DrawMapAndObject(char Map[HEIGHT][WEIGHT])
{
	for (int i = 0; i < 24; i++)
	{
		//char asd = _setmode(_fileno(stdout), _O_U8TEXT);
		for (int j = 0; j < 12; j++)
		{
			if (i == 2 && j != 0 && j != 11)
			{
				cout << "\033[48;2;135;135;135m";
				cout << "  ";
				continue;
			}

			switch (Map[i][j])
			{
			case '0': // 빈 공간
				cout << "\033[48;2;0;0;0m";
				cout << "  ";
				break;
			case '1': // 벽
				cout << "\033[48;2;255;255;255m";
				cout << "  ";
				break;
			case '2': // ㅡ 블럭
				cout << "\033[48;2;14;159;255m";
				cout << "  ";
				break;
			case '3': // ㄱ 블럭
				cout << "\033[48;2;0;0;160m";
				cout << "  ";
				break;
			case '4': // 역 ㄱ 블럭
				cout << "\033[48;2;240;93;0m";
				cout << "  ";
				break;
			case '5': // ㄱㄴ 블럭
				cout << "\033[48;2;255;40;40m";
				cout << "  ";
				break;
			case '6': // 역 ㄱㄴ 블럭
				cout << "\033[48;2;134;231;37m";
				cout << "  ";
				break;
			case '7': // ㅜ 블럭
				cout << "\033[48;2;138;43;226m";
				cout << "  ";
				break;
			case '8': // ㅁ 블럭
				cout << "\033[48;2;255;237;40m";
				cout << "  ";
				break;
			//case 'L': // 라인 부분
			//	cout << "\033[48;2;135;135;135m";
			//	cout << "  ";
			//	break;
			}
		}
		//char asdsf = _setmode(_fileno(stdout), _O_TEXT);
		cout << endl;
		setcolor(7, 0);
	}
}
