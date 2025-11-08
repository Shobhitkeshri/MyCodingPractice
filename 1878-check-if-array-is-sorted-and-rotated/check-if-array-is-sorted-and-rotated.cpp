class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int dips=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) dips++;
        }
        if(nums[n-1]>nums[0]) dips++;
        return dips<=1;
    }
};