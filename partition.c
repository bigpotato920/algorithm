#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(int *a, int i, int j)
{

    int index;
    int k;
    int m = 0;
    int p = a[i];
    int len = j - i + 1;
    int *b = (int *)malloc(sizeof(int) * len);


    for (k = i + 1; k <= j; k++)
    {
        if (a[k] < p)
            b[m++] = a[k];
    }
    index = i + m;
    b[m++] = p;
    for (k = i + 1; k <= j; k++)
    {
        if (a[k] > p)
            b[m++] = a[k];
    }

    for (k = 0; k < len; k++)
    {
        a[i + k] = b[k];

    }


    free(b);

    return index;
}


void quick_sort(int *a, int l, int h)
{
	int i;
    if (l >= h)
        return;
    int m = partition(a, l, h);
    quick_sort(a, l, m - 1);
    quick_sort(a, m + 1, h);
    for (i = l; i <= h; i++)
    	printf("%d ", a[i]);
    printf("\n");
}


int main(int argc, char const *argv[])
{

    int a[] = {5, 8, 1, 3, 7, 9, 2};
    quick_sort(a, 0, 6);
    return 0;
}