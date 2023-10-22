#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int kSpack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    // If weight of the item is more than capacity then this item cannot be included in knapsack
    if (wt[n - 1] > W)
        return kSpack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + kSpack(W - wt[n - 1], wt, val, n - 1), kSpack(W, wt, val, n - 1));
}
int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << "Maximum value that can be put in a knapsack of capacity W is: " << kSpack(W, weight, profit, n);
    return 0;
}