#include<bits/stdc++.h>
using namespace std;

int UpperBound(vector<int>& v, int key)
{
    int low = 0;
    int high = v.size()-1;
    int res = -1;


    while(low<=high)
    {
        int mid = (low+high)/2;
        if(v[mid]> key)
        {
            res = mid;
            high= mid - 1;
        }
        else if(v[mid]<=key)
        {
            low = mid + 1;
        }

    }
    return res;
}

int main()
{
    int n,x;
    vector<int> vec;

    cout<< "Enter the number of elements : ";
    cin>>n;
    cout<< "Enter the elements ";
    for(int i =0; i<n; i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    cout<< "Enter the value whose upper bound you want to search : ";
    cin>>x;
    int index = UpperBound(vec,x);
    cout<< "The upper bound is at index : " << index;

}

