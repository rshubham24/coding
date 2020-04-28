#include <bits/stdc++.h>

using namespace std;

int min1(int a, int b, int c){
	return min(min(a, b), c);
}

int edit_distance(string s, string r, int m, int n){
	int dp[m+1][n+1];
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j ++){
			if(i == 0){
				dp[i][j] = j;
			}
			else if(j == 0){
				dp[i][j] = i;
			}
			else if(s[i-1] == r[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main(){
	int t;
	cin >> t;
	for(int j = 0; j < t; j++){
		string s, r;
		cin >> s;
		cin >> r;
		int q = s.size(), p = r.size();
		cout << edit_distance(s, r, q, p) << endl; 
	}
    return 0;
}
