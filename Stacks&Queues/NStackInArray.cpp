#include <bits/stdc++.h>
class NStack
{       int *arr;
        int* top;// to store the top element of each stack
        int* next;// it stores the next free space 
        int freeSpot;// it tells the current free space 
         int n, s;
public:
    // Initialize your data structure.
    NStack(int N, int S)
        
    {   n=N;
        s=S;
        arr= new int[s];
         top= new int[n];
         next= new int[s];
         
     // initialising the values of top to -1
     for(int i=0; i<n;i++){
         top[i]=-1;
     }
     // next Intialisation
     for(int i=0;i<s;i++){
         next[i]=i+1;
     }
     
     // update the last index value to -1
     next[s-1]=-1;
     freeSpot=0;
        
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {  
        // if the stack is already full
        if(freeSpot==-1){
            return false;
        }
        
        // find the index to push the elem
       int index=freeSpot;
        // update the free spot 
        freeSpot=next[index];
        // insert th elem in the array
        arr[index]=x;
        
        // update the next
        next[index]=top[m-1];
        //update the top
        top[m-1]=index;
        
        return true;
        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty,             otherwise returns the popped element.
    int pop(int m)
    {
        // if there is no elem is the stack 
        if(top[m-1]==-1){
            return -1;
        }
        
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeSpot;
        freeSpot=index;
        return arr[index];
    }
};
