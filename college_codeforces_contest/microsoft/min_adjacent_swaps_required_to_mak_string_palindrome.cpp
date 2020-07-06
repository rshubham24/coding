#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
ll mode = 1000000007;
#define f first
#define s second
#define ss string
#define mp make_pair
#define pb push_back
#define p pair<int, int>
#define pp pair<int, p>
#define v vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define vp vector<p>
#define vpp vector<pair<int, p>>
#define vv vector<v>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
 
int main() {
        ss k;
        cin >> k;
        v c(26,0);
        for(char x : k){
            c[x-'a']++;
        }
        int g = 0;
        rep(i, 26){
            g += (c[i] & 1);
        }
        if(g > 1){
            cout << -1 << endl;
        }
        else{
            int end = k.size()-1, ans = 0;
            rep(i, k.length()/2){
                if(k[i] == k[end-i])
                    continue;
                int j, l;
                for(j = i+1 ; j <= end-i && k[j]!=k[end-i] ; j++);
                for(l = end-i-1; l >= i && k[l]!=k[i] ; l--);
                ans += min(j-i, end-i-l);
                if(j-i < end-i-l){                    
                    for(int q = j; q > i ; q--)
                        swap(k[q], k[q-1]);
                }else{
                    for(int q = l ; q < end-i ; q++)
                        swap(k[q], k[q+1]);
                }            
            }
            cout << ans << endl;
        }
}