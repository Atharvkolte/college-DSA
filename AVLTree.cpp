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
		
		Node* add(int value,Node* cur){
			if(cur==NULL){
				cur=new Node(value);
				head=cur;
				return cur;
			}
			if(cur->data<value){
				cur->right=add(value,cur->right);
				cur=balance(cur);
			}
			else{
				cur->left=add(value,cur->left);
				cur=balance(cur);
			}
			head=cur;
			return cur;
		}
		
		int height(Node* cur){
			if(cur==NULL) return 0;
			if(cur->left==NULL && cur->right==NULL) return 0;
			int lh,rh;
			lh=height(cur->left);
			rh=height(cur->right);
			if(lh>rh) return 1+lh;
			else return 1+rh;
		}
		
		int difference(Node* cur){
			int lheight=height(cur->left);
			int rheight=height(cur->right);
			return lheight-rheight;
		}
		
		Node* balance(Node *cur){
			int balFactor=difference(cur);
			if(balFactor>1){
				if(difference(cur->left)>0) cur=LLrotation(cur);
				else cur=LRrotation(cur);
			}
			else if(balFactor<-1){
				if(difference(cur->right)<0) cur=RRrotation(cur);
				else cur=RLrotation(cur);
			}
			return cur;
		}

		
		Node* LLrotation(Node *t){
			Node* leftTree=t->left;
			t->left=leftTree->right;
			leftTree->right=t;
			return leftTree;
		}
		
		Node* RRrotation(Node* t){
			
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
	obj.add(20,obj.getroot());
	obj.add(15,obj.getroot());
	obj.add(25,obj.getroot());
	//for ll
	/*obj.add(12);
	obj.add(18);
	obj.add(10);*/
	// for rr
	/*obj.add(27);
	obj.add(22);
	obj.add(29);*/
	//for lr
	obj.add(12,obj.getroot());
	obj.add(18,obj.getroot());
	obj.add(19,obj.getroot());
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
