#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& vec, int key)
{
    int low=0;
    int high = vec.size() -1;
    while(low<= high)
    {
       int mid = (low + high)/2;
       if(vec[mid]==key)
       {
           cout<<"Element found at Index : "<<mid<<endl;
           return mid;
       }
       else if(vec[mid]>key)
       {
           high = mid - 1;
       }
       else
       {
           low = mid + 1;
       }
    }
    return -1;
}
int main()
{
    int n, x;
    vector<int> v;
    cout<< "Enter the number of elements : ";
    cin>> n;
    cout<< "Enter the elements: " <<endl;
    for(int i=0; i<n ; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<< "Enter the elemenet you want to search: ";
    cin>>x;
    int isfound = BinarySearch(v , x);
    if( isfound == -1)
        cout<< "Value is not found. " <<endl;

}


