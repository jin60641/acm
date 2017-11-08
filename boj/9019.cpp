#include<stdio.h>
#define MAX_N 10000
using namespace std;

int index, back_index, print_index, target;
char result[MAX_N];
int q[MAX_N];
int check[MAX_N] = {0,};
int parent[MAX_N];

int clearQueue(){
	for( int i = print_index-1; i >= 0; --i ){
		printf("%c",result[i]);
	}
	printf("\n");
	for( int i = 0; i < back_index; ++i ){
		q[i] = 0;
	}
	for( int i = 0; i < MAX_N; ++i){
		check[i] = 0;
	}
	for( int i = 0; i < MAX_N; ++i){
		parent[i] = 0;
	}
	index = 0;
	back_index = 0;
}


int push( int num, int p ){
	q[back_index] = num;
	parent[num] = p;
	back_index++;
	return num;
}

int D(int num){
	return (num*2)%10000;
}
int S(int num){
	return num==0?9999:num-1;
}
int L(int num){
	return num/1000*1 + (num%1000)/100*1000 + (num%100)/10*100 + (num%10)/1*10;
}
int R(int num){
	return num/1000*100 + (num%1000)/100*10 + (num%100)/10*1 + (num%10)/1*1000;
}

int printParent(int num){
	int p = parent[num];
	if( p == -1 ){
		clearQueue();
		return 0;
	}
	char C;
	if( D(p) == num ){
		C = 'D';
	} else if( S(p) == num ){
		C = 'S';
	} else if( L(p) == num ){
		C = 'L';
	} else if( R(p) == num ){
		C = 'R';
	}
	result[print_index++] = C;
	printParent(p);
}

int bfs(){
	int back = q[index];
	int d = D(back);
	int s = S(back);
	int l = L(back);
	int r = R(back);
	check[back] = 1;
	if( check[d] != 1 ){
		check[push(d,back)] = 1;
	}
	if( check[s] != 1 ){
		check[push(s,back)] = 1;
	}
	if( check[l] != 1 ){
		check[push(l,back)] = 1;
	}
	if( check[r] != 1 ){
		check[push(r,back)] = 1;
	}
	if( d == target ){
		printParent(d);
		return 0;
	} else if( s == target ){
		printParent(s);
		return 0;
	} else if( l == target ){
		printParent(l);
		return 0;
	} else if( r == target ){
		printParent(r);
		return 0;
	}

	index++;
	bfs();
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	for( int i = 0; i < T; ++i ){
		int start;
		scanf("%d %d",&start,&target);
		push(start,-1);
		print_index = 0;
		bfs();
	}
	return 0;
}

