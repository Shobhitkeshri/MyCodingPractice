class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        unordered_map<string,int> m;
        int n=s.size();
        vector<string> ans;
        for(int i=0;i<=n-10;i++){
            string first=s.substr(i,10);
            m[first]++;
            if(m[first]==2){
                ans.push_back(first);
            }
        }
        return ans;
    }
};