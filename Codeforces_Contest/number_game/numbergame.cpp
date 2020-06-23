//FastestFinger wins for n = 1 , n  =2^x where (x > 1) and n = 2*p where p is a prime ≥ 3 else Ashishgup wins.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

bool check_prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ans = (n == 1);
        if(n > 2 && n % 2 == 0){
            if((n & n-1) == 0){
                ans = true;
            }
            else if(n%4 != 0 && check_prime(n/2)){
                ans = true;
            }
        }
        if(ans){
            cout << "FastestFinger" << endl;
        }
        else{
            cout << "Ashishgup" << endl;
        }
    }
	return 0;
}	