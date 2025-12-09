class Solution {
public:
    int M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m_left,m_right;
        for(int i=0;i<n;i++){
            m_right[nums[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            m_right[nums[i]]--;
            if(m_left.find(2*nums[i])!=m_left.end() && m_right.find(2*nums[i])!=m_right.end()){
                long long first=m_left[2*nums[i]]%M;
                long long second=m_right[2*nums[i]]%M;
                long long val=(first*second)%M;
                count=(count+val)%M;
            }
            m_left[nums[i]]++;
        }
        return count;
    }
};