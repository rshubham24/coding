/*Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"

Rules The game is played with a cubic die of  faces numbered  to .

Starting from square , land on square  with the exact roll of the die. If moving the number rolled would place the player beyond square , no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Function Description

Complete the quickestWayUp function in the editor below. It should return an integer that represents the minimum number of moves required.

quickestWayUp has the following parameter(s):

ladders: a 2D integer array where each  contains the start and end cell numbers of a ladder
snakes: a 2D integer array where each  contains the start and end cell numbers of a snake
Input Format

The first line contains the number of tests, .

For each testcase:
- The first line contains , the number of ladders.
- Each of the next  lines contains two space-separated integers, the start and end of a ladder.
- The next line contains the integer , the number of snakes.
- Each of the next  lines contains two space-separated integers, the start and end of a snake.

Constraints



The board is always  with squares numbered  to .
Neither square  nor square  will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print -1.
*/
#include <bits/stdc++.h>

using namespace std;

void snake(bool vis[], int a[], int src, int dis[]){
    queue<int> q;
    int next_node, node;
    q.push(src);
    dis[src] = 0;
    vis[src] = true;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++){
           next_node = a[node+i];
           if(next_node > 0 && next_node < 101 && vis[next_node] == false){
               dis[next_node] = dis[node] + 1;
               vis[next_node] = true;
               q.push(next_node);
           }
        }
    }
    if(vis[100] == false){
        cout << -1 << endl;
    }
    else{
        cout << dis[100] << endl;
    }
}

int main(){
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        bool vis[110];
        int a[110];
        int dis[110];
        for(int i = 1; i < 110; i++){
            a[i] = i;
            vis[i] = false;
        }
        int l, s, x, y;
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> x >> y;
            a[x] = y;
        }
        cin >> s;
        for(int i = 0; i < s; i++){
            cin >> x >> y;
            a[x] = y;
        }
        snake(vis, a, 1, dis);
    }
    return 0;
}
