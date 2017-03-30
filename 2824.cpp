#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	long long int last = 1000000000;
	int *A;
	A = (int*)malloc(sizeof(int)*(last+10));
	int *P;
	P = (int*)malloc(sizeof(int)*(last+10));
	int cnt = 0;
	for( int i = 0; i < last-2; ++i ){
		if(A[i] == 1){
			continue;
		}
		int Amin = i+2;
		P[cnt] = Amin;
		cnt++;
		for( long long int j = (long long int)Amin*(long long int)Amin; j < last; j += Amin ){
			A[j-2] = 1;
		}	
	}

	int N, M;
	int *np;
	int result = 1;
	np = (int*)malloc(sizeof(int)*(last+10));
	scanf("%d",&N);
	
	for( int i = 0; i < N; ++i ){
		int n;
		scanf("%d",&n);
		while(n!=1){
			for( int i = 0; i < cnt; ++i ){
				if( n%P[i] == 0 ){
					np[P[i]-1]++;
					n/=P[i];
					break;
				}
			}
		}
	}
	scanf("%d",&M);

	for( int i = 0; i < M; ++i ){
		int n;
		scanf("%d",&n);
		while(n!=1){
			for( int i = 0; i < cnt; ++i ){
				if( n%P[i] == 0 ){
					if( np[P[i]-1] >= 1 ){
						np[P[i]-1]--;
						result*=P[i];
					}
					n/=P[i];
					break;
				}
			}
		}
	}
	printf("%d\n",result);
	return 0;
}

