#include <bits/stdc++.h>

using namespace std;

int s[200005];
long long int ans[400020];

void imply(int m){
    for(int i = 0; i < m; i++){
        ans[i] = 0;
    }
}

int root(int x, int f[]){
    while(f[x] != x){
        f[x] = f[f[x]];
        x = f[x];
    }
    return x;
}

void dfs(vector<vector<pair<int, int>>> &a, int x, int y, int n){
    s[x] = 1;
    for(int i = 0; i < a[x].size(); i++){
        if(a[x][i].first != y){
            dfs(a, a[x][i].first, x, n);
            s[x] += s[a[x][i].first];
            ans[a[x][i].second] += (long long int)(n - s[a[x][i].first])*s[a[x][i].first];
        }
    }
}

int main(){
    int n, m, x, y, w;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> e; 
    for(int i = 0 ; i < m; i++){
        cin >> x >> y >> w;
        e.push_back(make_pair(w, make_pair(x, y)));
    }
    sort(e.begin(), e.end());
    vector<vector<pair<int, int>>> a(n+1);
    int f[n+1];
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    for(int i = 0; i < m; i++){
        x = e[i].second.first;
        y = e[i].second.second;
        w = e[i].first;
        if(root(x, f) != root(y, f)){
            f[root(y, f)] = root(x, f);
            a[x].push_back(make_pair(y, w));
            a[y].push_back(make_pair(x, w));
        }
    }
    imply(m);
    dfs(a, 1, 0, n);
    for(int i = 0; i < 2 * m + 10; i++) {
        ans[i + 1] += ans[i] / 2;
        ans[i] %= 2;
    }
    int gqy = 2 * m + 10;
    while(ans[gqy - 1] == 0) {
        gqy--;
    }
    for(int i = gqy - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}
