// Recursion
#include <bits/stdc++.h>

using namespace std;

int rec(vector<int> &a, int i, int sum, int sum_total){
	if(i == 0){
		return abs(sum_total - 2*sum);
	}
	else{
		return min(rec(a, i-1, sum+a[i-1], sum_total), rec(a, i-1, sum, sum_total));
	}
}

int main(){
	int n, sum = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	cout << rec(a, n, 0, sum);
	return 0;
}

// Dynamic Programming

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
	for(int i = 1; i <= sum; i++){
		dp[0][i] = false;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			dp[i][j] = dp[i-1][j];
			if(a[i-1] <= j){
				dp[i][j] = dp[i-1][j-a[i-1]];
			}
		}
	}
	for(int i = sum/2; i>=0; i--){
		if(dp[n][i]){
			cout << sum - 2*j;
			break;
		}
	}
	return 0;
}