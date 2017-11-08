#include<stdio.h>
#include<queue>
int check[100002];
struct s {
    int v;
    int w;
};
std::queue<s> q;
int N,K;
int f(){
    s n = q.front();
    int v = n.v;
    int w = n.w;
    if( v < 0 || ((N<K)?(v>K+1):(v>N)) || ( check[v] > 0 && check[v] < w ) ){
        q.pop();
        return 0;
    }
    check[v] = w;
    if( v == K ){
        q.pop();
        return 0;
    }
    s c = { v*2, w+1 };
    s a = { v-1, w+1 };
    s b = { v+1, w+1 };
    q.push(a);
    q.push(b);
    q.push(c);
    q.pop();
    return 0;
}

int main(){
    scanf("%d %d",&N,&K);
    s a = { N, 0 };
    q.push(a);
    while( q.size() ){
        f();
    }
    printf("%d\n",check[K]);
    return 0;
}

