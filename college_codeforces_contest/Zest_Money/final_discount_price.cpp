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
    vl a(n);
    rep(i, n){
    	cin >> a[i];
    }
    stack<ll> q;
    v ans;
    ll sum = 0;
    for(int i = n-1; i >= 0; i--){
    	while(!q.empty() && q.top() > a[i]){
    		q.pop();
    	}
    	if(q.empty()){
    		sum += a[i];
    		ans.pb(i);
    	}
    	else{
    		sum += a[i] - q.top();
    	}
    	q.push(a[i]);
    	continue;
    }
    cout << sum << endl;
    sort(all(ans));
    rep(i, ans.size()){
        cout << ans[i] << " ";
    }
	return 0;
}	