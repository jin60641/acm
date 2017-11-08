#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
	int N,a,b;
	int d=2000000002;
	int A[100001];
	scanf("%d",&N);
	int left = 0;
	int right = N-1;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	while(left<right){
		int ta,tb;
		ta = A[left];
		tb = A[right];
		if( abs(ta+tb) < d ){
			a = ta;
			b = tb;
			d = abs(a+b);
			if( d == 0 ){
				break;
			}
		}
		if( ta+tb < 0 ){	
			left++;
		} else if( ta+tb > 0 ){
			right--;
		}
	}
	printf("%d %d\n",a,b);
	return 0;
}
