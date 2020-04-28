#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, l;
	long long x, y;
	cin >> k >> l;
	vector<long long> b;
	pair<long long, int> c;
	for(int i = 0; i < l; i++){
		cin >> x;
		b.push_back(x);
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	for(int i = 0; i < k; i++){
		q.push(make_pair(0, i));
	}
	for(int i = 0; i < l; i++){
		c = q.top();
		q.pop();
		x = c.second;
		y = c.first;
		cout << x << " " << y << endl;
		q.push(make_pair(y+b[i], x));
	}
	return 0;
}