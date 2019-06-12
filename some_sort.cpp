#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n;j++)
            if(a[j] < a[i])
                swap(a[i],a[j]);
}

void insertion_sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j > 0 && a[i] < a[j-1]) j--;

        int temp = a[i];
        for(int k = i; k > j; k--)
            a[k] = a[k-1];
        a[j] = temp;
    }
}

void selection_sort(int a[], int n)
{
    int min_idx, i, j;
    for(i = 0; i < n-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < n; j++)
            if(a[j] < a[min_idx])
                min_idx = j;
        swap(a[i], a[min_idx]);
    }
}

void quick_sort(int a[], int left, int right)
{
    int i = left, j = right;
    int pivot = a[left + rand() % (right - left)];

    while(i <= j) 
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;

        if(i <= j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }

        if(left < j) quick_sort(a, left, j);
        if(i < right) quick_sort(a, i, right);
    }
}

int binary_search(int a[], int l, int r, int x)
{
    if(r >= 1)
    {
        int mid = l + (r-1)/2;

        if(a[mid] == x)
            return mid;
        if(a[mid] > x)
            return binary_search(a,1,mid-1,x);
        return binary_search(a,mid+1,r,x);
    }

    return -1;
}

void print_array(int a[], int n)
{
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout << endl;
}
// 3 34 35 45 100
int main()
{
    //int a[] = {34,45,35,3,100};
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]);
    print_array(a, n);
    bubble_sort(a,n);
    print_array(a,n);
    cout<<binary_search(a,0,n-1,64);
}
