#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

template < typename T > 
bool binary_search(const vector < T > &a,T key){
	int left = 0, right = a.size()-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(a[mid]==key)return true;
		else if(a[mid]<key){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return false;
}

int main(){
	//(1)
	int n;//the number of numbers to search
	scanf("%d",&n);
	vector < int > a;
	while(n--){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}

	//(2)
	sort(a.begin(),a.end());

	//(3)
	int q;//the number of querys
	while(q--){
		int x;
		scanf("%d",&x);
		if(binary_search(a,x))
			cout << "in the vector " << endl;
		else
			cout << "it isnt" << endl;	
	}
	return 0;
}
