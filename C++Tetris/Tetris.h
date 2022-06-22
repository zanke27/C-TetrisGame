#pragma once

const int HEIGHT = 25; // �ǻ�� 23ĭ + �� 1ĭ + �迭 �ϳ� ��
const int WEIGHT = 13; // �ǻ�� 10ĭ + ������ 2ĭ  + �迭 �ϳ� ��

typedef struct BlockPos
{
public:
	int blockLeftUpX;
	int blockLeftUpY;
	int blockX[4];
	int blockY[4];
	char blockShape[7][4][4][4] =
	{
#pragma region �Ѻ�
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
#pragma region ����
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
#pragma region ������
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
#pragma region ������
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
#pragma region ��������
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
#pragma region �̺�
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
#pragma region ����
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

void SetMap(char Map[HEIGHT][WEIGHT]);									    // �� �����
void DrawMapAndBlock(char Map[HEIGHT][WEIGHT]);							    // �ʰ� ���� �׸�
void SpawnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, int blockType);    // �� ����, type�޾Ƽ� �ٲ����
void DownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // �� ������
void TurnBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock, bool isLeftRotate); // �� ������ (���� �Ϻ� ����)
void BindBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // ���� �� ��ġ�� ���� (�ٴڿ� ����� �� ����)
void MoveLeftBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);			    // ���� �������� �̵�
void MoveRightBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);			    // ���� ���������� �̵�
void MoveDownBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);
void ClearBlock(char Map[HEIGHT][WEIGHT], int howLine);					    // ���� ����

bool Delay(clock_t time, int delayTime);
long DelayStart();
																		    
int ClearBlockLine(char Map[HEIGHT][WEIGHT]);								// �� ���� ��� ���� �ؾ��ϴ��� Ȯ��

bool ReachBlock(char Map[HEIGHT][WEIGHT], PBlock pBlock);				    // ���� �ٴڿ� ����� üũ
bool CheckBlock(char Map[HEIGHT][WEIGHT]);								    // ���� ���� ����� üũ