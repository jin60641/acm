#include<stdio.h>
using namespace std;

int main(){
	int A[1000010];
	int index[1000010];
	int cnt = 0;
	int a,b,left,right,n;
	int d = 2000000002;
	for( int i = 0; i < 1000000; ++i ){
		A[i] = i+1;
	}
	for( int j = 1; j < 1000000; ++j ){
		if(A[j] == 0){
			continue;
		}
		int Amin = A[j];
		P[cnt] = j;
		cnt++;
		for( int i = j; i < 1000000; i += Amin ){
			if( j == i ){
				continue;
			} else if( A[i] == 0 ){
				continue;
			} else {
				A[i] = 0;
			}
		}	
	}
	while(n!=0){
		left = 0;
		right = cnt-1:;
		while(left<right){
			a = P[left];
			b = P[right];
			if( a+b == n ){
				printf("%d = %d + %d\n",n,a,b);
				break;
			} else if( a + b > n ){
				right--;
			} else { // if (a + b) < n {
				left++;
			}
		}
		if( left >= right ){
			printf("Goldbach's conjecture is wrong.\n");
		}
		scanf("%d",&n);
	}
	return 0;
}

