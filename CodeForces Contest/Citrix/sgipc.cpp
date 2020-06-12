#include <bits/stdc++.h>

//using namespace std::chrono;
using namespace std;

long long mod = 1000000007;

typedef long long ll;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define v vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<pair<int, int>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
    cin >> n >> k;
    ll dp[n+1][k+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < k+1; j++){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int j = 1; j < k+1; j++){
        for(int i = 1; i < n+1; i++){
            dp[i][j] = dp[i-1][j-1];
            if(i > j){
                dp[i][j] += dp[i-j][j];   
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][k];
	return 0;
}