class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int start=0,end=0;
        int len=INT_MAX;
        int sum=0;
        while(end<n){
            sum+=nums[end];
            while(sum>=target){
             len=min(len,end-start+1);
               sum-=nums[start];
               start++;
            }
            end++;
        }
        
        return len==INT_MAX ?0:len;
    }
};