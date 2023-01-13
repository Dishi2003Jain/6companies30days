class Solution {
public:
    int numberOfSubstrings(string s) {
       int l=0,r=0,end=s.length()-1;
       int n=s.length();
       unordered_map<char,int> mp;
       int count=0;
       while(r<n){
           mp[s[r]]++;
           while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
               count+=1+(end-r);
               mp[s[l]]--;
               l++;
           }
           r++;
       }
       return count;
    }
};