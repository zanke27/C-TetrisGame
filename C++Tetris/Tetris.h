#pragma once

const int HEIGHT = 25; // 실사용 23칸 + 줄 1칸 + 배열 하나 더
const int WEIGHT = 13; // 실사용 10칸 + 생성될 2칸  + 배열 하나 더

typedef struct BlockPos
{
public:
	int blockLeftUpX;
	int blockLeftUpY;
	int blockX[4];
	int blockY[4];
	char blockShape[7][4][4][4] =
	{
#pragma region ㅡ블럭
		{
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 0 }
			}
		},
#pragma endregion		
#pragma region ㄱ블럭
		{
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 1, 1 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 1 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 }
			}
		},
#pragma endregion
#pragma region 역ㄱ블럭
		{
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 1 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 0, 1 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 1, 1, 1 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 }
			}

		},
#pragma endregion
#pragma region ㄱㄴ블럭
		{
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 1, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 1 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 1, 0 }
			}
		},
#pragma endregion
#pragma region 역ㄱㄴ블럭
		{
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 1 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
			},
			{
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 0, 0, 1 }
			}
		},
#pragma endregion
#pragma region ㅜ블럭
			{
				{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 1 },
				{ 0, 0, 1, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 1 },
				{ 0, 0, 0, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 1 },
				{ 0, 0, 1, 0 }
				}
			},
#pragma endregion
#pragma region ㅁ블럭
			{
				{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
				},
				{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
				}
			}
#pragma endregion
	};
}BlockPos, *PBlockPos;

typedef struct Block
{
public:
	BlockPos bPos;
	int blockType = 2;
	int rotationNum = 0;
}Block, *PBlock;

void SetMap(char Map[HEIGHT][WEIGHT]);									    // 맵 만들기
void DrawMapAndBlock(char Map[HEIGHT][WEIGHT]);							    // 맵과 블럭을 그림
void SpawnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, int blockType);    // 블럭 스폰, type받아서 바꿔야함
void DownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // 블럭 내리기
void TurnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, bool isLeftRotate); // 블럭 돌리기 (현재 일부 구현)
void BindBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // 블럭을 그 위치에 고정 (바닥에 닿았을 때 실행)
void MoveLeftBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);			    // 블럭을 왼쪽으로 이동
void MoveRightBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);			    // 블럭을 오른쪽으로 이동
void MoveDownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);
void ClearBlock(char Map[HEIGHT][WEIGHT], int howLine);					    // 블럭을 삭제

bool Delay(clock_t time, int delayTime);
long DelayStart();
																		    
int ClearBlockLine(char Map[HEIGHT][WEIGHT]);								// 블럭 삭제 어디서 부터 해야하는지 확인

bool ReachBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // 블럭이 바닥에 닿는지 체크
bool CheckBlock(char Map[HEIGHT][WEIGHT]);								    // 블럭이 선에 닿는지 체크