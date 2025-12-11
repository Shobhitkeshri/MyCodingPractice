class Solution {
public:
    int numberOfSubstrings(string s) {
         int n = s.size();
        int start = 0, end = 0;
        int cnt[3] = {0};
        int total = 0;

        while (end < n) {
            cnt[s[end] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                total += (n - end);
                cnt[s[start] - 'a']--;
                start++;
            }
            end++;
        }
        return total;       
    }
};