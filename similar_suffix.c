#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100000

int compute(char *s, int i, int j) {
	int c = 0;;
	int len = strlen(s);

	while (j < len) {
		if (s[i] == s[j]) {
			i++;
			j++;
			c++;
		} else {
			break;
		}
	}
	//printf("compute....%d\n", c);
	return c;

}

int main(int argc, char const *argv[])
{
	int T;
	char s[MAX_STR_LEN+1];
	int i,j;
	int c;
	int len;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%s", s);
		c = 0;
		j = 0;
		len = strlen(s);

		for (j = 0; j < len; j++) {
			c += compute(s, 0, j);
		}
		printf("%d\n", c);

	}
	return 0;
}