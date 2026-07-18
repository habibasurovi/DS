#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
void merge(int low, int mid, int high)
{
    vector<int> temp(high + 1);
    int i = low; //left
    int j = mid + 1; //right
    int k = low;
    while(i <= mid && j<= high)
    {
        if(vec[i]<= vec[j])
        {
            temp[k] = vec[i];
            i++;
        }
        else
        {
            temp[k] = vec[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = vec[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = vec[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        vec[i] = temp[i];
    }

}
void mergeSort(int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(low,mid); //sort left halves
        mergeSort(mid+1,high); //sort right halves
        merge(low, mid, high); // to merge both sides
    }
}

int main()
{
    int n,x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin>> x;
        vec.push_back(x);

    }

    mergeSort(0, n - 1);

    for (int i = 0; i<n; i++)
        cout << vec[i] << " ";
}
