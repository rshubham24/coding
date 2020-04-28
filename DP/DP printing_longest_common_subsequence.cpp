#include <bits/stdc++.h>

using namespace std;

void lcs(int a[], int b[], int n, int m){
    int l[n+1][m+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                l[i][j] = 0;
            }
            else if(a[i-1] == b[j-1]){
                l[i][j] = l[i-1][j-1] + 1;
            }
            else{
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    int i = n, j = m;
    vector<int> c;
    while (i > 0 && j > 0){ 
        if (a[i-1] == b[j-1]){ 
            c.push_back(a[i-1]); 
            i--;
            j--;     
        } 
        else if(l[i-1][j] > l[i][j-1]){
            i--;
        } 
        else{
            j--;
        } 
   }
    reverse(c.begin(), c.end());
    for(int x : c){
        cout << x << " ";
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    lcs(a, b, n, m);
    return 0;
}