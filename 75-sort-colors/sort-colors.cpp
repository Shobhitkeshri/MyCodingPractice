class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n=nums.size();
       int low=-1,high=n;
       int k=0;
       while(k<high){
        if(nums[k]==2){
            high--;
            swap(nums[k],nums[high]);
        }
        else if(nums[k]==0){
            low++;
            swap(nums[k],nums[low]);
            k++;
        }
        else k++;
       } 
    }
};