//
// Created by kaloyyyyy on 27/04/2022.
//

#ifndef GROUPREPORTING_SORT_H
#define GROUPREPORTING_SORT_H


void sort();
void printArray(int data[], int size);

void bubbleSort(int data[], int size);

void countSort(int array[], int size);

void quickSort(int array[], int low, int high);

int partition(int array[], int low, int high);
void selectionSort(int array[], int size);

void radixSort(int array[], int size);

void countingSort(int array[], int size, int place);

void insertionSort(int array[], int size);

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int p, int q, int r);

int getMax(int array[], int n);
void swap(int *a, int *b);
#endif //GROUPREPORTING_SORT_H
