#include<stdio.h>
long long int max( long long int a, long long int b ){
	return a>b?a:b;
}
long long int min( long long int a, long long int b ){
	if( a == 0 ){
		return b;
	} else if( b == 0 ){
		return a;
	}
	return a<b?a:b;
}
long long int last = 0, N;
long long int nums[100001];

struct range {
	long long int l,r,value;
};

range ranges[300000];
void make(long long int index, long long int left, long long int right){
	last = last>index?last:index;
	ranges[index].l = left;
	ranges[index].r = right;
	long long int cnt = right-left+1;
	if( cnt == 1 ){ // left == right
		ranges[index].value = nums[left];
	} else {
		long long int mid = (left+right)/2;
		make(index*2,left,mid);
		make(index*2+1,mid+1,right);
	}
}

long long int get(long long int now, long long int start, long long int end){
	if( ranges[now].l == start && ranges[now].r == end ){
		return ranges[now].value;
	}
	long long int left = now*2;
	long long int right = now*2+1;
	if( ranges[left].l <= start && start <= ranges[left].r ){
		if( end <= ranges[left].r ){
			return get(now*2,start,end);
		} else {
			long long int result[2] = { get(now*2,start,ranges[left].r), get(now*2+1,ranges[right].l,end) };
			return min(result[0],result[1]);
		}
	} else {
		return get(now*2+1,start,end);
	}
}

void clear(){
	for( int i = 1; i <= last; ++i ){
		ranges[i].l = 0;
		ranges[i].r = 0;
		ranges[i].value = 0;
	}
	for( int i = 1; i <= N; ++i ){
		nums[N] = 0;
	}
}

int main(){
	while( true ){
		scanf("%lld",&N);
		if( N == 0 ){
			break;
		}
		for( long long int i = 1; i <= N; ++i ){
			scanf("%lld",&nums[i]);
		}
		make(1,1,N);
		for( long long int i = last; i >= 1; --i ){
			if( ranges[i].l >= 1 && ranges[i].r >= 1 ){
				ranges[i/2].value = min(ranges[i/2].value, ranges[i].value);
			}
		}
		long long int result = 0;
		for( long long int i = 1; i <= last; ++i ){
			result = max( ranges[i].value * ( ranges[i].r - ranges[i].l + 1 ) , result );
		}
		printf("%lld\n",result);
		clear();
	}
	return 0;
}
