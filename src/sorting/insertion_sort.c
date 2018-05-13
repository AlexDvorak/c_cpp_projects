#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
int n = 11;
int arr[11];
void swp(int *elem0,int *elem1){
	int temp = *elem0;
	*elem0 = *elem1;
	*elem1 = temp;
}
int main(){
	// fill array randomly
	srand(time(NULL));
	for(int i = 0;i < n;i++){
		arr[i] = rand()%n;
	}
	// actual algorithm
	for(int elem = 0;elem<n;elem++){
		int temp_elem = elem;
		for(int swpper = temp_elem-1;arr[swpper]>arr[temp_elem];swpper--){
			if(arr[swpper]>arr[elem]){
				swp(&arr[swpper], &arr[elem])
			}
			temp_elem--;
	}
	// print out array
	for(int k = 0;k < n;k++){
		printf("%d ", arr[k]);
	}
	printf("\n");
}
