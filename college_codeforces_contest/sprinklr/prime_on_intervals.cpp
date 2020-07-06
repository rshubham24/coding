#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007;
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
#define vvs vector<vs>
#define vvl vector<vl>
#define vvp vector<vp>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repa(i, a, n) for(int i = a; i <= (n); ++i)
#define repd(i, n) for(int i = n; i >= 0; --i)
#define all(x) (x).begin(), (x).end()

int  N = 1000002;
v a(N, 1);

int get_prime_count(int start, int len){
    int finish = start + len -1;
    if(start != 0){
        return a[finish] - a[start-1];
    }
    else{
        return a[finish];   
    }
}

bool valid(int len, int k, int x, int y){
    repa(i, x, y-len+1){
        int t = get_prime_count(i, len);
        if(t < k){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    a[0] = a[1] = 0;
    for(int i = 2; i < N; i++){
        if(a[i] == 1){
            for(int j = i*2; j < N; j += i){
                a[j] = 0;
            }
        }
    }
    repa(i, 1, N-1){
        a[i] += a[i-1];
    }
    int x, y, k;
    cin >> x >> y >> k;
    int ans = -1, l = 1, h = y-x+1;
    while(l <= h){
        int mid = (l+h)/2;
        if(valid(mid, k, x, y)){
            ans = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}