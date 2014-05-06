#include <iostream>

using namespace std;

int remove_dup(int *a, int n)
{
	if (n == 0)
		return n;
	int start = 2;

	for (int i = 2; i < n; i++) {
		if ((a[i] == a[i-1] && a[i] == a[i-2]))
			continue;
		else
			a[start++] = a[i];
		
	}

	return start;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,1,1,2,2,3,4,5};

	cout << remove_dup(a, 8) << endl;

	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}

	cout << endl;
	return 0;
}