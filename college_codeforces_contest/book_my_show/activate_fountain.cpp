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
    int n;
    cin >> n;
    v a(n);
    vp b;
    rep(i, n){
        cin >> a[i];
        b.pb(mp(max(i-a[i], 0), min(i+a[i], n-1)));
    } 
    sort(all(b));
    int last = -1, ans = 0, j = 0;
    rep(i, b.size()){
        if(b[i].f <= last + 1){
            j = max(b[i].s, j);
            if(j == n-1){
                ans++;
                break;
            }
        }
        else{
            last = j;
            j = 0;
            i--;
            ans++;
        }
    }
    if(j != n-1){
        cout << ans + 1;
    }
    else{
        cout << ans;    
    }
	return 0;
}	