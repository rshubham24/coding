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
	int n, m, h, g, x;
	cin >> n >> m;
	v a(n, 1), b(m, 1);
	cin >> h;
	for(int i = 0; i < h; i++){
		cin >> x;
		x--;
		a[x] = 0;
	}
	cin >> g;
	for(int i = 0; i < g; i++){
		cin >> x;
		x--;
		b[x] = 0;
	}
	int maxe1 = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			sum++;
		}
		else{
			sum = 0;
		}
		maxe1 = max(maxe1, sum);
	}
	int maxe2 = 0;
	sum = 0;
	for(int i = 0; i < m; i++){
		if(b[i] == 0){
			sum++;
		}
		else{
			sum = 0;
		}
		maxe2 = max(maxe2, sum);
	}
	if(maxe1 == 0 && maxe2 == 0){
		cout << 1;
	}
	else if(maxe1 == 0 && maxe2 != 0){
		cout << maxe2+1;
	}
	else if(maxe1 != 0 && maxe2 == 0){
		cout << maxe1+1;
	}
	else{
		cout << (maxe1+1)*(maxe2+1);
	}
	return 0;
}