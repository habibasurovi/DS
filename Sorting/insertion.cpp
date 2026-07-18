#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void insertion()
{
    for(int i = 1; i<v.size(); i++)
    {
        int key = v[i];
        int j;
        for(j=i-1; j>=0&&v[j]<key; j--)
        {
            v[j+1] =v[j];
        }
        v[j+1]= key;
    }
}
int main()
{
    int x, n;
    cin>> n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    insertion();
    for(int i= 0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
}
