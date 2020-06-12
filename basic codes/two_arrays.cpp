#include <bits/stdc++.h>

using namespace std;

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

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int m, n, x;
    cin >> m >> n;
    vp a;
    rep(i, m){
        cin >> x;
        while(!a.empty() && a.back().f >= x){
            a.pop_back();
        }
        a.pb(mp(x, i));
    }
    ll ans = 1;
    int j = 0;
    int mod = 998244353;
    rep(i, n){
        cin >> x;
        if(i == 0 && a[j].f != x){
            ans = 0;
        }
        while(j != a.size() && a[j].f != x){
            j++;
        }
        if(j == a.size()){
            ans = 0;
        }
        else{
            if(i){
                ans *= a[j].s - a[j-1].s;
                ans %= mod;
                j++;
            }
        }
    }
    cout << ans;
    return 0;
}