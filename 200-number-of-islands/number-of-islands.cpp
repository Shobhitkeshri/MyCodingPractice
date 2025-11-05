class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};

    bool valid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void DFS(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<bool>> &visited){

        visited[i][j]=true;

        for(int k=0;k<4;k++){
            int ni=i+row[k];
            int nj=j+col[k];
            
            if(valid(ni,nj,n,m) && !visited[ni][nj] && grid[ni][nj]=='1'){
                DFS(ni,nj,n,m,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int noofLand=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    noofLand++;
                    DFS(i,j,n,m,grid,visited);
                }
            }
        }
        return noofLand;
    }
};