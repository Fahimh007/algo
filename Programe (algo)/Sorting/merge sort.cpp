#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s+e)/2;
    int len1 = mid-s + 1;
    int len2 = e-mid;
    //make 2 dynamic array(temp array)//
    int *first = new int[len1];
    int *second = new int[len2];
    //int first[len1];
    //int second[len2];

    int mainArrIndex = s;
    for(int i=0; i<len1; i++)
    {
        first[i] = arr[mainArrIndex++];
    }

    mainArrIndex = mid+1;//2nd array starting at (mid+1)//
    for(int i=0; i<len2; i++)
    {
        second[i] = arr[mainArrIndex++];
    }

    int index1 =  0;
    int index2 =  0;
    mainArrIndex = s;
    //merge 2 sorted array
    while(index1 < len1 && index2 < len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrIndex++] = second[index2++];
        }
    }

    while(index1<len1)
    {
        arr[mainArrIndex++] = first[index1++];
    }

    while(index2<len2)
    {
        arr[mainArrIndex++] = second[index2++];
    }
    //delete both dynamic array, for making free the memory.
    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e)
{
    if(s>=e) return;//base case
    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr,s,e);
}

int main()
{
    int arr[6] = {2,5,1,8,7,-1};
    int n = 6;

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
