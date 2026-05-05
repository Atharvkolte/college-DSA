#include<iostream>
#include<string>
#define max 5
using namespace std;

typedef struct telephoneDirectory{
    long int telephoneNo;
    string name;
}teledir;

class TeleHashing{
    private:
        teledir lp[max];
        teledir qp[max];
    
    public:
        TeleHashing(){
            for(int i=0;i<max;i++){
                lp[i].telephoneNo=-1;
                qp[i].telephoneNo=-1;
                lp[i].name="xyz";
                qp[i].name="xyz";
            }
        }
        void insertDatalP(long int number,string name){
            int hi,i;
            hi=number%max;
            if(lp[hi].telephoneNo==-1){
                lp[hi].telephoneNo=number;
                lp[hi].name=name;
                return;
            }
            else{
                i=(hi+1)%max;
                while(i!=hi){
                    if(lp[i].telephoneNo==-1){
                        lp[i].telephoneNo=number;
                        lp[i].name=name;
                        return;
                    }
                    i=(i+1)%max;
                }
                if(i==hi){
                    cout<<"Kuch nahi ho sakta ab"<<endl;
                    return;
                }
            }
        }
        void displaylp(){
            cout<<"name\ttelephoneNo."<<endl;
            for(int i=0;i<max;i++){
                cout<<lp[i].name<<"\t"<<lp[i].telephoneNo<<endl;
            }
        }
        void displayqp(){
            cout<<"name\ttelephoneNo."<<endl;
            for(int i=0;i<max;i++){
                cout<<qp[i].name<<"\t"<<qp[i].telephoneNo<<endl;
            }
        }
        
        void insertDataqP(long int number,string name){
            int hi,i;
            i=1;
            hi=(number+i*i)%max;
            if(qp[hi].telephoneNo==-1){
                qp[hi].telephoneNo=number;
                qp[hi].name=name;
                return;
            }
            else{
                for(int j=1;j<max;j++){
                    hi=(number+i*i)%max;
                    if(qp[hi].telephoneNo==-1){
                        qp[hi].telephoneNo=number;
                        qp[hi].name=name;
                        return;
                    }
                    i++;
                }
                cout<<"nahi milla"<<endl;
            }
        }
};



int main(){
    TeleHashing obj;
    obj.insertDataqP(123,"atharva");
    obj.insertDataqP(231,"mayur");
    obj.displayqp();
    return 0;
}