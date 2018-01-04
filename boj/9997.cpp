#include<stdio.h>

int N;
int cnt = 0;
int dic[25];
int max = (1 << 26) - 1;
void f(int now, int sum){
	if (sum == max){
		cnt += ( 1 << (N - now) );
	} else if (now < N){
		f(now + 1, sum | dic[now]);
		f(now + 1, sum);
	}
}
int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		char s[101];
		scanf("%s", s);
		for (int j = 0; s[j] != '\0'; ++j){
			dic[i] |= 1 << (s[j] - 'a');
		}
	}
	f(0, 0);
	printf("%d\n", cnt);
	return 0;
}
