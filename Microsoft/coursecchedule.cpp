class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
       vector<int>adj[n];
        for (auto it : pre)   adj[it[1]].push_back(it[0]);
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])   in[it]++; 
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(q.empty()==false){
            int x=q.front();
            q.pop();
            c++;
            for(auto it:adj[x]){
                in[it]--;
                if(in[it]==0)
                    q.push(it);
            }
        }
        if(c==n) return true;
        return false;

    }
};