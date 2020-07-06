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
    ss k;
    cin >> k;
    int n = k.size(), ans = 0;
    vv dp(n, v(n, 0));
    rep(i, n){
        dp[i][i] = 1;
    }
    repa(j, 1, n-1){
        rep(i, n-j){
            int t = i + j;
            if(k[i] == k[t]){
                dp[i][t] = 2 + dp[i+1][t-1];
            }
            else{
                dp[i][t] = max(dp[i][t-1], dp[i+1][t]);
            }
        }
    }
    rep(i, n){
        rep(j, n-1){
            ans = max(ans, dp[i][j]*dp[j+1][n-1]);
        }
    }
    cout << ans;
    return 0;
} 