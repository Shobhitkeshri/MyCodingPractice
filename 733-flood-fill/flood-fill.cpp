class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        int oriColor=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
             pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                for(int k=0;k<4;k++){
                    int ni=i+row[k];
                    int nj=j+col[k];

                    if(valid(ni,nj,n,m) && image[ni][nj]==oriColor){
                        image[ni][nj]=color;
                        q.push({ni,nj});
                    }
                }
            }
        return image;
    }
};