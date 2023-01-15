class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int count=0;
        map<pair<int,int>,int>mp;
        for(auto it:rectangles){
            mp[{it[0],it[1]}]++;
            mp[{it[2],it[3]}]++;
            mp[{it[0],it[3]}]--;
            mp[{it[2],it[1]}]--;
        }
        for(auto it:mp)  count+=abs(it.second);
        return count==4;
    }
};