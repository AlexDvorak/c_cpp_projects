#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
int order[] = {1,32,4,3,56,16,78,35};
int order_len = 8;
void swp(int *ob0,int *ob1){
	int temp = *ob1;
	*ob1 = *ob0;
	*ob0 = temp;
}
bool swpped;
int stop_from = 0;
int main(){
	while(stop_from<order_len){
		swpped = false;
		for(int i=0;i<order_len-(stop_from+1);i++){
			if(order[i]>order[i+1]){
				swpped = true;
				swp(&order[i],&order[i+1]);
				for(int j=0;j<order_len;j++){
					printf("%d ",order[j]);}
				printf("\n");
			}
		}
		stop_from++;
		if(!swpped){
			break;
		}
	}
}
