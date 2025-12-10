class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        unordered_map<int,int> m;
        m[0]=1;
        int total=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if(rem<0) rem=rem+k;
            if(m.count(rem)){
              total+=m[rem]++;
            }
            else m[rem]++;
        }
        return total;
    }
};