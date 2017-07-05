#include<stdio.h>

int N;
int p[200][200];
int cnt_zero = 0;
int cnt_plus = 0;

int cut( int left, int top, int size ){
	for( int i = left; i < left+size; ++i ){
		for( int j = top; j < top+size; ++j ){
			if( p[i][j] != p[left][top] ){
				int s = size/2;
				cut(left,top,s);		cut(left+s,top,s);	
				cut(left,top+s,s);		cut(left+s,top+s,s);
				return 0;
			}
		}
	}
	switch(p[left][top]){
		case 0:
			cnt_zero += 1;
			break;
		case 1:
			cnt_plus += 1;
			break;
	}
	return 0;
}

int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&p[i][j]);
		}
	}
	cut(0,0,N);
	
	printf("%d\n",cnt_zero);
	printf("%d\n",cnt_plus);
	return 0;
}
