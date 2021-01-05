#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
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
#endif // LINKED_LIST_H_INCLUDED
