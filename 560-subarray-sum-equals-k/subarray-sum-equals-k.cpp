class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int prefixSum=0;
        m[0]=1;
        int total=0;
        for(int i=0;i<n;i++){
           prefixSum+=nums[i];
           if(m.find(prefixSum-k)!=m.end()){
            total+=m[prefixSum-k];
            m[prefixSum]++;
           }
           else{
            m[prefixSum]++;
           }
        }
        return total;
    }
};