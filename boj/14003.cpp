#include<stdio.h>
#include<vector>
#include<algorithm>
int max( int a, int b ){
	return a>b?a:b;
}
struct pair{
	int value, index;
};
bool cmp( pair a, pair b ){
	if( a.value == b.value ){
		return a.index > b.index;
	} else {
		return a.value < b.value;
	}
}
pair get( std::vector<pair> &tree, int index ){
	pair result = { -1, 0 };
	while( index > 0 ){
		if( result.value < tree[index].value ){
			result.value = tree[index].value;
			result.index = tree[index].index;
		} 
		index -= ( index & -index );
	}
	return result;
}

void update( std::vector<pair> &tree, std::vector<int> &path, int index, pair target ){
	int value = target.value + 1;
	int tmp = index;
	path[index] = target.index;
	while( index < tree.size() ){
		if( tree[index].value < value ){
			tree[index].value = value;
			tree[index].index = tmp;
		}
		index += ( index & -index );
	}
}

int main(){
	int N, last;
	scanf("%d", &N);
	std::vector<pair> tree(N+1);
	std::vector<pair> v(N+1);
	std::vector<int> path(N+1);
	std::vector<int> a(N+1);
	std::vector<int> result;
	path[0] = -1;
	for( int i = 1; i <= N; ++i ){
		v[i].index = i;
		scanf("%d",&v[i].value);
		a[i] = v[i].value;
	}
	std::sort(v.begin()+1,v.end(),cmp);
	for( int i = 1; i <= N; ++i ) {
		update( tree, path, v[i].index, get( tree, v[i].index ) );
	}
	int length = get(tree,N).value;
	printf("%d\n",length);
	printf("\n");
	for( int i = 1; i <= N; ++i ){
		if( tree[i].value == length ){
			last = i;
			break;
		}
	}
	do{
		result.push_back(a[last]);
		last = path[last];
	} while( last != -1 );
	for( int i = length-1; i >= 0; --i ){
		printf("%d ",result[i]);
	}
	printf("\n");
	return 0;
}

