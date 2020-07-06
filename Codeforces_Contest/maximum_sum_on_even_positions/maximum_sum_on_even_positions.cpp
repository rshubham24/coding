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
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	vl a(n);
    	ll sum = 0;
    	rep(i, n){
    		cin >> a[i];
    		if(i%2 == 0){
    			sum += a[i];
    		}
    	}
    	ll ans = 0;
    	rep(j, 2){
    		ll b = 0, c = 0, d = 0;
    		rep(i, n){
    			if(i%2 == 0){
    				b += a[i];
    			}
    			else{
    				c += a[i];
    			}
    			if(i%2 == j){
    				ans = max(ans, (c - b) - d);
    				d = min(d, (c - b));
    			}
    		}
    	}
    	cout << ans+sum << endl;
    }       
    return 0;
} 