class Solution {
public:
    int n,m;
    int M=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k,0)));
        
        for(int rem=0;rem<k;rem++){
           dp[n-1][m-1][rem]=(grid[n-1][m-1]+rem)%k==0 ?1:0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int rem=0;rem<k;rem++){
                    if(i==n-1 && j==m-1) continue;
                     int R=(grid[i][j]+rem)%k;
                     int right=dp[i][j+1][R];
                     int down=dp[i+1][j][R];

                     dp[i][j][rem]=(down+right)%M;
                }
            }
        }

        return dp[0][0][0];
    }
};