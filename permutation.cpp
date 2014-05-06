#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool unique_swap(vector<int> &num, int begin, int end)
{
    for (int i = begin; i < end; i++) {
        if (num[i] == num[end])
            return false;
    }

    return true;
}

void permute_helper(int start, vector<int> &num, vector<vector<int> > &result)
{
    if (start == num.size()) {
        result.push_back(num);
      
    } else {
        for (int i = start; i < num.size(); i++) {
            if (unique_swap(num, start, i)) {
                swap(num[i], num[start]);
                permute_helper(start+1, num, result);
                swap(num[i], num[start]);
            }

        }
    }

}
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > result;
    
    if (num.size() == 0)
        return result;
    permute_helper(0, num, result);
    
    return result;
}


int main(int argc, char const *argv[])
{
    int a[] = {1,2,1};
    vector<int> num(a, a+3);
    vector<vector<int> > result = permuteUnique(num);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}