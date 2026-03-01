#include<iostream>
using namespace std;

template<typename t1>
class Node{
    public:
        t1 data;
        Node* next;
        Node(t1 val){
            data=val;
            next=NULL;
        }
};

template<typename t2>
class LLQueue{
    private:
        Node<t2>* rear;
        Node<t2>* front;

    public:
        LLQueue(){
            rear=NULL;
            front=NULL;
        }

        void enqueue(t2 val){
            if(front==NULL){
                front=new Node<t2>(val);
                rear=front;
                return;
            }
            rear->next=new Node<t2>(val);
            rear=rear->next;
            return;
        }
        bool isEmpty(){
            return front==NULL;
        }
        t2 dequeue(){
            if(isEmpty()){
                throw runtime_error("Queue is empty");
            }
            Node<t2>* temp=front;
            t2 val=temp->data;
            front=front->next;
            if(front==NULL) rear=NULL;
            delete temp;
            return val;
        }
        void display(){
            Node<t2>* cur;
            cur=front;
            while(cur!=NULL){
                cout<<cur->data<<"->";
                cur=cur->next;
            }
            cout<<endl;
        }
};

int main(){
    LLQueue<int> obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    obj.display();
    return 0;
}    
