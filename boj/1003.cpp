#include<stdio.h>

struct pair {
  int zero, one;
};

int main(){
  int T;
  scanf("%d",&T);
  pair dp[50];
  dp[0].zero = 1;
  dp[0].one = 0;
  dp[1].zero = 0;
  dp[1].one = 1;
  for (int i = 2; i <= 40; ++i) {
    int zero = dp[i-1].zero + dp[i-2].zero;
    int one = dp[i-1].one + dp[i-2].one;
    pair p = { zero, one };
    dp[i] = p;
  }
  while(T--){
    int N;
    scanf("%d",&N);
    printf("%d %d\n",dp[N].zero,dp[N].one);
  }
}
