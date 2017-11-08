#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main(){
	int *A;
	A = (int*)malloc(sizeof(int)*10000010);
	int P[1000000];
	int cnt = 0;
	int n;
	for( int i = 0; i < 10000000-2; ++i ){
		if(A[i] == 1){
			continue;
		}
		int Amin = i+2;
		P[cnt] = Amin;
		cnt++;
		for( long long int j = (long long int)Amin*(long long int)Amin; j < 10000000; j += Amin ){
			A[j-2] = 1;
		}	
	}

	scanf("%d",&n);
	while(n!=1){
		for( int i = 0; i < cnt; ++i ){
			if( n%P[i] == 0 ){
				printf("%d\n",P[i]);
				n/=P[i];
				break;
			}
		}
	}
	return 0;
}

