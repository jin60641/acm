#include<stdio.h>
#include<string.h>

int main(){
	char s[100001];
	int B;
	scanf("%s %d",s,&B);
	int tot = 0;
	int multi = 1;
	int len = strlen(s);
	for( int i = len-1; i >= 0; --i ){
		if( s[i] >= '0' && s[i] <= '9' ){
			tot += (s[i]-'0')*multi;
		} else {
			tot += (s[i]-'A'+10)*multi;
		}
		multi*=B;
	}
	printf("%d\n",tot);
	return 0;
}
