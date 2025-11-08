class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxi=nums[0],cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=maxi){
                cnt--;
                if(cnt==0){
                    maxi=nums[i];
                    cnt++;
                }
            }
            else cnt++;
        }
        return maxi;
    }
};