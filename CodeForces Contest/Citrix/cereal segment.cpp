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
		int x, n, ans = 0;
		cin >> x >> n;
		v a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		deque<int> q;
		for(int i = 0; i < x; i++){
			while(!q.empty() && a[i] <= a[q.back()]){
				q.pop_back();
			}
			q.pb(i);
		}
		for(int i = x; i < n; i++){
			ans = max(ans, a[q.front()]);
			while(!q.empty() && q.front() <= i-x){
				q.pop_front();
			}
			while(!q.empty() && a[i] <= a[q.back()]){
				q.pop_back();
			}
			q.pb(i);
		}
		ans = max(ans, a[q.front()]);
		cout << ans;
		return 0;
	}