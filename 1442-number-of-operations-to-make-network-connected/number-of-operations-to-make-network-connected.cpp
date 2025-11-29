class Solution {
public:
    int findPar(int u,vector<int> &parent){
        if(u==parent[u]) return u;
        
        return parent[u]=findPar(parent[u],parent);
    }
    void unionByRank(int u,int v,vector<int> &parent,vector<int> &rank){
        int pu=findPar(u,parent);
        int pv=findPar(v,parent);
        
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            rank[pu]++;
            parent[pv]=pu;
        }        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> parent(n),rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<connections.size();i++){
            unionByRank(connections[i][0],connections[i][1],parent,rank);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) components++;
        }
        return components-1;
    }
};