#include<stdio.h>

int edge[500000];
int weight[500000];
int tmp[100000];

int main(){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	
	for( int i = 0; i < 500000; ++i ){
		edge[i] = -1;
	}

	for( int i = 0; i < N; ++i ){
		int start, end;
		scanf("%d %d",&start,&end);
		edge[start] = end;
		tmp[i] = start;
		for( int j = 0; j < i; ++j ){
			if( edge[tmp[j]] == -1 || start == j ){
				continue;
			} else if( ( j > start && edge[tmp[j]] < end ) || ( j < start && edge[tmp[j]] > end ) ){
				weight[i]++;
				weight[tmp[j]]++;
				cnt+=2;
			}
		}
	}
	while( cnt != 0 ){
		int max = -1;
		int max_index;
		for( int i = 0; i < N; ++i ){
			if( weight[tmp[i]] > max ){
				max = weight[tmp[i]];
				max_index = tmp[i];
			}
		}
		for( int i = max_index+1; 
		break;
	}
	return 0;
}
