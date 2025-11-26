class Solution {
public:
    int n,m;
    int M=1e9+7;
    int solve(int i,int j,int currSum,vector<vector<int>> &grid,int k,vector<vector<vector<int>>> &dp){
        if(i==n-1 && j==m-1){
           return (grid[i][j]+currSum)%k==0;
        }
        if(i>=n || j>=m) return 0;

        if(dp[i][j][currSum]!=-1) return dp[i][j][currSum];

        int right=solve(i,j+1,(currSum+grid[i][j])%k,grid,k,dp);
        int down=solve(i+1,j,(currSum+grid[i][j])%k,grid,k,dp);

        return dp[i][j][currSum]=(right+down)%M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return solve(0,0,0,grid,k,dp);
    }
};