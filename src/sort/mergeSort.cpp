#include "mergeSort.hpp"

void merge(std::vector<int> &arr, int left, int right)
{
    int mid = (left + right) / 2;
    int size1 = mid - left + 1;
    int size2 = right - mid;

    std::vector<int> leftArr(size1);
    std::vector<int> rightArr(size2);

    // Copy data to temporary arrays
    for (int i = 0; i < size1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < size2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}