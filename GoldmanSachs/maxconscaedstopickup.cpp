class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>>mp;
        int ans = INT_MAX;
        for(int i=0;i<cards.size();i++)  mp[cards[i]].push_back(i);
        for(auto it:mp){
            if(it.second.size()>1){
            int count = INT_MAX;
            for(int i=0;i<it.second.size()-1;i++){
                count=min(count,it.second[i+1]-it.second[i]+1);
            }
            ans=min(ans,count);
            }
        }
        if(ans==INT_MAX)  return -1;
        return ans;
        }
};