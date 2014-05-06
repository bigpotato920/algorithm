#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

bool judge(int row, int col, vector<int> &matrix)
{
	for (int i = 0; i < row; i++) {
		if (matrix[i] == col)
			return false;
		if (abs(row-i) == abs(col-matrix[i]))
			return false;
	}

	return true;
}

void build_result(vector<vector<string> > &result, vector<int> &matrix)
{
	vector<string> solution;
	int len = matrix.size();
	cout << "len = " << len << endl;
	for (int i = 0; i < matrix.size(); i++) {
		string row;
		int j = matrix[i];
		cout << "j = " << j << endl;
		for (int k = 0; k < j; k++)
			row.push_back('.');
		row.push_back('Q');
		for (int k = j+1; k < len; k++)
			row.push_back('.');
		solution.push_back(row);
	}

	result.push_back(solution);
}

void nqueens(int n, vector<int> &matrix, vector<vector<string> > &result)
{
	if (n == matrix.size()) {
		build_result(result, matrix);
		return;
	}
	for (int i = 0; i < matrix.size(); i++) {
		if (judge(n, i, matrix)) {
			matrix[n] = i;
			nqueens(n+1, matrix, result);
		}
	}
}

vector<vector<string> > solveNQueens(int n) {
	vector<int> matrix(n, 0);
	vector<vector<string> > result;

	nqueens(0, matrix, result);

	return result;
}



int main(int argc, char const *argv[])
{
	vector<vector<string> > result;
   	result = solveNQueens(4);

   	for (int i = 0; i < result.size(); i++) {
   		vector<string> solution = result[i];
   		for (int j = 0; j < solution.size(); j++) {
   			cout << solution[j] << endl;
   		}
   		cout << endl;
   	}
   	return 0;
}