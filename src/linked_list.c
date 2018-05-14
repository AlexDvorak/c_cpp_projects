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
void insert(struct node *to_insert,struct node *before,struct node *after){
	*before->next = *to_insert;
	*to_insert->next = *after;
}
void prepend(struct node *head,struct node *to_prepend){
	*to_prepend->next = *head;
}
void traverse(struct node *head){
	struct node next_up = *head;
	while(1==1){
		printf("%d ", *next_up.val);
		if(!*next_up.next){
			break;
		}
	}
	printf("\n");
}
int main(){
	struct node head = create(10);
	struct node body_0 = create(1);
	struct node middle = create(5);
	append(&body_0,&head);
	insert(&middle,&head,&body_0);
	printf("%d\n",head.next->val);
	traverse(&head);
}
