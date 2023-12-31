#include<iostream>
using namespace std;

class Tree
{
	char data;
	Tree*Left;
	Tree*Right;
	Tree*root;
	
	public:   
	Tree()
	{
	root=NULL;
	}
	
	Tree*create(char a);
	void inorder(Tree*);
	void preorder(Tree*);
	void postorder(Tree*);
	Tree*construct(char []);
	void i_inorder(Tree*);
	void i_preorder(Tree*);
	void i_postorder(Tree*);

};


class Stack
{
	Tree*data;
	Stack*next;
	
	public:
		Stack*top;
		int fl;
		int flag();
		void push(Tree*,int );
		Tree*pop();
		Stack()
		{
			fl=0;
			top=NULL;
		}
};

Tree*Tree::create(char a)
{
	Tree*newnode=new Tree();
	newnode->data=a;
	newnode->Left=NULL;
	newnode->Right=NULL;
	return newnode;
}

void Tree::inorder(Tree*root)
{
	if(root!=NULL)
	{
		inorder(root->Left);
		cout<<root->data;
		inorder(root->Right);
	}
}

void Tree::preorder(Tree *root)
{
	if(root!=NULL)
	{
		cout<<root->data;
		preorder(root->Left);
		preorder(root->Right);
	}
}

void Tree::postorder(Tree *root)
{
	if(root!=NULL)
	{
		postorder(root->Left);
		postorder(root->Right);
		cout<<root->data;
	}
}

void Tree:: i_inorder(Tree* root)
{
	Stack s;
	while(1)
	{
		while(root !=NULL)
		{
			s.push(root,0);
			root=root->Left;
		}
		if(s.top==NULL)
			break;
		root=s.pop();
		cout<<root->data;
		root=root->Right;
	}
}

void Tree::i_preorder(Tree* root)
{
	Stack s1;
	while(1)
	{
		while(root !=NULL)
		{
			cout<<root->data;
			if(root->Right)
				s1.push(root->Right,0);
			root=root->Left;
		}
		if(s1.top==NULL)
			break;
		root=s1.pop();
	}
}
	
int Stack::flag()
{
	return top->fl;
}

void Tree::i_postorder(Tree* root)
{
	Stack s2;
	int f;
	do
	{
		while(root !=NULL)
		{
			s2.push(root,s2.fl);
			root=root->Left;
		}
		
		f=s2.flag();
		root=s2.pop();
		
		if(f==1)
		{
			cout<<root->data;
			root=NULL;
		}
		else
		{
			s2.push(root,1);
			if(root->Right)
			{
				root=root->Right;
			}
			else
			root=NULL;
		}
	}
	while(s2.top !=NULL);
}

void Stack::push(Tree*T,int flag)
{
	Stack*newnode= new Stack();
	newnode->data=T;
	newnode->fl=flag;
	newnode->next=top;

	top=newnode;
}

Tree*Stack::pop()
{
	Tree*ptr;
	if(top==NULL)
    {
		cout<<"The stack is Empty"<<endl;
    }
  	else
    {
		ptr=top->data;
		top=top->next;
		return ptr;
	}
}
	
Tree *Tree::construct(char exp[])
{
	int i=0;
	Stack obj1;

	while(exp[i]!='\0')
	{
		if(isalnum(exp[i]))
		{
			root=create(exp[i]);
			obj1.push(root,0);
		}
		else
		{
			root=create(exp[i]);
			root->Right=obj1.pop();
			root->Left=obj1.pop();
			obj1.push(root,0);
		}
		i++;
	}
	root=obj1.pop();
	return root;
}

int main()
{
	int ch, yn;
	char exp[10];
	Tree *root1;
	Tree obj;
 
	cout<<"Enter a postfix expression:";
	cin>>exp;
	root1 = obj.construct(exp);

do
{
	cout<<"1:Inorder"<<endl;
	cout<<"2:Preorder "<<endl;
	cout<<"3:Postorder"<<endl;
	cout<<"4:Iterative Inorder "<<endl;
	cout<<"5:Iterative Preorder"<<endl;
	cout<<"6:Iterative Postorder"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"Inorder traversal: ";
		obj.inorder(root1);
		break;
		
		case 2:
		cout<<"Preorder traversal: ";
		obj.preorder(root1);
		break;
		
		case 3:
		cout<<"Postorder traversal: ";
		obj.postorder(root1);
		break;
		
		case 4:
		cout<<"Inorder traversal: ";
		obj.i_inorder(root1);
		break;
		
		case 5:
		cout<<"Preorder traversal: ";
		obj.i_preorder(root1);
		break;
		
		case 6:
		cout<<"Postorder traversal: ";
		obj.i_postorder(root1);
		break;
	}
	cout<<"\nDo you want to continue??"<<"\t"<<"1:Yes"<<"\t"<<"2:No"<<endl;;
	cin>>yn;
}while(yn==1);
return 0;
}
