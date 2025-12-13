class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        int n=s.size();
        unordered_map<char,int> charPresent;
        int minLen=INT_MAX,startIndex=-1;
        for(int i=0;i<t.size();i++){
            charPresent[t[i]]++;
        }
        int start=0,end=0;
        int cntRequired=t.size();
        while(end<n){
            if(charPresent[s[end]]>0){
                charPresent[s[end]]--;
                cntRequired--;
            }
            else charPresent[s[end]]--;
            while(cntRequired==0){
                int len=end-start+1;
                if(len<minLen){
                    minLen=len;
                    startIndex=start;
                }
                charPresent[s[start]]++;
                if(charPresent[s[start]]>0) cntRequired++;

                start++;
            }
            end++;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minLen);
    }
};