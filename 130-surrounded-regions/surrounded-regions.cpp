class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};
    
    bool valid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

                queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0]='Z';
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='Z';
                q.push({i,m-1});
            }            
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                board[0][i]='Z';
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                board[n-1][i]='Z';
                q.push({n-1,i});
            }            
        }   

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int ni=i+row[k];
                int nj=j+col[k];

                if(valid(ni,nj,n,m) && board[ni][nj]=='O'){
                    board[ni][nj]='Z';
                    q.push({ni,nj});
                }
            }
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Z') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};