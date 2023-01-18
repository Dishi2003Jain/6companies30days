class Solution {
public:
    int dis(vector<int>&first , vector<int>&second){
        return (((second[0]-first[0])*(second[0]-first[0]))+((second[1]-first[1])*(second[1]-first[1])));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
       unordered_set<int> st;
       st.insert(dis(p1,p2));
       st.insert(dis(p1,p3));
       st.insert(dis(p1,p4));
       st.insert(dis(p2,p3));
       st.insert(dis(p2,p4));
       st.insert(dis(p3,p4));
       if(st.size()==2){
           for(auto x:st){
               if(x==0)  return false;
           }
           return true;
       }
       return false;
    }
};