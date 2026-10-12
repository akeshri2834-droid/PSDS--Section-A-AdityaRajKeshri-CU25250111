#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != 0)
            s.insert(x); // a set keeps only distinct values
    }
    cout << s.size() << "\n";
    return 0;
}