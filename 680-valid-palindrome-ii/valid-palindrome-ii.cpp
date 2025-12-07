class Solution {
public:
    bool find(int i,int j,bool isChanged,string &s){
        if(i>=j) return true;
        if(s[i]!=s[j]){
            if(isChanged==true) return false;
            return find(i+1,j,!isChanged,s) || find(i,j-1,!isChanged,s);
        }
        return find(i+1,j-1,isChanged,s);
    }
    bool validPalindrome(string s) {
        int n=s.size();
        bool isChanged=false;
        return find(0,n-1,isChanged,s);
    }
};