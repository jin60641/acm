#include<stdio.h>
const int MAX_N = 100000;
int N = MAX_N;
int arr[MAX_N];
int checked[MAX_N];
int target;
int cnt;
int clearArr(){
	for( int i = 0; i < N; ++i ){
		arr[i] = -1;
		checked[i] = -1;
	}
	return 0;
}

int search(int index,int depth,int j){
	printf("cnt : %d / index : %d / arr[index] : %d / depth : %d\n",cnt,index+1,arr[index]+1,depth);
	if( index == target ){
		printf("TARGET\n");
		cnt -= depth;
		return -1;
	} else if( checked[index] != -1 ){
		if( checked[index] == j ){
			return index;
		} else {
			return -1;
		}
	} else {
		checked[index] = j;
		int a = search(arr[index],depth+1,j);
		printf("cnt : %d / a : %d / index : %d\n",cnt,a+1,index+1);
		if( a == -1 ) {
			return -1;
		} else {
			cnt--;
			if( a == index ){
				return -1;
			} else {
				return a;
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for( int i = 0; i < T; ++i ){
		clearArr();
		scanf("%d",&N);
		cnt = N;
		for( int j = 0; j < N; ++j ){
			int num;
			scanf("%d",&num);
			arr[j] = num-1; 
		}
		for( int j = 0; j < N; ++j ){
			printf("j : %d\n",j+1);
			if( checked[j] == -1 ){
				checked[j] = j;
				target = j;
				search(arr[j],1,j);
			}
		}
		printf("!!cnt : %d\n",cnt);
	}
	return 0;
}
