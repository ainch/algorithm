#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

template < typename T > 
class Fenwick{
		private:
				vector < T > tree;
		public:
				Fenwick(int size){
					tree.resize(size+1);
				}
				T sum(int p){
					T ret = T(0);
					while(p){
						ret += tree[p];
						p -= (-p&p);
					}
					return ret;
				}
				void update(int p, T v){
					while(p<tree.size()){
						tree[p] += v;
						p += (-p&p);
					}
				}
};

int main(){
	int n;
	scanf("%d",&n);
	Fenwick<int> ft(n+1);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		ft.update(i,x);
	}
	
	int q;
	scanf("%d",&q);
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);
		
		int ans = ft.sum(e) - ft.sum(s-1);
		printf("%d",ans);
	}
	return 0;
}
