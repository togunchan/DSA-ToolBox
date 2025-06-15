#include "quickSort.hpp"

/**
 * @brief Partitions the given vector for QuickSort using the Lomuto partition scheme.
 *
 * This function selects the last element as the pivot and rearranges the elements
 * such that all elements less than or equal to the pivot are placed before it,
 * and all greater elements are placed after it. The pivot is then placed at its
 * correct sorted position.
 *
 * @param arr Reference to the vector of integers to be partitioned.
 * @param low Starting index of the portion to be partitioned.
 * @param high Ending index of the portion to be partitioned (pivot).
 * @return The index of the pivot after partitioning.
 *
 * @note This function is typically used as part of the QuickSort algorithm.
 *       It has a time complexity of O(n) for partitioning a single segment.
 */
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
 * @brief Sorts the given vector using the QuickSort algorithm.
 *
 * This function recursively partitions the array and sorts the left
 * and right subarrays based on a pivot element. The partitioning is
 * done using the Lomuto partition scheme.
 *
 * @param arr Reference to the vector of integers to be sorted.
 * @param low Starting index of the current subarray.
 * @param high Ending index of the current subarray.
 */
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}