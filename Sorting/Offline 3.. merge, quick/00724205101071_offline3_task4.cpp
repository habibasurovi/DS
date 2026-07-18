
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
        cout << "Pivot: " << vec[high] << endl;

        int p = Partition(low, high);

        QuickSort(low, p - 1);
        QuickSort(p + 1, high);
    }
}

int main()
{
    int n,x;
    cin >> n;


   for(int i=0; i<n; i++)
   {
       cin>>x;
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
