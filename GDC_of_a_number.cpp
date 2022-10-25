#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cout<<"Enter 2 numbers: ";
    cin>>m>>n;

    while(m!=n)
    {
        if(m>n)
            m=m-n;
        else
            n=n-m;
    }
    cout<<"GDC is "<<m;

    return 0;
}
