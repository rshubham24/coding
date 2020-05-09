// Constraint - next number should be greater then previous one by 1;

// Recursive

#include <bits/stdc++.h>

using namespace std;

int path(vector<vector<int>> &a, int i, int j, int n, int value){
	if(i < 0 || i >= n || j < 0 || j >= n){
		return 0;
	}
	if(a[i][j] == value+1){
		int d = 0;
		d = max(path(a, i-1, j, n, a[i][j]), path(a, i+1, j, n, a[i][j]));
		d = max(path(a, i, j+1, n, a[i][j]), d);
		d = max(path(a, i, j-1, n, a[i][j]), d);
		return d+1;
	}
	else{
		return 0;
	}
}

int rec(vector<vector<int>> &a, int n){
	int ans = 0, d;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d = 0;
			d = max(path(a, i-1, j, n, a[i][j]), path(a, i+1, j, n, a[i][j]));
			d = max(path(a, i, j+1, n, a[i][j]), d);
			d = max(path(a, i, j-1, n, a[i][j]), d);
			ans = max(d, ans);
		}
	}
	return ans+1;
}

int main(){
	int n, x;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
			a[i].push_back(x);
		}
	}
	cout << rec(a, n);
	return 0;
}

// DP

#include <bits/stdc++.h>

using namespace std;

int path(vector<vector<int>> &a, int i, int j, int n, int value, vector<vector<int>> &dp){
	if(i < 0 || i >= n || j < 0 || j >= n){
		return 0;
	}
	if(dp[i][j] != -1){
	    return dp[i][j];
	}
	if(a[i][j] == value+1){
		int d = 0;
		d = max(path(a, i-1, j, n, a[i][j], dp), path(a, i+1, j, n, a[i][j], dp));
		d = max(path(a, i, j+1, n, a[i][j], dp), d);
		d = max(path(a, i, j-1, n, a[i][j], dp), d);
		dp[i][j] = d+1;
		return d+1;
	}
	else{
		return 0;
	}
}

int rec(vector<vector<int>> &a, int n, vector<vector<int>> &dp){
	int ans = 0, d;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
		    if(dp[i][j] != -1){
		        ans = max(dp[i][j], ans);
		        continue;
		    }
			d = 0;
			d = max(path(a, i-1, j, n, a[i][j], dp), path(a, i+1, j, n, a[i][j], dp));
			d = max(path(a, i, j+1, n, a[i][j], dp), d);
			d = max(path(a, i, j-1, n, a[i][j], dp), d);
			dp[i][j] = d+1;
			ans = max(d+1, ans);
		}
	}
	return ans;
}

int main(){
	int n, x;
	cin >> n;
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector<vector<int>> dp(n);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
	        dp[i].push_back(-1);
	    }
	}
	cout << rec(a, n, dp);
	return 0;
}
