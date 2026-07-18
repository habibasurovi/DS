#include<bits/stdc++.h>
using namespace std;
vector<int> vec;

void BinarySearch(int key)
{
    int high = vec.size() - 1;
    int low = 0;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(vec[mid]==key)
        {
            cout<< "Book found"<<endl;
            return;

        }
        else if(vec[mid]<key)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout<< "Book not found." <<endl;
}

int UpperBound(int key)
{
    int low = 0;
    int high = vec.size() - 1;
    int res = vec.size();

    while(low <= high)
    {
        int mid = (low + high)/2;
        if(vec[mid]> key)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int LowerBound(int key)
{
    int low = 0;
    int high = vec.size() - 1;
    int res = vec.size();
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(vec[mid]>= key)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{

    int n, x;
    cin>> n;
    for(int i = 0; i<n; i++)
    {
        cin>> x;
        vec.push_back(x);
    }
    cin>>x;
    BinarySearch(x);
        cout<< "Lower Bound Index: "<< LowerBound(x)<<endl;
        cout<< "Upper Bound Index: "<< UpperBound(x)<<endl;
}
