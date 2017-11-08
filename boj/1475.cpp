#include<stdio.h>
#include<string.h>

int cnt[10];
int main(){
	char n[10];
	scanf("%s",n);
	int len = strlen(n);
	for( int i = 0; i < len; ++i ){
		++cnt[n[i]-'0'];
	}
	int tmp = cnt[6];
	cnt[6] = (cnt[6] + cnt[9])/2;
	cnt[9] = (tmp + cnt[9])/2 + (tmp+cnt[9])%2;
	int max = 0;
	for( int i = 0; i < 10; ++i ){
		max = max<cnt[i]?cnt[i]:max;
	}
	printf("%d\n",max);
	return 0;
}
