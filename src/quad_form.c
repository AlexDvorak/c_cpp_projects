#include <stdio.h>
#include <math.h>
int a;
int b;
int c;
int main(){
	printf("Quadratic Formula Solver\n");
	while(1 == 1){
		printf("---------------------------\n");
		printf("A: ");
		scanf("%d",&a);
		printf("B: ");
		scanf("%d",&b);
		printf("C: ");
		scanf("%d",&c);
		// 2 solutions if >0
		// 1 solution if 0
		// 0 real solutions if <0
		long double discrminant = (b*b)+((0-4)*a*c);
		if(discrminant < 0.0){
			printf("No real solutions.\n");
		}else if(discrminant == 0){
			long double answer = -b/(2*a);
			printf("Solution:\nx = %Lf\n",answer);
		}else{
			long double ans0 = (-b + sqrt(discrminant))/(2*a);
			long double ans1 = (-b - sqrt(discrminant))/(2*a);
			printf("Solutions:\nx = %Lf, %Lf\n",ans0,ans1);
		}
	}
	return 0;
}
