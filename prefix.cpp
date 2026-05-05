#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
        char data;
        Node *left,*right;
        Node(char val){
            data=val;
            left=right=NULL;
        }
};

class Stack{
    private:
        Node* stk[20];
        int top;
    public:
        Stack(){
            top=-1;
        }      
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top==19;
        }

        void add(Node* val){
            if(isFull()) return;
            stk[++top]=val;
            return;
        }
        Node* pop(){
            if(isEmpty()) return NULL;
            return stk[top--];
        }
};

class ExpressionTree{
    private:
        Node* head;
        string prefix_exp;
    public:
        ExpressionTree(){
            head=NULL;
        }
        void readExpression(){
            cout<<"Enter the prefix expression:";
            cin>>prefix_exp;
        }
        bool isOperand(char t){
            return (t>='a' && t<='z') || (t>='A' && t<='Z');
        }
        bool isOperator(char t){
            return t=='+' || t=='-' || t=='*' || t=='/';
        }
        void generateTree(){
            Stack s;
            Node* p;
            for(int i=prefix_exp.length()-1;i>=0;i--){
                p=new Node(prefix_exp[i]);
                if(isOperand(prefix_exp[i])){
                    s.add(p);
                }
                else if(isOperator(prefix_exp[i])){
                    p->left=s.pop();
                    p->right=s.pop();
                    s.add(p);
                }
            }
            head=s.pop();
        }

        Node* getroot(){
            return head;
        }
        void display(Node* t){
            if(!t) return;
            display(t->left);
            cout<<t->data;
            display(t->right);
        }

        void postorder(Node* t){
            Stack s1,s2;
            s1.add(t);
            while(!s1.isEmpty()){
                t=s1.pop();
                s2.add(t);

                if(t->left) s1.add(t->left);
                if(t->right) s1.add(t->right);
            }
            while(!s2.isEmpty()){
                t=s2.pop();
                cout<<t->data;
            }
        }
};


int main(){
    ExpressionTree obj;
    obj.readExpression();
    obj.generateTree();
    obj.display(obj.getroot());
    cout<<endl;
    obj.postorder(obj.getroot());
    return 0;
}