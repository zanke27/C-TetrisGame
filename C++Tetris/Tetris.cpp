#include "console.h"
#include "Tetris.h"

// 0: 검은 배경, 1: 벽, 2: ㅡ 블럭, 3: ㄱ 블럭, 4: 역 ㄱ 블럭, 5: ㄱㄴ 블럭, 6: 역 ㄱㄴ 블럭, 7: ㅜ 블럭, 8: ㅁ 블럭
void SetMap(char Map[HEIGHT][WEIGHT])
{
	strcpy_s(Map[0],  "100000000001");
	strcpy_s(Map[1],  "100000000001");
	strcpy_s(Map[2],  "100000000001");
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
	strcpy_s(Map[23], "100000000001");
	strcpy_s(Map[24], "111111111111");
}

void DrawMapAndBlock(char Map[HEIGHT][WEIGHT])
{
	for (int i = 1; i < HEIGHT; i++)
	{
		for (int j = 0; j < WEIGHT-1; j++)
		{
			if (i == 3 && j != 0 && j != 11 && Map[i][j] == '0') // 라인
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
			case 'A': // 끝난 ㅡ 블럭
				cout << "\033[48;2;14;159;255m";
				cout << "  ";
				break;
			case '3': // ㄱ 블럭
			case 'B': // 끝난 ㄱ 블럭
				cout << "\033[48;2;0;0;160m";
				cout << "  ";
				break;
			case '4': // 역 ㄱ 블럭
			case 'C': // 끝난 역 ㄱ 블럭
				cout << "\033[48;2;240;93;0m";
				cout << "  ";
				break;
			case '5': // ㄱㄴ 블럭
			case 'D': // 끝난 ㄱㄴ 블럭
				cout << "\033[48;2;255;40;40m";
				cout << "  ";
				break;
			case '6': // 역 ㄱㄴ 블럭
			case 'E': // 끝난 역 ㄱㄴ 블럭
				cout << "\033[48;2;134;231;37m";
				cout << "  ";
				break;
			case '7': // ㅜ 블럭
			case 'F': // 끝난 ㅜ 블럭
				cout << "\033[48;2;138;43;226m";
				cout << "  ";
				break;
			case '8': // ㅁ 블럭
			case 'G': // 끝난 ㅁ 블럭
				cout << "\033[48;2;255;237;40m";
				cout << "  ";
				break;
			}
		}
		cout << endl;
		setcolor(7, 0);
	}
}

void SpawnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, int blockType)
{
	pBlock->blockType = blockType;
	pBlock->bPos.blockLeftUpX = 4;
	pBlock->bPos.blockLeftUpY = 0;
	pBlock->rotationNum = 0;
	int check = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pBlock->bPos.blockShape[pBlock->blockType-2][pBlock->rotationNum][i][j] == 1)
			{
				Map[i][j + 4] = (char)(pBlock->blockType +'0');
				pBlock->bPos.blockX[check] = j + 4;
				pBlock->bPos.blockY[check] = i;
				check++;
			}
			else
			{
				Map[i][j + 4] = '0';
			}
		}
	}
}

void DownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{


	for (int i = 0; i < 4; i++)
		Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = '0';

	for (int i = 0; i < 4; i++)
		pBlock->bPos.blockY[i] += 1;

	pBlock->bPos.blockLeftUpY += 1;

	for (int i = 0; i < 4; i++)
		Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = (char)(pBlock->blockType + '0');
}

bool ReachBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{
	bool isCheck = false;
	for (int i = 0; i < 4; i++)
	{
		if (Map[pBlock->bPos.blockY[i] + 1][pBlock->bPos.blockX[i]] != '0'
			&& Map[pBlock->bPos.blockY[i] + 1][pBlock->bPos.blockX[i]] != (char)(pBlock->blockType + '0'))
			isCheck = true;
	}
	return isCheck;
}

void TurnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, bool isLeftRotate)
{
	int check = 0;
	int fortemp = 0;
	int tempRotationNum = pBlock->rotationNum;

	if (isLeftRotate)
	{
		if (tempRotationNum == 0)
			tempRotationNum = 3;
		else
			tempRotationNum = tempRotationNum - 1;
	}
	else if (!isLeftRotate)
	{
		tempRotationNum = (tempRotationNum + 1) % 4;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pBlock->bPos.blockShape[pBlock->blockType - 2][tempRotationNum][i][j] == 1)
			{
				if (Map[pBlock->bPos.blockLeftUpY + i][pBlock->bPos.blockLeftUpX + j] != '0' &&
					Map[pBlock->bPos.blockLeftUpY + i][pBlock->bPos.blockLeftUpX + j] != (char)(pBlock->blockType + '0'))
				{
					check++;
				}
			}
		}
	}

	if (check >= 1)
	{
		return;
	}

	check = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[j]] = '0';
		}
	}
	if (isLeftRotate)
	{
		if (pBlock->rotationNum == 0)
			pBlock->rotationNum = 3;
		else
			pBlock->rotationNum = pBlock->rotationNum - 1;
	}
	else if (!isLeftRotate)
	{
		pBlock->rotationNum = (pBlock->rotationNum + 1) % 4;
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pBlock->bPos.blockShape[pBlock->blockType - 2][pBlock->rotationNum][i][j] == 1)
			{
				pBlock->bPos.blockY[fortemp] = pBlock->bPos.blockLeftUpY + i;
				pBlock->bPos.blockX[fortemp] = pBlock->bPos.blockLeftUpX + j;
				fortemp++;
			}
		}
	}
	fortemp = 0;

	// 일단 있는거 다 지우고
	// 위치를 블럭에 1인 부분으로 바꿔주고
	// draw에서 알아서 blockPos에 따라 해주겠지??
}

void BindBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{
	for (int i = 0; i < 4; i++)
		Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = (char)(pBlock->blockType + 63);
}

void MoveLeftBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{
	bool isCan = true;
	for (int i = 0; i < 4; i++)
	{
		if (Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]-1] != (char)(pBlock->blockType + '0')
			&& Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i] - 1] != '0')
			isCan = false;
	}

	if (isCan == true)
	{
		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = '0';

		for (int i = 0; i < 4; i++)
			pBlock->bPos.blockX[i] -= 1;

		pBlock->bPos.blockLeftUpX -= 1;

		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = (char)(pBlock->blockType + '0');
	}
}

void MoveRightBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{
	bool isCan = true;
	for (int i = 0; i < 4; i++)
	{
		if (Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i] + 1] != (char)(pBlock->blockType + '0')
			&& Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i] + 1] != '0')
			isCan = false;
	}

	if (isCan == true)
	{
		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = '0';

		for (int i = 0; i < 4; i++)
			pBlock->bPos.blockX[i] += 1;

		pBlock->bPos.blockLeftUpX += 1;

		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = (char)(pBlock->blockType + '0');
	}
}

void MoveDownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock)
{
	bool isCan = true;
	for (int i = 0; i < 4; i++)
	{
		if (Map[pBlock->bPos.blockY[i+1]][pBlock->bPos.blockX[i]] != (char)(pBlock->blockType + '0')
			&& Map[pBlock->bPos.blockY[i+1]][pBlock->bPos.blockX[i]] != '0')
			isCan = false;
	}

	if (isCan == true)
	{
		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = '0';

		for (int i = 0; i < 4; i++)
			pBlock->bPos.blockY[i] += 1;

		pBlock->bPos.blockLeftUpY += 1;

		for (int i = 0; i < 4; i++)
			Map[pBlock->bPos.blockY[i]][pBlock->bPos.blockX[i]] = (char)(pBlock->blockType + '0');
	}
}

void ClearBlock(char Map[HEIGHT][WEIGHT], int howLine)
{
	for (int i = howLine; i > 4; i--)
	{
		for (int j = 1; j < 11; j++)
		{
			if (Map[i-1][j] != '2' && Map[i-1][j] != '3' && Map[i-1][j] != '4' && Map[i-1][j] != '5' &&
				Map[i-1][j] != '6' && Map[i-1][j] != '7' && Map[i-1][j] != '8')
				Map[i][j] = Map[i - 1][j];
			else
				Map[i][j] = '0';
		}
	}

	// 라인 위부터 줄까지 한칸씩 당김
}

bool Delay(clock_t time, int delayTime)
{
	if (clock() - time > delayTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

long DelayStart()
{
	clock_t start = clock();
	return start;
}

int ClearBlockLine(char Map[HEIGHT][WEIGHT])
{
	int temp = 0;
	for (int i = 23; i > 4; i--)
	{
		for (int j = 1; j < 11; j++)
		{
			if (Map[i][j] == '0')
				temp++;
		}
		if (temp == 0)
		{
			temp = i;
			break;
		}
		else
			temp = 0;
	}

	return temp;
}

bool CheckBlock(char Map[HEIGHT][WEIGHT])
{
	for (int i = 1; i < 11; i++)
	{
		if (Map[3][i] != '0')
			return true;
	}
	return false;
}