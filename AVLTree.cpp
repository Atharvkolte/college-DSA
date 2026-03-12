#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int val){
			data=val;
			left=NULL;
			right=NULL;
		}
};

class BST{
	private:
		Node* head;
		
	public:
		BST(){
			head=NULL;
		}
		
		void add(int value){
			if(head==NULL){
				head=new Node(value);
				return;
			}
			Node *cur,*p;
			cur=head;
			while(cur!=NULL){
				p=cur;
				if(cur->data<value) cur=cur->right;
				else cur=cur->left;
			}
			if(p->data<value)p->right=new Node(value);
			else p->left=new Node(value);
		}
		
		Node* LLrotation(Node *t){
			if(head==t){
				Node* leftTree=t->left;
				t->left=leftTree->right;
				leftTree->right=t;
				head=leftTree;
				cout<<"llrotation"<<endl;
				return head;
			}
			Node* leftTree=t->left;
			t->left=leftTree->right;
			leftTree->right=t;
			return leftTree;
		}
		
		Node* RRrotation(Node* t){
			if(head==t){
				Node* rightTree=t->right;
				t->right=rightTree->left;
				rightTree->left=t;
				head=rightTree;
				cout<<"RR rotation"<<endl;
				return head;
			}
			Node* rightTree=t->right;
			t->right=rightTree->left;
			rightTree->left=t;
			return rightTree;
		}
		
		Node* LRrotation(Node* t){
			Node* leftTree=t->left;
			t->left=RRrotation(leftTree);
			return LLrotation(t);
		}
		
		Node* RLrotation(Node* t){
			Node* rightTree=t->right;
			t->right=LLrotation(rightTree);
			return RRrotation(t);
		}
		
		void display(Node* t){
			if(t==NULL){
				return;
			}
			display(t->left);
			cout<<t->data<<" ";
			display(t->right);
		}
	
		Node* getroot(){
			return head;
		}

};


int main(){
	BST obj;
	obj.add(20);
	obj.add(15);
	obj.add(25);
	//for ll
	/*obj.add(12);
	obj.add(18);
	obj.add(10);*/
	// for rr
	/*obj.add(27);
	obj.add(22);
	obj.add(29);*/
	//for lr
	obj.add(12);
	obj.add(18);
	obj.add(19);
	// for rl
	/*obj.add(22);
	obj.add(27);
	obj.add(21);*/
	obj.display(obj.getroot());
	cout<<endl;
	obj.RLrotation(obj.getroot());
	obj.display(obj.getroot());
	cout<<endl;
	return 0;
}
