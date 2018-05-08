#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node *next;
	int val;
};
struct node create(int value){
	struct node a;
	a.next = malloc(sizeof(struct node));
	a.val = value;
	return a;
}
void append(struct node *that,struct node *to_that){
	*to_that->next = *that;
}
int main(){
	struct node head = create(10);
	struct node body_0 = create(1);
	append(&body_0,&head);
	printf("%d\n",head.next->val);
}
