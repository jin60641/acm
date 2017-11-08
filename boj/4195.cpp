#include<stdio.h>
#include<string>
#include<map>
int check[200001];
int size[200001];
int find( int a ){
    if( check[a] == a ){
        return a;
    }
    check[a] = find( check[a] );
    return check[a];
}
int Union( int a, int b ){
    if( find(a) != find(b) ){
		size[find(a)] += size[find(b)];
    	check[find(b)] = find(a);
    }
    return size[find(a)];
}
int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int F;
		scanf("%d",&F);
		int V = 0;
		std::map< std::string, int > m;
		for( int i = 0; i < F; ++i ){
			char a_tmp[21];
			char b_tmp[21];
			scanf("%s",a_tmp);
			scanf("%s",b_tmp);
			std::string a = a_tmp;
			std::string b = b_tmp;
			if( m[a] == 0 ){
				m[a] = ++V;
				check[V] = V;
				size[V] = 1;
			}
			if( m[b] == 0 ){
				m[b] = ++V;
				check[V] = V;
				size[V] = 1;
			}
			printf("%d\n",Union(m[a],m[b]));
		}
	}
	return 0;
}
