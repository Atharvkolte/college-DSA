#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data=val;
            left=right=NULL;
        }
};

class AVL{
    private:
        Node* head;
    public:
        AVL(){
            head=NULL;
        }
        Node* getroot(){
            return head;
        }

        int height(Node* t){
            if(!t) return 0;
            int l=height(t->left);
            int r=height(t->right);
            return 1+(l>r?l:r);
        }

        int difference(Node* t){
            return height(t->left)-height(t->right);
        }

        Node* LLrotation(Node* t){
            Node* lefttree=t->left;
            t->left=lefttree->right;
            lefttree->right=t;
            return lefttree;   
        }

        Node* RRrotation(Node* t){
            Node* righttree=t->right;
            t->right=righttree->left;
            righttree->left=t;
            return righttree;
        }
        
        Node* LRrotation(Node* t){
            t=RRrotation(t->left);
            return LLrotation(t);
        }

        Node* RLrotation(Node* t){
            t=LLrotation(t->right);
            return RRrotation(t);
        }

        Node* balance(Node* t){
            int balfactor=difference(t);
            if(balfactor>1){
                if(difference(t->left)>0){
                    t=LLrotation(t);
                    return t;
                }
                else{
                    t=LRrotation(t);
                }
            }
            else if(balfactor<-1){
                if(difference(t->right)<0){
                    t=RRrotation(t);
                }
                else{
                    t=RLrotation(t);
                }
            }
            return t;
        }

        Node* insert(Node* t,int val){
            if(t==NULL){
                t=new Node(val);
                head=t;
                return t;
            }
            if(t->data>val){
                t->left=insert(t->left,val);
                t=balance(t);
            }
            else{
                t->right=insert(t->right,val);
                t=balance(t);
            }
            head=t;
            return t;
        }

        void display(Node* t){
            if(!t) return;
            cout<<t->data<<" ";
            display(t->left);
            display(t->right);
        }

};

int main(){
    AVL obj;
    obj.insert(obj.getroot(),10);
    obj.insert(obj.getroot(),20);
    obj.insert(obj.getroot(),15);
    obj.display(obj.getroot());
    return 0;
}
