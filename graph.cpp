#include<iostream>
#include<vector>
using namespace std;

class Graph{
	private:
		int size;
		vector<vector<int>> matrix;
	public:
		Graph(int n){
			size=n;
			matrix=vector<vector<int> >(n, vector<int>(n,0));
		}
		void add_edge(int n,int m){
			matrix[n][m]=1;
		}
		void display(){
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<matrix[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};


int main(){
	Graph g(4);
	g.add_edge(0,0);
	g.add_edge(1,1);
	g.add_edge(2,2);
	g.add_edge(3,3);
	g.display();
}
