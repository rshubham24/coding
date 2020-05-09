#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, x, y, w;
    cin >> n >> m;
    bool vis[1200][1200];
    for(int i = 0; i < 1200; i++){
        for(int j = 0; j < 1200; j++){
            vis[i][j] = false;
        }
    }
    vector<vector<pair<int, int>>> a(n);
    for(int i = 0; i < m; i++){
        cin >> x >> y >> w;
        a[x-1].push_back(make_pair(y-1, w));
        a[y-1].push_back(make_pair(x-1, w));
    }
    cin >> x >> y;
    queue<pair<int, int>> q;
    q.push(make_pair(x-1, 0));
    while(!q.empty()){
        int k = q.front().first;
        int e = q.front().second;
        vis[k][e] = true;
        q.pop();
        for(int i = 0; i < a[k].size(); i++){
            int to = a[k][i].first;
            int cost = a[k][i].second;
            if(!vis[to][(e | cost)]){
                q.push(make_pair(to, (e | cost)));
                vis[to][(e | cost)] = true;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < 1200; i++){
        if(vis[y-1][i]){
            ans = i;
            break;
        }
    }
    cout << ans;;
    return 0;
}