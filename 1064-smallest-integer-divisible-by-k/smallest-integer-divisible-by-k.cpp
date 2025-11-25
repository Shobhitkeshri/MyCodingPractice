class Solution {
public:
    int smallestRepunitDivByK(int k) {
       int num=0;
        int cnt=0;
        while(cnt<k){
            cnt++;
            num=(num%k)*10+1;
         if(num%k==0){
            return cnt;
         }   
        }
        return -1;
    }
};