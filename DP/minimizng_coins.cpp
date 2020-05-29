// Recursive

#include <bits/stdc++.h>

using namespace std;
//using namespace std::chrono;

int mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>

int mincoins(v &a, int x){
	if(x == 0){
		return 0;
	}
	int e = INT_MAX, f;
	for(int i = 0; i < a.size(); i++){
		if(a[i] <= x){
			f = mincoins(a, x-a[i]);
			if(f != INT_MAX && f + 1 < e){
				e = f + 1;
			}
		}
	}
	return e;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x;
	v a;
	for(int i = 0; i < n; i++){
		cin >> y;
		a.pb(y);
	}
	int d = mincoins(a, x);
	if(d == INT_MAX){
		cout << -1;
	}
	else{
		cout << d;
	}
	return 0;
}

// DP

#include <bits/stdc++.h>

using namespace std;
//using namespace std::chrono;

int mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, y;
	cin >> n >> x;
	v a;
	for(int i = 0; i < n; i++){
		cin >> y;
		a.pb(y);
	}
	v dp(x+1, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(a[j] <= i){
				y = dp[i - a[j]];
				if(y != INT_MAX && y+1 < dp[i]){
					dp[i] = y+1;
				}
			}
		}
	}
	cout << dp[x];
	return 0;
}