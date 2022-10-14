#include <bits/stdc++.h>

using namespace std;

void solve(int *a, int m, int *b, int n)
{
    unordered_set<int> s(b, b + n);
    for (int i = 0; i < m; i++)
    {
        if (s.find(a[i]) != s.end())
        {
            s.erase(s.find(a[i]));
            cout << a[i] << ' ';
        }
    }
}

int main()
{
    system("CLS");
    int a[] = {1, 3, 3, 4, 5};
    int b[] = {3, 4, 5, 6, 7};
    solve(a, 5, b, 5);

    return 0;
}