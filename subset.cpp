#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int> &S) {
    int low = 0;
    int high = (1<<S.size()) - 1;
    int len = S.size();
    set<vector<int> > result;
    if (S.size() == 0)
        return vector<vector<int> >(result.begin(), result.end());

    sort(S.begin(), S.end());
    for (int mask = low; mask <= high; mask++) {
        vector<int> tmp;
        for (int i = 0; i < len; i++) {
            if (((mask >> i)&1) != 0) {
                tmp.push_back(S[i]);
            }
        }
        for (int i = 0 ;i < tmp.size(); i++)
            cout << tmp[i] << " ";
        cout << endl;
        result.insert(tmp);
    }


    return vector<vector<int> >(result.begin(), result.end());
}

int main(int argc, char const *argv[])
{
    vector<int> t;
    vector<vector<int> > result;

    t.push_back(1);
    t.push_back(2);
    t.push_back(2);

    result = subsets(t);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}