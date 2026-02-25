#include<iostream>
using namespace std;
#define MAX 100


class stack{
    private:
        int top;
        int arr[MAX];
    
    public:
        stack(){
            top=-1;
        }
        bool isFull(){
            return top==MAX-1;
        }
        bool isEmpty(){
            return top==-1;
        }
        void append(int data){
            if(isFull()){
                cout<<"Stack is FULL"<<endl;
                return;
            }
            arr[++top]=data;
            return;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            return arr[top--];
        }
};


class Queue{
    private:
        int front,rear;
        int arr[MAX];
    public:
        Queue(){
            front=-1;
            rear=-1;
        }

        bool isFull(){
            return rear==MAX-1;
        }
        bool isEmpty(){
            return front==-1;
        }
        void enqueue(int data){
            if(isFull()){
                cout<<"Queue is Full"<<endl;
                return;
            }
            if(front==-1) front++;
            arr[++rear]=data;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
            int val=arr[front];
            if(front==rear) front=rear=-1;
            else front++;
            return val;
        }
};

class Graph{
    private:
        int n;
        int arr[10][10];
        int visited[10];
    public:
        Graph(){
            for(int i=0;i<=10;i++){
                for(int j=0;j<=10;j++){
                    arr[i][j]=0;
                }
            }
        }

        void initgraph(){
            int s,d;
            int flag=1;
            cout<<"Enter No. of Nodes will be there:";
            cin>>n;
            while(flag){
                cout<<"Enter the source:";
                cin>>s;
                cout<<"Enter the Destination:";
                cin>>d;
                arr[s][d]=1;
                cout<<"Is there more connection(1/0):";
                cin>>flag;
            }
        }
        void showgraph(){
            cout<<"  ";
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
            for(int i=1;i<=n;i++){
                cout<<i<<"|";
                for(int j=1;j<=n;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        void travDFS(){
            for(int i=1;i<=n;i++) visited[i]=0;
            int temp;
            cout<<"Enter the value to start traversal:";
            cin>>temp;
            BFS(temp);
        }
        void DFS(int v){
            visited[v]=1;
            cout<<v<<"->";
            for(int w=1;w<=n;w++){
                if(arr[v][w]==1 && visited[w]==0){
                    DFS(w);
                }
            }
        }
        void nDFS(int v){
            stack obj;
            obj.append(v);
            while(!obj.isEmpty()){
                v=obj.pop(); 
                if(!visited[v]){
                    visited[v]=1;
                    cout<<v<<"->";
                    for(int w=n;w>-1;w--){
                        if(arr[v][w]==1 && visited[w]==0) obj.append(w);
                    }
                }
            }
        }

        void BFS(int v){
            Queue obj;
            obj.enqueue(v);
            while(!obj.isEmpty()){
                v=obj.dequeue();
                if(!visited[v]){
                    visited[v]=1;
                    cout<<v<<" ";
                    for(int w=1;w<=n;w++){
                        if(arr[v][w]==1 && visited[w]==0) obj.enqueue(w);
                    }
                }
            }
        }
};

int main(){
    Graph obj;
    obj.initgraph();
    obj.showgraph();
    obj.travDFS();
    cout<<endl;
    return 0;
}
