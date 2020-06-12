#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 5;
int s[N];
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;
    cin>>n;
    int s0;
    cin>>s0;
    int k,b,m;
    cin>>k>>b>>m;
    int a;
    cin>>a;
    s[1] = s0;
    for(int i=2;i<=n;i++){
        s[i] = (k * s[i-1] + b)%m + 1 + s[i-1];
    }

    int j = n;
    int ans = 0;
    for(int i=1;i<=n;i++){
        int val = a/s[i];
        int k;
        for(k=j;k>=1;k--){
            if(s[k] <= val){
                j = k;
                break;
            }
        }
        if(k == 0)break;
        ans += j;
    }
    cout << ans << "\n";
    
    return 0;    
}