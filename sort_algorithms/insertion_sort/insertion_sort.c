#include "stdio.h"

//Insertion sort naive approach
void naiveInsertionSort(int arrLength, int *arr){
    int i = 1;
    while(i < arrLength){
        int j = i;
        while(j >0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j = j -1;
        }
        i++;
    }
}

int main(int argc,char *argv[]){
    int startArr[] = {1,123,3,51,5,546,7,12,382,11};
    int arrLength = sizeof(startArr)/ sizeof(int);
    printf("length = %d\n",arrLength);
    naiveInsertionSort(arrLength, startArr);
    for(int k=0;k < arrLength;k++) {
        printf(" %d ",startArr[k]);
    }
}