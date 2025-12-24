class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=apple[i];

        sort(capacity.begin(),capacity.end());
        int boxes=0;
        int j=capacity.size()-1;
        while(j>=0 && sum>0){
            sum-=capacity[j--];
            boxes++;
        }
        return boxes;
    }
};