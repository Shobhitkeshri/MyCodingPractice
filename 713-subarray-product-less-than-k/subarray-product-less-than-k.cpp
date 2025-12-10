class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long product=1;
        int start=0,end=0;
        int total=0;
        while(end<n){
            product=1LL*product*nums[end];
            while(product>=k && start<=end){
              product=product/nums[start++];
            }
            total+=(end-start+1);
            end++;
        }
        return total;
    }
};