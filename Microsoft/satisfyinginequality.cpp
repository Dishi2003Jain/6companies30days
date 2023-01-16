class Solution {
public:
    long long c=0;
    void Count(vector<int>&v,int start, int mid, int end,int d){
        int l=start, r=mid+1;
        while(l<=mid && r<=end){
            if(v[l]<=(v[r]+d)){
                c+=(end-r+1);
                l++;
            }
            else{
                r++;
            }
        }
        sort(v.begin()+start,v.begin()+end+1);
    }
    void mergeSort(vector<int>&v, int start, int end, int d){
        if(start==end){
            return;
        }
        int mid=start+(end-start)/2;
        mergeSort(v,start,mid,d);
        mergeSort(v,mid+1,end,d);
        Count(v,start,mid,end,d);

    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]-nums2[i]);
        }
        mergeSort(v,0,n-1,diff);
        return c;
    }
};