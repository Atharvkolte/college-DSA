#include<iostream>
using namespace std;
#define MAX 5

class HashTable{
    private:
        int Hasharr[MAX];

    public:
        HashTable(){
            for(int i=0;i<MAX;i++){
                Hasharr[i] = -1;
            }
        }
        
        void insert(int val){
            int index = val % MAX;

            if(Hasharr[index] == -1){
                Hasharr[index] = val;
            }
            else{
                int i = 1;
                int newIndex;

                while(i < MAX){
                    newIndex = (index + i*i) % MAX;

                    if(Hasharr[newIndex] == -1){
                        Hasharr[newIndex] = val;
                        return;
                    }
                    i++;
                }

                cout << "Hash table is full\n";
            }
        }

        int search(int val){
            int index = val % MAX;

            if(Hasharr[index] == val){
                return index;
            }

            int i = 1;
            int newIndex;

            while(i < MAX){
                newIndex = (index + i*i) % MAX;

                if(Hasharr[newIndex] == val){
                    return newIndex;
                }
                i++;
            }

            return -1; // Not found
        }

        void display(){
            for(int i=0;i<MAX;i++){
                cout << i << " -> " << Hasharr[i] << endl;
            }
        }
};

int main(){
    HashTable obj;

    obj.insert(17);
    obj.insert(22);
    obj.insert(27); // try more collisions

    obj.display();

    cout << "Index of 17: " << obj.search(17) << endl;
    cout << "Index of 22: " << obj.search(22) << endl;

    return 0;
}