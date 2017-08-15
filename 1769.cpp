#include<stdio.h>

int main(){
	char s[1000001];
	scanf("%s",s);
	int cnt = 0;
	int sum = s[0]-'0';
	if( s[1] == '\0' ){
		printf("%d\n%s\n",cnt,sum%3==0?"YES":"NO");
		return 0;
	}
	while( true ){
		++cnt;
		sum = 0;
		for( int i = 0; s[i] != '\0'; ++i ){
			sum += s[i]-'0';
		}
		if( sum >= 10 ){
			int size = 0;
			while( sum != 0 ){
				s[size++] = sum%10 + '0';
				sum/=10;
			}
			s[size] = '\0';
			for( int i = 0; i < size/2; ++i ){
				char tmp = s[i];
				s[i] = s[size-1-i];
				s[size-1-i] = tmp;
			}
		} else {
			break;
		}
	}
	printf("%d\n%s\n",cnt,sum%3==0?"YES":"NO");
	return 0;
}
