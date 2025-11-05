class Solution {
public:
    int row[8]={-1,1,0,0,-1,1,-1,1};
    int col[8]={0,0,-1,1,1,-1,-1,1};

    bool valid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> board2(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              int liveCells=0;
              for(int k=0;k<8;k++){
                int ni=i+row[k];
                int nj=j+col[k];

                if(valid(ni,nj,n,m) && board[ni][nj]==1) liveCells++;
              }
              if(board[i][j]==1){
                if(liveCells<2) board2[i][j]=0;
                else if(liveCells>3) board2[i][j]=0;
                else board2[i][j]=1;
              }
              else{
                if(liveCells==3) board2[i][j]=1;
              }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=board2[i][j];
            }
        }
    }
};