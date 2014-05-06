#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void next_permutation(vector<int> &num)
{
	int len = num.size();
	int i;
	for (i = len-1; i >= 1; --i) {
		if (num[i] > num[i-1]) {
			swap(num[i], num[i-1]);
			break;
		}
	}

	if (i < 1) {
		reverse(num.begin(), num.end());
	}

}
int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 4, 3};

	vector<int> v(a, a+4);
	next_permutation(v);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}