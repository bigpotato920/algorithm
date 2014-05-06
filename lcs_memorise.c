#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int dp[MAX_LEN][MAX_LEN];

void init_dp() {
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			dp[i][j] = -1;
		}
		
	}
}
int lcs(const char *a, int i, const char *b, int j)
{
	if (i < 0 || j < 0)
		return 0;

	if (dp[i][j] == -1) {
		if (a[i] == b[j]) {
			dp[i][j] = lcs(a, i-1, b, j-1) + 1;
		}

		else {
			int first = lcs(a, i-1, b, j);
			int second = lcs(a, i, b, j-1);

			dp[i][j] =  first > second ? first : second;
		}
	}


	return dp[i][j];
}

void print_lcs(const char *a, int i, const char *b, int j)
{
	if (i < 0 || j < 0)
		return;
	if (dp[i][j] == dp[i-1][j-1] + 1) {
		print_lcs(a, i-1, b, j-1);
		printf("%c ", a[i]);
	} else if (dp[i][j] == dp[i-1][j])
		print_lcs(a, i-1, b, j);
	else
		print_lcs(a, i, b, j-1);


}
int main(int argc, char const *argv[])
{
	char *a = "124569";
	char *b = "154269";

	init_dp();
	printf("%d\n", lcs(a, strlen(a) - 1, b, strlen(b) - 1));

	print_lcs(a, strlen(a) - 1, b, strlen(b) - 1);
	return 0;
}