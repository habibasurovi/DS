#include <bits/stdc++.h>
using namespace std;

int Partition(vector<int>& A, int low, int high)
{
    int pivot = A[high];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (A[i] < pivot && i <= high - 1)
        {
            i++;
        }

        while (A[j] >= pivot && j >= low + 1)
        {

            j--;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    }

    swap(A[high], A[i]);

    return i;
}

void Quick_Sort(vector<int>& A, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(A, low, high);

        Quick_Sort(A, low, pi - 1);
        Quick_Sort(A, pi + 1, high);
    }
}

int main()
{
    vector<int> A = {50, 23, 9, 18, 61, 3};

    Quick_Sort(A, 0, A.size() - 1);

    for (int x : A)
    {
        cout << x << " ";
    }

    return 0;
}
