class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int mxm = 0;
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1))  low=mid+1;
            else high=mid;
        }
        mxm=low;
        low=0;
        high=mxm;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)<target) low=mid+1;
            else if(mountainArr.get(mid)==target) return mid; 
            else  high=mid-1;
        }
        low=mxm+1;
        high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mountainArr.get(mid)>target) low=mid+1;
            else if(mountainArr.get(mid)==target) return mid;
            else  high=mid-1;      
        }
        return -1;
    }
};