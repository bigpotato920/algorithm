#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int matrix[8] = {0};
int count = 0;

bool judge(int row, int col)
{
	for (int i = 0; i < row; i++) {
		if (matrix[i] == col)
			return false;

		if (abs(i-row) == abs(matrix[i]-col))
			return false;
	}

	return true;
}

void nqueen(int row)
{
	if (row == 8) {
		count++;
		for (int i = 0; i < 8; i++) {
			cout << matrix[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < 8; i++) {
		if (judge(row, i)) {
			matrix[row] = i;
			nqueen(row+1);
		}
	}
}


int main(int argc, char const *argv[])
{
	nqueen(0);

	cout << count << endl;
	return 0;
}