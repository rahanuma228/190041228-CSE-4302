#include<iostream>
#include<string.h>
using namespace std;


class Employer
{
public:
    string EmpName;
    int ID;
    int age;
    float salary;

    void getStatus()
    {
        if(age<=25)
        {
            if(salary<=20000)
            {
                cout<<"Low Salaried Person"<<endl;
            }
            else if(salary>20000)
            {
                cout<<"Moderate Salaried Person"<<endl;
            }
        }

        else
        {

            if(salary<=21000)
            {
                cout<<"Low Salaried Person"<<endl;
            }
            else if(salary>21000 && salary<=60000)
            {
                cout<<"Moderate Salaried Person"<<endl;
            }
            else if(salary>60000)
            {
                cout<<"High Salaried Person"<<endl;
            }
        }
    }
public:
    void FeedInfo(string name,int id,int ag,float sal)
    {
        EmpName=name;
        ID=id;
        age=ag;
        salary=sal;
    }
    void ShowInfo()
    {
        cout<<"\nName: "<<EmpName<<endl;
        cout<<"ID    : "<<ID<<endl;
        cout<<"Age   : "<<age<<endl;
        cout<<"Salary: "<<salary<<endl;
        getStatus();

    }
};

int main()
{
    string name;
    int id;
    int age;
    float salary;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter ID: ";
    cin>>id;
    cout<<"Enter Age: ";
    cin>>age;
    cout<<"Enter Salary: ";
    cin>>salary;
    Employer e1;
    e1.FeedInfo(name,id,age,salary);
    e1.ShowInfo();
}
