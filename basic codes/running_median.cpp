#include <bits/stdc++.h>

using namespace std;

multiset<long long int> a;
multiset<long long int> b; 
multiset<long long int>::iterator it, it1;

void check(){
    int n = a.size(), m = b.size();
    if(m == n + 1){
        a.insert(*b.begin());
        b.erase(b.begin());
    }
    if(n == m + 2){
        it = a.end();
        it--;
        b.insert(*it);
        a.erase(it);
    }
}

void insert(int x){
    if(a.empty() && b.empty()){
        a.insert(x);
    }
    else if(!a.empty() && b.empty()){
        if(x >= *a.begin()){
            b.insert(x);
        }
        else{
            long long int t = *a.begin();
            a.erase(a.begin());
            a.insert(x);
            b.insert(t);
        }
    }
    else{
        it = b.begin();
        if(x <= *it){
            a.insert(x);
        }
        else{
            b.insert(x);
        }
    }
    check();
    if(a.size() != b.size()){
        cout << *a.rbegin() << endl; 
    }
    else{
        long long int e = (*a.rbegin() + *b.begin());
        if(e%2 == 0){
            cout << e/2 << endl;
        }
        else{
            cout << e/2 << ".5" << endl;
        }
    }
}

void remove(int x){
    it = a.find(x);
    it1 = b.find(x);
    if(it == a.end() && it1 == b.end()){
        cout << "Wrong!" << endl;
        return;
    }
    else if(it == a.end() && it1 != b.end()){
        b.erase(it1);
    }
    else if(it1 == b.end() && it != a.end()){
        a.erase(it);
        }
    else if(it1 != b.end() && it != a.end()){
        a.erase(it);
    }
    check();
    if(a.size() == 0 && b.size() == 0){
        cout << "Wrong!" << endl;
    }
    else if(a.size() != b.size()){
        cout << *a.rbegin() << endl; 
    }
    else{
        long long int e = (*a.rbegin() + *b.begin());
        if(e%2 == 0){
            cout << e/2 << endl;
        }
        else{
            cout << e/2 << ".5" << endl;
        }
    }
}

int main(){
    int n;
    long long int x;
    char c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c >> x;
        if(c == 'a'){
            insert(x);
        }
        if(c == 'r'){
            remove(x);
        }
    }
    return 0;
}
