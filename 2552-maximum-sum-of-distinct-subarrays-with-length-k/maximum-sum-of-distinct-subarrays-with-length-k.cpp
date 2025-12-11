class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi=0;
        long long sum=0;

        int start=0,end=0;
        unordered_map<int,int> m;
        while(end<nums.size()){
           m[nums[end]]++;
           sum+=nums[end];
           while(m[nums[end]]>1 || (end-start+1>k)){
            m[nums[start]]--;
            sum-=nums[start];
            start++;
           }
           if(end-start+1==k){
            maxi=max(maxi,sum);
           }
           end++;
        }
        return maxi;
    }
};