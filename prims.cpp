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
        int T[10][10];
        int visited[10];
    public:
        Graph(){
            for(int i=0;i<=10;i++){
                for(int j=0;j<=10;j++){
                    arr[i][j]=0;
                    T[i][j]=0;
                }
            }
        }

        void initgraph(){
            int s,d,w;
            int flag=1;
            cout<<"Enter No. of Nodes will be there:";
            cin>>n;
            while(flag){
                cout<<"Enter the source:";
                cin>>s;
                cout<<"Enter the Destination:";
                cin>>d;
                cout<<"Enter the Weight:";
                cin>>w;
                arr[s][d]=w;
                arr[d][s]=w;
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


        int prims(){
            int ne=1,selected[10]={0},i,j,x=0,y=0;
            int min_cost=0;
            selected[1]=1;
            while(ne<n){
                int min=9999;
                for(i=1;i<=n;i++){
                    if(selected[i]==1){
                        for(j=1;j<=n;j++){
                            if(selected[j]==0){
                                if(selected[j] == 0 && arr[i][j] != 0 && arr[i][j] < min){
                                    min=arr[i][j];
                                    x=i;
                                    y=j;
                                }
                            }
                        }
                    }
                }
                min_cost+=min;
                T[x][y]=1;
                selected[y]=1;
                ne++;
            }
            return min_cost;
        }

        void printPrims(int min_cost){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(T[i][j]==1){
                        cout<<i<<"->"<<j<<" ="<<arr[i][j]<<endl;
                    }
                }
            }
            cout<<min_cost<<endl;
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
                        if(arr[v][w]>=1 && visited[w]==0) obj.enqueue(w);
                    }
                }
            }
        }
};

int main(){
    Graph obj;
    obj.initgraph();
    obj.showgraph();
    // obj.travDFS();
    // cout<<endl;
    int xyz=obj.prims();
    obj.printPrims(xyz);

    return 0;
}
