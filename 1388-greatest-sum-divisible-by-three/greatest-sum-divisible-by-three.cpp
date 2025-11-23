class Solution {
public:
    int find(int ind,int rem,int n,vector<int> &nums,vector<vector<int>> &dp){
    if (ind == n) {
        return rem == 0 ? 0 : -1e9;
    }
    if (dp[ind][rem] != -1e9) return dp[ind][rem];

    int r = nums[ind] % 3;

    int take = nums[ind] + find(ind + 1, (rem + r) % 3,n, nums, dp);

    int skip = find(ind + 1, rem,n, nums, dp);

    return dp[ind][rem] = max(take, skip);

    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,-1e9));
        return find(0,0,n,nums,dp);
    }
};