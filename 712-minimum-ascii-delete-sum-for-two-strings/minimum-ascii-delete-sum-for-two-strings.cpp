class Solution {
public:
    int findCommon(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i>=s1.size() || j>=s2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            int val=s1[i];
            return dp[i][j]=val+findCommon(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j]=max(findCommon(i,j+1,s1,s2,dp),findCommon(i+1,j,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
         int firstTotal=0,secondTotal=0;
         int n=s1.size(),m=s2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         for(int i=0;i<s1.size();i++){
            int val=s1[i];
            firstTotal+=val;
         }
         for(int i=0;i<s2.size();i++){
            int val=s2[i];
            secondTotal+=val;
         }
        int common=findCommon(0,0,s1,s2,dp);
        int totalAns=(firstTotal-common)+(secondTotal-common);
        return totalAns;
    }
};