class Solution {
public:
    int DFS(int node,int par,vector<int> &nums,vector<vector<int>> &adj,int k,int &cnt){
      int curr = nums[node];   // start new subtree sum

        for(int neigh : adj[node]) {
            if(neigh == par) continue;

            curr += DFS(neigh, node, nums, adj, k, cnt);
            curr %= k;
        }

        if(curr % k == 0) {
            cnt++;       // one valid component
            return 0;    // break component here, reset sum up
        }
        return curr;  
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
            if(n == 1) return 0;

            vector<vector<int>> adj(n);
            for(auto &e : edges) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

            long long total = 0;
            for(int x : nums) total += x;

            int ans = 0;

            for(int parts = 1; parts <= total; parts++) {
                if(total % parts == 0) {
                    int k = total / parts;
                    int cnt = 0;
                    DFS(0, -1, nums, adj, k, cnt);

                    if(cnt == parts) ans = max(ans, parts - 1);
                }
            }
            return ans;
    }
};