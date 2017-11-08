#include<stdio.h>
int first = -1;
int printLetter(int num){
	switch(num){
		case 0:
			printf("R");
			break;
		case 1:
			printf("O");
			break;
		case 2:
			printf("Y");
			break;
		case 3:
			printf("G");
			break;
		case 4:
			printf("B");
			break;
		case 5:
			printf("V");
			break;
	}
	return 0;
}
int search(int N, int R, int O, int Y, int G, int B, int V,int c){
	int C[6];
	C[0] = R;
	C[1] = O;
	C[2] = Y;
	C[3] = G;
	C[4] = B;
	C[5] = V;
	printf("\n %d : ",N);
	for( int i = 0; i < 6; ++i ){
		printf("%d",C[i]);
	}
	if( C[c] == -1 ){
		return -1;
	} else if( N == 0 ){
		if( c == 5 ){
			if( 1 <= first && first <= 3 ){
				printLetter(c);
				return 1;
			}
		} else if( c == 0 ){
			if( 2 <= first && first <= 4 ){
				printLetter(c);
				return 1;
			}
		} else if( c-1 <= first && first <= c+1 ){
			return 0;
		} else {
			printLetter(c);
			return 1;
		}
		return 0;
	} else {
		for( int i = 2; i <= 4; ++i ){
			int next = (c+i)%6;
			C[next] -= 1;
			int result = search(N-1,C[0],C[1],C[2],C[3],C[4],C[5],next);
			if( result == 1 ){
				printLetter(c);
				return 1;
			}
			C[next] += 1;
		}
	}
	return -1;
}

int main(){
//	freopen("B_input.txt","r",stdin);
//	freopen("B_output.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for( int i = 0; i < T; ++i ){
		int N;
		int C[6];
		int result = -1;
		scanf("%d %d %d %d %d %d %d",&N,&C[0],&C[1],&C[2],&C[3],&C[4],&C[5]);
		printf("Case #%d: ",i+1);
		for( int j = 0; j < 6; ++j ) {
			if( C[j] != 0 ){
				C[j] -= 1;
				first = j;
				result = search(N-1,C[0],C[1],C[2],C[3],C[4],C[5],j);
				if( result == -1 ){
					printf("IMPOSSIBLE");
				}
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
