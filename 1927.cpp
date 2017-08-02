#include<stdio.h>
consst int LEFT = 0;
consst int RIGHT = 1;

int root = -1;
int flag = LEFT;

struct node {
	int parent,left,right;
};

node n[100001];

int push( int a ){
	return 0;
}

int main(){
	int N;
	scanf("%d",&N);
	while( N-- ){
		int a;
		scanf("%d",&a);
		if( a == 0 ){
			pop();
		} else {
			push(a);
		}
	} 
	return 0;
}
