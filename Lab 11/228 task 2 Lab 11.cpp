#include <fstream>
#include <typeinfo>
#include <iostream>
using namespace std;
#include <process.h>

enum member_type {sstudent,tteacher};
const int MAX=1000;
class University
{
private:
    string name;
    int age;
    static int n;
    static University* arr[];
public:
    virtual void get_data()
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Age :";
        cin>>age;
    }
    virtual void put_data()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Age :"<<age<<endl;
    }
    virtual member_type get_type();
    static void add_member();
    static void display();
    static void read_file();
    static void write_file();
};
int University::n;
University* University::arr[MAX];

class Student:public University
{
private:
    string department;
    int id;
public:
    void get_data()
    {
        University::get_data();
        cout<<"Enter Department :";
        cin>>department;
        cout<<"Enter ID :";
        cin>>id;
    }
    void put_data()
    {
        University::put_data();
        cout<<"Department :"<<department<<endl;
        cout<<"ID :"<<id<<endl;
    }
};
class Teacher:public University
{
private:
    float dues;
public:
    void get_data()
    {
        University::get_data();
        cout<<"Enter Dues :";
        cin>>dues;
    }
    void put_data()
    {
        University::put_data();
        cout<<"Dues :"<<dues<<endl;
    }
};

void University::add_member()
{
    char c;
    cout <<"'s' to add a Student"
         "\n't' to add a Teacher"
         "\n\nEnter your choice: ";
    cin >> c;
    switch(c)
    {
    case 's':
        arr[n] = new Student;
        break;
    case 't':
        arr[n] = new Teacher;
        break;
    default:
        cout << "\nMember type not identified......\n";
        return;
    }

    arr[n++]->get_data();
}

void University::display()
{
    int j;
    for(j=0; j<n; j++)
    {
        cout<<j+1;
        switch(arr[j]->get_type())
        {
        case sstudent:
            cout<<" Type Student\n";
            break;
        case tteacher:
            cout<<" Type Teacher\n";
        }

        arr[j]->put_data();
        cout<<endl;
    }
}
member_type University::get_type()
{
    if( typeid(*this) == typeid(Student) )
        return sstudent;
    else if( typeid(*this)==typeid(Teacher) )
        return tteacher;
    else
    {
        cout << "\nUnknown member type";
        exit(1);
    }
    return sstudent;
}
void University::write_file()
{
    int size;
    cout << "Writing " << n << " members.\n";
    ofstream out;
    member_type mt;
    out.open("UNI.DAT", ios::trunc | ios::binary);
    if(!out)
    {
        cout << "\nError open file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        mt = arr[j]->get_type();
        out.write((char*)&mt, sizeof(mt));
        switch(mt)
        {
        case sstudent:
            size=sizeof(Student);
            break;
        case tteacher:
            size=sizeof(Teacher);
            break;
        }
        out.write((char*)(arr[j]),size);
        if(!out)
        {
            cout << "\nCannot write to file\n";
            return;
        }
    }
}
void University::read_file()
{
    int size;
    ifstream in;
    member_type mt;
    in.open("UNI.DAT", ios::binary);
    if(!in)
    {
        cout << "\nError open file\n";
        return;
    }
    n = 0;
    while(true)
    {
        in.read((char*)&mt, sizeof(mt) );
        if(in.eof())
            break;
        if(!in)
        {
            cout << "\nCannot read from file\n";
            return;
        }
        switch(mt)
        {
        case sstudent:
            arr[n] = new Student;
            size=sizeof(Student);
            break;
        case tteacher:
            arr[n] = new Teacher;
            size=sizeof(Teacher);
            break;
        default:
            cout << "\nUnidentified type!!!!!!\n";
            return;
        }
        in.read((char*)arr[n],size);
        if(!in)
        {
            cout << "\nCannot read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading from file " << n << " members\n";
}
int main()
{
    char c;
    while(true)
    {
        cout <<"'a' to add data for members"
             "\n'd' to display data for all members"
             "\n'w' to write all members data to file"
             "\n'r' to read all members data from file"
             "\n'e' to exit"
             "\nEnter your choice : ";
        cin>>c;
        switch(c)
        {
        case 'a':
            University::add_member();
            break;
        case 'd':
            University::display();
            break;
        case 'w':
            University::write_file();
            break;
        case 'r':
            University::read_file();
            break;
        case 'e':
            exit(0);
        default:
            cout << "\nError in selection!!!!!!!!";
        }
    }
}


