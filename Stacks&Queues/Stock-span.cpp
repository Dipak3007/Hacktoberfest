#include<stack>
vector<int> NGL(vector<int>&arr){
    stack<int>st;
    //cout<<"******"<<endl;
    vector<int>ans(arr.size());
    ans[0]=-1;
    st.push(0);
    
    for(int i=1 ;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        
        if(st.empty()){
            ans[i]=-1;
        }else{
             ans[i]=st.top();
        }
        st.push(i);
    }
    
    return ans;
}
vector<int> findSpans(vector<int> &price) {
    
    vector<int> ngl= NGL(price);
    
//     for(int i=0 ;i<ngl.size();i++){
//         cout<<ngl[i]<<" ";
//     }
//     cout<<endl;
    vector<int>ans(price.size());
//     cout<<"///"<<endl;
    for(int i=0 ;i<price.size(); i++){
//         cout<<"/// "<<i<<endl;
        ans[i]= i-ngl[i];
        
        
    }
    
    return ans;
    
    
    
}
