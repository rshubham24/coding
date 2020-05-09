#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	bool dp[n+1][sum+1];
	for(int i = 0; i <= n; i++){
		dp[i][0] = true;
	}
	for(int i = 1; i<= sum; i++){
		dp[0][i] = false;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			dp[i][j] = dp[i-1][j];
			if(a[i-1] <= j){
				dp[i][j] = dp[i-1][j - a[i-1]];
			}
		}
	}
	for(int i = 1; i <= sum; i++){
		if(dp[n][i] == 1){
			cout << i << " ";
		}
	}
	return 0;
}