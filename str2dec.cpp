#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


int str2dec(string &a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
        	cout << (1 << (a.size()-i-1)) << endl;
            sum |= (1 << (a.size()-i-1));
        }
    }
    
    return sum;
}

/*string int2str(int a)
{
	if (a == 0)
		return "0";
	string s;
	while (a) {
		s.push_back(a%2 + '0');
		a = a / 2;
	}

	reverse(s.begin(), s.end());

	return s;
}*/

string int2str (int a)
{
	stringstream ss;
	ss << a;

	return ss.str();
}

string add_binary(string a, string b)
{
	string sum;
	int m = a.size();
	int n = b.size();
	int max_len = m > n ? m : n;
	int carry = 0;

	stringstream ss;

	for (int i = 0; i < max_len; i++) {
		int p = i < m ? a[m-i-1] - '0' : 0;
		int q = i < n ? b[n-i-1] - '0' : 0;

		int tmp = p + q + carry;
		cout << p << " " << q << endl;
		carry = tmp / 2;
		sum =  int2str(tmp % 2) + sum;

	}

	if (carry == 1)
		sum = '1' + sum;

	return sum;
}

int main(int argc, char const *argv[])
{
	string a = "0";
	string b = "0";
	cout << add_binary(a, b) << endl;
	return 0;
}