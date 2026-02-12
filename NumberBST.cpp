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

class STK
{
private:
    int top;
    Node *arr[MAX];

public:
    STK()
    {
        top = -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
    bool isempty()
    {
        return top == -1;
    }
    void append(Node *val)
    {
        if (isFull())
        {
            cout << "stack is full" << endl;
            return;
        }
        arr[++top] = val;
        return;
    }
    Node *pop()
    {
        if (isempty())
        {
            cout << "Stack is empty" << endl;
            return NULL;
        }
        return arr[top--];
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

    void dipslay(Node *t)
    { // recursive
        if (t == NULL)
            return;
        cout << t->data << " ";
        dipslay(t->LC);
        dipslay(t->RC);
        
    }

    void print(Node *t)
    { // non recursive
        STK obj;
        int finish = 0;
        do
        {
            while (t != NULL)
            {
                obj.append(t);
                t = t->LC;
            }
            if (!(obj.isempty()))
            {
                t = obj.pop();
                cout << t->data << " ";
                t = t->RC;
            }
            else
            {
                finish = 1;
            }
        } while (finish != 1);
    }

	void postorder(Node* t){
		STK s1;
		STK s2;
		
		s1.append(t);
		
		while(!s1.isempty()){
			s2.append(t=s1.pop());
			if(t->LC) s1.append(t->LC);
			if(t->RC) s1.append(t->RC);
		}
		while(!s2.isempty()){
			cout<<s2.pop()->data<<" ";
		}
	
	}
	void preorder(Node* t){
		STK s1;
		s1.append(t);
		while(!s1.isempty()){
			t=s1.pop();
			cout<<t->data<<" ";
			if(t->RC)s1.append(t->RC);
			if(t->LC) s1.append(t->LC);
			
		}
	}
	
	void inorder(Node* t){
		STK s1;
		while(t!=NULL || !s1.isempty()){
			while(t!=NULL){
				s1.append(t);
				t=t->LC;
			}
			t=s1.pop();
			cout<<t->data<<" ";
			t=t->RC;
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
    obj.dipslay(obj.getroot());
    cout << endl;
    obj.print(obj.getroot());
    cout << endl;
    obj.delNode(75);
    obj.dipslay(obj.getroot());
    cout << endl;
	obj.postorder(obj.getroot());
    cout << endl;
    obj.preorder(obj.getroot());
    cout << endl;
    obj.inorder(obj.getroot());
    cout << endl;
    return 0;
}
