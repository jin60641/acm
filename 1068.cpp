#include<stdio.h>

int tree[50];
int N,cnt;

int removeNode(int r){
	tree[r] = -2;
	cnt--;
	for( int i = 0; i < N; ++i ){
		if( tree[i] == r ){
			removeNode(i);
		}
	}
	return 0;
}

int main(){
	int R;
	scanf("%d",&N);
	cnt = N;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&tree[i]);
	}
	scanf("%d",&R);
	removeNode(R);
	for( int i = 0; i < N; ++i ){
		if( tree[i] == -2 ){
			continue;
		}
		for( int j = 0; j < N; ++j ){
			if( tree[j] == i ){
				cnt--;
				break;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
