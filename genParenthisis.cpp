#include <iostream>
#include <string>
#include <vector>

using namespace std;

void _gen(int left, int right, int n, string s, vector<string> &result)
{
    if (left < right)
        return;

    if (left == n && right == n) {
        result.push_back(s);
        return;
    }

    if (left < n) {
        _gen(left+1, right, n, s+'(', result);
    }

    if (right < n) {
        _gen(left, right+1, n, s+')', result);
    }
}

vector<string> genParenthisis(int n) {

    string tmp;
    vector<string> result;

    _gen(0, 0, n, tmp, result);

    return result;
}


int main(int argc, const char *argv[])
{
    vector<string> result;

    result = genParenthisis(3);

    for (int i = 0; i < result.size(); i++) {
        string tmp = result[i];
        cout << tmp << endl;
    }

    cout << endl;
    return 0;
}
