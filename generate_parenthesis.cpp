#include <iostream>
#include <string>

using namespace std;

void insert_parenthesis(string &target, int pos)
{
    target.insert(pos, "()");
}

int main(int argc, const char *argv[])
{
    string s = "()";

    insert_parenthesis(s, 1);

    cout << "s = " << s << endl;
    return 0;
}
