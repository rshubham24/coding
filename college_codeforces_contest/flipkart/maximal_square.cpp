#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mode = 1000000007;
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
    int m, n;
    cin >> m >> n;
    vv a(m, v(n));
    rep(i, m){
    	rep(j, n){
    		cin >> a[i][j];
    	}
    }
    int ans = 0;
    vv dp(m, v(n, 0));
    rep(i, m){
        rep(j, n){
            if(i == 0 || j == 0){
                if(a[i][j] == 1){
                    dp[i][j] = 1;
                }
                ans = max(dp[i][j], ans);
                continue;
            }
            if(a[i][j] == 1){
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans*ans;
	return 0;
}	