#include <iostream>

using namespace std;
void swap(int *a, int *);
void printArray(int array[], int size, int numSwap);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);

int main() {
    int data[] = {5, 6, 8, 7, 9, 2, 3, 1};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "selection sort:\n";
    printArray(data, size, 0);
    selectionSort(data, size);
    int data2[] = {5, 6, 8, 7, 9, 2, 3, 1};
    cout << "\ninsertion sort:\n";
    printArray(data2, size, 0);
    insertionSort(data2, size);
}

// function to swap the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to print an array
void printArray(int array[], int size, int numSwap) {
    cout << "swap #" << numSwap << " : ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size) {
    int numSwap = 0;
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
        numSwap++;
        printArray(array, size, numSwap);

    }
}

void insertionSort(int array[], int size) {
    int numSwap = 0;
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
        numSwap++;
        printArray(array, size, numSwap);
    }
}
