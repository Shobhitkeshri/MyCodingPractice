class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=-1;
        int val=-101;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                i++;
                nums[i]=nums[j];
                val=nums[j];
            }
        }
        return i+1;
    }
};