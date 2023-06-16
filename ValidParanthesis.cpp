bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    int n=expression.length();
    for(int i=0;i<n;i++){
        if(expression[i]=='{'||expression[i]=='('||expression[i]=='['){
            st.push(expression[i]);
        }else {
            if(st.size()==0||(expression[i]=='}'&& st.top()!='{')||
            (expression[i]==']'&& st.top()!='[')||
            (expression[i]==')'&& st.top()!='(')){
                return false;
            }
           else {
                st.pop();
           }
            
        }
    }
    return st.empty();
}
//TIME COMPLEXITY:O(N);
//SPACE COMPLEXITY:O(N);
