class Solution {
public:
vector<int>ans;
int maxpoints=0; 
    void solve(int ind,int score,int arrow,vector<int> &nums,vector<int> &res){
        if(arrow==0||ind<0){
            if(score>maxpoints){
                maxpoints=score;
                ans=res;
            }
            return ;
        }
       
        if(arrow>nums[ind]){
           res[ind]=nums[ind]+1;
            solve(ind-1,score+ind,arrow-(nums[ind]+1),nums,res);
          res[ind]=0;
           
        }
        solve(ind-1,score,arrow,nums,res);
        
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12,0);
        solve(11,0,numArrows,aliceArrows,res);
        int cnt=0;
        for(auto it:ans){
            cnt+=it;

        }
        int startind=numArrows-cnt;
        if(startind>0){
            ans[0]+=startind;
        }
         return ans;
    }
};