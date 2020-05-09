// Iterative formulae :  max_prod(n) = max(i*(n-i), max_prod(n-i)*i)

// Greedy_algorithm

#include <bits/stdc++.h>

using namespace std;

int prod(int n){
	if(n == 2 || n == 3){
		return n-1;
	}
	int a = 1;
	while(n > 4){
		n -= 3;
		a *= 3;
	}
	return a*n;
}

int main(){
	int n;
	cin >> n;
	cout << prod(n);
	return 0;
}