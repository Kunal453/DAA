// Multi-threaded merge sort
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Function to merge two sorted subarrays into one sorted subarray
void merge(std::vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;// Calculate the size of the left subarray
    int n2 = right - mid;    // Calculate the size of the right subarray

    // Create temporary arrays to hold the subarrays
    std::vector<int> L(n1), R(n2);
    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
	
	// Merge the two subarrays back into the original array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
	
	 // Copy any remaining elements of L[] and R[] back to the original array
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort on the array
void mergeSort(std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Calculate the middle index
		
		// Recursively sort the left and right subarrays
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
		// Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

// Function to perform multithread merge sort
void mergeSortMultithread(std::vector<int> &arr, int left, int right, int depth)
{
    if (depth == 0 || left >= right)
    {
    	// If depth is zero or the subarray is small enough, perform single-threaded merge sort
        mergeSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    // Create two threads to sort the left and right subarrays
    std::thread leftThread(mergeSortMultithread, std::ref(arr), left, mid, depth - 1);
    std::thread rightThread(mergeSortMultithread, std::ref(arr), mid + 1, right, depth - 1);

 	// Wait for the threads to finish
    leftThread.join();
    rightThread.join();
	// Merge the sorted subarrays
    merge(arr, left, mid, right);
}

int main()
{
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arrSize = arr.size();
	
	 // Measure the time taken by simple merge sort
    auto startSimple = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arrSize - 1);
    auto endSimple = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationSimple = endSimple - startSimple;
	
	// Print the sorted array and time taken by simple merge sort
    std::cout << "Sorted array (Simple Merge Sort): ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Time taken by Simple Merge Sort: " << durationSimple.count() << " seconds" << std::endl;
	
	// Reset the array and measure the time taken by multithreaded merge sort
    arr = {12, 11, 13, 5, 6, 7};

    auto startMultithread = std::chrono::high_resolution_clock::now();
    mergeSortMultithread(arr, 0, arrSize - 1, 2); // Using 2 threads
    auto endMultithread = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMultithread = endMultithread - startMultithread;
	
	// Print the sorted array and time taken by multithreaded merge sort
    std::cout << "Sorted array (Multithreaded Merge Sort): ";
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Time taken by Multithreaded Merge Sort: " << durationMultithread.count() << " seconds" << std::endl;

    return 0;
}
