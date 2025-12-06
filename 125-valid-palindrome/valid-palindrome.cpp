class Solution {
public:
    bool palindrome(string v){
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]!=v[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string v="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                int x=s[i]-'A';
                char ch='a'+x;
                v+=ch;
            }
            else if(s[i]>='a' && s[i]<='z') v+=s[i];
            else if(s[i]>='0' && s[i]<='9') v+=s[i];
        }

        return palindrome(v);
    }
};