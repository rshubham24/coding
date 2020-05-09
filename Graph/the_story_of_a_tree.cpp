#include <bits/stdc++.h>

using namespace std;

void dfs(int v, vector<vector<int>> &a, vector<int> &f, int q, vector<int> &parent){
    parent[v] = q;
    for(int i = 0; i < a[v].size(); i++){
        if(a[v][i] == q){
            continue;
        }
        f[a[v][i]] += f[v];
        dfs(a[v][i], a, f, v, parent);
    }
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int n, x, y, m, k, ans = 0;
        cin >> n;
        vector<vector<int>> a(n);
        vector<int> parent(n, -1);
        for(int i = 0; i < n-1; i++){
            cin >> x >> y;
            a[x-1].push_back(y-1);
            a[y-1].push_back(x-1);
        }
        vector<int> f(n, 0);
        dfs(0, a, f, -1, parent);
        cin >> m >> k;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            x--;
            y--;
            if(parent[y] == x){
                f[0]++;
                f[y]--;
            }
            else{
                f[x]++;
            }
        }
        dfs(0, a, f, -1, parent);
        for(int i = 0; i < n; i++){
            if(f[i] >= k){
                ans++;
            }
        }
        int w = __gcd(ans, n);
        if(w != 1 && ans!= 0){
            cout << ans/w << "/" << n/w << endl;
        }
        else if (ans == 0){
            cout << ans << "/" << 1 << endl;
        }
        else{
            cout << ans << "/" << n << endl;
        }
    }
    return 0;
}
