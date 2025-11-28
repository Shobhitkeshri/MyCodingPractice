class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                grid[i][0]=0;
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                grid[i][m-1]=0;
            }            
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                q.push({0,i});
                grid[0][i]=0;
            }
            if(grid[n-1][i]==1){
                q.push({n-1,i});
                grid[n-1][i]=0;
            }            
        } 

         while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

                for(int k=0;k<4;k++){
                    int ni=i+row[k];
                    int nj=j+col[k];

                    if(valid(ni,nj,n,m) && grid[ni][nj]==1){
                        grid[ni][nj]=0;
                        q.push({ni,nj});
                    }
                }
            }  
        int provinces=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) provinces++;
            }
        }
        return provinces;
    }
};