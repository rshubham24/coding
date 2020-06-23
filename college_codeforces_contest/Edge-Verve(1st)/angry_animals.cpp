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
#define vvb vector<vb>
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, x, y;
	cin >> n;
	cin >> m;
	ll ans = (n*(n+1))/2;
	v a(m), b(m);
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	unordered_map<ll, ll> c;
	for(int i = 0; i < m; i++){
		x = min(a[i], b[i]);
		y = max(a[i], b[i]);
		if(c.find(x) != c.end()){
			c[x] = min(c[x], y);
		}
		else{
			c.insert(mp(x, y));
		}
	}
	vpl d;
	for(auto it = c.begin(); it != c.end(); it++){
		x = it->f;
		y = it->s;
		d.pb(mp(y, x));
	}
	sort(d.begin(), d.end());
	ll mi = 0;
	for(int i = 0; i < d.size(); i++){
		if(d[i].s > mi){
			ans -= (n-d[i].f+1)*(d[i].s-mi);
			mi = d[i].s;
		}
	}
	cout << ans;
	return 0;
}