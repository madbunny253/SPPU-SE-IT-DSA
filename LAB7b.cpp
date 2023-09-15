#include <iostream>
using namespace std;

class graph
{
	int mat[10][10];
	public:
			int wt, v, e, src, dst;
			void getdata();
			int findmin(int[], bool[]);
			void display(int[]);
			void displayMat();
			void PrimsAlgo();
};

void graph::getdata()
{
	cout<<"\n Enter total no. of vertices: ";
	cin>>v;
	cout<<" Enter total no. of edges: ";
	cin>>e;
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			mat[i][j]=0;
		}
	}
	
	cout<<"\nEnter data related to source, destination, weight of edge.";
	for (int i=0;i<e;i++)
	{
		cout<<"\n Enter source vertex: ";
		cin>>src;
		cout<<" Enter destination vertex: ";
		cin>>dst;
		cout<<" Enter weight of edge: ";
		cin>>wt;
		
		mat[src][dst]=wt;
		mat[dst][src]=wt;
	}
}

int graph::findmin(int key[], bool visited[])
{
	int p;
	int max=999;
	int minIndex=0;
	
	for(p=0;p<v;p++)
	{
		if(visited[p]==false && key[p]<max)
		{
			max=key[p];
			minIndex=p;
		}
	}
	return minIndex;
}

void graph::display(int parent[])
{
	int i;
	cout<<"Min spanning tree: ";
	cout<<"\n";
	cout<<"Edge\t\tWeight\n";
	for(i=0;i<v;i++)
	{
		if(mat[i][parent[i]]!=0)
			cout<<parent[i]<<" -> "<<i<<" \t\t"<<mat[i][parent[i]]<<" \n";
	}
}

void graph::displayMat()
{
	cout<<"\nAdjecency matrix is: "<<"\n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void graph::PrimsAlgo()
{
	int k,m;
	int parent[v];
	int key[v];
	bool visited[v];
	
	for (int i=0;i<v;i++)
	{
		key[i]=999;
		visited[i]=false;
		parent[i]=i;
	}
	
	cout<<"\n";
	cout<<"\n Source vertex for MinST: ";
	cin>>src;
	
	key[src]=0;
	for(k=0;k<v;k++)
	{
		int minVert=findmin(key, visited);
		visited[minVert]=true;
		for(m=0;m<v;m++)
		{
			if(mat[minVert][m]!=0 && visited[m]==false && mat[minVert][m]<key[m])
			 {
			 	parent[m]=minVert;
			 	key[m]=mat[minVert][m];
			 }
		}
	}
	display(parent);
}

int main()
{
	graph g;
	g.getdata();
	g.PrimsAlgo();
	g.displayMat();
	return 0;
}