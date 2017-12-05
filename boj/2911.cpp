#include<stdio.h>
#include<algorithm>
#include<vector>

int last = 1;
struct node {
	int l,r,v,i;
};
std::vector<node> tree(300000);
struct pair {
	int p,c;
};
pair a[100001];
bool cmp(pair a, pair b){
	return a.p < b.p;
}

void init( int now, int l, int r ){
	tree[now].l = l;
	tree[now].r = r;
	if( l == r ){
		tree[now].v = l;
	} else if( now <= last){
		init( now*2, l, (l+r)/2 );
		init( now*2+1, (l+r)/2+1, r );
	}
}

int find( int now, int left, int right ){
	int l = now*2;
	int r = now*2+1;
	int v = tree[now].v;
	if( tree[now].r - tree[now].l == 0 ){
		return v;
	} else if( tree[now].l == left && tree[now].r == right ){
		return v;
	} else if( right <= tree[l].r ){
		return find(l,left,right);
	} else if( tree[r].l <= left ){
		return find(r,left,right);
	} else {
		int lv = find(l,left,tree[l].r);
		int rv = find(r,tree[r].l,right);
		return (a[lv].c < a[rv].c)?lv:rv;
	}
}

int f( int left, int right, int max ){
	if( left > right ){
		return 0;
	}
	int mid = find(1,left,right);
	if( left == right ){
		return a[mid].c-max;
	} else {
		return (a[mid].c-max) + f( left, mid-1, a[mid].c ) + f( mid+1, right, a[mid].c );
	}
}

int main(){	
	int N,M;
	scanf("%d %d",&N,&M);
	for( ; last < N; last <<= 1  );
	last = ( last << 1 ) - 1;
	init(1,1,N);
	for( int i = 1; i <= N; ++i ){
		scanf("%d %d",&a[i].p,&a[i].c);
	}
	std::sort(a+1,a+N+1,cmp);
	for( int i = last; i >= 1; --i ){
		if( tree[i].l >= 1 && tree[i].r >= 1 ){
			if( tree[i/2].v == 0 || a[tree[i].v].c < a[tree[i/2].v].c ){
				tree[i/2].v = tree[i].v;
			}
		}
	}
	printf("%d\n",f(1,N,0));
	return 0;
}
