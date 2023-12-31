#include<iostream>
using namespace std;
class Queue
{
	int front, rear,item;
		
	public:
		void enqueue(int q[], int n);
		void dequeue(int q[], int n);
		void display(int q[], int n);
		Queue()
		{
			front=-1;
			rear=-1;
		}
};

void Queue :: enqueue(int q[], int n)
{
	if(front==(rear+1)%n)
	{
		cout<<"Queue is full";
	}
	else
	{
		if(front==-1)
		{
			front = 0;
		}
		rear=(rear+1)%n;
		cout<<"Enter the element you want to insert";
		cin>>item;
		q[rear] = item;	
	}
}

void Queue :: dequeue(int q[], int n)
{
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	else 
	{
		item=q[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		front=(front+1)%n;
	}
	
}

void Queue :: display(int q[], int n) 
{
	if(front==-1)
	{
		cout<<"Queue is empty"<<endl;
	}
	
	else if(front>rear)
	{
		for(int i=front; i<n; i++)
		{
	
		cout<<q[i]<<"\t";
		}
		for(int j =0; j<=rear; j++)
		{
			cout<<q[j]<<"\t";
		}
	}
	
	else
	{
		for(int i=front; i<=rear; i++)
		{
			cout<<q[i]<<"\t";
		}
	}
}

int main()
{
	int size,ch; //variable declare
	char x1;
	Queue x; //queue object
	cout<<"Enter the size of queue: "<<endl;
	cin>>size;
	int q[size]; //array declare
	do
	{
		cout<<"1: Insert element"<<"\t"<<"2: Delete Element"<<"\t"<<"3: Display"<<endl;
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1: x.enqueue(q, size);
				break;
			case 2:x.dequeue(q,size);
				break;
			case 3:x.display(q,size);
				break;
		}
		cout<<"\nDo you want to continue? (y/n)"<<endl;
		cin>>x1;
	}while(x1!='n');
	return 0;	 
}
