#include<stack>
bool findRedundantBrackets(string &s)
{   
    stack<char> stack;
    
    for(int i=0 ;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*'|| s[i] =='/'){
            
            stack.push(s[i]);
        }
        else{
            // ) 
            // now check whether there is an opening brackets in the stack and operation 
            
            if(s[i]==')'){
                
                
                
                bool isRedundant= true;
                while(stack.top() !='('){
                    char ch=stack.top();
                    
                    if(ch=='+' || ch=='-' || ch=='*'|| ch =='/'){
                        isRedundant=false;
                    }
                    stack.pop();
                    
                }
                
                
                if(isRedundant==true){
                    return true;
                }
                stack.pop();
            }
        }
    }
    
    return false;
    
}
