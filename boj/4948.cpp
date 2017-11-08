#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
	int last = 123456*2;
	int *A;
	A = (int*)malloc(sizeof(int)*(last+10));
	int *P;
	P = (int*)malloc(sizeof(int)*(last+10));
	int cnt = 0;
	int n;
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
	while(true){
		scanf("%d",&n);
		if( n == 0 ){
			break;
		}
		
		int flag = 0;
		int result = 0;
		for( int i = 0; i < cnt; ++i ){
			if( P[i] > n  ){
				if( P[i] > 2*n ){
					printf("%d\n",result);
					break;
				} else {
					++result;
				}
			}
		}
	}
	return 0;
}

