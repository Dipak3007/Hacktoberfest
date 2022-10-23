// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    bool knows(vector<vector<int> >& M, int a, int b){
        if(M[a][b]==1){
            return true;
        }else{
            return false;
        }
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0 ;i<n;i++){
            s.push(i);
        }
        
        while(s.size()>1){
            int a= s.top(); s.pop();
            int b=s.top(); s.pop();
            
            if(knows(M,a,b)){
                s.push(b);
            }else{
                s.push(a);
            }
        }
        
        // ab jo ek elem stack me bacha hai 
        // use nikaalo 
        // that must be the potenatial candidate 
        int candidate =s.top();
        
        // check for rows
        bool rowsBool= false;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0){
                zeroCount++;
            }
        }
        
        if(zeroCount==n){
            rowsBool=true;
        }
        
        
        // check for cols 
        bool colsBool= false;
        int oneCount=0;
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1){
                oneCount++;
            }
        }
        
        if(oneCount==n-1){
            colsBool=true;
        }
        
        if(colsBool ==true&& rowsBool==true){
            return candidate;
        }
        else{
            return -1;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
