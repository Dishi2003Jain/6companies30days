class Solution {
public:
     int reverse(int num){
         int rev=0;
        while(num>0){
            rev = rev*10+num%10;
            num/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        long long count=0;
        for(auto num:nums){
            int diff = num-reverse(num);
            if(mp.find(diff)!=mp.end())   count+=mp[diff];
            mp[diff]++;
        }
        return count%1000000007;
    }
};