#include<iostream>
using namespace std;

const int pixel = 1;
const int colored = 2;

int cellsCount(int x, int y);
int m, n;

int map[8][8] = { {1,0,0,0,0,0,0,1},
				  {0,1,1,0,0,1,0,0},
				  {1,1,0,0,1,0,1,0},
				  {0,0,0,0,0,1,0,0},
				  {0,1,0,1,0,1,0,0},
				  {0,1,0,1,0,1,0,0},
				  {1,0,0,0,1,0,0,1},
				  {0,1,1,0,0,1,1,1} };

int main()
{
	m = 8;
	n = 8;
	int totalPicture = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cellsCount(i, j) > 0) {
				totalPicture++;
			}
		}
	}

	cout << "total picture: " << totalPicture << endl;
}

int cellsCount(int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n) {
		return 0;
	} else if (map[x][y] != pixel) {
		return 0;
	} else {
		map[x][y] = colored;
		return 1 + cellsCount(x, y + 1)
			     + cellsCount(x + 1, y - 1)
			     + cellsCount(x + 1, y)
			     + cellsCount(x + 1, y + 1)
			     + cellsCount(x, y - 1)
			     + cellsCount(x - 1, y - 1)
			     + cellsCount(x - 1, y)
			     + cellsCount(x - 1, y - 1);
	}
}
