#include <bits/stdc++.h>

using namespace std;

vector<int> f(100050, 0);
int k;
vector<long long> dis(100050, 0);
long long maxdis, ans = 0;

void dfs(int src, int p, int x, vector<vector<pair<int, int>>> &a, vector<vector<pair<int, int>>> &b){
    for(int i = 0; i < a[src].size(); i++){
        if(a[src][i].first != p){
            dfs(a[src][i].first, src, a[src][i].second, a, b);
            f[src] += f[a[src][i].first];
        }
    }
    if(f[src] != 0 && f[src] < k){
        b[src].push_back(make_pair(p, x));
        b[p].push_back(make_pair(src, x));
    }
}

void dist(int src, int p, int x, vector<vector<pair<int, int>>> &b){
    long long max1 = 0, max0 = 0;
    ans = ans + (2 * x);
    for(int i = 0; i < b[src].size(); i++){
        if(b[src][i].first != p){
            dist(b[src][i].first, src, b[src][i].second, b);
            dis[src] = max(dis[src], dis[b[src][i].first] += b[src][i].second);
            if(dis[b[src][i].first] > max0){
                max1 = max0;
                max0 = dis[b[src][i].first]; 
            }        
            else if(dis[b[src][i].first] > max1){
                max1 = dis[b[src][i].first];
            }
        }
    }
    maxdis = max(maxdis, max1 + max0);
}

int main(){
    int n, x, y, w;
    cin >> n >> k;
    vector<int> l;
    for(int i = 0; i < k; i++){
        cin >> x;
        l.push_back(x-1);
        f[x-1]++;
    }
    vector<vector<pair<int, int>>> a(n);
    vector<vector<pair<int, int>>> b(n);
    for(int i = 0; i < n-1; i++){
        cin >> x >> y >> w;
        a[x-1].push_back(make_pair(y-1, w));
        a[y-1].push_back(make_pair(x-1, w));
    }
    dfs(0, -1, 0, a, b);
    dist(l[0], -1, 0, b);
    cout << ans - maxdis;
    return 0;
}