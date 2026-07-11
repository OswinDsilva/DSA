#include<bits/stdc++.h>
using namespace std;

bool helperDFS(int i,const vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans){
    visited[i] = 1;
    for(auto adj: graph[i]){
        if(visited[adj] == 0){
            if(!helperDFS(adj, graph, visited, ans)){
                return false;
            }
        }else if(visited[adj] == 1){
            return false;
        }
    }
    visited[i] = 2;
    ans.push_back(i);
    return true;
}
vector<int> topologicalSortDFS(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> ans;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            if(!helperDFS(i, graph, visited, ans)){
                return {};
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void helperBFS(vector<vector<int>>& graph, vector<int>& ans, vector<int>& indegrees){
    int n = graph.size();
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto adj: graph[curr]){
            indegrees[adj]--;
            if(indegrees[adj] == 0)
                q.push(adj); 
        }
    }
}
vector<int> topologicalSortBFS(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> indegrees(n,0);
    for(int i=0;i<n;i++){
        for(auto adj:graph[i]){
            indegrees[adj]++;
        }
    }
    vector<int> ans;
    helperBFS(graph, ans, indegrees);
    if(ans.size() == n)
        return ans;
    else 
        return {};
}

bool helperSafeNodes(int i, vector<vector<int>>& graph, vector<int>& visited){
    visited[i] = 1;
    for(auto adj: graph[i]){
        if(visited[adj] == 0){
            if(!helperSafeNodes(adj, graph, visited)){
                return false;
            }
        }else if(visited[adj] == 1){
            return false;
        }
    }
    visited[i] = 2;
    return true;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            helperSafeNodes(i, graph, visited);
        }
    }   
    for(int i=0;i<n;i++){
        if(visited[i] == 2)
            ans.push_back(i);
    }
    return ans; 
}

vector<int> eventualSafeNodesBFS(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> ans;
    vector<vector<int>> reverse_graph(n);
    vector<int> outdegrees(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        for(auto adj: graph[i]){
            reverse_graph[adj].push_back(i);
            outdegrees[i]++;
        }
    }
    for(int i=0;i<n;i++){
        if(outdegrees[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(auto adj: reverse_graph[curr]){
            outdegrees[adj]--;
            if(outdegrees[adj] == 0)
                q.push(adj);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}


bool alienHelperDFS(int i, vector<vector<int>>& graph, vector<int>& visited, vector<char>& ans){
    visited[i] = 1;
    for(auto adj: graph[i]){
        if(visited[adj] == 0){
            if(!alienHelperDFS(adj, graph, visited, ans)){
                return false;
            }
        }else if(visited[adj] == 1){
            return false;
        }
    }
    visited[i] = 2;
    ans.push_back(i+'a');
    return true;
}
vector<char> alienDictionary(int n, int k, vector<string>& wordList){
    vector<vector<int>> graph(k);
    for(int i=0;i<n-1;i++){
        bool differing = false;
        int curr_len = wordList[i].length();
        int next_len = wordList[i+1].length();
        for(int j=0;j<min(curr_len, next_len);j++){
            if(wordList[i][j] != wordList[i+1][j]){
                graph[wordList[i][j]-'a'].push_back(wordList[i+1][j]-'a');
                differing = true;
                break;
            }
        }
        if(!differing && curr_len > next_len){
            return {};
        }
    }

    vector<int> visited(k,0);
    vector<char> ans;
    for(int i=0;i<k;i++){
        if(visited[i] == 0){
            if(!alienHelperDFS(i, graph, visited, ans)){
                return {};
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}