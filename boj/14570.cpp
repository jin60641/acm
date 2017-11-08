#include<stdio.h>
struct node {
    int left,right;
};

node n[200001];

int find( int now, long long int K ){
    if( n[now].right == -1 && n[now].left == -1 ){
        return now;
    } else if( n[now].right == -1 ){
        return find( n[now].left, K );
    } else if( n[now].left == -1 ){
        return find( n[now].right, K );
    }
    if( K%2LL == 0LL ){
        return find( n[now].right, K/2LL );
    } else {
        return find( n[now].left, K/2LL + 1LL );
    }
}

int main(){
    int N;
    scanf("%d",&N);
    for( int i = 1; i <= N; ++i ){
        int l,r;
        scanf("%d %d",&l,&r);
        n[i].left = l;
        n[i].right = r;
    }

    long long int K;
    scanf("%lld",&K);
	printf("%d\n",find(1,K));
    return 0;
}

