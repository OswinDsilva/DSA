#include<bits/stdc++.h>
using namespace std;


void DFS(vector<vector<int>>& graph, int i, vector<int>& visited){
    visited[i] = 1;
    for(int j=0;j<graph.size();j++){
        if(graph[i][j] == 0)
            continue;
        if(visited[j] == 1)
            continue;
        DFS(graph, j, visited);
    }
}

int CountConnectedComponents(vector<vector<int>>& graph){
    vector<int> visited(graph.size(), 0);
    int count = 0;
    for(int i=0;i<graph.size();i++){
        if(visited[i] == 1)
            continue;
        DFS(graph, i, visited);
        count++;
    }
    return count;
}

int main(){
    vector<vector<int>> graph = {{1,1,0},{1,1,0},{0,0,1}};
    cout<<CountConnectedComponents(graph);
}