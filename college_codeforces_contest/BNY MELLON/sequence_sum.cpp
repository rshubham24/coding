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
#define vv vector<v>
#define vpl vector<pair<long long, long long>>
#define vvl vector<vl>
#define vvp vector<vp>
#define vvb vector<vb>
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, j, k;
	ll ans = 0;
	cin >> i >> j >> k;
	for(int n = i; n <= j; n++){
		ans += n;
	}
	for(int n = j-1; n >= k; n--){
		ans += n;
	}
	cout << ans;
	return 0;
}