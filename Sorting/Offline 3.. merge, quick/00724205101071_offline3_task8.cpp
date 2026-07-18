#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
int comparisons = 0;

void Merge(int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high)
    {
        comparisons++;

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

    while(j <= high)
    {
        temp.push_back(vec[j]);
        j++;
    }

    int k = 0;

    while(k < temp.size())
    {
        vec[low + k] = temp[k];
        k++;
    }
}

void MergeSort(int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        MergeSort(low, mid);
        MergeSort(mid + 1, high);

        Merge(low, mid, high);
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

    MergeSort(0, vec.size() - 1);

    cout << "Sorted Array: ";

    int i = 0;
    while(i < vec.size())
    {
        cout << vec[i] << " ";
        i++;
    }

    cout << endl;
    cout << "Total Comparisons = " << comparisons;

    return 0;
}
