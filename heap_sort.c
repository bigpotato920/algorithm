#include <stdio.h>

void max_heapify(int *a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;
    
    if (l < n && a[l] > a[i])
        largest = l;
    else
        largest = i;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int tmp = a[largest];
        a[largest] = a[i];
        a[i] = tmp;
        
        max_heapify(a, largest, n);
    }

}


void build_heap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(a, i, n);
}

void heap_sort(int *a, int n)
{
    build_heap(a, n);

    for (int i = n - 1; i >= 1; i--) {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        max_heapify(a, 0, i);
    }
}

int main(int argc, const char *argv[])
{
    int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    heap_sort(a, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
