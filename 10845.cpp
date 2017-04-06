#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

int q[30000];

int back = 15000;
int front = back;
int empty(){
	for( int i = front; i < back; ++i ){
		if( q[i] != 0 ){
			return 0;
		}
	}
	return 1;
}

int main(){
	int N;
	int num;
	char str[100];
	scanf("%d",&N);
	for( int i = 0; i < 30000; ++i ){
		q[i] = 0;
	}
	for( int i = 0; i < N; ++i ){
		scanf("%s",str);
		if( strcmp("push",str) == 0 ){
			scanf("%d",&num);
			q[back] = num;
			back++;
		} else if( strcmp("front",str) == 0 ){
			if(empty()){
				printf("-1\n");
			} else {
				printf("%d\n",q[front]);
			}
		} else if( strcmp("size",str) == 0 ){
			printf("%d\n",back-front);
		} else if( strcmp("empty",str) == 0 ){
			printf("%d\n",empty());
		} else if( strcmp("pop",str) == 0 ){
			if(empty()){
				printf("-1\n");
			} else {
				printf("%d\n",q[front]);
				q[front] = 0;
				front++;
			}
		} else if( strcmp("back",str) == 0 ){
			if(empty()){
				printf("-1\n");
			} else {
				printf("%d\n",q[back-1]);
			}
		}
	}
}
