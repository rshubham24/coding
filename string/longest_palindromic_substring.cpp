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
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvb vector<vb>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)

string lps(string k){
        int n = k.size(), j;
        int index_i, index_j;
        int size = 1;
        vvb dp(n, vb(n, false));
        rep(i, n){
            dp[i][i] = true;
            if(i < n-1 && k[i] == k[i+1]){
                dp[i][i+1] = true;
                if(size == 1){
                    size++;
                    index_i = i;
                    index_j = i+1;
                }
            }
        }
        repa(l, 2, n-1){
            rep(i, n-l){
                j = i + l;
                if(dp[i+1][j-1] && k[i] == k[j]){
                    dp[i][j] = true;
                    if((j-i+1) > size){
                        size++;
                        index_i = i;
                        index_j = j;
                    }
                }
            }
        }
        if(size == 1){
            string e = "";
            if(n != 0){
                e = k[0];
            }
            return e;
        }
        string e;
        repa(i, index_i, index_j){
            e += k[i];
        }
        return e;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string k;
    cin >> k;
    cout << lps(k);
    return 0;
}   