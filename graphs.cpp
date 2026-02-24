#include<iostream>
#include<ios>
#include<limits>
#include<cstring>
#include<vector>
#define MAX 20
using namespace std;

class Node{
	public:
	int val;
	Node* next;
	Node(int data){
		val=data;
		next=NULL;
	}
};

class GraphLandmark{
	private:
		int GAM[10][10];
		int n;
		int s,d;
		int visited[10]={0};
		Node* headarr[10];
	public: 
	
		GraphLandmark(){
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < 10; j++){	
					GAM[i][j] = 0;
				}
				headarr[i]=new Node(i);
			}
				
		}
		
		void initGraph(){
			for(int i = 0; i < 10; i++){
				for(int j = 0; j < 10; j++){	
					GAM[i][j] = 0;	
				}
				headarr[i]->val=i;
				headarr[i]->next=NULL;
			}
		}
		
		void createGraph(){
			cout<<"\nEnter number of nodes :: ";
			cin>>n;
			int flag = true;
			while(flag){
				cout<<"\nEnter source node :: ";
				cin>>s;
				cout<<"\nEnter destination node :: ";
				cin>>d;
				GAM[s][d]=1;

				Node *cur,*p;
				p=new Node(d);
				
				if(headarr[s]->next==NULL){
					headarr[s]->next=p;
				}
				else{
					cur=headarr[s]->next;
					while(cur->next!=NULL) cur=cur->next;
					cur->next=p;
				}
				cout<<"\nDo you have node  (yes-1/no-0):: ";
				cin>>flag;
			}
		}
		void displayAM(){
			cout<<"\nGraph Adjancee Matrix\n";
			for(int i = 1; i <= n; i++){
				cout<<"   "<<i;
			}
			
			for(int i = 1; i <= n; i++){
				cout<<"\n"<<i<<" ";
				for(int j = 1; j <= n; j++){	
					cout<<GAM[i][j];
				}
			}
		}
		void displayGAM() {
			cout<<"\nGraph Adjacency Matrix:\n\n";
			cout<<"  ";
			for(int i=1;i<=n;i++){
				cout<<i<<" ";
			}
			cout<<"\n";
			cout<<"  ";
			for (int i=1;i<=n;i++)cout<<"--";
			cout<<"\n";

			for(int i=1;i<=n;i++){
				cout<<i<<"|"; 
				for(int j=1;j<=n;j++){
				    cout<<GAM[i][j]<<" ";
				}
				cout<<"\n";
			}
			
			for(int i=1;i<=n;i++){
				Node* cur=headarr[i];
				while(cur!=NULL){
					cout<<"["<<cur->val<<"]->";
					cur=cur->next;
				}
				cout<<endl;
			}
		}	
		void DFS(int v){
			visited[v]=1;
			cout<<v<<"->";
			for(int w=1;w<=n;w++){
				if(GAM[v][w]==1 && visited[w]==0){
					DFS(w);
				}
			}
		}
};
int main(){
    GraphLandmark G;
	int choice=0,s;
	while(choice!=6){
		cout<<"\n***********BST***********";
		cout<<"\n1. Create Graph .";
		cout<<"\n2. Display Graph Adjancee Matrix.";
		cout<<"\n3. Display Graph Adjancee List..";
		cout<<"\n4. Traverse BSF.";
		cout<<"\n5. Traverse DFS.";
		cout<<"\n6. Exit";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"\nWhat operation you want :: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				G.initGraph();
				G.createGraph();
				break;
			case 2:
				G.displayGAM();
				break;
				
			case 3:
				
				break;
				
			case 4:
				cout<<"\nWhat is starting node:";
				cin>>s;
				cout<<"\nThe DFS traversal is\n";
				G.DFS(s);
				break;
			case 5:
				
				break;
				
			case 6:
				cout<<"\nThanks for using BST."<<endl;
				break;
				
			default:
				cout<<"Wrong Choice!!";
		}
	}
	
	return 0;
	
}
