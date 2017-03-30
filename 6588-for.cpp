#include<stdio.h>
using namespace std;
int main(){
	int A[1000010] = {0,};
	int P[1000010];
	int cnt = 0;
	int a,b,left,right,n;
	for( int j = 1; j < 1000000; ++j ){
		if(A[j] == 1){
			continue;
		}
		int Amin = A[j];
		P[cnt] = Amin;
		cnt++;
		for( int i = j; i*i < 1000000; i += Amin ){
			if( j == i ){
				continue;
			} else if( A[i] == 1 ){
				continue;
			} else {
				A[i] = 1;
			}
		}	
	}
	while(true){
		scanf("%d",&n);
		if( n == 0 ){
			break;
		}
		left = 0;
		right = cnt-1;
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
	}
	return 0;
}

