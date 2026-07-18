#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

int Partition(int low, int high)
{
    int pivot = vec[high];

    int i = low;
    int j = high - 1;

    while(i <= j)
    {
        while(i <= high - 1 && vec[i] < pivot)
            i++;

        while(j >= low && vec[j] >= pivot)
            j--;

        if(i < j)
            swap(vec[i], vec[j]);
    }

    swap(vec[i], vec[high]);

    return i;
}

void QuickSort(int low, int high)
{
    if(low < high)
    {
        int p = Partition(low, high);

        QuickSort(low, p - 1);
        QuickSort(p + 1, high);
    }
}

int main()
{
    int n,x;
    cin >> n;

    int i = 0;

    while(i < n)
    {
        cin >> x;
        vec.push_back(x);
        i++;
    }

    int pivot;
    cin >> pivot;

    int index = -1;

    i = 0;
    while(i < n)
    {
        if(vec[i] == pivot)
        {
            index = i;
            break;
        }
        i++;
    }

    if(index == -1)
    {
        cout << "Pivot not found!";
        return 0;
    }

    swap(vec[index], vec[n - 1]);

    QuickSort(0, n - 1);

    cout << "Sorted Array: ";

    i = 0;
    while(i < n)
    {
        cout << vec[i] << " ";
        i++;
    }

    return 0;
}
