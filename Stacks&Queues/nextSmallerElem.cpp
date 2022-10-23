#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=n-1; i>=0;i--){
       // jab tak ek chota elem nhi milta tab tak pop karte jao
        int curr=arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        
        // ans is stack kaa top
        ans[i]=st.top();
        // curr elem ko humesha push karvana h
        st.push(curr);
        
    }
    
    return ans;
}
