#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, max = -1, index;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> m;
	deque<int> b(m);
	for(int i = 0; i < m; i++){
        while(!b.empty() && a[i] >= a[b.back()]){ 
            b.pop_back();
        }  
        b.push_back(i);
	}
	for(int i = m; i < n; i++){
		cout << a[b.front()] << " ";
		while(!b.empty() && b.front() <= i - m){ 
            b.pop_front();
        }
        while(!b.empty() && a[i] >= a[b.back()]){ 
            b.pop_back();
        }  
        b.push_back(i);
	}
	cout << a[b.front()];
	return 0;
}