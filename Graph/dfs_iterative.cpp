#include <bits/stdc++.h>

using namespace std;

void func(vector<vector<int>> &a, int c, int b){
	a[b].push_back(c);
	a[c].push_back(b);
}

void DFS(vector<vector<int>> &a, int b){
	bool visited[9];
	for(int i = 0; i < 9; i++){
		visited[i] = false;
	}
	stack<int> s;
    s.push(b); 
    while (!s.empty()){  
        int k = s.top(); 
        s.pop(); 
        if (!visited[k]){ 
            cout << k << " "; 
            visited[k] = true; 
        } 
        for(auto i = a[k].begin(); i != a[k].end(); ++i) 
            if (!visited[*i]) 
                s.push(*i); 
    }
}

int main(){
	vector<vector<int>> a(9);
	func(a, 0, 1);
	func(a, 0, 2);
	func(a, 1, 3);
	func(a, 1, 4);
	func(a, 2, 5);
	func(a, 2, 6);
	func(a, 5, 7);
	func(a, 5, 8);
	DFS(a, 0);
	cout << endl;
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}