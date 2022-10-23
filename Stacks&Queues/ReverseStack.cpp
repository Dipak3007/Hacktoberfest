void insertAtBottom(stack<int>& myStack, int x){
    // base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }
    
    int num =myStack.top();
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(num);
    
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    
    int num= stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}
