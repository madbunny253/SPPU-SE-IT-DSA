#include<iostream>
#include<string>
using namespace std;

struct student
{
    string name;
    int sgpa;
    int roll_no;
};

void add_data(int i,struct student a[])
{
    cout<<endl<<"Enter the name of the student: ";
    cin>>a[i].name;
    cout<<"Enter roll no. of "<<a[i].name<<" :";
    cin>>a[i].roll_no;
    cout<<"Enter the sgpa of "<<a[i].name<<" :";
    cin>>a[i].sgpa;
}

void display(int i ,struct student a[])
{
    cout<<endl<<"Name of the student : "<<a[i].name<<"\t"<<endl;
    cout<<a[i].name<<"'s Roll_No. is : "<<a[i].roll_no<<"\t"<<endl;
    cout<<a[i].name<<" has sgpa : "<<a[i].sgpa<<"\t"<<endl;
}

void search(int n ,struct student a[])
{
    int sgpa;
    int temp =0;
    cout<<"\nEnter the sgpa you want to search : ";
    cin>>sgpa;
    for (int i =0; i<n ; i++)
    {
        if (sgpa==a[i].sgpa)
        {
            temp=1;
            cout<<"The match is: "<<a[i].name<<"\t\tRoll No: "<<a[i].roll_no<<"\tSGPA: "<<a[i].sgpa;
        }

    }
    if (temp==0)
    {

        cout<<" Sry you entered sgpa is not in our database"<<endl;
    }
}



void insertionsort(int n , struct student a[])

{
    int j;
    struct student nTemp;
    for(int i=1; i<n; i++)
    {
        nTemp = a[i];
        j= i-1;

        while(j>=0)
        {
            if(a[j].roll_no>nTemp.roll_no)
            {
                a[j+1] = a[j];
                a[j] = nTemp;
                j--;
            }
            else
            {
                break;
            }

        }
        a[j+1]= nTemp;
    }
    cout<<"\nThe sorted array by name is :"<<endl;
    for(int i =0 ; i< n; i++)
    {
        cout<<endl<<"Name of the student : "<<a[i].name<<"\t"<<endl;
        cout<<a[i].name<<"'s Roll_No. is : "<<a[i].roll_no<<"\t"<<endl;
        cout<<a[i].name<<" has sgpa : "<<a[i].sgpa<<"\t"<<endl;
    }

}

void namesearch(int n,struct student a[])
{
            string nam;
            int flag=0;
            cout<<"enter the name of Student : ";
            cin>>nam;
    for(int i=0; i<n; i++)
    {
        if(nam==a[i].name)
        {
            cout<<"the sgpa of the "<<a[i].name<<" is : "<<a[i].sgpa;
            cout<<"\nthe roll_no of the "<<a[i].name<<" is : "<<a[i].roll_no;
            flag= 1;
        }
    }
    if(flag==0)
    {
        cout<<"Wrong Entry please try again";
    }
}



void sortingrollno(int n , struct student a[],int flag)
{
    struct student temp;
	for(int i=0;i<(n-1);i++)
	{
		for(int j=0;j<(n-1);j++)
		{
			if(a[j].roll_no>a[j+1].roll_no)
				{
					temp=a[j];
					a[j] = a[j+1];
					a[j+1]= temp;
				}
		}
	}
	if(flag!=1)
	{
	    cout<<"\nThe sorted array of roll no. is :"<<endl;
	    for(int i =0 ; i< n; i++)
	    {
	        cout<<endl<<"Name of the student : "<<a[i].name<<"\t"<<endl;
	        cout<<a[i].name<<"'s Roll_No. is : "<<a[i].roll_no<<"\t"<<endl;
	        cout<<a[i].name<<" has sgpa : "<<a[i].sgpa<<"\t"<<endl;
	    }
    }

}

void sortingsgpa(int n , struct student a[] )
{
    int i , j ;
    string swap;
    int pass = 0;
    string name[n];
    int numbers[n];
    for (int i=1; i<n; i++)
    {
        if(a[i].sgpa>a[i-1].sgpa)
        {
            cout<<a[i].name<<endl;
        }
    }

    for (int i =0 ; i< n ; i++)
    {
        for(int j =i+1 ; j<n ; j++)
        {
            if (numbers[j]<numbers[i])
            {
                swap=name[i];
                name[i]=name[j];
                name[j]=swap;
            }
        }
        pass++;
    }
    cout<<endl;
    cout<<"\n The Toppers of the class are :"<<endl;
    for(int i =0 ; i< n ; i++)
    {
        cout<<name[n-i]<<"\t";
    }
}

void roll_no_list(int n , int numbers[] , struct student a[])
{
    cout<<"The list of Roll Number is:\n";
    for (int i =0; i<n ; i++)
    {
        numbers[i]= a[i].roll_no;
        cout<<numbers[i]<<"\n";
    }
}

void top10(struct student a[] , int p , int q)
{
    struct student temp;
    int pivot= p;
    int b=p;
    int r=q;
    if (b<r)
    {

        while(b<r)
        {
            while(a[b].sgpa>=a[pivot].sgpa)
            {
                b++;
            }
            while(a[r].sgpa<a[pivot].sgpa)
            {
                r--;
            }
            if (b<r)
            {
                temp=a[b];
                a[b]=a[r];
                a[r]=temp;
            }
        }

            temp=a[pivot];
            a[pivot]=a[r];
            a[r]=temp;
            top10(a,p,r-1);
            top10(a,r+1,q);

    }
}

void binarysearch(int n ,struct student a[])//int element )
{
    sortingrollno(n ,a,1);

    int low , mid , high ;
    float element;
    low=0;
    high=n-1;
    cout<<"\nEnter the sgpa : ";
    cin>>element;
    while(low <=high)
    {
        mid=(low+high)/2;
        if (a[mid].sgpa==element)
        {
            cout<<"Match is\nName: "<<a[mid].name<<"\tRoll No: "<<a[mid].roll_no<<"\tSGPA: "<<a[mid].sgpa;
            break;
        }
        else if (a[mid].sgpa<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<endl;
}

void disp(struct student a[],int n)
{
    int top;
    cout<<"How many toppers to display: ";
    cin>>top;
    cout<<"\nToppers are\n";
    for(int k=0; k<top; k++)
    {
        cout<<endl<<"Name of the student : "<<a[k].name<<"\t"<<endl;
        cout<<a[k].name<<"'s Roll_No. is : "<<a[k].roll_no<<"\t"<<endl;
        cout<<a[k].name<<" has sgpa : "<<a[k].sgpa<<"\t"<<endl;

    }
}


int main()
{
    int n , p,flag;
    struct student a[15];
    cout<<"\nEnter the no.of students that you want to add in your Database : ";
    cin>>n;
    string names[n];
    int numbers[n];
    int element;
    string arnList[n];
    int data[n];
    for (int i=0 ; i<n ; i++)
    {
        data[i]=a[i].sgpa;
    }
    do
    {
        cout<<"\n01.Add data \n02.display data \n03.Search sgpa \n04.list of roll no. \n05.Sorted list of roll no . \n06.Search student by sgpa.  \n07.Arrange the student alphabetically  \n08.Toppers of the class \n09.Search by Name \n00.Exit"<<endl<<endl ;
        cout<<endl<<"Enter your choice :";
        cin>>p;
        switch(p)
        {
        case 1:
            for (int i =0; i<n ; i++)
            {
                add_data(i,a);

            }
            break;
        case 2:
            for (int i =0 ; i<n ; i++)
            {
                display(i,a);
            }
            break;
        case 3:
            search(n,a);
            break;

        case 4:
            roll_no_list(n,numbers,a);
            break;

        case 5:
            sortingrollno(n ,a,flag);
            break;

        case 6:
            binarysearch(n , a); 
            break;

        case 7:
            insertionsort(n , a);
            break;

        case 8:
            top10(a,0,n-1);
            disp(  a,n);

            break;
        case 9:

            namesearch(n,a);
        }
    }
    while (p!=0);
    cout<<endl<<"-------";

}
