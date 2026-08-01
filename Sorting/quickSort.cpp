#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int> &v, int low, int high)
{
    int index = low - 1;
    int pivot = v[high];
    for(int i = low; i<high; i++)
    {
        if(v[i]<=pivot)
        {
            index++;
            swap(v[i], v[index]);
        }

    }
    index++;
    swap(v[high], v[index]);
    return index;
}

void quickSort(vector<int> &v, int low, int high)
{
    if(low<high)
    {
    int pvIdx = Partition(v,low, high);
    quickSort(v, low, pvIdx - 1); //left
    quickSort(v, pvIdx + 1, high); //right
    }
}


int main()
{
    vector<int> vec;
    int n,x;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    quickSort(vec, 0, n-1);
    for(int i = 0; i<n; i++)
    {
        cout<<vec[i]<< " ";
    }
}
