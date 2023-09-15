#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
    char Name[10];
    int Roll_No;
    void getdata()
    {
        cout<<"\n Enter the Roll Number and Name:";
        cin>>Roll_No>>Name;
    }

    void insert()
    {
        cout<<"\n The Roll Number and Name:";
        cout<<Roll_No<<"    "<<Name;
    }

};

class file
{
    fstream fp;
public:
    void create()
    {
        char ans;
        Student s;
        fp.open("student.dat",ios::out);
        do
        {
            s.getdata();
            fp.write((char *)&s,sizeof(s));
            cout<<"\n Do you want to continue? (y/n)";
            cin>>ans;
        }
        while(ans=='Y'||ans=='y');
        fp.close();
    }
    
    void append()
    {
        char ans;
        Student s;
        fp.open("student.dat",ios::app);
        do
        {
            s.getdata();
            fp.write((char *)&s,sizeof(s));
            cout<<"\n Do you want to continue? (y/n)";
            cin>>ans;
        }
        while(ans=='Y'||ans=='y');
        fp.close();
    }
    
    void display()
    {
        Student s;
        fp.open("student.dat",ios::in);
        while(!fp.eof())
        {
            fp.read((char *)&s,sizeof(s));
            if (!fp.eof())
                s.insert();
        }
        fp.close();
    }
    
    void search()
    {
        Student s;
        int flag=0;
        cout <<"\n Enter Roll Number to be searched:";
        int r;
        cin >> r;
        fp.open("student.dat",ios::in);
        while(!fp.eof())
        {
            fp.read((char *)&s,sizeof(s));
            if (!fp.eof() && s.Roll_No==r)
            {
                flag=1;
                s.insert();
                break;
            }
        }
        if (flag==0)  cout << "\n Not found";
        fp.close();
    }
    
    void update()
    {
        Student s;
        int flag=0;
        cout <<"\n Enter Roll Number to be updated:";
        int r;
        cin >> r;
        fp.open("student.dat",ios::in|ios::out);
        while(!fp.eof())
        {
            fp.read((char *)&s,sizeof(s));
            if (!fp.eof() && s.Roll_No==r)
            {
                flag=1;
                cout <<"\n Enter new data\n";
                s.getdata();
                fp.seekp(-1*sizeof(s),ios::cur);
                fp.write((char *)&s,sizeof(s));
                break;
            }
        }

        if (flag==0)
            cout << "\n Not found";
        fp.close();
    }
    
    void del()
    {
        Student s;
        int flag=0;
        fstream fp1;
        cout <<"\n Enter Roll Number to be deleted:";
        int r;
        cin >> r;
        fp.open("student.dat",ios::in);
        fp1.open("temp.dat",ios::out);
        while(fp.read((char *)&s,sizeof(s)))
        {

            if ( s.Roll_No!=r)
            {
                flag=1;
                fp1.write((char *)&s,sizeof(s));
            }
        }
        if (flag==0)  cout << "\n Not found";
        fp.close();
        fp1.close();
        remove("student.dat");
        rename("temp.dat","student.dat");
    }
};


int main()
{
    file f;
    int choice;
    do
    {
        cout << "\n1 Create file \n 2 Display data \n 3 Search student\n 4 Append data";
        cout << " \n 5 Delete student \n 6 Update\n 7 Exit";
        cout << "\n Enter choice:";
        cin >> choice;
        switch(choice)
        {
        case 1:
            f.create();
            break;
        case 2:
            f.display();
            break;
        case 3:
            f.search();
            break;
        case 4:
            f.append();
            break;
        case 5:
            f.del();
            break;
        case 6:
            f.update();
            break;
        
        }
    }
    while(choice < 7);
}
