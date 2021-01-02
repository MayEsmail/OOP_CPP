#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int sz,int elem){
    int lo=0,hi=sz-1,mid;
    while(hi>=lo){
        mid=(lo+hi)/2;
        if(arr[mid]==elem)
            return mid;
        else if(arr[mid]>elem)
            hi=mid-1;
        else
            lo=mid+1;
    }
    return -1;
}
int main(){
    int n,val,idx,*arr;
    cout<<"Enter number of elements of the array : ";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cout<<"Enter the element you wanna search for : ";
    cin>>val;
    idx=binarySearch(arr,n,val);
    (~idx)?cout<<"Element found in index : "<<idx:cout<<"Element not found !";
    delete[] arr;
    return 0;
}
