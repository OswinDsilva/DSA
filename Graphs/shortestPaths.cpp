#include<bits/stdc++.h>
using namespace std;
using PII = pair<int,int>;
using TIII = tuple<int,int,int>;

vector<int> shortestDistanceUnitWeights(int src,vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> dist(n,-1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto adj : graph[curr] ){
            if(dist[adj] == -1){
                dist[adj] = dist[curr]+1;
                q.push(adj);
            }
        }
    }
    return dist;
}

bool getTopoSortedNodes(int i, vector<vector<PII>>& graph, vector<int>& visited, vector<int>& sortedNodes){
    visited[i] = 1;
    for(auto adj: graph[i]){
        if(visited[adj.first] == 0){
            if(!getTopoSortedNodes(adj.first, graph, visited, sortedNodes)){
                return false;
            }
        }else if (visited[adj.first] == 1){
            return false;
        }
    }     
    visited[i] = 2;
    sortedNodes.push_back(i);
    return true;
}
vector<int> shortestDistanceDAGWeighted(int src, vector<vector<PII>>& graph){
    vector<int> topoSortedNodes;
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            if(!getTopoSortedNodes(i, graph, visited, topoSortedNodes)){
                return dist;
            }
        }
    }
    while(!topoSortedNodes.empty()){
        int curr = topoSortedNodes.back();
        topoSortedNodes.pop_back();
        for(auto adj: graph[curr]){
            if(dist[curr] != INT_MAX && dist[adj.first] > dist[curr] + adj.second){
                dist[adj.first] = dist[curr] + adj.second;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}

//first is distance/weight , second is vertex
vector<int> DjisktraPQ(int src, vector<vector<PII>>& graph){
    priority_queue<pair<int,int>, vector<PII>, greater<PII>> pq; 
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        pair<int,int> curr = pq.top();
        pq.pop();
        if(curr.first > dist[curr.second])
            continue;
        for(auto adj: graph[curr.second]){
            if(dist[adj.second] > dist[curr.second] + adj.first){
                dist[adj.second] = dist[curr.second] + adj.first;
                pq.push({dist[adj.second],adj.second});
            }
        }
    }
    return dist;
}

vector<int> DjisktraSet(int src, vector<vector<PII>>& graph){
    set<pair<int,int>, less<PII>> s;
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        pair<int,int> curr = *s.begin();
        s.erase(s.begin());
        for(auto adj: graph[curr.second]){
            if(dist[adj.second] > dist[curr.second] + adj.first){
                if(dist[adj.second] != INT_MAX){
                    s.erase({dist[adj.second],adj.second});
                }
                dist[adj.second] = dist[curr.second] + adj.first;
                s.insert({dist[adj.second], adj.second});
            }
        }
    }
    return dist;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0] == 1)
        return -1;
    int m = grid.size();
    int n = grid[0].size();
    int dist = 1;
    const vector<PII> directions = {{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};
    queue<PII> q;
    q.push({0,0});
    grid[0][0] = 1;
    while(!q.empty()){
        int qLen = q.size();
        for(int i=0;i<qLen;i++){
            PII curr = q.front();
            q.pop();
            if(curr.first == m-1 && curr.second == n-1){
                return dist;
            }
            for(auto dir: directions){
                int row = curr.first + dir.first;
                int col = curr.second + dir.second;
                if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 0)
                    continue;
                
                grid[row][col] = 1;
                q.push({row,col});
            }
        }
        dist++;
    }
    return -1;
}


int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    const vector<PII> directions = {{0,1},{1,0},{0,-1},{-1,0}}; 
    priority_queue<TIII, vector<TIII>, greater<TIII>> pq; 
    vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

    pq.push({0,0,0});
    effort[0][0] = 0;

    while(!pq.empty()){
        TIII curr = pq.top();
        pq.pop();
        int curr_effort = get<0>(curr);
        int r = get<1>(curr);
        int c = get<2>(curr);
        if(r == m-1 && c == n-1)
            return curr_effort;
        if(curr_effort > effort[r][c]){
            continue;
        }
        for(auto dir: directions){
            int row = r + dir.first;
            int col = c + dir.second;

            if(row < 0 || row >= m || col < 0 || col >= n)
                continue;

            if(effort[row][col] > max(curr_effort, abs(heights[r][c]-heights[row][col]))){
                effort[row][col] = max(curr_effort, abs(heights[r][c]-heights[row][col]));
                pq.push({effort[row][col],row, col});
            }
        }
    }
    return effort[m-1][n-1];
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<PII>> graph(n);
    for(auto rec: flights){
        graph[rec[0]].push_back({rec[2],rec[1]});
    }

    queue<TIII> q;
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    // {stops, node, price}
    q.push({0,src,0});
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int stops =  get<0>(curr);
        int node = get<1>(curr);
        int pathPrice = get<2>(curr);
        if(node == dst){
            continue;
        }
        if(stops > k){
            continue;
        }
        for(auto adj : graph[node]){
            if(dist[adj.second] > pathPrice + adj.first){
                dist[adj.second] = pathPrice + adj.first;
                q.push({stops+1, adj.second, dist[adj.second]});
            }
        }
    }
    if(dist[dst] == INT_MAX)
        return -1;
    return dist[dst];
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<PII>> graph(n);
    for(auto time: times){
        graph[time[0]-1].push_back({time[2], time[1]-1});
    }

    vector<int> delay(n, INT_MAX);    
    priority_queue<PII, vector<PII> , greater<PII>> pq;
    pq.push({0,k-1});
    delay[k-1] = 0;
    
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        
        if(curr.first > delay[curr.second])
            continue;
        for(auto adj: graph[curr.second]){
            if(delay[adj.second] > adj.first + curr.first){
                delay[adj.second] = adj.first + curr.first;
                pq.push({delay[adj.second], adj.second});
            }
        }
    }
    int max_val = -1;
    for(int i=0;i<n;i++){
        if(delay[i] == INT_MAX)
            return -1;
        max_val = max(max_val , delay[i]);
    }
    return max_val;
}

static const int mod = 7+1e9;
int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<long long, int>>> graph(n);
    for(auto& road: roads){
        int u = road[0];
        int v = road[1];
        int t = road[2];
        graph[u].push_back({t,v});
        graph[v].push_back({t,u});
    }        
    
    vector<long long> ways(n, 0);
    vector<long long> distances(n, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    distances[0] = 0;
    ways[0] = 1;
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();

        if(curr.first > distances[curr.second])
            continue;
        for(const auto& adj: graph[curr.second]){
            long long newDist = adj.first+curr.first;
            if(distances[adj.second] > newDist){
                pq.push({newDist, adj.second});
                distances[adj.second] = newDist;
                ways[adj.second] = ways[curr.second];
            }else if(distances[adj.second] == newDist){
                ways[adj.second] = (ways[adj.second] + ways[curr.second]) % mod;
            }
        }
    }
    
    return ways[n-1] % mod;
}


int minMultiplications(int start,int end, vector<int> nums){
    const int mod = 1e5;
    vector<int> multiplications(mod, INT_MAX);
    
    queue<int> q;
    q.push(start);
    multiplications[start] = 0;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        if(curr == end){
            return multiplications[end];
        }
        for(auto num : nums){
            int newStart = (curr * num) % mod;
            if(multiplications[newStart] > multiplications[curr]+1){
                multiplications[newStart] = multiplications[curr]+1;
                q.push(newStart);
            }
        }
    }
    return -1;
}

// {} indicates negative cycle
vector<int> bellmanFord(int n,int src, vector<vector<int>>& edges, bool isDirected){
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    for(int i=0;i<n-1;i++){
        bool updated = false;
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt =  edge[2];
            
            if(distance[u] == INT_MAX)
                continue;
            
            if(distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                updated = true;
            }
            
            if(!isDirected){
                if(distance[v] == INT_MAX)
                    continue;
                if(distance[v] + wt < distance[u]){
                    distance[u] = distance[v] + wt;
                    updated = true;
                }
            }
        }
        if(!updated){
            break;
        }
    }

    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt =  edge[2];
            
        if(distance[u] == INT_MAX)
            continue;
            
        if(distance[u] + wt < distance[v]){
            return {};
        }
            
        if(!isDirected){
            if(distance[v] == INT_MAX)
                continue;
            if(distance[v] + wt < distance[u]){
                return {};
            }
        }
    }
    return distance;
}

vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges){
    bool isDirected = false;
    vector<vector<int>> graphMatrix(n, vector<int>(n, INT_MAX));
    for(int i=0;i<n;i++){
        graphMatrix[i][i] = 0;
    }
    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graphMatrix[u][v] = min(graphMatrix[u][v], wt);
        if(!isDirected){
            graphMatrix[v][u] = min(graphMatrix[v][u], wt);
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graphMatrix[i][k] == INT_MAX || graphMatrix[k][j] == INT_MAX){
                    continue;
                }
                graphMatrix[i][j] = min(graphMatrix[i][j],graphMatrix[i][k] + graphMatrix[k][j]);
            }
        }
    }
    return graphMatrix;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    for(const auto& edge: edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        graph[u][v] = min(graph[u][v],wt);
        graph[v][u] = min(graph[v][u],wt);
    }
    for(int i=0;i<n;i++){
        graph[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k] == INT_MAX || graph[k][j] == INT_MAX){
                    continue;
                }
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    int curr_count = 0;
    int min_count = INT_MAX;
    int city = -1;
    for(int i =0;i<n;i++){
        curr_count = 0;
        for(int j=0;j<n;j++){
            if(graph[i][j] == 0 || graph[i][j] == INT_MAX || graph[i][j] > distanceThreshold)
                continue;
            curr_count++;
        }
        if(min_count >= curr_count){
            min_count = curr_count;
            city = i;
        }

    }
    return city;
}


int main(){
    vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    cout<<findTheCity(5, edges, 2);
}