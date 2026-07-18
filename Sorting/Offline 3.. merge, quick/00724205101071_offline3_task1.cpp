#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
int comparisons = 0;

int Partition(int low, int high)
{
    int pivot = vec[high];

    int i = low;
    int j = high - 1;

    while(i <= j)
    {
        while(i <= high - 1 && vec[i] < pivot)
        {
            comparisons++;
            i++;
        }

        if(i <= high - 1)
            comparisons++;

        while(j >= low && vec[j] >= pivot)
        {
            comparisons++;
            j--;
        }

        if(j >= low)
            comparisons++;

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

    for(int i = 0; i < n; i++)
    {
        cin>>x;
        vec.push_back(x);

    }

    QuickSort(0, n - 1);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
        cout << vec[i] << " ";

    cout << endl;
    cout << "Comparisons = " << comparisons << endl;

    return 0;
}
