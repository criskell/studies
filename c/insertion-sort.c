#include <stdio.h>

void insertion_sort(int *arr, int size, int reversed);

int main()
{
  int a[] = {0, 4, 1};

  insertion_sort(a, 3, 1);

  for (int i = 0; i < 3; i++)
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

    for (j = i - 1; arr[j] < value == reversed && j >= 0; j--)
    {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = value;
  }
}