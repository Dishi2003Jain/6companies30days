class Solution {
public:
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<pair<string,vector<string>>> pr;
        vector<string> answer;
        for(int i=0;i<transactions.size();i++){
            pr.push_back(make_pair(transactions[i],sp(transactions[i])));
        }
        for(int i=0;i<pr.size();i++){
            vector<string> s = pr[i].second;
            if(stoi(s[2])>1000){
                cout<<s[2]<<endl;
                answer.push_back(pr[i].first);
                continue;
            }
            for(int j=0;j<pr.size();j++){
                if(i!=j){
                vector<string> t = pr[j].second;
                if( abs(stoi(t[1]) - stoi(s[1])) <= 60){
                    if(t[0] == s[0] && t[3] != s[3]){
                       answer.push_back(pr[i].first);
                        break;
                    } 
                } 
                }
            }
        }
        return answer;
    }

    vector<string> sp(string &str){
        vector<string> ans;
        string s;
        for(int i=0;i<str.size();i++){
            if(str[i]==','){
                ans.push_back(s);
                s.clear();
            }
            else{
                s.push_back(str[i]);
            }
        }
        ans.push_back(s);
        return ans;
    }
};