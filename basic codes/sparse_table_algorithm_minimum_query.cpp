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

int n, q;
v a;
vv b;

void preprocess(){
	b.pb(v(n));
	for(int i = 0; i < n; i++){
		b[0][i] = a[i];
	}
	int d;
	for(int i = 1, k = 2; k <= n; k *= 2, i++){
		d = n-k+1;
		b.pb(v(d));
		for(int j = 0; j < d; j++){
			b[i][j] = min(b[i-1][j], b[i-1][j+k/2]);
		}
	}
}

void output(int x, int y){
	int d = log2(y - x + 1);
	int e = y - x + 1 - pow(2, d);
	cout << min(b[d][x], b[d][x+e]) << endl;
}

void query(){
	int x, y;
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		x--;
		y--;
		output(x, y);
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	a = v(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	preprocess();
    query();
	return 0;
}