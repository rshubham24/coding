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

int n, k;

bool check(int x, int t, v &a){
	int ans = 0;
	rep(i, n){
		if(!t){
			ans++;
			t ^= 1;
		}
		else{
			if(a[i] <= x){
				ans++;
				t ^= 1;
			}
		}
	}
	return ans >= k;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    v a(n);
    rep(i, n){
    	cin >> a[i];
    }
    int i = 0, j = 1e9;
    while(i < j){
    	int mid = (i+j)/2;
    	if(check(mid, 0, a) || check(mid, 1, a)){
    		j = mid;
    	}
    	else{
    		i = mid+1;
    	}
    }
    cout << i;
	return 0;
}	