#include <bits/stdc++.h>

using namespace std;

static int m = 0;
vector<pair<int, int>> r;

void min_heapify(int *a,int i,int n){
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n){
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            m++;
            a[j/2] = a[j];
            r.push_back(make_pair((j/2)-1, j-1));
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}

void build_minheap(int *a, int n){
    int i;
    for(i = n/2; i >= 1; i--){
        min_heapify(a,i,n);
    }
}
int main(){
    int n, i, x;
    cin >> n;
    int a[n];
    for (i = 1; i <= n; i++){
        cin >> a[i];
    }
    build_minheap(a, n);
    if(m == 0){
        cout << 0;
    }
    else{
        cout << r.size() << endl;
        for(int i = 0; i < r.size(); i++){
            cout << r[i].first << " " << r[i].second << endl;
        }
    }
}