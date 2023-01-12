class Solution {
public:
    typedef pair<int, int> pi;
    bool divisible(int n,vector<int> &vctdivide){
         for(int i=0;i<vctdivide.size();i++){
             if(vctdivide[i]%n!=0)  return false;
         }
         return true;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        unordered_map <int,int> mp;
        for(auto it:nums)  mp[it]++;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(auto it:mp)  pq.push(make_pair(it.first,it.second));
        int count=0;
        while(!pq.empty()){
            pair<int,int> tp = pq.top();
            if(divisible(tp.first,numsDivide)) {
                 break;
            }
            else{
            count+=tp.second;
            pq.pop();
            if(pq.empty()) return -1;
            }
        }
        return count;
    }
};