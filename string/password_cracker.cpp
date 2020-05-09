#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        char w[10][20];
        int lp[10];
        for(int i = 0; i < n; i++){
            cin >> w[i];
            lp[i] = strlen(w[i]);
        }
        int a[2010];
        char x[2010];
        cin >> x;
        int k = strlen(x);
        a[k] = n;
        for(int i = k-1; i >= 0; i--){
            a[i] = -1;
            for(int j = 0; j < n; j++){
                if((i+lp[j]) <= k && a[i+lp[j]] >= 0 && !strncmp(x + i, w[j], lp[j])){
                    a[i] = j;
                    break;
                }
            }
        }
        if(a[0] == -1){
            cout << "WRONG PASSWORD" << endl;
        }
        else{
            for(int i = 0; i < k; i+=lp[a[i]]){
                cout << w[a[i]];
                if(i+lp[a[i]] == k){
                    cout << endl;
                }
                else{
                    cout << " ";
                }
            }
        }
    }   
    return 0;
}