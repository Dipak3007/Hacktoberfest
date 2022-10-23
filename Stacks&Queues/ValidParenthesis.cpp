bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(int i=0 ;i<expression.length();i++){
        char ch= expression[i];
        if(ch=='{' || ch=='(' || ch=='[' ){
            // if there is a opening bracket
            st.push(ch);
        }else{
            // stack is not empty 
            if(!st.empty()){
               char top= st.top();
                if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{')){
                    st.pop();
                } else{
                    return false;
                }
            }
            else{
                // stack is empty already or matlb '}' isk liye koi corresponding forward bracket h hi nhi 
                 return false;
            }
            
        }
    
    }
    
    if(st.empty()){
        return true;
    }else{
        return false;
    }
    
    
    
    
}
