#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
int mergeCount = 0;

void mergeArray(int l, int mid, int r)
{
    mergeCount++;

    vector<int> temp;

    int i = l;
    int j = mid + 1;

    while(i <= mid && j <= r)
    {
        if(vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }

    while(j <= r)
    {
        temp.push_back(vec[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++)
    {
        vec[l + k] = temp[k];
    }
}

void mergeSort(int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;

        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        mergeArray(l, mid, r);
    }
}

int main()
{
    int n, x;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    mergeSort(0, vec.size() - 1);

    cout << "Sorted Array: ";

    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }

    cout << endl;
    cout << "Total Merge Operations: " << mergeCount;

    return 0;
}
