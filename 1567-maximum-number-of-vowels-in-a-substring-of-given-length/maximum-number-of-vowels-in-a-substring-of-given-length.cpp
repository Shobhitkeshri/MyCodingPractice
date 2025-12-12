class Solution {
public:
    bool vowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int start=0,end=0;
        int vowels=0;
        int maxVowels=0;
        for(int i=0;i<k;i++){
            if(vowel(s[i])) vowels++;
        }
        maxVowels=max(maxVowels,vowels);
        start=0,end=k;
        while(end<n){
            if(vowel(s[end])) vowels++;
            if(vowel(s[start])) vowels--;
            start++;
            maxVowels=max(maxVowels,vowels);
            end++;
        }
        return maxVowels;
    }
};