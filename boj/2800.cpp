#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>

std::vector<std::string> result;
int check[5000][11];
int K = 0;
int end = 0;
int max = 0;

int c(int l, int r){
    if( l < 0 || r < 0 || l < r){
        return 0;
    }
    if( l-r < r ){
        r = l-r;
    }
    double ret = 1;
    for( int i = 0; i < r; ++i ){
        ret = ret*(l-i)/(r-i);
    }
    return (int)(ret+1e-9);
}

int fill( int start, int weight, int index ){
    int cnt = 0;
    for( int i = start; i <= K-(end-weight); ++i ){
        int tmp = cnt;
        int l = K-i-1;
        int r = end-weight-1;
        int a = c(l,r);
        if( a == 0 ){
            continue;
        }
        cnt += a;
        for( int j = tmp; j < cnt; ++j ){
            check[j+index][weight] = i;
        }
        fill(i+1,weight+1,tmp+index);
    }
    return 0;
}

struct pair{
	int open, close;
};

int main(){
	char s[201];
	scanf("%s",s);
	
	std::stack<int> open;
	std::vector<pair> v;
	
	int len = 0;
	for( ; s[len] != '\0'; ++len ){
		if( s[len] == '(' ){
			open.push(len);
		} else if( s[len] == ')' ){
			int o = open.top();
			pair p = { o, len };
			v.push_back(p);
			open.pop();
		}
	}

	K = v.size();
	
	int cnt = 0;
	for( int i = 1; i <= K; ++i ){
		end = i;
		max = c(K,end);
		fill(0,0,0);
		for( int j = 0; j < max; ++j ){
			std::string tmp = s;
			for( int k = 0; k < end; ++k ){
				pair p = v[check[j][k]];
				tmp[p.open] = '!';
				tmp[p.close] = '!';
			}
			std::string tmp2;
			for( int k = 0; k < tmp.size(); ++k ){
				if( tmp[k] == '!' ){
					continue;
				}
				tmp2.push_back(tmp[k]);
			}
			++cnt;
			result.push_back(tmp2);
		}
	}
	std::sort(result.begin(),result.end());
	for( int i = 0; i < result.size(); ++i ){
		int flag = 0;
		for( int j = i+1; j < result.size(); ++j ){
			if( result[i].compare(result[j]) == 0 ){
				flag = 1;
			}
		} 
		if( flag == 0 ){
			printf("%s\n", result[i].c_str());
		}
	}
}
