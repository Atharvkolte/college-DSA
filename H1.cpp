#include<iostream>
using namespace std;
#define MAX 5

class HashTable{
    private:
        int Hasharr[MAX];

    public:
        HashTable(){
            for(int i=0;i<MAX;i++){
                Hasharr[i]=-1;
            }
        }
        
        void insert(int val){
            int n=val%MAX;
            if(Hasharr[n]==-1){
                Hasharr[n]=val;
            }
            else{// Linear probing 
                int start=n;
                n=(n+1)%MAX;
                while(n!=start){
                    if(Hasharr[n]==-1){
                        Hasharr[n]=val;
                        return;
                    }
                    n=(n+1)%MAX;
                }
            }
        }
        int search(int val){
            int n=val%MAX;
            if(Hasharr[n]==val){
                return n;
            }
            int start=n;
            n=n+1%MAX;
            while(n!=start){
                if(Hasharr[n]==val){
                    return n;
                }
                n=(n+1)%MAX;
            }
            cout<<"cannot find it"<<endl;
        }
};


int main(){
    HashTable obj;
    obj.insert(17);
    obj.insert(22);
    cout<<obj.search(17);
    cout<<obj.search(22);
    return 0;
}