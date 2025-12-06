class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(nums1[i]);
        for(int j=0;j<m;j++) ans.push_back(nums2[j]);
        sort(ans.begin(),ans.end());

        if((n+m)%2==0){
            int first=(n+m)/2-1;
            int second=first+1;
            return (double) (ans[first]+ans[second])/2;
        }
        return (double)ans[(n+m)/2];
    }
};