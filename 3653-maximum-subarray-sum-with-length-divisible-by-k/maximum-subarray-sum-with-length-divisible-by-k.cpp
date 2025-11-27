class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
        long long result=LLONG_MIN;
        vector<long long> prefix(n);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        for(int start=0;start<k;start++){
            long long currSum=0;
            
            int i=start;
            while(i<n && i+k-1<n){
                int j=i+k-1;
                
                long long subSum= (i>0) ? prefix[j]-prefix[i-1]:prefix[j];
                currSum=max(subSum,currSum+subSum);
                result=max(result,currSum);

                i+=k;
            }
        }
        return result;
    }
};