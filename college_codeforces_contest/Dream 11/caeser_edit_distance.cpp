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
    ss k, l;
    cin >> k >> l;
    int m = k.size();
    int n = l.size();
    v a(m), b(n);
    rep(i, m){
        a[i] = (int)(k[i]-'a');
    }       
    rep(i, n){
        b[i] = (int)(l[i]-'a');
    }
    int ans = 0;
    rep(j, 26){
        vv dp(m+1, v(n+1));
        rep(i, m+1){
            rep(q, n+1){
                if(i == 0 || q == 0){
                    dp[i][q] = 0;
                }
                else if(a[i-1] == b[q-1]){
                    dp[i][q] = dp[i-1][q-1] + 1;
                }
                else{
                    dp[i][q] = max(dp[i-1][q], dp[i][q-1]);
                }
            }
        }
        ans = max(ans, dp[m][n]);
        rep(i, m){
            a[i] = a[i]+1;
            if(a[i] == 26){
                a[i] = 0;
            }       
        }
    }
    cout << m+n-2*ans;
    return 0;
}   