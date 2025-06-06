#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
int main()
{
int n;
printf("Enter the value of n: ");
scanf("%d", &n);
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL)
{
printf("Memory allocation failed.");
return 1;
}
srand(time(NULL));
printf("Original array:\n");
for (int i = 0; i < n; i++)
{
arr[i] = rand() % 10000;
printf("%d ", arr[i]);
}
printf("\n");
struct timespec start, end;
clock_gettime(CLOCK_MONOTONIC, &start);
quickSort(arr, 0, n - 1);
clock_gettime(CLOCK_MONOTONIC, &end);
double time_taken = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
printf("Sorted array:\n");
printArray(arr, n);
printf("Time taken: %.0f nanoseconds\n", time_taken);
free(arr);
return 0;
}
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
int pivot_index = partition(arr, low, high);quickSort(arr, low, pivot_index - 1);
quickSort(arr, pivot_index + 1, high);
}
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}
