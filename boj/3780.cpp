#include<stdio.h>

int weight[20001];
int check[20001];

int find(int a ){
	if( check[a] == a ){
		return a;
	}
	int tmp = find(check[a]);
	weight[a] = (weight[a] + weight[check[a]])%1000;
	check[a] = tmp;
	return check[a];
}

int abs(int a){
	return a<0?-a:a;
}

int Union( int a, int b ){
	int ra = find(a);
	int rb = find(b);
	if( ra == rb ){
		return 0;
	}
	// a가 센터가 아닐때 필요한 코드
	//check[ra] = a;
	//weight[ra] = weight[a];
	check[a] = rb;
	weight[a] = (abs(a-b) + weight[b]) % 1000;
	find(a); find(b);
	return 1;
}

int clear(){
	for( int i = 0; i <= 20000; ++i ){
		check[i] = i;
		weight[i] = 0;
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int N;
		scanf("%d",&N);
		clear();
		while( true ){
			char c = getchar();
			if( c == 'I' ){
				int A,B;
				scanf("%d %d",&A,&B);
				Union(A,B);
			} else if( c == 'E' ){
				int A;
				scanf("%d",&A);
				find(A);
				printf("%d\n",weight[A]);
			} else if( c == 'O' ){
				break;
			}
		}
	}
}
