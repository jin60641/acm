#include<stdio.h>
#include<vector>

int V,E,check[20001];
std::vector<int> v[20001];

void clear(){
	for( int i = 1; i <= V; ++i ){
		v[i].clear();
		check[i] = 0;
	}
}

int dfs(int now, int flag){
	if( check[now] != 0 ){
		if( check[now] != flag ){
			return 1;
		} else {
			return 0;
		}
	}
	check[now] = flag;
	for( int i = 0; i < v[now].size(); ++i ){
		if( dfs( v[now][i], flag==1?2:1 ) == 1 ){
			return 1;
		}
	}
	return 0;
}

int main(){
	int K;
	scanf("%d",&K);
	while( K-- ){
		scanf("%d %d",&V,&E);
		for( int i = 0; i < E; ++i ){
			int from, to;
			scanf("%d %d",&from,&to);
			v[from].push_back(to);
			v[to].push_back(from);
		}
		int flag = 0;
		for( int i = 1; i <= V; ++i ){
			if(check[i] == 0 && dfs(i,1) ){
				flag = 1;
				break;
			}
		}
		printf("%s\n",flag?"NO":"YES");
		clear();
	}
	return 0;
}
