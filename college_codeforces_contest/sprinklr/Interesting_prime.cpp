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
#define vvs vector<vs>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vb vis(1000005, 0);
    v a;
    repa(i, 2, 1000000){
        if(!vis[i]){
            a.pb(i);
            int j = 2;
            while(i*j < 1000005){
                vis[i*j] = 1;
                j++;
            }
        }
    }
    v b;
    rep(i, a.size()){
        int k = a[i], j = 1, c = 1;
        while(c){
            int g = k - pow(j, 4);
            if(g < 0){
                break;
            }
            int l = sqrt(g);
            if(l*l == g){
                b.pb(a[i]);
                break;
            }
            j++;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        rep(i, b.size()){
            if(b[i] <= n){
                ans++;
            }
            else{
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
} 