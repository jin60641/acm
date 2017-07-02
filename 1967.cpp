#include<stdio.h>
#include<vector>
using namespace std;
struct edge{
	int value;
	int weight;
};
vector<edge> nodes[10001];
int Max = 0;
int root = 1;
int f( int parent ){
	vector<edge> *v;
	v = &nodes[parent];
	int cnt = v->size();
	if( cnt == 0 ){
		return 0;
	}
	int max = 0; 
	int max2 = 0; // max2 is bigger than max
	for( vector<edge>::iterator i = v->begin(); i != v->end(); ++i ){
		int result = f( (*i).value ) + (*i).weight;
		if( result > max2 ){
			max = max2;
			max2 = result;
		} else if( result > max ){
			max = result;
		}
	}
	if( Max < max + max2 ){
		Max = max + max2;
	}
	return max2;
}
int main(){
	int n;
	scanf("%d",&n);
	for( int i = 1; i < n; ++i ){
		int parent,offspring,weight;
		scanf("%d %d %d",&parent,&offspring,&weight);
		edge l;
		l.value = offspring;
		l.weight = weight;
		nodes[parent].push_back(l);
	}
	f(root);	
	printf("%d\n",Max);
	return 0;
}
