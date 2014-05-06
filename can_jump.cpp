
#include <iostream>

using namespace std;

bool can_jump(int A[], int n)
{
	bool result = false;
	if (n == 1)
		return true;
	for (int i = n-2; i >= 0; --i) {
		if (A[i] >= n-i-1) {
			if (can_jump(A, i+1))
				result = true;
		}
	}
	cout << result << endl;
	return result;
}


int main(int argc, char const *argv[])
{
	//int A[] = {2, 3, 1, 1, 4};
	int A[] = {1, 2, 0, 2, 0, 4};

	cout << can_jump(A, 6) << endl;
	return 0;
}