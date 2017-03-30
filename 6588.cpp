#include<stdio.h>
using namespace std;
int main(){
	int A[1000010] = {0,};
	int P[1000010];
	int cnt = 0;
	int a,b,left,right,n;
	for( int i = 0; i < 1000000-2; ++i ){
		if(A[i] == 1){
			continue;
		}
		int Amin = i+2;
		P[cnt] = Amin;
		cnt++;
		for( long long int j = (long long int)Amin*(long long int)Amin; j < 1000000; j += Amin ){
			A[j-2] = 1;
		}	
	}

	while(true){
		scanf("%d",&n);
		if( n == 0 ){
			break;
		}
		left = 0;
		right = cnt-1;
		if( n <= P[cnt/4]+P[0] ){
			right = cnt/4;
		} else if( n <= P[cnt/2]+P[0] ){
			right = cnt/2;
		}
		while(left<=right){
			a = P[left];
			b = P[right];
			if( a+b == n ){
				printf("%d = %d + %d\n",n,a,b);
				break;
			} else if( a + b > n ){
				right--;
			} else {
				left++;
			}
		}
		if( left-1 == right ){
			printf("Goldbach's conjecture is wrong.\n");
		}
	}
	return 0;
}

