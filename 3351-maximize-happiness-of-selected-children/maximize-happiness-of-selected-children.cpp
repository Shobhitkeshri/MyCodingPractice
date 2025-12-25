class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        int cnt=0;
        priority_queue<int,vector<int>> pq;
        for(int i=0;i<happiness.size();i++){
            pq.push(happiness[i]);
        }
        while(!pq.empty() && k>0){
            int val=pq.top();
            pq.pop();

            val-=cnt;
            if(val<0) break;
            cnt++;
            sum+=val;
            k--;
        }
        return sum;
    }
};