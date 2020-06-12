#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n;
	v a(n);
	v sum(n, 0);
	cin >> x;
	if(x == 1){
		sum[0] = 1;
	}
	else{
		sum[0] = -1;
	}
	for(int i = 1; i < n; i++){
		cin >> a[i];
		if(a[i] == 1){
			sum[i] = sum[i-1]+1;
		}
		else{
			sum[i] = sum[i-1]-1;
		}
	}
	if(sum[n-1] < 0){
		cout << 0;
	}
	else{
		for(int i = 0; i < n-1; i++){
			if((sum[n-1] - sum[i]) < sum[i]){
				cout << i+1;
				break;
			}
		}
	}
	return 0;
}