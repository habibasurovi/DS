#include<bits/stdc++.h>
using namespace std;

vector<int> a, b, merged;

void Merge()
{
    int i = 0;
    int j = 0;

    while(i < a.size() && j < b.size())
    {
        if(a[i] <= b[j])
        {
            merged.push_back(a[i]);
            i++;
        }
        else
        {
            merged.push_back(b[j]);
            j++;
        }
    }

    while(i < a.size())
    {
        merged.push_back(a[i]);
        i++;
    }

    while(j < b.size())
    {
        merged.push_back(b[j]);
        j++;
    }
}

int main()
{
    int n, m, x;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x;
        b.push_back(x);
    }

    Merge();

    cout << "Merged Array: ";

    int i = 0;
    while(i < merged.size())
    {
        cout << merged[i] << " ";
        i++;
    }

    cout << endl;

    int size = merged.size();

    if(size % 2 == 1)
        cout << "Median = " << merged[size / 2];
    else
        cout << "Median = " << (merged[size / 2] + merged[(size / 2) - 1]) / 2.0;

    return 0;
}
