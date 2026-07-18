#include<bits/stdc++.h>
using namespace std;
vector<int> Merge(vector<int> &v1, vector<int> &v2)
{
    int i = 0;
    int j = 0;
    vector<int> temp;
    while(i< v1.size() && j< v2.size())
    {
        if(v1[i]<= v2[j])
        {
            temp.push_back(v1[i]);
            i++;
        }
        else
        {
            temp.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size())
    {
        temp.push_back(v1[i]);
        i++;
    }
    while(j< v2.size())
    {
        temp.push_back(v2[j]);
        j++;
    }
    return temp;

}
float median(vector<int> &v1, vector<int> &v2)
{
    vector<int> vec = Merge(v1,v2);
    int mid = vec.size()/2;
    if(vec.size()%2 !=0)
    {
        return vec[mid];
    }
    else
    {
        return (vec[mid-1]+vec[mid])/2.0;
    }
}
int main()
{
    vector<int> v1, v2;
    int n1, n2, x;
    cin>> n1>> n2;
    for(int i = 0; i<n1; i++)
    {
        cin>>x;
        v1.push_back(x);
    }
    for(int i = 0; i<n2; i++)
    {
        cin>>x;
        v2.push_back(x);
    }
    vector<int> fin = Merge(v1, v2);
    for(int i=0; i<(n1+n2); i++)
    {
        cout << fin[i] << " ";
    }
    cout << endl;
    cout << "The median of the Merged Array is : " << median(v1,v2) << endl;

}
