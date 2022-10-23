#include<stack>
int findMinimumCost(string str) {
  // Every close brace should have open brace before it ..inorder to be a valid 
    if(str.length()%2==1){//  agar odd length
        return -1;
    }
    stack<char> s;
    for(int i=0 ;i<str.length();i++){
        char ch= str[i];
        if(str[i]=='{'){
            s.push(ch);
        }else{
            // not a open bracket
            // its a clode bracket '}'
            if(!s.empty() && s.top()=='{'){
                s.pop();// we are juts remving opening bracket
            }
            else{
                s.push(ch);
            }
        }
    }
        
        
        // stack contains invalid expressions
        int a=0, b=0;
        
        while(!s.empty()){
            if(s.top()=='{'){
                b++;
            }else{
                a++;
            }
            s.pop();
        }
        
        int ans=(a+1)/2 +(b+1)/2;
        return ans;
        
    
    
    
    
    
    
    
    
}
