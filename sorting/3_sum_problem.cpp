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

bool sum(vpl &a, ll t, ll n){
	int l, r;
	sort(a.begin(), a.end());
	for(int i = 0; i < n-2; i++){
		l = i+1;
		r = n-1;
		while(l < r){
			ll k = a[i].f + a[l].f + a[r].f;
			if(k == t){
				cout << a[i].s << " " << a[l].s << " " << a[r].s;
				return true;
			}
			else if(k > t){
				r--;
			}
			else{
				l++;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, t, x;
	cin >> n >> t;
	vpl a;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.pb(mp(x, i+1));
	}
	if(!sum(a, t, n)){
		cout << "IMPOSSIBLE";
	}
	return 0;
}