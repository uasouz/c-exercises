#include <stdlib.h>
#include <memory.h>
#include "stdio.h"
#include "../sort_algorithms/quick_sort/quick_sort.h"

void findPair(int sum,int*array,int soa){
    for(int i=0;i < soa;i++) {
        for(int j=0;j < soa;j++) {
            if(j!=i){
                if(array[i]+array[j]==sum){
                    printf("Pair found at index %d and %d (%d + %d)\n",i,j,array[i],array[j]);
                    return;
                }
            }
        }
    }
    printf("Pair not found");
}

void findPairv2(int sum,int array[],int soa){
    int sortedArray[soa];
    memcpy(sortedArray,array, soa* sizeof(int));
    quickSort(sortedArray,0,soa-1);
    int low = 0;
    int high= soa-1;
    int pairsFound=0;

    while(low<high){
        if (sortedArray[low]+sortedArray[high] == sum){
            printf("Pair found at index %d and %d (%d + %d)\n",low,high,sortedArray[low],sortedArray[high]);
            pairsFound++;
        }

        if(sortedArray[low]+sortedArray[high] < sum){
            low++;
        } else {
            high--;
        }
    }
    if(pairsFound==0)
        printf("Pair not found");
}

void findPairv3(int sum,int array[],int soa){

}

void proccessArguments(int argc,char *argv[],int* sum,int* destination){
    int numbersArray[argc-1];
    char* stringMarker = "S";
    for(int i=0;i < argc-1;i++){
        char * arg = argv[i+1];
        if(strstr(arg,stringMarker)!=NULL){
            size_t length = strlen(arg) -1;
            if(length>0) {
                char sumValue[length];
                strncpy(sumValue, arg+1, length);
                if (sumValue != NULL) {
                    int svp = atoi(sumValue);
                    memcpy(sum, &svp, sizeof(svp));
                }
            }
        }else {
            numbersArray[i]=atoi(arg);
        }
    }
    memcpy(destination,numbersArray, sizeof(numbersArray));
}

int main(int argc,char *argv[]) {
    if (argc==1) {
        printf("no arguments");
        return 1;
    }

    int sum;
    int array [argc-2];
    proccessArguments(argc,argv,&sum,array);
    int soa = sizeof(array)/sizeof(int);
    findPairv2(sum,array,soa);
    return  0;
}

