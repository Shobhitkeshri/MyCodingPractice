class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq; 
        
        int n=arr.size();
        for(int i=0;i<n;i++){
           if(pq.empty() || pq.size()<k) pq.push({abs(arr[i]-x),arr[i]});
           else{
            int first=pq.top().first;
            int second=pq.top().second;
            
               int val=abs(arr[i]-x);
               if(first>=val){
                if(first>val || (first==val && second>arr[i])){
                    pq.pop();
                    pq.push({val,arr[i]});
                }
                
               }
           }
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};