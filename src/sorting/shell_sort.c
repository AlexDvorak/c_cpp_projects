#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
float n=11;
int arr[11];
int main(){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		arr[i] = rand()%n;
	}
}
