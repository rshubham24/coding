#include <bits/stdc++.h>

using namespace std;

void tower_hanoi(int n, char from, char to, char aux){
	if(n == 1){
		cout << "Move disk 1 from rod " << from << "to rod " << to << endl;
		return;
	}
	tower_hanoi(n-1, from, aux, to);
	cout << "Move disk " << n << "from rod " << from << " to rod " << to << endl;
	tower_hanoi(n-1, aux, to, from); 
}

int main(){
	int n;
	cin >> n;
	tower_hanoi(n, 'A', 'B', 'C');
	return 0;
}