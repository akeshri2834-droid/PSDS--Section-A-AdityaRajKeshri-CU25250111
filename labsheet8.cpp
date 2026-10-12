#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue; // skip duplicate

        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = a[i] + a[l] + a[r];
            if (sum == 0)
            {
                cout << a[i] << " " << a[l] << " " << a[r] << "\n";
                l++;
                r--;
                while (l < r && a[l] == a[l - 1])
                    l++; // skip duplicates
                while (l < r && a[r] == a[r + 1])
                    r--;
            }
            else if (sum < 0)
                l++; // need a bigger sum
            else
                r--; // need a smaller sum
        }
    }
    return 0;
}