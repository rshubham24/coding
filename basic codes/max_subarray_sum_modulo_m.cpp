#include<bits/stdc++.h> 

using namespace std; 
   
long long int maxSubarray(long long int arr[],int n, long long int m) { 
    long long int x, prefix = 0, maxim = 0; 
    set<long long int> S; 
    S.insert(0);     
    for (int i = 0; i < n; i++){
        prefix = (prefix + arr[i])%m; 
        maxim = max(maxim, prefix); 
        auto it = S.lower_bound(prefix+1); 
        if (it != S.end()){ 
            maxim = max(maxim, prefix - (*it) + m ); 
        }
        S.insert(prefix); 
    }  
    return maxim; 
}

int main() { 
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        long long int m;
        cin >> n >> m;
        long long int a[n];
        for(int j = 0; j < n; j++){
            cin >> a[j];
        }
        cout << maxSubarray(a, n, m) << endl;
    }
    return 0; 
} 
