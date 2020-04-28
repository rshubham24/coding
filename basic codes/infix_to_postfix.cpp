#include <bits/stdc++.h>

using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int main() {
    string s;
    int j = 0;
    char c;
    string os;
    getline(cin, s);
    stack<char> a;
    a.push('$');
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            a.push(s[i]);
        }
        else if(s[i] == ')'){
            while(a.top() != '('){
                c = a.top();
                os += c;
                a.pop();
            }
            a.pop();
        }
        else if(isalnum(s[i])){
            c = s[i];
            os += c;
        }
        else{
            while(a.top() != '$' && prec(s[i]) <= prec(a.top())){
                c = a.top();
                os += c;
                a.pop();
            }
            a.push(s[i]);
        }
    }
    while(a.top() != '$'){
        c = a.top();
        os += c;
        a.pop();
    }
    cout << os;
    return 0;
}
