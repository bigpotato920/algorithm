#include <iostream>
#include <vector>

using namespace std;

bool bsearch(vector<int> &row, int begin, int end, int target)
{
    while (begin <= end) {
        int middle = begin + (end-begin)/2;
        if (row[middle] == target)
            return true;
        else if (row[middle] > target)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    return false;
}

bool row_search(vector<int> &row, int target)
{
    return bsearch(row, 0, row.size()-1, target);
}


int inrow(vector<int> &row, int target)
{
    if (target < row[0])
        return -1;
    else if (target > row[row.size()-1])
        return 1;
    else
        return 0;
}

bool matrix_search(vector<vector<int> > &matrix, int begin, int end, int target)
{
    while (begin <= end) {
        int middle = begin + (end-begin)/2;
        int index = inrow(matrix[middle], target);
        if (index == 0)
            return row_search(matrix[middle], target);
        else if (index == -1)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    return false;
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {

    //return matrix_search(matrix, 0, matrix.size()-1, target);
    int row_count = matrix.size();
    int col_count = matrix[0].size();

    int begin = 0;
    int end = row_count * col_count - 1;

    while (begin <= end) {
        int middle = begin + (end - begin) / 2;

        if (matrix[middle/col_count][middle%row_count] == target)
            return true;
        else if (matrix[middle/col_count][middle%row_count] < target)
            begin = middle + 1;
        else
            end = middle - 1;

    }

    return false;
}

int main(int argc, char const *argv[])
{
    int a1[] = {1, 3};
    int a2[] = { 5, 6, 7, 8};
    int a3[] = {9, 10, 11, 12};

    vector<int> v1(a1, a1+4);
    vector<int> v2(a2, a2+4);
    vector<int> v3(a3, a3+4);

    vector<vector<int> > matrix;
    matrix.push_back(v1); 
    //matrix.push_back(v2); 
    //matrix.push_back(v3); 

    cout << searchMatrix(matrix, 3);
    return 0;
}