#include<iostream>
using namespace std;


template<typename T1>
class Node{
    public:
        T1 data;
        Node* next;
        Node* prev;
    
        Node(T1 val){
            data=val;
            next=NULL;
            prev=NULL;
        }
};

template<typename T2>
class STK{
    private:
        Node<T2>* head;
        Node<T2>* top;
    
    public:
        STK(){
            head=NULL;
            top=NULL;
        }
        void add(T2 val){
            if(head==NULL){
                head=new Node<T2>(val);
                top=head;
                return;
            }
            Node<T2>* temp=new Node<T2>(val);
            top->next=temp;
            temp->prev=top;
            top=temp;
            return;
        }
        bool isEmpty(){
            return top==NULL;
        }
        T2 pop(){
            if(isEmpty()){
                throw runtime_error("Stack is empty");
            }
            Node<T2>* temp=top;
            T2 val=temp->data;
            top=temp->prev;

            if(top==NULL) head=NULL;
            else top->next=NULL;

            delete temp;
            return val;
        }
        void display(){
            Node<T2>* cur=head;
            while(cur!=NULL){
                cout<<cur->data<<"->";
                cur=cur->next;
            }
            cout<<endl;
        }
};


int main(){
    STK<int> obj;
    obj.add(10);
    obj.add(20);
    obj.add(30);
    obj.add(40);
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    cout<<obj.pop()<<endl;
    obj.display();
    return 0;
}
