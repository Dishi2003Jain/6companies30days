class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int count=0;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            count++;
            if(k==count){
                q.pop();
                count=0;
            }
            else{
                int p = q.front();
                q.pop();
                q.push(p);
            }
        }
        return q.front();
    }
};