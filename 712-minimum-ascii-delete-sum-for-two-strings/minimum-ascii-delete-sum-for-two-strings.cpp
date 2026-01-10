class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
         int firstTotal=0,secondTotal=0;
         int n=s1.size(),m=s2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         for(int i=0;i<s1.size();i++){
            int val=s1[i];
            firstTotal+=val;
         }
         for(int i=0;i<s2.size();i++){
            int val=s2[i];
            secondTotal+=val;
         }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=s1[i-1]+ dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int totalAns=(firstTotal-dp[n][m])+(secondTotal-dp[n][m]);
        return totalAns;
    }
};