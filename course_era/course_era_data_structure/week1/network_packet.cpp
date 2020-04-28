#include <bits/stdc++.h>

using namespace std;
    
void exec (int S, int n){
    vector <int> s(n),t(n),ans(n, 0);
    int i,j,k,l=0,c=0,z=0;
    for (i=0;i<n;i++)cin>>s[i]>>t[i];
    if(n > 0){
        c = s[0]+t[0];
    }
    s.push_back(100000000);
    queue <int> q;
    i=0;
    while(i<n){
        if (q.empty()){
            q.push(i);
        }
        else{
            if (q.size()<S || (t[i-1] == 0 && ans[i-1] != -1)){
                q.push(i);
            }
            else{
                ans[i]=-1;
            }
        }
        i++;
        while (s[i]>=c && !q.empty()){
            k=q.front();
            if (z<=s[k]){
                ans[k]=s[k];
                z=s[k]+t[k];
                q.pop();
            }
            else if (z>s[k]){
                ans[k]=z;
                z=z+t[k];
                q.pop();
            }
            k = q.front();
            if (c<=s[k]){
                c=s[k]+t[k];
            }
            else if (c>s[k]){
                c=c+t[k];
            }
        }
    }
    for (i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return;
}

int main() {
    int s, n;
    cin>>s>>n;
	exec(s,n);
	return 0;
}