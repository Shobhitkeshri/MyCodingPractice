class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int no1=0;
        int n=nums.size();
        int ans=0;
        if(nums[0]==1) no1++;
        for(int i=1;i<n;i++){
           if(nums[i]==0){
                ans=max(ans,no1);
                no1=0;
           }

           else if(nums[i]==1){
            if(nums[i-1]==1) no1++;
            else if(nums[i-1]==0) no1=1;
           }
        }
        ans=max(ans,no1);
        return ans;
    }
};