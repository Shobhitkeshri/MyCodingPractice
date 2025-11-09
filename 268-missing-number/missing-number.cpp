class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i=0;i<=n;i++){
            if(m.find(i)==m.end()) return i;
        }
        return -1;
    }
};