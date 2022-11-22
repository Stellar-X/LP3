#include <bits/stdc++.h>

using namespace std;


// Iterative Method
int fibonacci_iter(int n)
{
    int f0=0, f1=1;

    if(n==0)
        return f0;
    
    if(n==1)
        return f1;
    
    for(int i=2; i<=n; i++)
    {
        f1 = f1 + f0;
        f0 = f1 - f0;
    }

    return f1;
}


// Recursive Method
int fibonacci_rec(int n)
{
    if(n==0 || n==1)
        return n;
    
    return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}


int main()
{
    int n;
    cout<<"\nEnter value of 'n' : ";
    cin>>n;

    cout<<"\nOutput (Iterative Method) : "<<fibonacci_iter(n);
    cout<<"\nOutput (Recursive Method) : "<<fibonacci_rec(n);

    return 0;
}