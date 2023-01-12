class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<int,int> mp;
        int bulls=0,cows=0;
        for(int i=0;i<g.size();i++){
            if(g[i]==s[i])  bulls++;
        }
        for(auto it:s) mp[it]++;
        for(auto it:g){
            if(mp[it]>0){
                cows++;
                mp[it]--;
            }
        }
        cows=cows-bulls;
        string b=to_string(bulls);
        string c=to_string(cows);
        string ans=b+"A"+c+"B";
        return ans;
    }
};