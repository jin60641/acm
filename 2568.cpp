#include<stdio.h>
#include<algorithm>
using namespace std;


struct weight {
	int index;
	int value;
};


bool cmp(weight a, weight b) { return a.value>b.value; }

int edge[500000];

int main(){
	struct weight w[500000];
	int N;
	scanf("%d",&N);
	int cnt = 0;
	
	for( int i = 0; i < 500000; ++i ){
		w[i].index = i;
		edge[i] = -1;
	}

	for( int i = 0; i < N; ++i ){
		int start, end;
		scanf("%d %d",&start,&end);
		edge[start] = end;
		for( int j = 0; j < N; ++j ){
			if( start == j ){
				continue;
			} else if( ( j > start && edge[j] < end ) || ( j < start && edge[j] > end ) ){
				w[i].value++;
				w[j].value++;
				cnt+=2;
			}
		}
	}
	/*
	printf("\n");
	for( int i = 0; i < N; ++i ){
		printf("%d ",w[i].index);
	}
	printf("\n");
	for( int i = 0; i < N; ++i ){
		printf("%d ",w[i].value);
	}
	printf("\n");
	*/
	sort(w,w+N,cmp);
	/*
	for( int i = 0; i < N; ++i ){
		printf("%d ",w[i].index);
	}
	printf("\n");
	for( int i = 0; i < N; ++i ){
		printf("%d ",w[i].value);
	}
	printf("\n");
	*/
	printf("%d",cnt);
	int index = 0;
	while( cnt != 0 ){
		for( int i = 0; i < ; ++i ){
		}
	}
	
	return 0;
}
