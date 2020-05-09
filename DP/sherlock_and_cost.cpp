#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = 0;
        for(int i = 0; i < n-1; i++){
            dp[i+1][0] = max(dp[i][0], dp[i][1] + abs(a[i]-1));
            dp[i+1][1] = max(dp[i][0] + abs(a[i+1]-1), dp[i][1] + abs(a[i+1]-a[i]));
        }
        cout << max(dp[n-1][0], dp[n-1][1]) << endl;
    }    
    return 0;
}