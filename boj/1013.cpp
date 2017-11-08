#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		char s[201];
		scanf("%s",s);
		int flag = s[0]=='1'?1:5;
		int result = 0;
		for( int i = 1; s[i] != '\0'; ++i ){
			if( flag == 0 ){
				result = 0;
				flag = s[i]=='1'?1:5;
			} else if( flag == 1 ){
				result = 0;
				if( s[i] == '0' ){
					flag = 2;
				} else {
					break;
				}
			} else if( flag == 2 ){
				result = 0;
				if( s[i] == '0' ){
					flag = 3;
				} else {
					break;
				}
			} else if( flag == 3 ){
				result = 0;
				if( s[i] == '1' ){
					flag = 4;
					result = 1;
				}
			} else if( flag == 4 ){
				if( s[i] == '1' && s[i+1] != '\0' && s[i+2] != '\0' && s[i+1] == '0' && s[i+2] == '0' ){
					result = 0;
					flag = 3;
					i += 2;
				} else if( s[i] == '0' ){
					flag = 5;
					result = 0;
				} else {
					result = 1;
				}
			} else if( flag == 5 ){
				if( s[i] == '1' ){
					flag = 0;
					result = 1;
				} else {
					result = 0;
					break;
				}
			}
		}
		printf("%s\n",result==1?"YES":"NO");
	}
	return 0;
}
