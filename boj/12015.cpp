#include<stdio.h>
#include<vector>
#include<algorithm>
int max(int a, int b){
	return a>b?a:b;
}
struct pair{
	int value, index;
};
bool cmp( pair a, pair b ){
	if( a.value == b.value ){
		return a.index > b.index; // 증가수열
	} else {
		return a.value < b.value;
	}
}

struct range {
	int l,r,value;
};

int N;
range ranges[2500000];

void make(int index, int l, int r){
	ranges[index].l = l;
	ranges[index].r = r;
	int cnt = r-l+1;
	if( cnt == 1 ){ // l == r
		ranges[index].value = 0;
	} else {
		int mid = (l+r)/2;
		make(index*2,l,mid);
		make(index*2+1,mid+1,r);
	}
}

int get( int now, int start, int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ranges[now].value;
	}
	int l = now*2;
	int r = now*2+1;
	if( ranges[l].l <= start && start <= ranges[l].r ){
		if( end <= ranges[l].r ){
			return get(now*2,start,end);
		} else {
			int result[2] = { get(now*2,start,ranges[l].r), get(now*2+1,ranges[r].l,end) };
			return max(result[0],result[1]);
		}
	} else {
		return get(now*2+1,start,end);
	}
}

int refresh( int now, int target, int value ){
	if( ranges[now].l == ranges[now].r && ranges[now].l == target ){
		ranges[now].value = value;
		return value;
	}
	int l = now*2, r = now*2+1;
	if( ranges[l].l <= target && target <= ranges[l].r ){
		ranges[now].value = max( ranges[now].value, refresh( now*2, target, value ) );
		return ranges[now].value;
	} else {
		ranges[now].value = max( ranges[now].value, refresh( now*2+1, target, value ) );
		return ranges[now].value;
	}
}

int main(){
	std::vector<pair> v;
	scanf("%d", &N);
	pair no = { 0, 0 };
	v.push_back(no);
	for( int i = 1; i <= N; ++i ){
		pair p = { 0, i };
		scanf("%d",&p.value);
		v.push_back(p);
	}
	std::sort(v.begin()+1,v.end(),cmp);
	int last = 1;
	while( last < N*2 ){
		last*=2;
	}
	last -= 1;
	make(1,1,N);
	for( int i = 1; i <= N; ++i ){
		refresh( 1, v[i].index,  get(1,1,v[i].index)+1 );
	}
	printf("%d\n",get(1,1,N));
	return 0;
}
