#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000
void merge(int a[], int low, int mid, int high)
{
int i, j, k;
int b[MAX_SIZE];
int h;
h = low;
i = low;
j = mid + 1;
while ((h <= mid) && (j <= high))
{
if (a[h] < a[j])
{
b[i] = a[h];
h = h + 1;
}
else
{
b[i] = a[j];
j = j + 1;
}
i = i + 1;
}
if (h > mid)
{
for (k = j; k <= high; k++)
{
b[i] = a[k];
i = i + 1;
}
}
else
{
for (k = h; k <= mid; k++)
{
b[i] = a[k];
i = i + 1;
}
}
for (k = low; k <= high; k++)
{
a[k] = b[k];
}
}
void mergesort(int a[], int low, int high)
{
int mid;
if (low < high)
{
mid = (low + high) / 2;
mergesort(a, low, mid);
mergesort(a, mid + 1, high);
merge(a, low, mid, high);
}
}
int main()
{
int a[MAX_SIZE];
int n;
printf("********** MERGE SORT PROGRAM*********\n");
printf("Enter the number of elements to be sorted: ");
scanf("%d", &n);
srand(time(NULL));
printf("Array elements to be sorted are:\n");
for (int i = 0; i < n; i++)
{
a[i] = rand() % 100;
printf("%d ", a[i]);
}
struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);
mergesort(a, 0, n - 1);
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken = (end.tv_sec - start.tv_sec) * 1e9 +(end.tv_nsec - start.tv_nsec);
printf("\nThe sorted elements are:\n");
for (int i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\nThe time taken to sort is %.10f seconds\n",time_taken);
}
