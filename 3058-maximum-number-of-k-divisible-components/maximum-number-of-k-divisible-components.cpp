class Solution {
public:
    int DFS(int node,int sum,int par,vector<vector<int>> &adj,int &cnt,vector<int> &values,int k){
        sum=values[node];

        for(auto neigh:adj[node]){
            if(neigh!=par){
                sum+=DFS(neigh,sum,node,adj,cnt,values,k);
                sum%=k;
            }
        }
        sum%=k;
        if(sum%k==0) cnt+=1;
        return sum;
        
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;

        DFS(0,0,-1,adj,cnt,values,k);
        return cnt;

    }
};