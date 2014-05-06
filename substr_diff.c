#include <stdio.h>

#define MAX_LEN 1500

int compute(int k, char *s1, char *s2) {

}

int main(int argc, char const *argv[])
{
	int T;
	int K;
	int L;
	int i;

	char s1[MAX_LEN+1];
	char s2[MAX_LEN+1];

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%s%s", &K, s1, s2);
		L = compute(K, s1, s2);
		printf("L\n");
	}

	return 0;
}