 #include <iostream>
 using namespace std;
 
class bt
{
 	public:
        int data;
       	bt *rchild;
       	bt *lchild, *parent, *found;
        bt *root;
        bt()
            {
               root=NULL;    
            }
		void search(int);
		void insert(int);
		void del(bt*,int);
   		void inorder(bt*);
      	void lvlorder(int);
};



void bt::insert(int key)
{
        bt*newnode=new bt();
		newnode->data =key;
		newnode->lchild=NULL;
		newnode->rchild=NULL;

        bt*parent;
        bt*data;
        bt*curr;
        
        if(root==NULL)
        	root=newnode;
        else
        {
        	curr=root;
        	while(curr!=NULL)
        	{
            	if(curr ->data <key)
            	{
            		parent=curr;
                	curr=curr->rchild;
            	}
            	else
            	{
                	parent=curr;
            		curr=curr->lchild;  
            	}
        	}
        	if(parent ->data >key)
            	parent->lchild=newnode;	
        	else
            	parent->rchild=newnode;
    	}
}

void bt::inorder(bt*curr)
{
	if (curr!=NULL)
	{
		inorder(curr->lchild);
		cout<<" "<<curr->data;
		inorder(curr->rchild);
	}
}

void bt::search(int key)
{
	bt* curr=root;
	
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			cout<<"Data found !";
			found=curr;
			break;
		}	
		else
		{
			if(key<curr->data)
			{
				parent=curr;
				curr= curr->lchild;
			}
			else
			{
				parent=curr;
				curr=curr->rchild;
			}
		}
	}	
	if(curr==NULL)
	cout<<"Data not found !"<<endl;
}

void bt::lvlorder(int size)
{
	bt*q[15];
	bt*curr=root;
	int front=0,rear=0;
	int qsize=0;
	q[rear]=curr;
	qsize++;
	
	while(qsize>0)
	{
		curr=q[front++];
		cout<<curr->data<<"\t";
		qsize--;
		if(curr->lchild!=NULL)
			q[++rear]=curr->lchild;
		if(curr->rchild!=NULL)
			q[++rear]=curr->rchild;
		if(qsize==0)
		{
			qsize=(rear-front)+1;
			cout<<"\n";
		}
	}
}

void bt::del(bt* curr,int key)
{
	search(key);
	curr=found;
	
	if(curr->lchild==NULL && curr->rchild==NULL)
	{
		if(parent->lchild==curr)
			parent->lchild = NULL;
		else
			parent->rchild=NULL;
		cout<<"Deleted element(Case 1): "<<key;
	}

	if(curr->lchild!=NULL && curr->rchild==NULL)	
	{
		if( curr == parent-> rchild)
			parent->rchild = curr->lchild;
		else
			parent->lchild= curr->lchild;
		delete(curr);
		cout<<"Deleted element(Left child): "<<key;
	}
	
	if(curr->lchild==NULL && curr->rchild!=NULL)
	{
		if(curr == parent->rchild)
 			parent->rchild = curr->rchild;
       else
         parent->lchild = curr->rchild;
       delete(curr);
       cout<<"Deleted element(Right child): "<<key;
	}
	

    if(curr->lchild!=NULL && curr->rchild!=NULL)
    {
        parent=curr;
   		bt* temp= curr->lchild;
        while(temp->rchild!=NULL)
		{
			parent=temp;
			temp=temp->rchild;
		}
		curr->data=temp->data;
		if(parent=curr)
		{
			parent->lchild=temp->lchild;
		}
		else
			parent->rchild=temp->rchild;
		cout<<"Deleted element(Case 3): "<<key;
    }
}

int main()
{
        int key,xkey,ch,n,size;
        cout<<"Enter total nos to insert: ";
        cin>>n;
        bt obj;
        for(int i=0; i<n; i++)
        {
                cout<<"Insert element: ";
                cin>>key;
                obj.insert(key);
        }
        do{
            cout<<"\nSelect\n 1.Inorder\n 2.Search\n 3.Delete\n 4.Level Order\n 5.Exit"<<endl;
            cin>>ch;
            switch(ch)
            {
          		case 1:
    				obj.inorder(obj.root);
  					break;
  				case 2:
  					cout<<"Enter number to Search: ";
  					cin>>xkey;
  					obj.search(xkey);
  					break;
  				case 3:
  					cout<<"Enter number to delete: ";
  					cin>>xkey;
  					obj.del(obj.root,xkey);
  					break;
  				case 4:
  					cout<<"Level order traversal is: \n";
  					obj.lvlorder(size);
  					break;
  				case 5:
        			break;
  				default:
        			cout<<"Wrong Input !";
        	}
        }while(ch!=5);
}
