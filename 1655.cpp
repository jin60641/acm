#include<stdio.h>
int size = 0;
int h[100001];
int abs( int a ){
	return a<0?-a:a;
}
int min( int a, int b ){
	if( a == -10001 ){
		return b;
	} else if( b == -10001 ){
		return a;
	} else {
		return a<b?a:b;
	}
}
int cal( int a ){
	if( a <= 2 ){
		printf("cal %d : %d\n",h[a],abs(h[a]-h[1])+abs(h[a]-h[2]));
		return abs(h[a]-h[1])+abs(h[a]-h[2]);
	} else {
		printf("cal %d : %d\n",h[a],min( abs(h[a]-h[1])+abs(h[a]-h[0]), abs(h[a]-h[0])+abs(h[a]-h[2]) ));
		return min( abs(h[a]-h[1])+abs(h[a]-h[0]), abs(h[a]-h[0])+abs(h[a]-h[2]) );
	}
}
void swap(int a, int b){
	int tmp = h[a];
	h[a] = h[b];
	h[b] = tmp;
}
void up( int a ){
	if( a != 0 && cal(a) < cal((a-1)/2) ){
		swap(a, (a-1)/2);
		up((a-1)/2);
	} else if( a >= 3 && a <= 6 && cal(a) == cal((a-1)/2) && cal(0) > cal(a) ){
		swap(a, 0);
	}
}
void push( int a ){
	h[size] = a;
	up(size++);
}
int top(){
	return h[0];
}
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		h[i] = 10001;
	}
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		push(a);
		for(int j = 0; j < size; ++j ){
			printf("%d ",h[j]);
		}
		printf("\n");
		printf("%d\n",top());
	}
	return 0;
}
