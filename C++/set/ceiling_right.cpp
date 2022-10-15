#include <bits/stdc++.h>

using namespace std;

void solve(int *a, int n)
{
    set<int> s;
    for (int i = 1; i < n; ++i)
    {

        s.insert(a[i]);
    }
    auto it = s.lower_bound(a[0]);
    if (it != s.end())
        cout << *it << ' ';
    else
        cout << -1 << ' ';
}

main()
{

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
        solve(a + i, n - i);

    return 0;
}