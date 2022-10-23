void solve(stack<int>&inputStack, int N, int count){
    // base case
    if(count==N/2){
        inputStack.pop();
        return;
    }
    
    int el=inputStack.top();
    inputStack.pop();
    // Recursive Call
    solve(inputStack, N, count+1);
    inputStack.push(el);
}
void deleteMiddle(stack<int>&inputStack, int N){
	solve(inputStack,N,0);
   
}
