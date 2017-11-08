#include<stdio.h>
#include<stdlib.h>
#include<vector>
struct node{
	node* next;
	int data;
};
void remove(node* curr){
	printf("%d",(curr->next)->data);
	curr->next = (curr->next)->next;
}
int main(){
	int N, M, cnt = 0;
	scanf("%d %d",&N,&M);
	node* head = (node*)malloc(sizeof(node));
	head->data = 1;
	node* curr = head;
	for( int i = 2; i <= N; ++i ){
		node* n = (node*)malloc(sizeof(node));
		curr->next = n;
		n->data = i;
		curr = n;
	}
	curr->next = head;
	printf("<");
	while(cnt < N){
		for( int i = 1; i < M; ++i ) curr = curr->next;
		remove(curr);
		++cnt;
		if( cnt != N ) printf(", ");
	}
	printf(">");
	return 0;
}
