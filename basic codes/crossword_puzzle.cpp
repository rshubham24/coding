#include <bits/stdc++.h>

using namespace std;

vector<string> grid(10);
vector<string> city; 
bool e;

void crossword(int index){
    if(!e){
        return;
    }
    if(index == city.size()){
        if(e){
            for(auto i: grid){
                cout << i << endl;
            }
            e = false;
        }
        return;
    }
    int k;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(k = 0; k < city[index].size() && (i + k) < 10; k++){
                if(grid[i+k][j] != '-' && grid[i+k][j] != city[index][k]){
                    break;
                }
            }
            if(k == city[index].size()){
                vector<string> tmp = grid;
                for(k = 0; k < city[index].size(); k++){
                    grid[i+k][j] = city[index][k];
                }
                crossword(index+1);
                grid = tmp;
            }
            for(k = 0; k < city[index].size() && (j + k) < 10; k++){
                if(grid[i][j+k] != '-' && grid[i][j+k] != city[index][k]){
                    break;
                }
            }
            if(k == city[index].size()){
                vector<string> tmp = grid;
                for(k = 0; k < city[index].size(); k++){
                    grid[i][j+k] = city[index][k];
                }
                crossword(index+1);
                grid = tmp;
            }
        }
    }
}

int main(){
    e = true;
    string s, k;
    for(int i = 0; i < 10; i++){
        cin >> grid[i];
    }
    cin >> s;
    for(auto i: s){
        if(i == ';'){
            city.push_back(k);
            k = "";
        }
        else{
            k += i;
        }
    }
    city.push_back(k);
    crossword(0);
    return 0;
}
