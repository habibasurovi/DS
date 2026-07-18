#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

int Partition(int low, int high)
{
    int pivot = vec[high];

    int i = low - 1;
    int j = low;

    while(j < high)
    {
        if(vec[j] < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
        j++;
    }

    swap(vec[i + 1], vec[high]);

    return i + 1;
}

void QuickSort(int low, int high)
{
    if(low < high)
    {
        int p = Partition(low, high);

        cout << "Pivot " << vec[p] << " is placed at index " << p << endl;

        QuickSort(low, p - 1);
        QuickSort(p + 1, high);
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

    QuickSort(0, vec.size() - 1);

    cout << "Sorted Array: ";

    int i = 0;
    while(i < vec.size())
    {
        cout << vec[i] << " ";
        i++;
    }

    return 0;
}
