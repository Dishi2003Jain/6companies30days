class Solution {
public:
   
    int evalRPN(vector<string>& t) {
        stack<long long> st;
        for(int i = 0;i<t.size();i++){
            if(t[i]=="+" || t[i]=="-" || t[i]=="*" || t[i]=="/"){
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                if(t[i]=="+"){
                    st.push(b+a);
                }
                else if(t[i]=="-"){
                    st.push(b-a);
                }
                else if(t[i]=="*"){
                    st.push(b*a);
                }
                else{
                    st.push(b/a);
                }
            }
            else{
                st.push(stoi(t[i]));
            }
        }
        return st.top();
    }
};