#include <bits/stdc++.h>
using namespace std;
struct Employee{
    int code;
    string name;
};
void myswap(Employee &a,Employee &b){
    Employee tmp;
    tmp=a;
    a=b;
    b=tmp;
}
void sort_by_code(Employee *arr,int sz){
    int mn_idx=0;
    for(int i=0;i<sz-1;i++,mn_idx=i){
        for(int j=i+1;j<sz;j++)
            if(arr[mn_idx].code>arr[j].code)
                mn_idx=j;
        myswap(arr[i],arr[mn_idx]);
    }
}
void sort_by_name(Employee *arr,int sz){
    bool sorted=0;
    int i=0,j=0;
    while(!sorted){
        sorted=1;
        for(i=0;i<sz-j;i++){
            if(arr[i].name>arr[i+1].name){
                myswap(arr[i],arr[i+1]);
                sorted=0;
            }
        }
        j++;
    }
}
int main(){
    int n,op;
    cout<<"Enter number of Employees : ";
    cin>>n;
    Employee *arr=new Employee[n];
    cout<<"Enter employees data\n";
    for(int i=0;i<n;i++)
        cin>>arr[i].code>>arr[i].name;
    cout<<"Enter 1 to sort by code or 2 to sort by name : ";
    cin>>op;
    if(op==1)
        sort_by_code(arr,n);
    else if(op==2)
        sort_by_name(arr,n);
    cout<<"Employees data after sorting\n";
    for(int i=0;i<n;i++)
        cout<<arr[i].code<<" "<<arr[i].name<<endl;
    delete[]arr;
    return 0;
}
