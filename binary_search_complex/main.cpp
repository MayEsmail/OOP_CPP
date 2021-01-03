#include <bits/stdc++.h>
using namespace std;
class Complex{
    float real,imag;
public:
    Complex(int r=0,int i=0){
        real=r;
        imag=i;
    }
    void set_real(int r){
        real=r;
    }
    void set_imag(int i){
        imag=i;
    }
    float get_real(){
        return real;
    }
    float get_imag(){
        return imag;
    }
};
bool cmp(Complex a,Complex b){
    if(a.get_real()<b.get_real())
        return 1;
    else if(a.get_real()>b.get_real())
        return 0;
    else
        return a.get_imag()<=b.get_imag();
}
int binarySearch(Complex arr[],int sz,Complex elem){
    int lo=0,hi=sz-1,mid;
    float r=elem.get_real(),i=elem.get_imag();
    while(hi>=lo){
        mid=(lo+hi)/2;
        if(arr[mid].get_real()==r&&arr[mid].get_imag()==i)
            return mid;
        else if(cmp(elem,arr[mid]))
            hi=mid-1;
        else
            lo=mid+1;
    }
    return -1;
}
int main(){
    Complex val,*arr;
    int n,idx;
    float r,img;
    cout<<"Enter number of elements of the array : ";
    cin>>n;
    arr=new Complex[n];
    cout<<"Enter the Elements\n";
    for(int i=0;i<n;i++){
        cout<<"real : ";
        cin>>r;
        cout<<"imag : ";
        cin>>img;
        arr[i].set_real(r);
        arr[i].set_imag(img);
    }
    sort(arr,arr+n,cmp);
    cout<<"Enter the complex you wanna search for :\nreal : ";
    cin>>r;
    cout<<"imag : ";
    cin>>img;
    val.set_real(r);
    val.set_imag(img);
    idx=binarySearch(arr,n,val);
    (~idx)?cout<<"Element found in index : "<<idx:cout<<"Element not found !";
    delete[] arr;
    return 0;
}
