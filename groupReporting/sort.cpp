//
// Created by kaloyyyyy on 27/04/2022.
//

#include "sort.h"
#include <iostream>
using namespace std;
#include <vector>

void sort() {

    char choice;
    do {
        int data[] = {-2, 420, 0, 110, -9, 360, -69};
        int arr[] = {4, 2, 2, 8, 3, 3, 1};
        int size = sizeof(data) / sizeof(data[0]);
        cout
                << "a. bubble    b. count    c. quick    d. selection    e. radix    f. insertion    g. merge    x. main menu\n";
        cin >> choice;
        switch (choice) {
            case 'a':
                cout << "Unsorted Array:\n";
                printArray(data, size);
                bubbleSort(data, size);
                cout << "Bubble Sorted Array in Ascending Order:\n";
                printArray(data, size);
                break;
            case 'b':
                cout << "Unsorted Array:\n";
                printArray(arr, size);
                countSort(arr, size);
                cout << "Count Sorted Array in Ascending Order:\n";
                printArray(arr, size);
                break;
            case 'c':
                cout << "Unsorted Array:\n";
                printArray(data, size);
                quickSort(data, 0, size - 1);
                cout << "Quick Sorted Array in Ascending Order:\n";
                printArray(data, size);
                break;
            case 'd':
                cout << "Unsorted Array:\n";
                printArray(data, size);
                selectionSort(data, size);
                cout << "Selection Sorted Array in Ascending Order:\n";
                printArray(data, size);
                break;
            case 'e':
                cout << "Unsorted Array:\n";
                printArray(arr, size);
                radixSort(arr, size);
                cout << "Radix Sorted Array in Ascending Order:\n";
                printArray(arr, size);
                break;
            case 'f':
                cout << "Unsorted Array:\n";
                printArray(data, size);
                insertionSort(data, size);
                cout << "insertion Sorted Array in Ascending Order:\n";
                printArray(data, size);
                break;

            case 'g':
                cout << "Unsorted Array:\n";
                printArray(data, size);
                mergeSort(data, 0, size - 1);
                cout << "Merge Sorted Array in Ascending Order:\n";
                printArray(data, size);
                break;
            default:
                cout << "invalid choice\n";
                break;
        }
    } while (choice != 'x');
}


// print array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

/* unoptimized bubble sort
void bubbleSort(int array[], int size) {

    //loop to access each array element
    for (int step = 0; step < size; ++step) {

        //loop to compare array elements
        for (int i = 0; i < size - step; ++i) {

            //compare two adjacent elements
            //change > to < to sort in descending order
            if (array[i] > array[i + 1]) {

                //swapping elements if elements
                //are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}*/
// optimized bubble sort
void bubbleSort(int array[], int size) {

    // loop to access each array element
    for (int step = 0; step < (size - 1); ++step) {

        // check if swapping occurs
        int swapped = 0;

        // loop to compare two elements
        for (int i = 0; i < (size - step - 1); ++i) {

            // compare two array elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]) {

                // swapping occurs if elements
                // are not in intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                swapped = 1;
            }
        }

        // no swapping means the array is already sorted
        // so no need of further comparison
        if (swapped == 0) {
            break;
        }
    }
}

void countSort(int array[], int size) {
    // The size of count must be at least the (max+1) but
    // we cannot assign declare it as int count(max+1) in C++ as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    int output[10];
    int count[10];
    int max = array[1];

    // Find the largest element of the array
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        printArray(array, 7);
        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {

            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }

        // put min at the correct position
        swap(&array[min_idx], &array[step]);
    }
}

// Function to get the largest element from an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
    const int max = 10;
    int output[10];
    int count[max];

    for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }

    // Calculate count of elements
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Main function to implement radix sort
void radixSort(int array[], int size) {
    // Get maximum element
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            printArray(array,size);
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

// Merge two sub arrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> L(n1);
    std::vector<int> M(n2);
    cout <<"\nL[i]: ";
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
        cout<<L[i]<<", ";
    }
    cout <<"\nM[i]: ";
    for (int j = 0; j < n2; j++) {
        M[j] = arr[q + 1 + j];
        cout<<M[j]<<", ";
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    cout<<endl;
    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        cout<<arr[k]<<", ";
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    cout <<"\nL[i]: ";
    while (i < n1) {
        cout<<L[i]<<", ";
        arr[k] = L[i];
        i++;
        k++;
    }
    cout <<"\nM[i]: ";
    while (j < n2) {
        cout<<M[j]<<", ";
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}