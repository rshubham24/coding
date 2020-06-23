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
    unordered_map<char, int> a, b;
    rep(i, k.size()){
    	a[k[i]] = 1;
    }
    int l = a.size();
    int j = 0, ans = INT_MAX, t = 0;
    rep(i, k.size()){
    	if(b[k[i]] == 0){
    		b[k[i]]++;
    		t++;
    	}
    	else{
    		b[k[i]]++;
    	}
    	while(b[k[j]] > 1){
    		b[k[j]]--;
    		j++;
    	}
    	if(t == l){
    		ans = min(ans, (i-j+1));
    	}
    }
    cout << ans;
	return 0;
}