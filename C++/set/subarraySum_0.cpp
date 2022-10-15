#include <bits/stdc++.h>

using namespace std;

bool solve(int *a, int n)
{
    unordered_set<int> s;
    int pre_Sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_Sum += a[i];
        if (s.find(pre_Sum) != s.end())
            return 1;
        if (pre_Sum == 0)
            return 1;
        s.insert(pre_Sum);
    }
    return 0;
}

int main()
{
    system("CLS");
    int a[] = {
        4,
        2,
        -3,
        1,
        6,
    };
    if (solve(a, 5))
        cout << "YES";
    else
        cout << "No";

    return 0;
}