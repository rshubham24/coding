#include <bits/stdc++.h>

using namespace std;

int change(int n){
    int c, d, e;
    c = n/5;
    d = (n%5)/2;
    e = (n%5)%2;
    return c + d + e;
}

int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n, w, r, operation, min1 = INT_MAX;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        for(int j = 0; j < 5; j++){
            operation = 0;
            for(int i = n-1; i >= 0; i--){
                w = a[i] - a[0] + j;
                if(w != 0){
                    r = change(w);
                }
                else{
                    r = 0;
                }
                operation += r;
            }
            min1 = min(operation, min1);
        }
        cout << min1 << endl;
    }
    return 0;
}
