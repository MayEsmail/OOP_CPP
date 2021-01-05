#include <bits/stdc++.h>
using namespace std;
int binarySearch(string arr[],int sz,string elem){
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
    int n,idx;
    string *arr;
    string str;
    cout<<"Enter number of strings in the array : ";
    cin>>n;
    arr=new string[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cout<<"Enter the element you wanna search for : ";
    cin>>str;
    idx=binarySearch(arr,n,str);
    (~idx)?cout<<"Element found in index : "<<idx:cout<<"Element not found !";
    delete[] arr;
    return 0;
}
