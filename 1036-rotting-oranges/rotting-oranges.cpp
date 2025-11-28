class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        
        int freshOranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) freshOranges++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }

        int time=0;
        while(!q.empty() && freshOranges>0){
            int q_size=q.size();
            while(q_size--){
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                for(int k=0;k<4;k++){
                    int ni=i+row[k];
                    int nj=j+col[k];

                    if(valid(ni,nj,n,m) && grid[ni][nj]==1){
                        freshOranges--;
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            time++;
        }
        if(freshOranges==0) return time;
        return -1;
    }
};