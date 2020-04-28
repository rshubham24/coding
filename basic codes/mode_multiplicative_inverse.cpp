#include<bits/stdc++.h>

using namespace std;

int mmi(int x,unsigned int y,unsigned int m){
	if(y == 0){
		return 1;
	}
	int p = mmi(x, y/2, m)%m;
	p = (p*p)%m;
	if(y%2 == 0){
		return p;
	}
	else{
		return (x*p)%m;
	}
} 
   
int main() { 
	int n = 3;
	int m = 13;
	int d = mmi(n, m-2, m);// Here n is the number whose mmi we are calculating and m is the mode.
	cout << d;
    return 0;
} 
