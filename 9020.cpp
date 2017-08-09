#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int A[10010] = {0,};
	int P[10010];
	int cnt = 0;
	int a,b,left,right,n;
	for( int i = 0; i < 10000-2; ++i ){
		if(A[i] == 1){
			continue;
		}
		int Amin = i+2;
		P[cnt] = Amin;
		cnt++;
		for( long long int j = (long long int)Amin*(long long int)Amin; j < 10001; j += Amin ){
			A[j-2] = 1;
		}	
	}
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int n;
		scanf("%d",&n);
		left = 0;
		right = cnt-1;
		if( n <= P[cnt/4]+P[0] ){
			right = cnt/4;
		} else if( n <= P[cnt/2]+P[0] ){
			right = cnt/2;
		}
		int result[2] = { -5000, -10 };
		while(left<=right){
			a = P[left];
			b = P[right];
			if( a+b == n && result[1] - result[0] > b - a ){
				result[1] = b;
				result[0] = a;
				right--;
			} else if( a + b > n ){
				right--;
			} else {
				left++;
			}
		}
		if( left-1 == right ){
			printf("%d %d\n",result[0],result[1]);
		}
	}
	return 0;
}

