#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
struct Employee{
    int code;
    string name;
};
int seq_search_by_code(Employee arr[],int sz,int code){
    for(int i=0;i<sz;i++)
        if(arr[i].code==code)
            return i;
    return -1;
}
int seq_search_by_name(Employee arr[],int sz,string name){
    for(int i=0;i<sz;i++)
        if(arr[i].name==name)
            return i;
    return -1;
}
int main(){
    Employee *arr;
    int n,code,idx,op;
    string name;
    cout<<"Enter number of Employees : ";
    cin>>n;
    arr=new Employee[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].code>>arr[i].name;
    cout<<"Enter 1 to search by code or 2 to search by name : ";
    cin>>op;
    switch(op){
        case 1:
            cout<<"Enter code of employee you wanna search for : ";
            cin>>code;
            idx=seq_search_by_code(arr,n,code);
            (~idx)?cout<<"Employee found in index : "<<idx<<endl:cout<<"Employee not found!\n";
            break;
        case 2:
            cout<<"Enter name of employee you wanna search for : ";
            cin>>name;
            idx=seq_search_by_name(arr,n,name);
            (~idx)?cout<<"Employee found in index : "<<idx<<endl:cout<<"Employee not found!\n";
            break;
        default:
            cout<<"invalid option\n";
    }
    delete[] arr;
    getche();
    return 0;
}
