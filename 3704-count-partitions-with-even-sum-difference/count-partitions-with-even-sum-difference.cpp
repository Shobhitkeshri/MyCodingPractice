class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return 0;
        int left=0,right=sum;
        
        int cnt=0;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right-=nums[i];
            if(abs(left-right)%2==0) cnt++;
        }
        return cnt;
    }
};