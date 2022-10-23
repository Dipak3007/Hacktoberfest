class Solution {
public:
    
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0;i--){
           // jab tak ek chota elem nhi milta tab tak pop karte jao
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }

            // ans is stack kaa top
            ans[i]=st.top();
            // curr elem ko humesha push karvana h
            st.push(i);

            }
        return ans;
        
    }
        
    vector<int> prevSmallerElement(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0; i<n;i++){
       // jab tak ek chota elem nhi milta tab tak pop karte jao
        int curr=arr[i];
        while(st.top()!=-1 && arr[st.top()]>=curr){
            st.pop();
        }
        
        // ans is stack kaa top
        ans[i]=st.top();
        // curr elem ko humesha push karvana h
        st.push(i);
        
        }
    
        return ans;
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=nextSmallerElement(heights,n);
        vector<int> prev(n);
        prev=prevSmallerElement(heights,n);
        int area=INT_MIN;
        for(int i=0 ;i<n;i++){
            int l=heights[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(area, newArea);
        }
        
        return area;
    }
};
