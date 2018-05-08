#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int order[] = {6,5,3,1,8,7,2,4};
int order_len = 8;
int gap;
float shrink = 1.3;
bool sorted = false;

void swp(int *ob0,int *ob1){
	int temp = *ob0;
	*ob0 = *ob1;
	*ob1 = temp;
}

int main(){
	gap = order_len;
	while(!sorted){
		gap = floor(gap/shrink);
		if(gap>1){
			sorted = false;
		}else{
			gap = 1;
			sorted = true;
		}
		for(int i=0;i+gap<order_len;i++){
			if(order[i]>order[i+gap]){
				swp(&order[i],&order[i+gap]);
				sorted=false;
			}
		}
	}
	for(int k=0;k<order_len;k++){printf("%d ",order[k]);}printf("\n");
}
