#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	node* next;
	node* prev;
	char c;
};
node* head = (node*)calloc(1,sizeof(node));
node* cursor = head;

void add(char c){
	node *n = (node*)calloc(1,sizeof(node));
	n->c = c;
	n->prev = cursor;
	if( cursor->next ){
		n->next = cursor->next;
		(cursor->next)->prev = n;
	}
	cursor->next = n;
	cursor = n;
}

int del(){
	if( cursor != head ){
		if( cursor->next ){
			(cursor->next)->prev = cursor->prev;
			(cursor->prev)->next = cursor->next;
		} else {
			(cursor->prev)->next = NULL;
		}
		cursor = cursor->prev;
	}
}

void left(){
	if( cursor->prev ){
		cursor = cursor->prev;
	}
}

void right(){
	if( cursor->next ){
		cursor = cursor->next;
	}
}

void print(){
	node* cur = head->next;
	while( cur ){
		printf("%c",cur->c);
		cur = cur->next;
		if( !cur ){
			break;
		}
	}
	printf("\n");
}
int main(){
	char s[100001];
	scanf("%s",s);
	int N;
	scanf("%d",&N);
	int len = strlen(s);
	for( int i = 0; i < len; ++i ){
		add(s[i]);
	}

	for( int i = 0; i < N; ++i ){
		char c;
		scanf(" %c",&c);
		switch(c){
			case 'L' : // Left
				left();
				break;
			case 'D' : // right
				right();
				break;
			case 'B' : //delete
				del();
				break;
			case 'P' : //add
				char nc;
				scanf(" %c",&nc);
				add(nc);
				break;
			case 'T' : //print all
				print();
				break;
		}
	}
	print();
	return 0;
}

