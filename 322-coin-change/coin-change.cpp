class Solution {
public:
    int find(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(ind==coins.size() || amount<0) return 1e9;

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+find(ind,amount-coins[ind],coins,dp);
        }
        int notTake=find(ind+1,amount,coins,dp);

        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
       int val= find(0,amount,coins,dp); 
       return val==1e9 ? -1 :val;
    }
};