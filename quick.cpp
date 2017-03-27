#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N; 
int A[1000001];

int swap(int, int); 

int cut(int left,int pivot){ 
	if( left == pivot ){
		return 0;
	}
	int right = pivot-1;
	int i = left; 
	int j = right;
	while( i != j ){
		if( A[i] > A[pivot] ){
			if( A[j] < A[pivot] ){
				swap(i,j);
				cut(left,i);
				cut(i+1,pivot);
			} else {
				--j;
			}
		} else {
			++i;
		}
		if( i == j ){
			if( A[i] > A[pivot] ){
				swap(i,pivot);
			}
		}
	}
}

int swap(int left,int right){
	int tmp = A[left];
	A[left] = A[right];
	A[right] = tmp;
	return 0;
}

int main(){
	int a;
	scanf("%d %d",&N,&a);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	
	cut(0,N-1);
	printf("%d",A[a]);
	return 0;
}
