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
	int n, sum;
	cin >> n;
	v a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> sum;
	int i = 0, j = 0, t = 0, ans = 0;
	while(j < n){
		if(t < sum){
			if(i >= n){
				ans = max(ans, i-j);
				break;
			}
			t += a[i];
			i++;
		}
		else if(t == sum){
			t += a[i];
			t -= a[j];
			i++;
			j++;
		}
		else if(t > sum){
			ans = max(ans, i-j-1);
			t -= a[j];
			j++;
		}
		if(t == sum){
			ans = max(ans, i-j);
		}
	}
	cout << ans;
	return 0;
}