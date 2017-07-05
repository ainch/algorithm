#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long lint;
typedef pair < lint , lint > ll;

int ccw(ll a, ll b, ll c){
	lint res = 0;
	res += (a.first*b.second + b.first*c.second + c.first*a.second);
	res -= (a.first*c.second + b.first*a.second + c.first*b.second);
	if(res>0)return 1;
	else if(res==0)return 0;
	else return -1;
}

ll left;
bool comp(const ll &a,const ll &b){
	return ccw(left,a,b)>0;
}

vector < ll > make_convex_hull(vector < ll > &a){
	sort(a.begin(),a.end());
	ll left = a[0];
	
	stable_sort(a.begin() + 1,a.end(),comp);

	vector < ll > ret;
	for(int i=0;i<a.size();++i){
		while(ret.size()>=2 && ccw(ret[ret.size()-2],ret[ret.size()-1],a[i]))
				ret.pop_back();
	}
	return ret;
}

int main(){
	int n;
	scanf("%d",&n);
	
	vector < ll > a;
	for(int i=0;i<n;++i){
		lint x,y;
		scanf("%lld%lld",&x,&y);
		a.push_back(ll(x,y));
	}

	vector < ll > convex_hull;
	convex_hull = make_convex_hull(a);

	for(int i=0;i<convex_hull.size();++i){
		const ll &point = convex_hull[i];
		printf("x : %lld y : %lld\n",point.first,point.second);
	}

	return 0;
}
