#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,val,idx=-1,*arr;
    cout<<"Enter number of element of the array : ";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the element you wanna search for : ";
    cin>>val;
    ///search
    for(int i=0;i<n;i++)
        if(arr[i]==val){
            idx=i;
            break;
        }
    (~idx)?cout<<"Element found in index : "<<idx:cout<<"Element not found !";
    delete[] arr;
    return 0;
}
