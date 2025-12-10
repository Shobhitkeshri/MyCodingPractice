class Solution {
public:
    bool find(int low,int high,int n,vector<int> &nums,int target){
        if(low>high) return false;

        int mid=(low+high)/2;
        if(nums[mid]==target) return true;

        return find(low,mid-1,n,nums,target) || find(mid+1,high,n,nums,target);
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;

        
        return find(0,n-1,n,nums,target);
    }
};