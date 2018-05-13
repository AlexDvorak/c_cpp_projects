#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
int n = 11;
int arr[11];
int main(){
	srand(time(NULL));
	for(int i = 0;i < n;i++){
		arr[i] = rand()%n;
	}
	int i,j,min_indx,tmp;
	for(i = 0;i < n;i++){
		min_indx = i;
		for(j = i+1;j < n;j++){
			if(arr[j] < arr[min_indx]){
				min_indx = j;
			}
		}
		if(min_indx != i){
			tmp = arr[i];
			arr[i] = arr[min_indx];
			arr[min_indx] = tmp;
		}
	}
	// print out array
	for(int k = 0;k < n;k++){
		printf("%d ", arr[k]);
	}
	printf("\n");
}
