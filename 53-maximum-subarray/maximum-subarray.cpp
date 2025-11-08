class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0,maxNeg=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0){
                ans=max(ans,sum);
            }
            if(sum<0) sum=0;
            if(nums[i]<=0) maxNeg=max(maxNeg,nums[i]);
        }
        return ans==INT_MIN ? maxNeg :ans;
    }
};