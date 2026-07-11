#include<bits/stdc++.h>
using namespace std;

void DFSMatrix(vector<vector<int>>& graph, int i, vector<int>& visited){
    visited[i] = 1;
    for(int j=0;j<graph.size();j++){
        if(graph[i][j] == 0)
            continue;
        if(visited[j] == 1)
            continue;
        DFSMatrix(graph, j, visited);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> visited(isConnected.size(), 0);
    int count = 0;
    for(int i=0;i<isConnected.size();i++){
        if(visited[i] == 1)
            continue;
        DFSMatrix(isConnected, i, visited);
        count++;
    }
    return count;
}

void BFSMatrix(vector<vector<int>>& graph,vector<int>& visited){
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int j=0;j<graph.size();j++){
            if(graph[i][j] == 0)
                continue;
            if(visited[j] == 1)
                continue;
            q.push(j);
            visited[j] = 1;
        }
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int freshCount = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                q.push({i,j});
            }
            if(grid[i][j] == 1)
                freshCount++;
        }
    }

    int minutes = 0;
    
    while(!q.empty()){
        int curr_size = q.size();
        bool rotted = false;
        for(int k=0;k<curr_size;k++){
            pair<int, int> curr = q.front();
            q.pop();
            //up
            if(curr.first-1 >= 0 && grid[curr.first-1][curr.second] == 1){
                grid[curr.first-1][curr.second] = 2;
                q.push({curr.first-1,curr.second});
                freshCount--;
                rotted = true;
            }
            //left
            if(curr.second-1 >=0 && grid[curr.first][curr.second-1] == 1){
                grid[curr.first][curr.second-1] = 2;
                q.push({curr.first,curr.second-1});
                freshCount--;
                rotted = true;
            }
            //up
            if(curr.first+1 < m && grid[curr.first+1][curr.second] == 1){
                grid[curr.first+1][curr.second] = 2;
                q.push({curr.first+1,curr.second});
                freshCount--;
                rotted = true;
            }
            //right
            if(curr.second+1 < n && grid[curr.first][curr.second+1] == 1){
                grid[curr.first][curr.second+1] = 2;
                q.push({curr.first,curr.second+1});
                freshCount--;
                rotted = true;
            }
        }
        if(rotted)
            minutes += 1;
    }
    if(freshCount == 0)
        return minutes;
    return -1;
}
    

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int,int>> q;
    int orig_color = image[sr][sc];
    if(orig_color == color)
        return image;
    image[sr][sc] = color;
    q.push({sr,sc});
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
        for(auto x: directions){
            int row = curr.first + x.first;
            int col = curr.second + x.second;

            if(row < m && row >= 0 && col < n && col >= 0 && image[row][col] == orig_color){
                q.push({row,col});
                image[row][col] = color;
            }
        }
    }
    return image;
}

bool helperBFS(int i, vector<vector<int>>& graph, vector<int>& visited){
    queue<pair<int,int>> q;
    q.push({i,-1});
    visited[i] = 1;
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
            
        for(int j=0;j<graph.size();j++){
            if(graph[curr.first][j] == 0)
                continue;
            if(visited[j] == 0){
                q.push({j,curr.first});
                visited[j] = 1;
            }else if(curr.second != j){
                return true;
            }
        }
    }
    return false;
}
bool UndirectedCycleDetectionBFS(vector<vector<int>>& graph){
    vector<int> visited(graph.size(),0);
    for(int i=0;i<graph.size();i++){
        if(visited[i] == 1)
            continue;
        if(helperBFS(i, graph, visited)){
            return true;
        }
    }
    return false;
}

bool helperDFS(int i,int parent,vector<vector<int>>& graph, vector<int>& visited){
    visited[i] = 1;
    for(int j=0;j<graph.size();j++){
        if(graph[i][j] == 0)
            continue;
        if(visited[j] == 0){
            if(helperDFS(j,i,graph,visited)){
                return true;
            }
        }else if(parent != j){
            return true;
        }
    }
    return false;
}
bool UndirectedCycleDetectionDFS(vector<vector<int>>& graph){
    vector<int> visited(graph.size(),0);
    for(int i=0;i<graph.size();i++){
        if(visited[i] == 1)
            continue;
        if(helperDFS(i,-1,graph,visited)){
            return true;
        }
    }
    return false;
}


bool helperCourse(int vertex,vector<vector<int>>& list, vector<int>& states){
    states[vertex] = 1;

    for(auto neighbour: list[vertex]){
        if(states[neighbour] == 0){
            if(!helperCourse(neighbour, list, states)){
                return false;
            }
        }else if(states[neighbour] == 1){
            return false;
        }
    }
    states[vertex] = 2;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> list(numCourses);
    for(const auto& row : prerequisites){
        list[row[1]].push_back(row[0]);
    }

    vector<int> states(numCourses,0);
    for(int i=0;i<numCourses;i++){
        if(states[i] != 0)
            continue;
        if(!helperCourse(i, list, states)){
            return false;
        }
    }
    return true;
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
    queue<pair<int,int>> q;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    bool found = false;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 0){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto dir: directions){
            int row = curr.first + dir.first;
            int col = curr.second + dir.second;

            if(row < 0 || row >= m || col < 0 || col >= n)
                continue;

            if(dist[row][col] != INT_MAX)
                continue;

            dist[row][col] = dist[curr.first][curr.second]+1;
            q.push({row,col});
        }
    }
    return dist;
}

void helperSolve(int x, int y,vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    board[x][y] = 'S';
    q.push({x,y});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto dir: directions){
            int row = curr.first + dir.first;
            int col = curr.second + dir.second;

            if(row < 0 || row >= m || col < 0 || col >= n)
                continue;

            if(board[row][col] == 'O'){
                board[row][col] = 'S';
                q.push({row,col});
            }
        }
    }
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    for(int i=0;i<n;i++){
        if(board[0][i] == 'O')
            helperSolve(0,i,board);
        if(board[m-1][i] == 'O')
            helperSolve(m-1,i,board);
    }
    for(int i=0;i<m;i++){
        if(board[i][0] == 'O')
            helperSolve(i,0,board);
        if(board[i][n-1] == 'O')
            helperSolve(i,n-1,board);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == 'S'){
                board[i][j] = 'O';
            }
        }
    }
}

void helperEnclave(int x, int y,vector<vector<int>>& board){
    int m = board.size();
    int n = board[0].size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    board[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        for(auto dir: directions){
            int row = curr.first + dir.first;
            int col = curr.second + dir.second;

            if(row < 0 || row >= m || col < 0 || col >= n)
                continue;

            if(board[row][col] == 1){
                board[row][col] = 0;
                q.push({row,col});
            }
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0;i<n;i++){
        if(grid[0][i] == 1)
            helperEnclave(0,i,grid);
        if(grid[m-1][i] == 1)
            helperEnclave(m-1,i,grid);
    }
    for(int i=0;i<m;i++){
        if(grid[i][0] == 1)
            helperEnclave(i,0,grid);
        if(grid[i][n-1] == 1)
            helperEnclave(i,n-1,grid);
    }

    int count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> hashset(wordList.begin(), wordList.end());
    if(hashset.find(endWord) == hashset.end()){
        return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int changes = 0;
    bool found = false;
    while(!q.empty()){
        int len = q.size();

        for(int k=0;k<len;k++){
            string curr = q.front();
            q.pop();
            if(curr == endWord){
                found = true;
                break;
            }
            for(int i=0;i<curr.length();i++){
                string temp = curr;
                for(char j='a';j<='z';j++){
                    temp[i] = j;
                    auto it = hashset.find(temp);
                    if(it != hashset.end()){
                        hashset.erase(it);
                        q.push(temp);
                    }
                }
            }
        }
        changes++;
        if(found)
            break;
    }
    if(found)
        return changes;
    return 0;
}

void buildLadders(string beginWord, string curr, unordered_map<string, unordered_set<string>>& parents, vector<string>& result, vector<vector<string>>& ans){
    unordered_set<string>& list = parents[curr];
    if(curr == beginWord){
        vector<string> temp = result;
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        return;
    }
    for(auto parent: list){
        result.push_back(parent);
        buildLadders(beginWord, parent, parents, result, ans);
        result.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, unordered_set<string>> parents;
    unordered_set<string> hashset(wordList.begin(), wordList.end());
    
    if(hashset.find(endWord) == hashset.end()){
        return {};
    }

    queue<string> q;
    q.push(beginWord);
    auto itr = hashset.find(beginWord);
    if(itr != hashset.end()){
        hashset.erase(itr);
    }
    bool found = false;
    while(!q.empty()){
        int qLen = q.size();
        unordered_set<string> visitedThisLevel = {};
        for(int k =0;k<qLen;k++){
            string s = q.front();
            q.pop();
            if(s == endWord){
                found = true;
                continue;
            }
            int len = s.length();
            
            for(int i=0;i<len;i++){
                string temp = s;
                for(char j='a';j<='z';j++){
                    if(temp[i] == j)
                        continue;
                    temp[i] = j;
                    auto it = hashset.find(temp);
                    if(it != hashset.end()){
                        parents[temp].insert(s);
                        if(visitedThisLevel.find(temp) == visitedThisLevel.end()){
                            visitedThisLevel.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        for(auto x: visitedThisLevel){
            hashset.erase(x);
        }
        if(found)
            break;
    }
    if(!found)
        return {};

    vector<string> result;
    result.push_back(endWord);
    vector<vector<string>> ans;
    buildLadders(beginWord, endWord, parents, result, ans);
    return ans;
}

void islandDFS(int r, int c, vector<vector<char>>& grid){
    grid[r][c] = 'V';
    static const vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int m = grid.size();
    int n = grid[0].size();
    for(const auto& dir : directions){
        int row = r + dir.first;
        int col = c + dir.second;
        if(row < 0 || row >= m || col < 0 || col >= n) 
            continue;
        if(grid[row][col] == '1'){
            islandDFS(row, col, grid);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1'){
                islandDFS(i,j,grid);
                count++;
            }
        }
    }
    return count;
}

bool bipartiteBFS(int i, vector<vector<int>>& graph, vector<int>& visited){
    queue<int> q;
    q.push(i);
    visited[i] = 0;
    int color = 0;
    while(!q.empty()){
        int qLen = q.size();
        for(int i=0;i<qLen;i++){
            int curr = q.front();
            q.pop();
            for(auto adj: graph[curr]){
                if(visited[adj] == -1){
                    visited[adj] = !visited[curr];
                    q.push(adj);
                    continue;
                }
                if(visited[adj] == visited[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) { 
    int n = graph.size();
    vector<int> visited(n, -1);

    for(int i=0;i<n;i++){
        if(visited[i] != -1)
            continue;
        if(!bipartiteBFS(i, graph, visited)){
            return false;
        }
    }
    return true;
}

bool helperFindOrder(int numCourses, int i, vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans){
    visited[i] = 1;
    for(auto x: graph[i]){
        if(visited[x] == 0){
            if(!helperFindOrder(numCourses, x, graph, visited, ans)){
                return false;
            }
        }
        else if(visited[x] == 1){
            return false;
        }
    }
    ans.push_back(i);
    visited[i] = 2;
    return true;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> visited(numCourses, 0);
    vector<vector<int>> graph(numCourses);
    for(auto row: prerequisites){
        graph[row[1]].push_back(row[0]);
    }

    vector<int> ans = {};
    for(int i=0;i<numCourses;i++){
        if(visited[i] == 0){
            if(!helperFindOrder(numCourses, i, graph, visited, ans)){
                return {};
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}