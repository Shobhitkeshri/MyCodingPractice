class Solution {
public:
   int row[4]={-1,1,0,0};
   int col[4]={0,0,-1,1};
   
   bool valid(int i,int j,int n){
    return i>=0 && j>=0 && i<n && j<n;
   }

   int DFS(int i,int j,vector<vector<int>> &grid,int id){
     
     int size=1;
     grid[i][j]=id;
     for(int k=0;k<4;k++){
        int ni=i+row[k];
        int nj=j+col[k];
        if(valid(ni,nj,grid.size()) && grid[ni][nj]==1){
            size+=DFS(ni,nj,grid,id);
        }
     }
     return size;
   }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int maxArea=0;
        
        int id=2;
        unordered_map<int,int> sizemap;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                int currArea=DFS(i,j,grid,id);
                sizemap[id]=currArea;
                maxArea=max(maxArea,currArea);
                id++;
               }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueIds;
                    for(int k=0;k<4;k++){
                        int ni=i+row[k];
                        int nj=j+col[k];
                        if(valid(ni,nj,n) && grid[ni][nj]>1){
                            uniqueIds.insert(grid[ni][nj]);
                        }
                    }
                    int currArea=1;
                    for(auto it:uniqueIds){
                      currArea+=sizemap[it];
                    }
                    maxArea=max(maxArea,currArea);
                }
            }
        }
        return maxArea;
    }
};