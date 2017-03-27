#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
	int N,a,b,c;
	int d=2000000002;
	int A[5001];
	scanf("%d",&N);
	int left = 0;
	int right = N-1;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	for( int i = 0; i < N-2; ++i ){
		left = i+1;
		right = N-1;
		int tc = A[i];
		while(left<right){
			int ta = A[left];
			int tb = A[right];
			if( abs(ta+tb+tc) < d ){
				a = ta;
				b = tb;
				c = tc;
				d = abs(a+b+c);
				break;
			}
			if( ta+tb < tc ){	
				left++;
			} else if( ta+tb > tc ){
				right--;
			}
		}
		if( d == 0 ){
			break;
		}
	}
	int R[3] = {a,b,c};
	sort(R,R+3);
	printf("%d %d %d\n",R[0],R[1],R[2]);
	return 0;
}
