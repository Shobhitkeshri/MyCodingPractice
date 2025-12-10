class Solution {
public:
    int firstOcc(vector<int> &nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
    int secondOcc(vector<int> &nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n=nums.size();
        ans[0]=firstOcc(nums,target);
        ans[1]=secondOcc(nums,target);
        return ans;
    }
};