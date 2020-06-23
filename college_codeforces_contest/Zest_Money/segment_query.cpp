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
#define all(x) (x).begin(), (x).end()

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, per;
    cin >> n;
    vl a(n);
    rep(i, n){
        cin >> a[i];
    }
    cin >> per;
    vvl dp(n, vl(200));
    rep(j, 200){
        rep(i, n){
            int c = (per*a[i] + 100 - 1)/100;
            dp[i][j] = c;
            a[i] -= c;
            if(i){
                dp[i][j] += dp[i-1][j];
            }
        }
    }
    int q;
    cin >> q;
    vl d(q), l(q), r(q);
    rep(i, q){
        cin >> d[i];
    }
    cin >> q;
    rep(i, q){
        cin >> l[i];
    }
    cin >> q;
    rep(i, q){
        cin >> r[i];
    }
    rep(i, q){
        l[i]--;
        d[i]--; 
        r[i]--;
        if(d[i] < 200){
            cout << dp[r[i]][d[i]] - (l[i] ? dp[l[i]-1][d[i]] : 0) << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
	return 0;
}	