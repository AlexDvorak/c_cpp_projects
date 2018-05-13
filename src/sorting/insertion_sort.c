#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
int n = 11;
int arr[11];
int main(){
	// fill array randomly
	srand(time(NULL));
	for(int i = 0;i < n;i++){
		arr[i] = rand()%n;
	}
	// actual algorithm
	int i,j,new_val;
	for(i = 1;i < n;i++){
		new_val = arr[i];
		j = i;
		while(j > 0 && arr[j-1] > new_val){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = new_val;
	}
	// print out array
	for(int k = 0;k < n;k++){
		printf("%d ", arr[k]);
	}
	printf("\n");
}
