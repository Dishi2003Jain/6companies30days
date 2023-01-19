class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int>pq;
        vector<pair<int,int>> vct;
        for(int i=0;i<p.size();i++){
            vct.push_back({c[i],p[i]});
        }
        sort(vct.begin(),vct.end());
        int i=0;
        while(i<vct.size() && k){
            if(w>=vct[i].first){
                 pq.push(vct[i].second);
                 i++;
            }
            else{
                if(pq.empty()) return w;
                else{
                    w+=pq.top();
                    pq.pop();
                    k--;
                }
            }
        }
        while(k-- && !pq.empty()){
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};