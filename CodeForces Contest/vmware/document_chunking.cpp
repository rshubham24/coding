#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define ss string
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define pp pair<int, p>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)

ll check(ll i){
    ll ans = 0;
    while(i != 0){
        if(i%2 == 1){
        	ans++;
        }
        i = i/2;
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, n, m, x, y;
	cin >> t >> n >> m;
	vector<pair<ll, ll>> a;
	a.pb(mp(0, 0));
	ll ans = 0;
	rep(i, n){
		cin >> x >> y;
		a.pb(mp(x, y));
	}
	a.pb(mp(t+1, t+1));
    rep(i, a.size()-1){
        ll c = a[i+1].f - a[i].s - 1;
        ans += check(c);
    }
    cout << ans << endl;
	return 0;
}	