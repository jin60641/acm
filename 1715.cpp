#include<stdio.h>
int v[100001];
int size = 0;
int swap( int a, int b ){
	int tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
	return 0;
}
int down( int a ){
	if( size <= a*2 ){
		return 0;
	} else if( ( size == a*2+1 || v[a*2+1] < v[a*2+2] ) && ( v[a*2+1] < v[a] ) ){
		swap(a*2+1, a);
		down(a*2+1);
	} else if( size >= a*2+2 && v[a*2+2] < v[a] ){
		swap(a*2+2, a);
		down(a*2+2);
	}
	return 0;
}
int up( int a ){
	if( a == 0 ){
		return 0;
	} else if( v[a] < v[(a-1)/2] ){
		swap(a, (a-1)/2);
		up((a-1)/2);
	}
	return 0;
}
int push( int a ){
	v[size++] = a;
	up(size-1);
	return 0;
}
int pop(){
	if( size == 0 ){
		return 0;
	}
	int ret = v[0];
	v[0] = v[--size];
	down(0);
	return ret;
}

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		push(a);
	}
	int result = 0;
	while( size != 0 ){
		int a = pop();
		int b = pop();
		if( a != 0 && b != 0 ){
			result += a+b;
			push(a+b);
		}
	}
	printf("%d\n",result);
	return 0;
}

