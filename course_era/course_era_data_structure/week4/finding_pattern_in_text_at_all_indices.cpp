#include <bits/stdc++.h> 

using namespace std; 
  
void printOccurrences(string txt, string pat){ 
    int found = txt.find(pat); 
    while (found != string::npos) { 
        cout << found << " "; 
        found = txt.find(pat, found + 1); 
    } 
} 
  
int main(){
	string y, z;
	cin >> y >> z;  
    printOccurrences(z, y);
    return 0;
}
 