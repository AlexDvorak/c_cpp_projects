#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


/* the aim of the partition is to return the subscript of the exact */
/* position of the pivot when it is sorted */
// the low variable is used to point to the position of the next lowest element
int partition(int arr[], int first, int last){
    int pivot = arr[last]; // changed the pivot
    int low = first;
    int i = first; // changed
    while(i <= last-1 ){// or you can do for(i=first;i<last;i++)
        if(arr[i] < pivot){
            swap(&arr[i], &arr[low]);
            low++;
        }
        i++;
    }
    swap(&arr[last], &arr[low]);
    // after finishing putting all the lower element than the pivot
    // It's time to put the pivot into its place and return its position
    return low;
}



void quick_sort(int arr[], int first, int last){
    int pivot_pos;
    if(first < last){
        pivot_pos = partition(arr, first, last);
        quick_sort(arr, first, pivot_pos-1);
        quick_sort(arr, pivot_pos+1, last);
    }
}

int main(int argc, char *argv[]){
    int tab[]={4,53,5,6,7,1};
    quick_sort(tab,0,5);
    int i=0;
    for (i=0;i<6;i++)
    {
        printf(" %d ",tab[i]);
    }
    printf("\n");

    return 0;
}
