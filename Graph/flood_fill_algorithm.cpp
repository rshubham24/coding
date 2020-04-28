// pseudo code

function DFS(x, y, visited, n, m)
    if (x ≥ n OR y ≥ m)
        return
    if(x < 0 OR y < 0)
        return
    if(visisted[x][y] == True)
        return
    visited[x][y] = True
    DFS(x-1, y-1, visited, n, m)
    DFS(x-1, y, visited, n, m)
    DFS(x-1, y+1, visited, n, m)
    DFS(x, y-1, visited, n, m)
    DFS(x, y+1, visited, n, m)
    DFS(x+1, y-1, visited, n, m)
    DFS(x+1, y, visited, n, m)
    DFS(x+1, y+1, visited, n, m)