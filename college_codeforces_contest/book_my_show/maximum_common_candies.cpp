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

int m1, m2, l;

void dfs(vb &vis, vector<vv> &dp, int g, int j, int q){
    l++;
    vis[j] = true;
    int a;
    if(j+1 > m1 || j+1 > m2){
        int a = max(m1, m2);
        m1 = j+1;
        m2 = a;
    }
    for(int i = 0; i < dp[g][j].size(); i++){
        if(!vis[dp[g][j][i]]){
            dfs(vis, dp, g, dp[g][j][i], q);
        }
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    unordered_map<int, int> d;
    cin >> n;
    vector<vv> dp(105, vv(n));
    cin >> q;
    v a(q), b(q), c(q);
    rep(i, q){
        cin >> a[i];
        a[i]--;
    }
    cin >> q;
    rep(i, q){
        cin >> b[i];
        b[i]--;
    }
    cin >> q;
    rep(i, q){
        cin >> c[i];
        d[c[i]]++;
    }
    rep(i, q){
        dp[c[i]][a[i]].pb(b[i]);
        dp[c[i]][b[i]].pb(a[i]);
    }
    int le = 0, ans = 0;
    rep(i, 105){
        if(d[i] == 0){
            continue;
        }
        else{
            vb vis(n, false);
            m1 = 0;
            m2 = 0; 
            l = 0;
            rep(j, n){
                if(!vis[j]){
                    dfs(vis, dp, i, j, j);
                    //cout << j << " " << l << " " << m1 << " " << m2 << endl;
                    if(l == le){
                        ans = max(ans, m1*m2);
                    }
                    else if(l > le){
                        ans = m1*m2;
                        le = l;
                    }
                }
                l = 0;
                m1 = 0;
                m2 = 0;
            }
        }
    }
    cout << ans;
    
	return 0;
}	