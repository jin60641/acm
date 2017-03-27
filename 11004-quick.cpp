#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N, K; 
int A[5000001];

int swap(int, int); 

int cut(int left,int pivot){ 
	if( left == pivot ){
		return 0;
	}
	int right = pivot-1;
	int i = left; 
	int j = right;

/*	
	for( int k = left; k <= pivot; ++k ){
		printf("%d ",A[k]);
	}
	printf("\nleft : %d / pivot : %d\n",left,pivot);
*/
	
	while( i <= j ){
		if( i == j ){
			if( A[i] > A[pivot] ){
				swap(i,pivot);
			}
			if( left <= K && K <= i-1 ){
				cut(left,i-1);
			} else if( i+1 <= K && K <= pivot ){
				cut(i+1,pivot);
			}
		}
		if( A[i] > A[pivot] ){
			if( A[j] < A[pivot] ){
				swap(i,j);
			} else {
				--j;
			}
		} else {
			++i;
		}
	}
}

int swap(int left,int right){
/*
	for( int k = left; k <= right; ++k ){
		printf("%d ",A[k]);
	}
	printf("\nswap!! left : %d / right : %d\n",left,right);
*/
	int tmp = A[left];
	A[left] = A[right];
	A[right] = tmp;
/*
	for( int k = left; k <= right; ++k ){
		printf("%d ",A[k]);
	}
	printf("\n");
*/
	return 0;
}

int main(){
	scanf("%d %d",&N,&K);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	
	cut(0,N-1);
	printf("%d",A[K-1]);
	return 0;
}
