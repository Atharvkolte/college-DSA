#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

typedef struct Employee{
	int EID;
	string name;
	string designation;
	float salary;
}EMP;
 	
class SequentialFile{
	private:
		EMP eObj;
	public:
		void readData();
		void displayData();
		void insertRecord();
		void UpdateRecord(string);
		void SearchRecord(string);
		void deleteRecord(string);
		void DisplayRecord();
		
};

void SequentialFile::displayData(){
	cout<<"Enter Employee ID::"<<eObj.EID<<endl;
	cout<<"Enter Employee name::"<<eObj.name<<endl;
	cout<<"Enter Emplpoyee designation::"<<eObj.designation<<endl;
	cout<<"Enter Emplpoyee Salary::"<<eObj.salary<<endl;
}

void SequentialFile::SearchRecord(string name){
	fstream fin;
	fin.open("employee3.txt",ios::in | ios::binary);
	while(fin.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name==name){
			cout<<"Record found"<<endl;
			cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
			return;
		}	
	}
	cout<<"record not found"<<endl;
	fin.close();	
}

void SequentialFile::readData(){
	cout<<"Enter Employee ID::"<<endl;
	cin>>eObj.EID;
	cout<<"Enter Employee name::"<<endl;
	cin>>eObj.name;
	cout<<"Enter Emplpoyee designation::"<<endl;
	cin>>eObj.designation;
	//cin.ignore();
	cout<<"Enter Emplpoyee Salary::"<<endl;
	cin>>eObj.salary;
}

void SequentialFile::insertRecord(){
	fstream fout;
	fout.open("employee3.txt",ios::app | ios::binary);
	readData();
	fout.write((char*)&eObj,sizeof(eObj));
	fout.close();
}

void SequentialFile::DisplayRecord(){
	fstream fin;
	fin.open("employee3.txt",ios::in | ios::binary);
	while(fin.read((char*)&eObj,sizeof(eObj))){
		cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
	}
	fin.close();	
}

void SequentialFile::UpdateRecord(string name){
	fstream finout;
	int count=0;
	finout.open("employee3.txt",ios::in | ios::out | ios::binary);
	while(finout.read((char*)&eObj,sizeof(eObj))){
		count++;
		if(eObj.name==name){
			cout<<"Record found"<<endl;
			cout<<eObj.EID<<setw(15)<<eObj.name<<setw(15)<<eObj.designation<<setw(15)<<eObj.salary<<endl;
			readData();
			finout.seekp((count-1)*sizeof(eObj),ios::beg);
			finout.write((char*)&eObj,sizeof(eObj));
			return;
		}	
	}
	cout<<"record not found"<<endl;
	finout.close();	
}

void SequentialFile::deleteRecord(string name){
	fstream in;
	fstream out;
	out.open("temp.txt",ios::out|ios::binary);
	in.open("employee3.txt",ios::in|ios::binary);
	while(in.read((char*)&eObj,sizeof(eObj))){
		if(eObj.name!=name){
			out.write((char*)&eObj,sizeof(eObj));
		}
	}
	in.close();
	out.close();
	remove("employee3.txt");
	rename("temp.txt","employee3.txt");
}

int main(){
	SequentialFile obj;
	//obj.readData();
	//obj.displayData();
	obj.insertRecord();
	obj.insertRecord();
	obj.insertRecord();
	obj.DisplayRecord();
	string name;
	/*cout<<"which record u need to update enter the name:"<<endl;
	cin>>name;
	obj.UpdateRecord(name);
	obj.DisplayRecord();*/
	cout<<"which record u need to update enter the name:"<<endl;
	cin>>name;
	obj.deleteRecord(name);
	
	obj.DisplayRecord();
	return 0;
}
