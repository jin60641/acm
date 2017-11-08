#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

int s[100];
char check[40000][16];
int L;
int C = 0;
int max;

int c(int l, int r){
	if( l < 0 || r < 0 || l < r){
		return 0;
	}
	if( l-r < r ){
		r = l-r;
	}
	double result = 1;
	for( int i = 0; i < r; ++i ){
		result = result*(l-i)/(r-i);
	}
	return (int)(result+1e-9);
}

int fill( int start, int weight, int index ){
	int cnt = 0;
	for( int i = start; i <= C-(L-weight); ++i ){
		int tmp = cnt;
		int l = C-i-1;
		int r = L-weight-1;
		int a = c(l,r);
		if( a == 0 ){
			continue;
		}
		cnt += a;
		for( int j = tmp; j < cnt; ++j ){
			check[j+index][weight] = s[i];
		}
		fill(i+1,weight+1,tmp+index);
	}
	return 0;
}

int main(){
	scanf("%d %d\n",&L,&C);
	for( int j = c(C,L)-1; j >= 0; --j ){
		for( int i = 0; i < L; ++i ){
			check[j][i] = 0;
		}
	}
	max = c(C,L);
	
	for( int i = 0; i < C*2; ++i ){
		s[i] = getchar();
	}
	for( int i = 0; i < C*2; ++i ){
		if( i%2 == 0 ){
			s[i/2] = s[i];
		}
	}
    s[C] = '\0';
    std::sort(s,s+C);

	fill(0,0,0);
	for( int i = 0; i < max; ++i ){
		int mo = 0;
		int ja = 0;
		for( int j = 0; j < L; ++j ){
			if( check[i][j] == 'a' || check[i][j] == 'e' || check[i][j] == 'i' || check[i][j] == 'o' || check[i][j] == 'u' ){
                ++mo;
            } else {
                ++ja;
			}
			
			if( mo >= 1 && ja >= 2 ){
				for( int k = 0; k < L; ++k ){
					printf("%c",check[i][k]);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
