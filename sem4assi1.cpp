#include<iostream>
using namespace std;


typedef struct Node{
    struct Node* LC;
    string word;
    string meaning;
    struct Node* RC;
    
}NODE;


class BST{
    private:
        NODE *root;
    
    public:
        BST(){
            root=NULL;
        }
        void addNode(string word ,string meaning){
            NODE *p=new NODE;
            p->LC=NULL;
            p->word=word;
            p->meaning=meaning;
            p->RC=NULL;
            if(root==NULL){
                root=p;
                return;
            }else{
                NODE *cur,*f;
                cur=root;
                while(cur){
                    f=cur;
                    if(word==cur->word){
                        cout<<"word Repeated!!!"<<endl;
                        return;
                    }
                    else if(word>cur->word)
                        cur=cur->RC;
                    else 
                        cur=cur->LC;
                }
                if(word>f->word)
                    f->RC=p;
                else
                    f->LC=p;
            }
        }
        void deleteNode(){}
        void updateNode(){}
        void display(){}
        void searchNode(){}
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
