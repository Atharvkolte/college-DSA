#include<iostream>
using namespace std;


class MyVector{
	private:
		int* data;
		int size;
		int capacity;
		
	public:
		MyVector(){
			size=0;
			capacity=1;
			data=new int[capacity];
		}
		
		void push_back(int val){
			if(size==capacity){
				capacity*=2;
				int* newData=new int[capacity];
				for(int i=0;i<size;i++){
					newData[i]=data[i];
				}
				delete[] data;
				data=newData;
			}
			data[size++]=val;
		}
		
		int operator[](int index){
			return data[index];
		}
		int getSize(){
			return size;
		}
		~MyVector(){
			delete[] data;
		}
}; 


int main(){
	cout<<"Hello world"<<endl;
	
	MyVector v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	for(int i=0;i<v.getSize();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
