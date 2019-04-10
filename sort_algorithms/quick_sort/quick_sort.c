//
// Created by hadara on 4/10/19.
//
#include <stdlib.h>
#include "stdio.h"

void swap(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

void swapInt(int *first, int *second) {
    int temp = *second;
    *second = *first;
    *first = temp;
}

void swapArrayItems(int arr[], int first, int second) {
    int *temp = &arr[first];
    arr[first] = arr[second];
    arr[second] = *temp;
}

int HoarePartitionSchemeTry1(int *arr, int low, int high, int pivot) {
//    int left = low -1;
//    int right = high + 1;
    while (low <= high) {
        while (arr[low] < pivot) {
            low++;
        }
        while (arr[high] > pivot) {
            high--;
        }
        if (low <= high) {
            swapInt(&arr[low], &arr[high]);
            low++;
            high--;
        }
        return low;
    }
    return low;
}

int HoarePartitionScheme(int arr[], int low, int high) {
    int pivot = arr[(low + high) / 2];
    int left = low - 1;
    int right = high + 1;
    while (1) {
        do {
            left++;
        } while (arr[left] < pivot);
        do {
            right--;
        } while (arr[right] > pivot);

        if (left >= right)
            return right;

        swapInt(&arr[left], &arr[right]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low >= high)
        return;
    int pivot = arr[(low + high) / 2];
    int part = HoarePartitionScheme(arr, low, high);
    printf("\n%d\n", part);
    quickSort(arr, low, part);
    quickSort(arr, part+1, high);
}

int main(int argc, char *argv[]) {
    int startArr[] = {1, 123, 3, 51, 5, 546, 7, 12, 382, 11};
    int arrLength = sizeof(startArr) / sizeof(int);
    printf("length = %d\n", arrLength);
    quickSort(startArr, 0, arrLength - 1);
    for (int k = 0; k < arrLength; k++) {
        printf(" %d ", startArr[k]);
    }
}