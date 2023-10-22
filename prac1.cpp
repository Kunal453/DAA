#include <bits/stdc++.h>
using namespace std;

int itstep = 0;
int recstep = 0;

int Fibbonacci(int n)
{
    vector<int> v;

    v.push_back(0);
    v.push_back(1);

    for (int i = 0; i < n; i++)
    {
        itstep++;
        v.push_back(v[i - 1] + v[i - 2]);
    }

    int vcsize = v.size() - 1;
    return v[vcsize];
}
int fibonacciRecursive(int x)
{
    if ((x == 1) || (x == 0))
    {
        return (x);
    }
    else
    {
        recstep++;
        return (fibonacciRecursive(x - 1) + fibonacciRecursive(x - 2));
    }
}

int main()
{
    int n;
    cin >> n;
    cout << "recursive :" << fibonacciRecursive(n) << endl;
    cout << "using iteration :" << Fibbonacci(n) << endl;
    cout << "number of step for reccursion :" << recstep << endl;
    cout << "iterative step :" << itstep << endl;
}