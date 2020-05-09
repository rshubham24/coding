#include <bits/stdc++.h>

using namespace std;

int dice(int n, int m, int x){
	dp[n+1][x+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= x; j++){
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= m && i <= x; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <=n; i++){
		for(int j = 1; j <= x; j++){
			for(k = 1; k <=m && k < j; k++){
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	return dp[n][x];
}

int main(){
	int n, m, x;
	cin >> n >> m >> x;
	cout << dice(n, m, x);
	return 0;
}