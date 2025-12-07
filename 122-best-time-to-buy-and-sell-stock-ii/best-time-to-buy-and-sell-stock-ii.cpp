class Solution {
public:
    int find(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(ind>=n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==0){
            return dp[ind][buy]=max(-prices[ind]+find(ind+1,1,n,prices,dp),find(ind+1,0,n,prices,dp));
        }
        else{
            return dp[ind][buy]=max(prices[ind]+find(ind+1,0,n,prices,dp),find(ind+1,1,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(2,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy==0){
                    dp[buy]=max(-prices[ind]+dp[1],dp[0]);
                }
                else{
                    dp[buy]=max(prices[ind]+dp[0],dp[1]);
                }
            }
        }

        return dp[0];
    }
};