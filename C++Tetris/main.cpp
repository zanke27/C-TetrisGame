#include "console.h";
#include "Tetris.h";
using namespace std;

char mainMap[HEIGHT][WEIGHT];
int main(void)
{
	SetMap(mainMap);

	for (int i = 0; i < 21; i++)
	{
		char asd = _setmode(_fileno(stdout), _O_U8TEXT);
		for (int j = 0; j < 12; j++)
		{
			switch (mainMap[i][j])
			{
			case '0':
				setcolor(128, 0);
				wcout << L"  ";
				break;
			case '1':
				setcolor(255, 0);
				wcout << L"  ";
				break;
			}
		}
		char asdsf = _setmode(_fileno(stdout), _O_TEXT);
		cout << endl;
		setcolor(7, 0);
	}
}