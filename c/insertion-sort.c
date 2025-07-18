#include <stdio.h>

void insertion_sort(int *arr, int size, int reversed);

int main()
{
  int a[] = {0, 1};

  insertion_sort(a, 2, 1);

  for (int i = 0; i < 2; i++)
  {
    printf("%d ", a[i]);
  }
}

void insertion_sort(int *arr, int size, int reversed)
{
  if (size <= 1)
    return;

  for (int i = 1; i < size; i++)
  {
    int value = arr[i];
    int j;

    for (j = i - 1; (reversed ? arr[j] < value : arr[j] > value) && j >= 0; j--)
    {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = value;
  }
}