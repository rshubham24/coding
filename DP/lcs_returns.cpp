#include <bits/stdc++.h>

using namespace std;

int dp[5050][5050], dpa[5050][5050];

int main(){
    string s, r;
    cin >> s >> r;
    int m = s.size(), n = r.size(), count = 0, d;
    char q;
    set<int> a;
    s = '$' + s;
    r = '$' + r;
    for(int i = 0; i <= n; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i] == r[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    d = dp[m][n];
    for(int i = m+1; i >= 1; i--){
        for(int j = n+1; j >= 1; j--){
            if(i == m+1 || j == n+1){
                dpa[i][j] = 0;
            }
            else if(s[i] == r[j]){
                dpa[i][j] = dpa[i+1][j+1] + 1;
            }
            else{
                dpa[i][j] = max(dpa[i+1][j], dpa[i][j+1]);
            }
        }
    }
    for(int i = 0; i <= m; i++){
        a.clear();
        for(int j = 1; j <= n; j++){
            if((dp[i][j-1] + dpa[i+1][j+1]) == d){
                a.insert((int)r[j]);
            }
        }
        count += a.size();
    }
    cout << count;
    return 0;
}
