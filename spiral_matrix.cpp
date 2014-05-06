#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int> > get_matrix(int n)
{
	vector<vector<int> > matrix;
	int i,j;
	for (i = 0; i < n; i++) {
		vector<int> tmp;
		for (j = 0; j < n; j++) {
			tmp.push_back(0);   
		}
		matrix.push_back(tmp);
	}

	i = j = 0;
	int begin = 0;
	int end = n-1;
	int value = 1;
	int last = n * n;

	while (1) {
	    //up
		for (; j <= end; j++) {
			matrix[i][j] = value;
			printf("matrix[%d][%d] = %d\n", i, j, value);
			if (value == last)
				return matrix;
			value++;

		}
		i++;
		j--;
	    //right
		for (; i <= end; i++) {
			matrix[i][j] = value;
			printf("matrix[%d][%d] = %d\n", i, j, value);
			if (value == last)
				return matrix;
			value++;
		}
		j--;
		i--;
	    //down
		for (;j >= begin; j--) {
			matrix[i][j] = value;
			printf("matrix[%d][%d] = %d\n", i, j, value);
			if (value == last)
				return matrix;
			value++;
		}
		i--;
		j++;
	    //left
		for (; i > begin; i--) {
			matrix[i][j] = value;
			printf("matrix[%d][%d] = %d\n", i, j, value);
			if (value == last)
				return matrix;
			value++;
		}
		i++;
		j++;
		begin++;
		end--;
	}
}
int main(int argc, char const *argv[])
{
	for (int k = 1; k < 10; k++) {
		vector<vector<int> > matrix = get_matrix(k);

		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}