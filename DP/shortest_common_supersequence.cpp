#include <bits/stdc++.h>

using namespace std;

void scs(string s, string k){
	int l = s.size(), m = k.size();
	int dp[l+1][m+1];
	for(int i = 0; i <= l; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(s[i-1] == k[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	vector<pair<int, int>> a;
	int i = l, j = m;
	while(i > 0 && j > 0){
		if(s[i-1] == k[j-1]){
			i--;
			j--;
			a.push_back(make_pair(i, j));
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	reverse(a.begin(), a.end());
	string w = "";
	int n = 0, p = 0, d, e;
	for(int i = 0; i < a.size(); i++){
		d = a[i].first;
		e = a[i].second;
		for(int j = n; j < d; j++){
			w += s[j];
		}
		for(int j = p; j < e; j++){
			w += k[j];
		}
		w += s[d];
		n = d+1;
		p = e+1;
	}
	for(int i = n; i < l; i++){
		w += s[i];
	}
	for(int i = p; i < m; i++){
		w += k[i];
	}
	cout << w;
}

int main(){
	string s, k;
	cin >> s >> k;
	scs(s, k);
	return 0;
}
