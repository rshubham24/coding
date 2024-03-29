#include <bits/stdc++.h>

using namespace std;
//using namespace std::chrono;

int mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>
#define vv vector<v>
#define vpl vector<pair<long long, long long>>
#define vvl vector<vl>
#define vvp vector<vp>
multiset<int> a, b;

void check(){
	int y;
	if(b.size() > a.size()){
		y = *b.begin();
		a.insert(y);
		b.erase(b.begin());
	}
	else if(a.size() > (b.size() + 1)){
		y = *a.rbegin();
		b.insert(y);
		auto it = a.end();
		it--;
		a.erase(it);
	}
}

void median(int x){
	if(a.size() == 0 && b.size() == 0){
		a.insert(x);
	}
	else if(b.size() == 0){
		if(x >= *a.begin()){
			b.insert(x);
		}
		else{
			int y = *a.begin();
			a.erase(a.begin());
			a.insert(x);
			b.insert(y);
		}
	}
	else{
		if(x >= *b.begin()){
			b.insert(x);
		}
		else{
			a.insert(x);
		}
	}
	check();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, x;
	cin >> n >> k;
	v c;
	for(int i = 0; i < n; i++){
	    cin >> x;
	    c.pb(x);
	}
	for(int i = 0; i < k; i++){
		median(c[i]);
	}
	cout << *a.rbegin() << " ";
	for(int i = k; i < n; i++){
		median(c[i]);
		auto it = a.find(c[i-k]);
		if(it != a.end()){
		    a.erase(it);
		}
		else{
			it = b.find(c[i-k]);
		    b.erase(it);
		}
		check();
		cout << *a.rbegin() << " "; 
	}
	return 0;
}