#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct student{
    char div; 
    string name;
    int roll;
    string address;
};

class StudentData{
    private:
        student obj;

    public:
        void getData();
        void insertData();
        void readData();
        void deleteData(string);
        void updateData(string);
};

void StudentData::getData(){
    cout<<"enter the Name:";
    cin>>obj.name;
    cout<<"Enter the rollNo.:";
    cin>>obj.roll;
    cout<<"Enter the division:";
    cin>>obj.div;
    cout<<"Enter the address:";
    cin>>obj.address;
}

void StudentData::insertData(){
    fstream out;
    out.open("employee1.txt",ios::app | ios::binary);
    getData();
    out.write((char*)&obj,sizeof(obj));
    out.close();
}

void StudentData::readData(){
    fstream in;
    in.open("employee1.txt",ios::in | ios::binary);
    while(in.read((char*)&obj,sizeof(obj))){
        cout<<obj.name<<setw(15)<<obj.div<<setw(15)<<obj.roll<<setw(15)<<obj.address<<endl;
    }
    in.close();
}
void StudentData::deleteData(string name){
    fstream in;
    in.open("employee1.txt",ios::in | ios::binary);
    fstream out;
    out.open("temp.txt",ios::out | ios::binary);

    while(in.read((char*)&obj,sizeof(obj))){
        if(obj.name!=name)
            out.write((char*)&obj,sizeof(obj));
    }

    in.close();
    out.close();
    remove("employee1.txt");
    rename("temp.txt","employee1.txt");
}
void StudentData::updateData(string name){
    fstream inout;
    inout.open("employee1.txt",ios::in | ios::out | ios::binary);
    int count=0;
    while(inout.read((char*)&obj,sizeof(obj))){
        count++;
        if(obj.name==name){
            cout<<"hi";
            cout<<obj.name<<setw(15)<<obj.div<<setw(15)<<obj.roll<<setw(15)<<obj.address<<endl;
            getData();
            inout.seekp(sizeof(obj)*(count-1),ios::beg);
            inout.write((char*)&obj,sizeof(obj));
        }
    }
    inout.close();
}
int main(){
    StudentData obj;
    obj.insertData();
    obj.insertData();
    obj.readData();
    cout<<endl;
    //obj.deleteData("omkar");
    obj.updateData("omkar");
    return 0;
}