#include <stdio.h>

void reverse(char *buf, int count)
{
	char *begin = buf;
	char *end = buf + count -1;
	char tmp;
	while (begin <= end) {
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
char *itoa(int num, char *buf, int base)
{
	int negative = 0;
	int rem = 0;
	int index = 0;

	if (num == 0) {
		buf[index++] = '0';
		buf[index] = '\0';

		return buf;
	}

	if (num < 0 && base == 10) {
		negative = 1;
		num = 0 - num;
	}

	while (num > 0) {
		rem = num % base;
		buf[index++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (negative)
		buf[index++] = '-';

	buf[index] = '\0';

	reverse(buf, index);

	return buf;
}

int main(int argc, char const *argv[])
{
	char buf[100];
	int num = 1234567890;
	printf("%s\n", itoa(num, buf, 10));
	return 0;
}