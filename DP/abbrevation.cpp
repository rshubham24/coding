#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        string s, r;
        cin >> s >> r;
        int n = s.size(), m = r.size();
        bool dp[n+1][m+1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = false;
            }
        }
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                if(!dp[i][j]){
                    continue;
                }
                if(s[i] >= 'a' && s[i] <= 'z'){
                    dp[i+1][j] = 1;
                }
                if(s[i] >= 'A' && s[i] <= 'Z' && s[i] == r[j]){
                    dp[i+1][j+1] = 1;
                }
                if(s[i] >= 'a' && s[i] <= 'z' && (s[i] - 32) == r[j]){
                    dp[i+1][j+1] = 1;
                }
            }
        }
        if(dp[n][m]){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
