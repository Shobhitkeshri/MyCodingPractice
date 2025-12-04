class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int i=0,j=n-1;
        while(i<n && directions[i]=='L'){
             i++;
        }
        while(j>=0 && directions[j]=='R') j--;

        int cnt=0;
        while(i<n && i<=j ){
           if(directions[i]=='R' || directions[i]=='L') cnt++;
           i++;
        }
        return cnt;
    }
};