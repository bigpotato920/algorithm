#include <vector>
#include <iostream>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    const int max_row_count = 100;
    const int max_col_count = 100;
    int matrix[max_row_count][max_row_count] = {{0}};
    int row_count = obstacleGrid.size();
    int col_count = obstacleGrid[0].size();
    
    for (int i = col_count-1; i >=0; --i) {
        if (obstacleGrid[row_count-1][i] == 1)
            matrix[row_count-1][i] = 0;
        else
            matrix[row_count-1][i] = 1;
    }

    for (int i = row_count-1; i >= 0; --i) {
        if (obstacleGrid[i][col_count-1] == 1)
            matrix[i][col_count-1] = 0;
        else
            matrix[i][col_count-1] = 1;
    }
    
    for (int i = row_count-2; i >= 0; --i) {
        for (int j = col_count-2; j >= 0; --j) {
            if (obstacleGrid[i][j] == 1)
                matrix[i][j] = 0;
            else
                matrix[i][j] = matrix[i][j+1] + matrix[i+1][j];
        }
    }
    
    return matrix[0][0];
}

int main(int argc, char const *argv[])
{
	vector<int> tmp(2, 0);
	vector<vector<int> > ob;
	ob.push_back(tmp);
	cout << uniquePathsWithObstacles(ob);
	return 0;
}
