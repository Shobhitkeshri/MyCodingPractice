class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int start=0,end=0;
        unordered_map<char,int> m;
        int len=0;
        while(end<n){
            m[s[end]]++;
            while(m[s[end]]>1){
               m[s[start]]--;
               start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};