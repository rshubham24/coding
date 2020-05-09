// Recursive

#include <bits/stdc++.h>

using namespace std;

int insert(string s, int a, int b){
	if(a == b){
		return 0;
	}
	if(a > b){
		return INT_MAX;
	}
	if(a == b-1){
		if(s[a] == s[b]){
			return 0;
		}
		else{
			return 1;
		}
	}
	if(s[a] == s[b]){
		return insert(s, a+1, b-1);
	}
	else{
		return min(insert(s, a+1, b), insert(s, a, b-1))+1;
	}
}

int main(){
	string s;
	cin >> s;
	cout << insert(s, 0, s.size()-1);
	return 0;
}

// DP

#include <bits/stdc++.h>

using namespace std;

int insert(string s){
	string rev = s;
	int n = s.size();
	reverse(rev.begin(), rev.end());
	int dp[n+1][n+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(s[i-1] == rev[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return n - dp[n][n];
}

int main(){
	string s;
	cin >> s;
	cout << insert(s);
	return 0;
}