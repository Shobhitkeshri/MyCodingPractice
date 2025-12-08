class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first=0,second=0;
        int n=s.size();
        unordered_map<char,int> m;
        int ans=0;
        while(second<n){
           while(m[s[second]]>0){
            m[s[first]]--;
            first++;
           }
           ans=max(ans,second-first+1);
           m[s[second]]++;
           second++;
        }
        return ans;
    }
};