#include<bits/stdc++.h>
void convertor(unordered_map<int,list<int>>&adj,vector<vector<int>>& edges){
    for(int i = 0 ;i<edges.size();i++){
        for(int j = 0 ;j<edges[0].size();j++)
       {     if(edges[i][j] == 1)
              {  
               adj[i].push_back(j);
               }
        }
//         adj[v].push_back(u);
    }
}

bool bfs(int node,unordered_map<int,list<int>>&adj,vector<int>&color ){
    queue<int>q;
    q.push(node);
    color[node] = 1;
    while(q.empty() == false){
        int parent =q.front();
        q.pop();
        for(auto x : adj[parent]){
            if(color[x] == -1){
                q.push(x);
                color[x] = 1- color[parent] ;
            }
            else if(color[x] == color[parent]){
                return false;
            }
        }
        
    }
    return true;
}


bool isGraphBirpatite(vector<vector<int>> &edges) {
    unordered_map<int,list<int>> adj;
    convertor(adj,edges);
    vector<int>color(edges[0].size(),-1);
    for(int i = 0 ;i<edges[0].size() ;i++){
        if(color[i] == -1){
            
            if(bfs(i,adj,color) == false){
                return false;
            }
        }
        
    }
    return true;
       
}
