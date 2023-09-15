#include<iostream>
using namespace std;

class graph
{
	int src, dst, wt;
	public:
		void accept();
		void display();
		void sort(graph *[], int);
		int findParent(int, int *);
		graph *kruskal(graph *[], int);
};

void graph::accept()
{
	cout<<"\n Enter source vertex: ";
		cin>>src;
		cout<<" Enter destination vertex: ";
		cin>>dst;
		cout<<" Enter weight of edge: ";
		cin>>wt;
}

void graph::display()
{
	cout<<src<<"\t\t"<<wt<<"\n";
}

void graph::sort(graph *edge[], int n)
{
	int i,j;
	graph *temp=NULL;
	
	for(i=n-1; i>0; i--)
	{
		for(j=0; j<i; j++)
		{
			if(edge[j]->wt > edge[j+1]->wt)
			{
				temp = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = temp;
			}
		}
	}
	
}

int graph::findParent(int v, int *parent)
{
	if(parent[v] == v)
		return v;
	return findParent(parent[v], parent);
}


graph *graph::kruskal(graph *edge[], int v)
{
	int i, count=0, p=0;
	int *parent = new int[v];
	for(i=0; i<v; i++)
	{
		parent[i] = i;
	}
	cout<<"Min spanning tree: "<<"\n";
	cout<<"\nSource\t\tDestination\t\tWeight\n";
	while(count!=(v-1))
	{
		int src = findParent(edge[p]->src, parent);
		int dst = findParent(edge[p]->dst, parent);
		if(src!=dst)
		{
			cout<<"\n"<<edge[p]->src<<"\t\t"<<edge[p]->dst<<"\t\t"<<edge[p]->wt;
			parent[src] = dst;
			count++;
		}
		p++;
	}
}

int main()
{
	graph *edge[10];
	graph *temp;
	int v, i, e, ch;
	do
	{
		cout<<"\n 1.Create\n 2.Display sorted graph\n 3.Display MinST\n 4.Exit";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\n Enter total no. of vertices: ";
				cin>>v;
				cout<<" Enter total no. of edges: ";
				cin>>e;
				for(i=0; i<e; i++)
				{
					edge[i]=new graph;
					edge[i]->accept();
				}
				break;
				
			case 2:
				temp->sort(edge, e);
				cout<<"\n";
				cout<<"Graph after sorting edges: "<<"\n";
				for(i=0; i<e; i++)
				{
					edge[i]->display();
				}
				break;
				
			case 3:
				edge[i]->kruskal(edge, v);
				break;
				
			case 4:
				exit(0);
				
			default:
				cout<<"\n Invalid input !";
		}
	}while(ch!=4);
	return 0;
}
