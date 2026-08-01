#include<bits/stdc++.h>
using namespace std;
vector<int> A;
/**1st element as pivot
int Partition(int low, int high)
{
    int i = low;
    int j = high;
    int pivot = A[low];

    while(i<j)
    {
        while(A[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(A[j]>pivot && j>= low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(A[j], A[i]);
        }
    }
    swap(A[low],A[j]);
    return j;
} **/

//last element as pivot

/**int comparison = 0;
int Partition(int low, int high)
{
    int i = low;
    int j = high;
    int pivot = A[high];

    while(i<j)
    {
        while(A[i]<pivot && i<=high-1)
        {
            i++; //finds the greater than pivot
            comparison++;
        }
        if(i<=high-1)
        {
            comparison++;
        }
        while(A[j]>=pivot && j>= low+1)
        {
            j--; //finds smaller than pivot
            comaparison++;
        }
        if(j>= low+1)
        {
            comparison++;
        }
        if(i<j)
        {
            swap(A[j], A[i]);
        }
    }
    swap(A[high],A[i]);
    return i;
}

void quickSort(int low, int high)
{
    if(low<high)
    {
        int pvIdx = Partition(low, high);
        quickSort(low, pvIdx-1);
        quickSort(pvIdx+1, high);
    }
}**/

/** any element as pivot
int Partition(int low, int high)
{
    int pivotIndex = low + (high - low) / 2;   // Choose any pivot index
    int pivot = A[pivotIndex];

    int i = low;
    int j = high;

    while(i <= j)
    {
        while(A[i] < pivot)
            i++;

        while(A[j] > pivot)
            j--;

        if(i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    return i;
}
void quickSort(int low, int high)
{
    if(low >= high)
        return;

    int p = Partition(low, high);

    quickSort(low, p - 1);
    quickSort(p, high);
}**/
int main()
{
    int n,x;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        cin>>x;
        A.push_back(x);
    }
    quickSort(0, n-1);
    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<< " ";
    }
}


