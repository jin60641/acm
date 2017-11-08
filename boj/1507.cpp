#include<stdio.h>
#include<vector>
#include<algorithm>
int check[20];
int weight[20];
struct edge {
    int l,r,w;
};
std::vector<edge> v;
int cmp( edge a, edge b ){
    return a.w<b.w;
}
int find( int a ){
    if( check[a] == a ){
        return a;
    }
    int ra = find(check[a]);
    weight[a] += weight[check[a]];
    check[a] = ra;
    return ra;
}
int Union( edge e ){
    int ra = find(e.l);
    int rb = find(e.r);
    if( ra == rb ){
        return 0;
    }
    check[ra] = rb;
    weight[ra] = e.w + weight[e.l] - weight[e.r];
    find(e.l); find(e.r);
    return 1;
}
int main(){
    int N;
    scanf("%d",&N);
    for( int i = 0; i < N; ++i ){
        check[i] = i;
        for( int j = 0; j < N; ++j ){
            int a;
            scanf("%d",&a);
            if( i < j ){
                edge e = { i, j, a };
                v.push_back(e);
            }
        }
    }
    std::sort(v.begin(),v.end(),cmp);
    for( int i = 0; i < v.size(); ++i ){
        Union(v[i]);
    }
    int result = weight[0];
    int flag = find(0);
    for( int i = 1; i < N; ++i ){
        result += weight[i];
        if( find(i) != flag ){
            flag = -1;
            break;
        }
    }
    printf("%d\n",flag==-1?-1:result);
    return 0;
}


