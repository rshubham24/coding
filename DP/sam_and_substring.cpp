#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    long long sum, m;
    sum = s[0] - '0';
    m = s[0] - '0';
    for(int i = 1; i < n; i++){
        m = 10*m + (i+1)*(s[i] - '0');
        m = m%mod;
        sum = (sum+m)%mod;
    }
    cout << sum;
    return 0;
}
