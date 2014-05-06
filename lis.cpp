#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_LEN 256

using namespace std;

/**
 * @brief longest increase sequence
 * @details  return length of the longest incresing sequence
 * 
 * @param a string
 * @return [length of the longest incresing sequence]
 */
int lis(string &a)
{
	if (a.size() == 0)
		return 0;
	vector<int> b(a.size(), 0);
	b[0] = 1;
	int max = 0;

	for (int i = 0; i < a.size(); i++) {
		int k = 0;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && k < b[j])
				k = b[j];
		}
		b[i] = k + 1;
	}

	for (int i = 0; i < b.size(); i++) {
		if (b[i] > max) 
			max = b[i];
	}

	return max;
}

int main(int argc, char const *argv[])
{
	string a("154269");
	cout << lis(a) << endl;
	return 0;
}