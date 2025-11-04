#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
        int prn;
        string name;
        string memberType;
        Student *next;
};

class rgenClub{
    private:
        Student* headSYA;
        Student* headSYB;
        Student* headSY;
    public:
        rgenClub(){
            headSYA=NULL;
            headSYB=NULL;
            headSY=NULL;
        }
        void addNodeSYA(int prn,string name,string memberType){
            Student* p=new Student();
            p->prn=prn;
            p->name=name;
            p->memberType=memberType;
            p->next=NULL;
            if(headSYA==NULL){
                headSYA=p;
                return;
            }
            if(memberType=="Regular"){
                Student* curr;
                curr=headSYA;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=p;
                return;
            }
            if(memberType=="President"){
                p->next=headSYA;
                headSYA=p;
            }
            if(memberType=="Screatry"){
                Student* curr;
                Student* prev;
                curr=headSYA;
                while(curr != NULL && curr->memberType=="President"){
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=p;
                p->next=curr;
            }
        }
        void deleteNodeSYA(int prn){
            if(headSYA==NULL){
                cout<<"There no one to delete"<<endl;
            }
            Student* curr;
            Student* prev;
            prev=NULL;
            curr=headSYA;
            if(curr->prn==prn){
                headSYA=curr->next;
                delete curr;
                return;
            }
            while(curr!=NULL){
                if(curr->prn==prn){
                    prev->next=curr->next;
                    delete curr;
                    return;
                }
                prev=curr;
                curr=curr->next;
            }
            cout<<"Node not found it's not in list "<<prn<<endl;
            
        }
        void addNodeSYB(int prn,string name,string memberType){
            Student* p=new Student();
            p->prn=prn;
            p->name=name;
            p->memberType=memberType;
            p->next=NULL;
            if(headSYB==NULL){
                headSYB=p;
                return;
            }
            if(memberType=="Regular"){
                Student* curr;
                curr=headSYB;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=p;
                return;
            }
            if(memberType=="President"){
                p->next=headSYB;
                headSYB=p;
            }
            if(memberType=="Screatry"){
                Student* curr;
                Student* prev;
                curr=headSYB;
                while(curr != NULL &&curr->memberType=="President"){
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=p;
                p->next=curr;
            }
        }
        void deleteNodeSYB(int prn){
            if(headSYB==NULL){
                cout<<"There no one to delete"<<endl;
            }
            Student* curr;
            Student* prev;
            prev=NULL;
            curr=headSYB;
            if(curr->prn==prn){
                headSYB=curr->next;
                delete curr;
                return;
            }
            while(curr!=NULL){
                if(curr->prn==prn){
                    prev->next=curr->next;
                    delete curr;
                    return;
                }
                prev=curr;
                curr=curr->next;
            }
            cout<<"Node not found it's not in list "<<prn<<endl;
            
        }
        void mergeAB(){
            Student* curr;
            if(headSYA==NULL && headSYB==NULL){
                cout<<"the list is empty";    
            }
            else if(headSYA!=NULL && headSYB==NULL){
                headSY=headSYA;
            }
            else if(headSYA==NULL && headSYB!=NULL){
                headSY=headSYB;
            }
            else{
                headSY=headSYA;
                curr=headSY;
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                curr->next=headSYB;
            }
        }
        void displaySYA(){
            Student* curr;
            curr=headSYA;
            while(curr!=NULL){
                cout<<"["<<curr->name<<"|"<<curr->prn<<"|"<<curr->memberType<<"]->";
                curr=curr->next;
            }
            cout<<"NULL"<<endl;
        }
        void displaySYB(){
            Student* curr;
            curr=headSYB;
            while(curr!=NULL){
                cout<<"["<<curr->name<<"|"<<curr->prn<<"|"<<curr->memberType<<"]->";
                curr=curr->next;
            }
            cout<<"NULL"<<endl;
        }
        void displaySY(){
            Student* curr;
            curr=headSY;
            while(curr!=NULL){
                cout<<"["<<curr->name<<"|"<<curr->prn<<"|"<<curr->memberType<<"]->";
                curr=curr->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    rgenClub obj;
    obj.addNodeSYA(1,"AK","Regular");
    obj.addNodeSYA(2,"AaK","Regular");
    obj.addNodeSYA(3,"AaaK","President");
    obj.addNodeSYA(4,"AaaaK","Screatry");
    obj.deleteNodeSYA(2);
    obj.displaySYA();
    obj.addNodeSYB(1,"HD","Regular");
    obj.addNodeSYB(2,"HHD","Regular");
    obj.addNodeSYB(3,"HHHD","President");
    obj.addNodeSYB(4,"HHHHD","Screatry");
    obj.displaySYB();
    obj.mergeAB();
    obj.displaySY();
    return 0;
}
