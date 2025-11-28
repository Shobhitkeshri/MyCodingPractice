class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(mat[i][j]==0){
                  q.push({i,j});
                  dist[i][j]=0;
              }
            }
        }
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
                for(int k=0;k<4;k++){
                    int ni=i+row[k];
                    int nj=j+col[k];

                    if(valid(ni,nj,n,m) && dist[ni][nj]>1+dist[i][j]){
                        dist[ni][nj]=1+dist[i][j];
                        q.push({ni,nj});
                    }
                }
        }
        return dist;
    }
};