#include <bits/stdc++.h>
using namespace std;
struct Employee{
    int code;
    string name,department;
    bool operator<(Employee e){
        return code<e.code;
    }
    bool operator!=(Employee e){
        return code != e.code;
    }
};
template<typename T>
class Node{
public:
    Node<T> *prev,*next;
    T data;
    Node(){
        prev=next=NULL;
    }
};
template<typename T>
class linkedList{
    Node<T> *head,*tail;
    int sz;
public:
    linkedList(){
        head=tail=NULL;
        sz=0;
    }
    Node<T>* Seach(T key);
    void Append(T data);
    void Insert(T data);
    bool Delete(T key);
    void Freelist();
    int getSize();
    bool isEmpty();
    T get_first();
    T get_last();
    T peek_first();
    T peek_last();
};
template<typename T>
Node<T>* linkedList<T>::Seach(T key){
    Node<T> *cur=head;
    while(cur&&cur->data!=key)
        cur=cur->next;
    return cur;
}
template<typename T>
void linkedList<T>::Append(T data){
    Node<T> *elem=new Node<T>();
    elem->data=data;
    if(head==NULL){
        head=tail=elem;
    }
    else{
        elem->prev=tail;
        tail->next=elem;
        tail=elem;
    }
    sz++;
}
template<typename T>
void linkedList<T>::Insert(T data){
    Node<T> *cur=head;
    Node<T> *elem=new Node<T>();
    elem->data=data;
    while(cur&&cur->data<elem->data){
        cur=cur->next;
    }
    if(cur==NULL)
        return Append(data),void();
    else if(cur==head){
        elem->next=head;
        head->prev=elem;
        head=elem;
    }
    else{
        elem->prev=cur->prev;
        cur->prev->next=elem;
        elem->next=cur;
        cur->prev=elem;
    }
    sz++;
}
template<typename T>
bool linkedList<T>::Delete(T key){
    Node<T> *cur=Seach(key);
    if(!cur)
        return 0;
    if(head==cur&&tail==cur)
        head=tail=NULL;
    else if(head==cur){
        head=head->next;
        head->prev=NULL;
    }
    else if(tail==cur){
        tail=tail->prev;
        tail->next=NULL;
    }
    else{
        cur->next->prev=cur->prev;
        cur->prev->next=cur->next;
    }
    delete cur;
    sz--;
    return 1;
}
template<typename T>
void linkedList<T>::Freelist(){
    Node<T> *cur=head;
    while(cur){
        head=head->next;
        delete cur;
        cur=head;
    }
    tail=NULL;
    sz=0;
}
template<typename T>
int linkedList<T>::getSize(){
    return sz;
}
template<typename T>
bool linkedList<T>::isEmpty(){
    return sz==0;
}
template<typename T>
T linkedList<T>::get_first(){
    if(isEmpty())
    return {NULL};
    Node<T> *cur=head;
    head=head->next;
    if(head)head->prev=NULL;
    else tail=NULL;
    T ret=cur->data;
    sz--;
    delete cur;
    return ret;
}
template<typename T>
T linkedList<T>::peek_first(){
    if(isEmpty())
        return {NULL};
    return head->data;
}
template<typename T>
T linkedList<T>::get_last(){
    if(isEmpty())
        return {NULL};
    Node<T> *cur=tail;
    tail=tail->prev;
    if(tail)tail->next=NULL;
    else head=NULL;
    T ret=cur->data;
    sz--;
    delete cur;
    return ret;
}
template<typename T>
T linkedList<T>::peek_last(){
    if(isEmpty())
        return {NULL};
    return tail->data;
}
void options(){
    cout<<"********************************************************************************\nNotes about input form:\nEnter operation number(mandatory) then data(if needed) :\n"<<
    "1-to Append Enter 1 then data\n2-to Insert enter 2 then data\n3-to Search enter 3 then key you wanna search for\n4-to Delete enter 4 then the key to be deleted\n5-enter 5 to free the list\n6-enter 6 to get size of the list\n7-enter 7 to know if the list is Empty?\n8-enter 8 to pop and get the first element in the list\n9-enter 9 to pop and get the last element in the list\n10-enter 10 to peek the first element in the list\n11-enter 11 to peek the last element in the list\n12-enter 12 to Exit\n"
    <<"********************************************************************************\n";
}
int main(){
    int type,op;
    bool exit=0;
    cout<<"Enter 1 for integers list, 2 for strings list or 3 for employee list : ";
    cin>>type;
    switch(type){
        case 1:{
            linkedList<int>lst;
            int data;
            options();
            do{
                cin>>op;
                switch(op){
                    case 1:
                        cin>>data;
                        lst.Append(data);
                        break;
                    case 2:
                        cin>>data;
                        lst.Insert(data);
                        break;
                    case 3:
                        cin>>data;
                        (lst.Seach(data)!=NULL)?cout<<"Found\n":cout<<"Not found\n";
                        break;
                    case 4:
                        cin>>data;
                        (lst.Delete(data))?cout<<"deleted!\n":cout<<"No such data in the list\n";
                        break;
                    case 5:
                        lst.Freelist();
                        cout<<"freed\n";
                        break;
                    case 6:
                        cout<<"Size = "<<lst.getSize()<<endl;
                        break;
                    case 7:
                        (lst.isEmpty())?cout<<"list is empty\n":cout<<"list is not empty\n";
                        break;
                    case 8:
                        (!lst.isEmpty())?cout<<"first element was : "<<lst.get_first()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 9:
                        (!lst.isEmpty())?cout<<"last element was : "<<lst.get_last()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 10:
                        (!lst.isEmpty())?cout<<"first element is : "<<lst.peek_first()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 11:
                        (!lst.isEmpty())?cout<<"last element is : "<<lst.peek_last()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 12:
                        exit=1;
                        break;
                    default:
                        cout<<"invalid option!\n";
                        break;
                }
            }while(!exit);
            }break;
        case 2:
            {
            linkedList<string>lst;
            string data;
            options();
            do{
                cin>>op;
                switch(op){
                    case 1:
                        cin>>data;
                        lst.Append(data);
                        break;
                    case 2:
                        cin>>data;
                        lst.Insert(data);
                        break;
                    case 3:
                        cin>>data;
                        (lst.Seach(data)!=NULL)?cout<<"Found\n":cout<<"Not found\n";
                        break;
                    case 4:
                        cin>>data;
                        (lst.Delete(data))?cout<<"deleted!\n":cout<<"No such data in the list\n";
                        break;
                    case 5:
                        lst.Freelist();
                        cout<<"freed\n";
                        break;
                    case 6:
                        cout<<"Size = "<<lst.getSize()<<endl;
                        break;
                    case 7:
                        (lst.isEmpty())?cout<<"list is empty\n":cout<<"list is not empty\n";
                        break;
                    case 8:
                        (!lst.isEmpty())?cout<<"first element was : "<<lst.get_first()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 9:
                        (!lst.isEmpty())?cout<<"last element was : "<<lst.get_last()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 10:
                        (!lst.isEmpty())?cout<<"first element is : "<<lst.peek_first()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 11:
                        (!lst.isEmpty())?cout<<"last element is : "<<lst.peek_last()<<endl:cout<<"No elements in the list"<<endl;
                        break;
                    case 12:
                        exit=1;
                        break;
                    default:
                        cout<<"invalid option!\n";
                        break;
                }
            }while(!exit);
            }break;
        case 3:{
            linkedList<Employee>lst;
            Employee data;
            Node<Employee>*dataptr;
            options();
            cout<<"enter append & insert data as code, name and department in order but to search or delete just enter the code\n";
            do{
                cin>>op;
                switch(op){
                    case 1:
                        cin>>data.code>>data.name>>data.department;
                        lst.Append(data);
                        break;
                    case 2:
                        cin>>data.code>>data.name>>data.department;
                        lst.Insert(data);
                        break;
                    case 3:
                        cin>>data.code;
                        ((dataptr=lst.Seach(data))!=NULL)?cout<<"Found\t name : "<<dataptr->data.name<<", department :"<<dataptr->data.department<<endl:cout<<"Not found\n";
                        break;
                    case 4:
                        cin>>data.code;
                        (lst.Delete(data))?cout<<"deleted!\n":cout<<"No such data in the list\n";
                        break;
                    case 5:
                        lst.Freelist();
                        cout<<"freed\n";
                        break;
                    case 6:
                        cout<<"Size = "<<lst.getSize()<<endl;
                        break;
                    case 7:
                        (lst.isEmpty())?cout<<"list is empty\n":cout<<"list is not empty\n";
                        break;
                    case 8:
                        if(!lst.isEmpty()){
                            data=lst.get_first();
                            cout<<data.code<<" "<<data.name<<" "<<data.department<<"\t (popped!)"<<endl;
                        }
                        else
                            cout<<"No Employees in the list"<<endl;
                        break;
                    case 9:
                        if(!lst.isEmpty()){
                            data=lst.get_last();
                            cout<<data.code<<" "<<data.name<<" "<<data.department<<"\t (popped!)"<<endl;
                        }
                        else
                            cout<<"No Employees in the list"<<endl;
                        break;
                    case 10:
                        if(!lst.isEmpty()){
                            data=lst.peek_first();
                            cout<<data.code<<" "<<data.name<<" "<<data.department<<endl;
                        }
                        else
                            cout<<"No Employees in the list"<<endl;
                        break;
                    case 11:
                        if(!lst.isEmpty()){
                            data=lst.peek_last();
                            cout<<data.code<<" "<<data.name<<" "<<data.department<<endl;
                        }
                        else
                            cout<<"No Employees in the list"<<endl;
                        break;
                    case 12:
                        exit=1;
                        break;
                    default:
                        cout<<"invalid option!\n";
                        break;
                }
            }while(!exit);
            }break;
        default :
            cout<<"invalid option!\n";
    }
    cout<<"good bye!\n";
    return 0;
}
