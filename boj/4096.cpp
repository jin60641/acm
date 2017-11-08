#include<stdio.h>

int len = 0;

char s[10];
char add( int start ){
	for( int i = start-1; i >= 0; --i ){
		if( s[i] == '9' ){
			s[i] = '0';
		} else {
			++s[i];
			return s[len-start-1];
		}
	}
	return s[len-start-1];
}

int main(){
	while( true ){
		scanf("%s",s);
		char tmp[10];
		int start = 0;
		for( len = 0; s[len] != 0; ++len ){
			if( s[len] != '0' && start == 0 ){
				start = len;
			}
		}
		for( int i = 0; i < len; ++i ){
			tmp[i] = s[i];
		}
		if( len == 1 && s[0] == '0' ){
			break;
		}
		for( int i = 0; i < len/2; ++i ){
			if( s[i] == s[len-i-1] ){
				continue; 
			} else if( s[i] > s[len-i-1] ){
				s[len-i-1] = s[i];
			} else if( s[i] < s[len-i-1] ){
				if( s[i] == '0' ){
					if( i == start-1 ){
						s[len-i-1] = add(len-i-1);
					} else {
						s[len-i-1] = add(len-i-1);
					}
				} else {
					s[len-i-1] = add(len-i-1);
				}
			}
		}
		int multi = 1;
		int tot = 0;
		for( int i = len-1; i >= 0; --i ){
			tot += ((s[i]-'0')-(tmp[i]-'0'))*multi;
			multi *= 10;
		}
		printf("%d\n",tot);
	}
	return 0;
}
