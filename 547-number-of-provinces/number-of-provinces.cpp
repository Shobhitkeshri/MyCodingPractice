class Solution {
public:
    void DFS(int node,int par,vector<bool> &visited,vector<vector<int>> &adj){
        if(visited[node]) return;

        visited[node]=true;

        for(int &neigh:adj[node]){
            if(neigh==par) continue;
            if(!visited[neigh]){
              DFS(neigh,node,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                provinces++;
                DFS(i,-1,visited,adj);
            }
        }
        return provinces;
    }
};