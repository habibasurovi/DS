#include<bits/stdc++.h>
using namespace std;
vector<int> vec;

void InsertElement(int key)
{
    int low = 0;
    int high = vec.size() - 1;
    int res = 0;
    while(low<=high)
    {
        int mid = (low + high )/2;
        if(vec[mid]== key)
        {
            res = mid;
        }
        else if(vec[mid]<key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    vec.push_back(0);
    for(int i = vec.size(); i>res; i--)
    {
        vec[i] = vec[i-1];
    }
    vec[res] = key;

}
int main()
{
    int n, x, val;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    cin>>val;
    InsertElement(val);
    for(int i = 0; i<vec.size(); i++)
    {
        cout<<vec[i] << "  ";
    }
}
