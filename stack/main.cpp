#include <bits/stdc++.h>
#include "linked_list.h"
using namespace std;
template<typename T>
class Stack{
    linkedList<T>stk;
    int sz;
public:
    Stack(){sz=0;}
    ~Stack(){stk.Freelist();}
    bool isFull(){
        Node<T> *tmp;
        if(tmp=new Node<T>()){
            delete tmp;
            return 0;
        }
        return 1;
    }
    bool isEmpty(){
        return stk.isEmpty();
    }
    bool push(T data){
        stk.Append(data);
    }
    T pop(){
        return stk.get_last();
    }
    T peek(){
        return stk.peek_last();
    }
    int get_size(){
        return sz;
    }
};
int main(){
    Stack<int>s;
    s.push(5);
    s.push(10);
    s.push(1);
    s.push(20);
    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }
    return 0;
}
