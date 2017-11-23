#include<stdio.h>
int main(){
	int n = 0;
	char tmp[100], s[100];
	scanf("%d",&n);
	int len = 0;
	while( n > 0 ){
		tmp[len++] = n%2 + '0';
		n/=2;
	}
	for( int i = 0; i < len; ++i ){
		s[i] = tmp[len-i-1];
	}
	s[len] = '\0';
	int one = 0;
	int zero = 0;
	int flag = 0;
	int max = 1;
	for( int i = 0; i < len; ++i ){
		if( s[i] == '1' ){
			if( flag == 0 ){
				one++;
			} else {
				one = 1;
				zero = 0;
				flag = 0;
			}
		} else if( s[i] == '0' ){
			flag = one;
			++zero;
			if( zero >= flag ){
				max = flag>max?flag:max;
			} else {
				max = max<(zero+1)?(zero+1):max;
			}
		}
	}
	int sum = 0;
	int add = 1;
	for( int i = 1; i < max; ++i ){
		add *= 2;
	}
	for( int i = 0; i < max; ++i ){
		sum += add;
		add *= 2;
	}
	printf("%d\n",sum);
	return 0;
}
