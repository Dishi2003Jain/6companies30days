class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n-1;i++){
            unordered_map<double,int> mp;
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0])  mp[1000001]++;
                else{
                    double slope=(double)(points[j][1]-points[i][1])/(double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            int temp=0;
            for(auto x:mp){
                temp=max(temp,x.second);
            }
          ans=max(ans,temp+1);
        }
      return ans;
    }
};