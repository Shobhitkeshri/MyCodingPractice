class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int,int>> x_build(n+1,{INT_MAX,-1});
        vector<pair<int,int>> y_build(n+1,{INT_MAX,-1});
        
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];

            x_build[x].first=min(x_build[x].first,y);
            x_build[x].second=max(x_build[x].second,y);

            y_build[y].first=min(y_build[y].first,x);
            y_build[y].second=max(y_build[y].second,x);
        }
        int totalCovered=0;
        for(int start=0;start<buildings.size();start++){
            int x=buildings[start][0];
            int y=buildings[start][1];
            
            int mini_x=x_build[x].first;
            int maxi_x=x_build[x].second;

            int mini_y=y_build[y].first;
            int maxi_y=y_build[y].second;

            if(y>mini_x && y<maxi_x && x>mini_y && x<maxi_y) totalCovered++;
            
        }
        return totalCovered;
    }
};