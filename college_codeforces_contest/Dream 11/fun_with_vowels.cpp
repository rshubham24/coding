#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007;
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
    ss a;
    cin >> a;
    int n = a.size();
    vv dp(6, v(n+1));
    rep(i, 6){
        dp[i][0] = 0;
    }
    rep(j, n+1){
        dp[0][j] = 0;
    }
    unordered_map<int, char> map;
    map[1] = 'a';
    map[2] = 'e';
    map[3] = 'i';
    map[4] = 'o';
    map[5] = 'u';
    repa(i, 1, 5){
        repa(j, 1, n){
            dp[i][j] = dp[i][j-1];
            if(a[j-1] == map[i] && dp[i-1][j] >= i-1){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j])+1;
            }
        }
    }
    cout << dp[5][n];
    return 0;
}