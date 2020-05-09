#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, w;
	cin >> n >> w;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	int dp[n+1][w+1];
	for(int i = 0; i < n+1; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i < w+1; i++){
		dp[0][i] = -1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			dp[i][j] = dp[i-1][j];
			if(a[i-1] <= j){
				if(dp[i-1][j-a[i-1]] != -1){
					dp[i][j] = max(b[i] + dp[i-1][j-a[i-1]], dp[i-1][j]);
				}
			}
		}
	}
	int maxe = 0;
	for(int i = 1; i <= w; i++){
		maxe = max(dp[n][i], maxe);
	}
	cout << maxe;
	return 0;
}
