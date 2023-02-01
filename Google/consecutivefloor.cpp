class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int maxi=INT_MIN;
        sort(special.begin(),special.end());
        maxi=max((special[0]-bottom),(top-special[special.size()-1]));
        for(int i=0;i<special.size()-1;i++){
            maxi=max(maxi,(special[i+1]-special[i]-1));
        }
        return maxi;
    }
};