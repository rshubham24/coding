#include <bits/stdc++.h>

using namespace std;

long long func(vector<pair<long long, long long>> &a,long long x){
	while(a[x].second != -1){
		x = a[x].second;
	}
	return x;
}

void funce(vector<pair<long long, long long>> &a, long long x, long long y){
	if(a[y].second != -1){
		funce(a, x, a[y].second);
	}
	a[y].second = x;
	return;
}

int main(){
	long long x, y, max = -1, n, m, b;
	cin >> n >> m;
	vector<pair<long long, long long>> a;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x > max){
			max = x;
		}
		a.push_back(make_pair(x, -1));
	}
	
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		if(x == y){
    		cout << max << endl;
		    continue;
		}
		x = x-1;
		y = y-1;
		b = y;
		x = func(a, x);
		y = func(a, y);
		a[x].first += a[y].first;
		a[y].first = 0;
		if(a[x].first > max){
			max = a[x].first;
		} 
		funce(a, x, b);
		cout << max << endl;
	}
	return 0;
}