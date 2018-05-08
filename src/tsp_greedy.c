#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
// Structures
struct city{
	float x;
	float y;
};
// Utility Functions
struct city make_city(float x,float y){
	struct city a;
	a.x = x;
	a.y = y;
	return a;
}
float dist(struct city c0, struct city c1){
	return sqrt( ((c1.x-c0.x)*(c1.x-c0.x)) + ((c1.y-c0.y)*(c1.y-c0.y)));
}
void swp_cit(struct city *a,struct city *b){
	struct city temp = *a;
	*a = *b;
	*b = temp;
}
float sum_dist(struct city cities[],int order[],int len){
	float sum = 0;
	for(int i=0;i<len-2;i++){
		sum+=dist(cities[i],cities[i+1]);
	}
	return sum;
}
void swp_int(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int rand_int(int max){
	return rand()%max;
}
// Global Variables
int num_cit = 5;
struct city cities[5];
int order[5];
int main(){
	// Setup
	for(int i=0;i<num_cit;i++){
		cities[i] = make_city(rand_int(10),rand_int(10));
		order[i] = i;
	}
	// Greedy Algorithm
	/*int decided = 0;
	int best;
	int best_cit;
	for(int i=0;i<num_cit;i++){
		best=99999;
		for(int j=0;j<num_cit;j++){
			if(j==decided){
				continue;
			}else if(dist(cities[order[j]],cities[order[decided]])<best){
				best = dist(cities[order[j]],cities[order[decided]]);
				best_cit = j;
			}
		}
		decided = best_cit;
		swp(&order[decided],&order[i]);
	}*/
	// 2-Opt Swap
	for(int k=0;k<num_cit;k++){printf("%f %f\n",cities[k].x,cities[k].y);}
	float curr_dist;
	bool swpped = false;
	while(1==1){
		swpped = false;
		for(int i=0;i<num_cit;i++){
			for(int j=0;j<num_cit;j++){
				curr_dist =  sum_dist(cities,order,num_cit);
				if(i==j){
					continue;
				}
				swp_cit(&cities[order[i]],&cities[order[j]]);
				if(sum_dist(cities,order,num_cit)<curr_dist){
					printf("%d %d %d %d %d\n",order[0],order[1],order[2],order[3],order[4]);
					printf("%f\n",sum_dist(cities,order,num_cit));
					swpped = true;
					continue;
				}else{
					swp_cit(&cities[order[i]],&cities[order[j]]);
					swp_int(&order[i],&order[j]);
				}
			}
		}
		if(!swpped){
			break;
		}
	}
	printf("%d %d %d %d %d\n",order[0],order[1],order[2],order[3],order[4]);
}
