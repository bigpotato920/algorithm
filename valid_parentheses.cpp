#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(string s)
{
    vector<char> stack;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        switch (c) {
            case '(':
            case '[':
            case '{':

                stack.push_back(c);
                break;
            case ')':
            case ']':
            case '}':
                char top = stack.back();
                stack.pop_back();
                if ((c == '}' && top == '{') || (c == ']' && top == '[') ||
                        (c == ')' && top == '('))
                    break;
                else {
                    cout << "mismatch" << c << top << endl;
                    return false;

                }

        }


    }

    if (stack.size() == 0)
        return true;
    cout << "single" << endl;
    return false;
}

int main(int argc, const char *argv[])
{
    string s = "([{}])";

    bool result = is_valid(s);

    cout << result << endl;
    return 0;
}
