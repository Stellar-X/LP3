#include <bits/stdc++.h>

using namespace std;

// 0-1 Knapsack Problem using DP (Tabulation Method)
int knapsack(int capacity, vector<int> weight, vector<int> profit)
{
    int n = weight.size();

    vector<vector<int>> dp(n+1, vector<int>(capacity+1));
    for(int i=0; i<=n; i++)
        for(int w=0; w<=capacity; w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(weight[i-1] > capacity)
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(profit[i-1]+dp[i-1][w-weight[i-1]], dp[i-1][w]);
        }
    
    return dp[n][capacity];
}


int main()
{
    int capacity;
    cout<<"Enter capacity of knapsack : ";
    cin>>capacity;

    int n;
    cout<<"Enter no. of weights : ";
    cin>>n;

    cout<<"\nEnter weights and their associated profits :\n";
    vector<int> weight(n), profit(n);
    for(int i=0; i<n; i++)
        cin>>weight[i]>>profit[i];
    
    cout<<"\nMaximum Profit : "<<knapsack(capacity, weight, profit)<<"\n";

    return 0;
}