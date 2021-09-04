#include<bits/stdc++.h>
using namespace std;

class Citizen
{
protected:
    string name;
    long long int birth_id;
public:
    Citizen(string n,long long int b_id):name(n),birth_id(0)
    {
     set_name(n);
     set_birth_id(b_id);
    }
    void set_name(string n)
    {
        name=n;
    }
    void set_birth_id(long long int b_id)
    {
        birth_id=b_id;
    }
    string get_name()
    {
        return name;
    }
    long long int get_birthid()
    {
      return birth_id;
    }
    virtual void display_data()=0;///pure virtual function because every derived classes inheriting this base class must have this else the code will not compile

    virtual void driving_license()
    {
        cout<<"I don't have a driving license"<<endl;
    }
    virtual void profession()///virtual function only because the derived classes are not forced to have this attribute
    {
       cout<<"I don't have a job!!!!!!!"<<endl;
    }
};

class Doctor:public Citizen
{
private:
    string hospital_name;
    double salary;
    int license;
public:
    Doctor(string n,long long int b_id,string hos,double s,int l):Citizen(n,b_id)
    {
        set_info(hos,s,l);
    }
    void set_info(string hos,double s,int l)
    {
        hospital_name=hos;
        salary=s;
        license=l;
    }
    void display_data()
    {
       cout<<"\nName :"<<get_name()<<endl;
       cout<<"Birth ID is:"<<get_birthid()<<endl;
        cout<<"Hospital working at :"<<hospital_name<<endl;
    }
    void profession()
    {
        cout<<"I am a doctor."<<endl;
        cout<<"Salary is:"<<salary<<endl;
    }
    void driving_license()
    {
        cout<<"I have a driving license."<<endl;
        cout<<"License ID is:"<<license<<endl;
    }
};

class Student:public Citizen
{
private:
    string institution;
public:
    Student(string n,long long int b_id,string ins):Citizen(n,b_id)
    {
        set_institution(ins);
    }
    void set_institution(string ins)
    {
        institution=ins;
    }
    void display_data()
    {
        cout<<"Name :"<<get_name()<<endl;
        cout<<"Birth ID is:"<<get_birthid()<<endl;
        cout<<"Institution :"<<institution<<endl;
    }
};

int main()
{
    Citizen* c[50];

    c[0]=new Student("Rahanuma",200012,"IUT");
    c[1]=new Doctor("Mark",199034,"CMC",120000,1900228);

    for(int i=0;i<2;i++)
    {
       c[i]->display_data();
       c[i]->profession();
       c[i]->driving_license();
    }
}
