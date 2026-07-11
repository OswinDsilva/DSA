#include<bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
using TIII = tuple<int,int,int>;

vector<PII> PrimsMST(int n, vector<vector<int>>& edges){
    vector<vector<PII>> graph(n);
    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graph[u].push_back({wt,v});
        //assuming undirected
        graph[v].push_back({wt,u});
    }

    vector<PII> ans;
    int sum = 0;
    vector<int> visited(n,0);
    priority_queue<TIII, vector<TIII>, greater<>> pq;
    pq.push({0,0,-1});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int prevEdgeWeight = get<0>(curr);
        int curr_node = get<1>(curr);
        int parent_node = get<2>(curr);
        if(visited[curr_node] == 1)
            continue;
        if(parent_node != -1){
            ans.push_back({parent_node,curr_node});
        }
        visited[curr_node] = 1;
        sum += prevEdgeWeight;
        for(const auto& [wt, adj]: graph[curr_node]){
            if(visited[adj] == 0)
                pq.push({wt, adj, curr_node});
        }
    }
    return ans;
}

class DisjointSet{
    private:
        int n;
        vector<int> rank, parent, size;
    public:
        DisjointSet(int num) : n(num){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=1;i<=n;i++){
                parent[i] = i;
            }
        }
        int FindUltParent(int i){
            if(parent[i] == i)
                return i;
            parent[i] = FindUltParent(parent[i]);
            return parent[i];
        }
        void UnionByRank(int u, int v){
            int pu = FindUltParent(u);
            int pv = FindUltParent(v);
            if(pu == pv){
                return;
            }
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            }else{
                parent[pu] = pv;
                rank[pv]++;
            }
        }
        void UnionBySize(int u, int v){
            int pu = FindUltParent(u);
            int pv = FindUltParent(v);
            if(pu == pv){
                return;
            }
            if(size[pu] < size[pv]){
                size[pv] += size[pu];
                parent[pu] = pv;
            }else{
                size[pu] += size[pv];
                parent[pv] = pu;
            }
        }

        int getSize(int u){
            return size[u];
        }
};

vector<PII> KruskalsMST(int n, vector<vector<int>>& edges){
    priority_queue<TIII, vector<TIII>, greater<>> pq;
    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        pq.push({wt,u,v});
    }

    vector<PII> ans;
    int sum = 0;
    DisjointSet ds(n);

    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int wt = get<0>(curr);
        int u = get<1>(curr);
        int v = get<2>(curr);
        if(ds.FindUltParent(u) != ds.FindUltParent(v)){
            ds.UnionByRank(u,v);
            ans.push_back({u,v});
            sum += wt;
        }
    }
    return ans;
}

int makeConnected(int n, vector<vector<int>>& connections) {
    int numConnections = connections.size();
    if(numConnections < n-1)
        return -1;
    DisjointSet ds(n);
    for(const auto& connection: connections){
        int u = connection[0];
        int v = connection[1];
        ds.UnionByRank(u+1,v+1);
    }
    int numComponents = 0;
    for(int i=0;i<n;i++){
        if(ds.FindUltParent(i+1) == i+1){
            numComponents++;
        }
    }
    return numComponents-1;
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int offset = 10001;
    set<int> seen_nodes;
    DisjointSet ds(2*offset);
    for(const auto& stone: stones){
        int u = stone[0]+1;
        int v = stone[1]+1 + offset;
        ds.UnionByRank(u, v);
        seen_nodes.insert(u);
        seen_nodes.insert(v);
    }
    int count = 0;
    for(const auto& node: seen_nodes){
        if(ds.FindUltParent(node) == node)
            count++;
    }
    return n - count;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> email_map;
    for(int i=0;i<n;i++){
        int recLen = accounts[i].size();
        for(int j=1;j<recLen;j++){
            if(email_map.find(accounts[i][j]) ==  email_map.end()){
                email_map[accounts[i][j]] = i+1;
            }else{
                ds.UnionByRank(i+1, email_map[accounts[i][j]]);
            }
        }
    }
    vector<vector<string>> ans(n);
    for(const auto& [email, node] : email_map){
        int ultPar = ds.FindUltParent(node);
        ans[ultPar-1].push_back(email);
    }
    vector<vector<string>> result;
    for(int i=0;i<n;i++){
        if(ans[i].empty())
            continue;
        sort(ans[i].begin(), ans[i].end());
        vector<string> row;
        row.push_back(accounts[i][0]);
        for(auto const& email: ans[i]){
            row.push_back(email);
        }
        result.push_back(row);
    }
    return result;
}

vector<int> numIslands(int m, int n, int k, vector<vector<int>> ops){
    vector<vector<int>> grid(m, vector<int>(n,0));
    DisjointSet ds(m * n);
    vector<PII> directions = {{-1,0},{0,1}, {1,0}, {0,-1}};
    vector<int> ans;
    int i = 0;
    int count = 0;
    for(const auto& op : ops){
        int r = op[0];
        int c = op[1];
        if(grid[r][c] == 0){
            grid[r][c] = 1;
            count++;
        }else{
            ans.push_back(count);
            continue;
        }
        for(const auto& dir: directions){
            int row = r + dir.first;
            int col = c + dir.second;
            if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0)
                continue; 
            int orig_node = r*n + c + 1;
            int dir_node = row*n + col + 1;
            if(ds.FindUltParent(orig_node) != ds.FindUltParent(dir_node)){
                ds.UnionByRank(orig_node, dir_node);
                count--;
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n*n);
    vector<PII> directions = {{1,0}, {0,-1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                continue;
            }
            for(const auto& dir: directions){
                int row = i + dir.first;
                int col = j + dir.second;

                if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == 0){
                    continue;
                }

                ds.UnionBySize(row * n + col + 1, i * n + j + 1); 
            }
        }
    }
    vector<PII> directions1 = {{-1,0},{0,1}, {1,0}, {0,-1}};
    int max_space = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            unordered_set<int> st;
            int curr_space = 1;
            if(grid[i][j] == 1)
                continue;
            for(const auto& dir:directions1){
                int row = i + dir.first;
                int col = j + dir.second;

                if(row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == 0){
                    continue;
                }

                st.insert(ds.FindUltParent(row*n + col+1));
            }
            for(const auto& par : st){
                curr_space += ds.getSize(par);
            }
            max_space = max(max_space, curr_space);
        }
    }
    if(max_space == INT_MIN)
        return n*n;
    return max_space;
}

int swimInWater(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<PII> directions = {{-1,0},{0,1}, {1,0}, {0,-1}};
    priority_queue<TIII, vector<TIII>, greater<>> pq;
    pq.push({grid[0][0],0,0});
    vector<vector<int>> elevations(m, vector<int>(n, INT_MAX));
    elevations[0][0] = grid[0][0];
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        int elevation = get<0>(curr);
        int r = get<1>(curr);
        int c = get<2>(curr);
        if(elevations[r][c] < elevation){
            continue;
        }
        for(const auto& dir: directions){
            int row = r + dir.first;
            int col = c + dir.second;
            if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != INT_MAX){
                continue;
            }

            int newElevation = max(elevation , grid[row][col]);
            if(newElevation < elevations[row][col]){
                elevations[row][col] = newElevation;
                pq.push({newElevation,row, col});
            }
        }
    }
    return elevations[m-1][n-1];
}

int currTime = 1;
void helperDFS(vector<vector<int>>& graph, int i , int par,vector<int>& lowestTimes, vector<vector<int>>& ans, vector<int>& discoveredTimes){
    lowestTimes[i] = currTime;
    discoveredTimes[i] = currTime;
    currTime++;
    for(const auto& adj: graph[i]){
        if(adj == par)
            continue;
        if(discoveredTimes[adj] == -1){
            helperDFS(graph, adj, i, lowestTimes, ans, discoveredTimes);
            lowestTimes[i] = min(lowestTimes[i], lowestTimes[adj]);
            if(discoveredTimes[i] < lowestTimes[adj]){
                ans.push_back({i, adj});
            }
        }
        else
            lowestTimes[i] = min(lowestTimes[i], discoveredTimes[adj]);
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);
    vector<int> lowestAdjTimes(n, INT_MAX);
    vector<int> discoveredTimes(n, -1);
    vector<vector<int>> ans;
    for(const auto& connection: connections){
        graph[connection[0]].push_back(connection[1]);
        graph[connection[1]].push_back(connection[0]);
    }

    helperDFS(graph, 0, -1,lowestAdjTimes, ans, discoveredTimes);

    return ans;
}

int main(){
    vector<vector<int>> connections = {{0,2},{1,3}} ;
    cout<<swimInWater(connections);
}
