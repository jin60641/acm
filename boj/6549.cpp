#include<stdio.h>
long long int max( long long int a, long long int b ){
	return a>b?a:b;
}
int last = 0, N;
int nums[100001];

struct range {
	int l,r,index;
};

range ranges[300000];
void init(int index, int left, int right){
	last = last>index?last:index;
	ranges[index].l = left;
	ranges[index].r = right;
	int width = right-left+1;
	if( width == 1 ){
		ranges[index].index = left;
	} else {
		int mid = (left+right)/2;
		init(index*2,left,mid);
		init(index*2+1,mid+1,right);
	}
}

int query(int now, int start, int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ranges[now].index;
	}
	int left = now*2;
	int right = now*2+1;
	if( ranges[left].l <= start && start <= ranges[left].r ){
		if( end <= ranges[left].r ){
			return query(now*2,start,end);
		} else {
			int result[2] = { query(now*2,start,ranges[left].r), query(now*2+1,ranges[right].l,end) };
			return nums[result[0]] < nums[result[1]] ? result[0]:result[1];
		}
	} else {
		return query(now*2+1,start,end);
	}
}
void clear(){
	for( int i = 1; i <= last; ++i ){
		ranges[i].l = 0;
		ranges[i].r = 0;
		ranges[i].index = 0;
	}
	for( int i = 1; i <= N; ++i ){
		nums[N] = 0;
	}
}

long long int f(int l,int r){
	int width = r-l+1;
	int now = query(1,l,r);
	int height = nums[now];
	long long int result = (long long)height*(long long)width;
	if( l <= now-1 ) result = max( result, f(l,now-1) );
	if( r >= now+1 ) result = max( result, f(now+1,r) );
	return result;
}

int main(){
	while( true ){
		scanf("%d",&N);
		if( N == 0 ){
			break;
		}
		for( int i = 1; i <= N; ++i ) scanf("%d",&nums[i]); 
		init(1,1,N);
		for( int i = last; i >= 2; --i )
			if( ranges[i].l >= 1 && ranges[i].r >= 1 )
				if( ranges[i/2].index == 0 || nums[ranges[i].index] < nums[ranges[i/2].index] ) 
					ranges[i/2].index = ranges[i].index;
		long long int result = f(1,N);
		printf("%lld\n",result);
		clear();
	}
	return 0;
}

