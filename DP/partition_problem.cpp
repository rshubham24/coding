#include <bits/stdc++.h>

using namespace std;

bool partition(vector<int> &a, int n, int sum){
	int dp[n+1][sum+1];
	for(int i = 0; i < n+1; i++){
		dp[i][0] = 1;
	}
	for(int i = 1; i < sum+1; i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			dp[i][j] = dp[i-1][j];
			if(a[i-1] <= j){
				dp[i][j] += dp[i-1][j-a[i-1]];
			}
			if(dp[i][j] > 1){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	if(partition(a, n, sum)){
		cout << "true";
	}
	else{
		cout << "false";
	}
	return 0;
}
