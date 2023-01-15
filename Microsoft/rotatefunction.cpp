class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0,totalsum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            totalsum+=(i*nums[i]);
        }
        int ans = totalsum;
        for(int i=n-1;i>=0;i--){
            totalsum+=(sum-nums[i]*n);
            ans=max(ans,totalsum);
        }
        return ans;
    }
};