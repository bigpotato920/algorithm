#include <stdio.h>
#include <stdlib.h>

int merge_and_count(int a[], int begin, int mid, int end)
{
	int num_count = end - begin + 1;
	int inversion_count = 0;
	int i = begin;
	int j = mid + 1;
	int k = 0;

	int *b = (int*)malloc(sizeof(int) * num_count);

	k = 0;

	while (i <= mid && j <= end) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			inversion_count++;
		}

	}

	while (i <= mid) {
		b[k++] = a[i++];
		inversion_count++; b   
	}

	while (j <= end)
		b[k++] = a[j++];

	for (k = 0; k < num_count; k++)
		a[begin + k] = b[k];

	free(b);

	return inversion_count;
}

int merge_sort(int a[], int begin, int end)
{
	if (begin < end) {
		int mid = (begin + end) / 2;

		int l_count = merge_sort(a, begin, mid);
		int r_count = merge_sort(a, mid + 1, end);
		
		return merge_and_count(a, begin, mid, end) + l_count + r_count;
	}

	return 0;
}


int main(int argc, char const *argv[])
{
	int a[] = {2, 3, 8, 6, 1};

	int inversion_count = merge_sort(a, 0, 4);

	for (int i = 0; i < 5; i++)
		printf("%d ", a[i]);
	printf("\n");

	printf("%d\n", inversion_count);
	return 0;
}