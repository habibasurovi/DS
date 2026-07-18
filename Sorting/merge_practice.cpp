#include<bits/stdc++.h>
using namespace std;
int comparison = 0;
int mrg = 0;
int recursive = 0;

void Merge(vector<int> &vec, int low, int mid, int high)
{
    mrg++;
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    while(i<= mid && j<= high)
    {
        comparison++;
        if(vec[i]<= vec[j])
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
    while(i<=mid)
    {
        temp.push_back(vec[i]);
        i++;
    }
    while(j<= high)
    {
        temp.push_back(vec[j]);
        j++;
    }
    for(int f = low; f<=high; f++)
    {
        vec[f]=temp[f-low];
    }
}
void mergeSort(vector<int> &vec, int low, int high)
{
    recursive++;
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(vec,low, mid);
        mergeSort(vec,mid+1, high);
        Merge(vec, low, mid, high);
    }
}

int main()
{
    vector<int> v;
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    mergeSort(v,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<< v[i] << " ";
    }
    cout << endl;
    cout << "Total Number of Comparison Needed : " << comparison << endl;
    cout << "Total Number of Merge operation performed : " << mrg << endl;
    cout << "Total Number of Recursive Calls Merge Sort Makes : " << recursive << endl;
}
