class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2;
        nums2=nums;
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n && nums[i]==nums2[i]) i++;
        int j=nums.size()-1;
        while(j>=0 && nums[j]==nums2[j])  j--;
        if(i==n) return 0;
        return j-i+1;
    }
};