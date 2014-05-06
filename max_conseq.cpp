#include <iostream>
#include <set>
#include <vector>

using namespace std;

int longest_consecutive(vector<int> &num)
{

    set<int> m_set;
    int max_len = 1;
    int cur_len = 1;

    for (int i = 0; i < num.size(); i++) {
        m_set.insert(num[i]);
    }

    for (int i = 0; i < num.size(); i++) {
        int cur_num = num[i];
        int tmp = cur_num;
        while (1) {
            if (m_set.count(++tmp) > 0) {
                cur_len++;
                m_set.erase(tmp);
            } else {
                break;
            }
        }
        tmp = cur_num;
        while (1) {
            if (m_set.count(--tmp) > 0) {
                cur_len++;
                m_set.erase(tmp);
            } else {
                break;
            }
        }

        if (cur_len > max_len)
            max_len = cur_len;
        cur_len = 1;
    }
    
    return max_len;
}
int main(int argc, const char *argv[])
{
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> v(a, a+6);
    int r = longest_consecutive(v);
    
    cout << r << endl;
    return 0;
}
