#include <iostream>
using namespace std;
#define MAX 100


class Node
{
public:
    int data;
    Node *LC;
    Node *RC;
    Node(int val)
    {
        data = val;
        LC = NULL;
        RC = NULL;
    }
};
class Queue{
	private:
		Node* arr[MAX];
		int front;
		int rear;
	public:
		Queue(){
			front=0;
			rear=-1; 
		}
		bool isFull(){
			return rear==MAX-1;
		}
		bool isEmpty(){
			return front==-1;
		}
		void enqueue(Node *val){
			if(front==-1) front++;
			if(isFull()){
				cout<<"Queue is Full"<<endl;
				return;
			}
			arr[++rear]=val;
		}
		Node* dequeue(){
			Node* val;
			if(isEmpty()){
				cout<<"Queue is Empty";
			}
			val=arr[front];
			if(front == rear) front = rear =-1;
			else front++;
			return val;
		}
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        if (root == NULL)
        {
            root = new Node(val);
            return;
        }
        Node *cur;
        Node *p;
        cur = root;
        while (cur != NULL)
        {
            p = cur;
            if (cur->data > val)
                cur = cur->LC;
            else
                cur = cur->RC;
        }
        if (p->data > val)
            p->LC = new Node(val);
        else
            p->RC = new Node(val);
        return;
    }

    Node *seaRCh(int val)
    {
        Node *cur = root;
        while (cur != NULL)
        {
            if (cur->data == val)
                return cur;
            else if (cur->data < val)
                cur = cur->RC;
            else
                cur = cur->LC;
        }
        return NULL;
    }

    Node* leftmost(Node *t){
        while(t->LC!=NULL) t=t->LC;
        return t;
    }

    void delNode(int val)
    {
        Node *cur = root;
        Node *parent = NULL;
        while (cur != NULL && cur->data != val)
        {
            parent = cur;
            if (cur->data < val)
                cur = cur->RC;
            else
                cur = cur->LC;
        }
        if (cur == NULL)
        {
            cout << "not find the val" << endl;
            return;
        }
        if (cur->LC == NULL && cur->RC == NULL)
        {
            if (cur == root)
                root = NULL;
            else if (parent->LC == cur)
                parent->LC = NULL;
            else
                parent->RC = NULL;
            delete cur;
            return;
        }
        if (cur->LC == NULL && cur->RC != NULL)
        {
            if (cur == root)
                root = cur->RC;
            else if (parent->LC == cur)
                parent->LC = cur->RC;
            else
                parent->RC = cur->RC;
            delete cur;
            return;
        }
        if (cur->RC == NULL && cur->LC != NULL)
        {
            if (cur == root)
                root = cur->LC;
            else if (parent->LC == cur)
                parent->LC = cur->LC;
            else
                parent->RC = cur->LC;
            delete cur;
            return;
        }
        if (cur->RC != NULL && cur->LC != NULL){
            Node* replace=leftmost(cur->RC);
            int temp=replace->data;
            delNode(replace->data);
            cur->data=temp;
        }
    }

    void BFS(Node* t){
    	Queue obj;
    	obj.enqueue(t);
    	while(!obj.isEmpty()){
    		t=obj.dequeue();
    		cout<<t->data<<" ";
    		if(t->LC!=NULL) obj.enqueue(t->LC);
    		if(t->RC!=NULL) obj.enqueue(t->RC);
    	}
    }

    Node *getroot()
    {
        return root;
    }
};

int main()
{
    BST obj;
    obj.insert(50);
    obj.insert(25);
    obj.insert(100);
    obj.insert(20);
    obj.insert(30);
    obj.insert(70);
    obj.insert(110);
    obj.insert(23);
    obj.insert(75);
    obj.insert(105);
	obj.BFS(obj.getroot());
	cout<<endl;
    return 0;
}
