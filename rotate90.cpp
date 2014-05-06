#include <iostream>
#include <vector>

using namespace std;

void swap(vector<vector<int> > &matrix, int src_x, int src_y, int dst_x, int dst_y) {
    int tmp = matrix[src_x][src_y];
    matrix[src_x][src_y] = matrix[dst_x][dst_y];
    matrix[dst_x][dst_y] = tmp;
    
}

void rotate(vector<vector<int> > &matrix) {
    vector<vector<int> > tmp(matrix);
    int count = matrix.size();
    /*for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            tmp[j][count-i-1] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            matrix[i][j] = tmp[i][j];
        }
    }*/
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j <= i; j++) {
            swap(matrix, i, j, j, i);
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count/2; j++) {
            swap(matrix, i, j, i, count-j-1);
        }
    }
}


int main(int argc, char const *argv[])
{
    int a1[] = {1, 2};
    int a2[] = {3, 4};

    vector<vector<int> > matrix;
    vector<int> v1(a1, a1+2);
    vector<int> v2(a2, a2+2);

    matrix.push_back(v1);
    matrix.push_back(v2);

    rotate(matrix);
    int count = matrix.size();
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}