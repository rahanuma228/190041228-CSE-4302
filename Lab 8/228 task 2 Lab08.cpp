#include<bits/stdc++.h>
using namespace std;

class Employee//demo class
{
 public:
     void whoAmI()
    {
        cout<<"\n\nI am a ";
    }
};
class Staff:protected Employee//protected inheritance
{
private:
    int code;
    string name;

public:
    void set_staffdata(string n,int c)//setting the name and code
    {
        name=n;
        code=c;
    }
    string get_name() const//displaying should not change any member function thats why it is constant
    {
       return name;
    }
    int get_code() const//displaying should not change any member function thats why it is constant
    {
       return code;
    }
    void whoAmI()
    {
        Employee::whoAmI();
        cout<<"staff";
    }
};

//Class Teacher is inheriting Staff Class (public inheritance)
class Teacher:public Staff
{
private:
    string subject;
    string publication;

public:

    void set_teacherdata(string s,string p)//setting subject and publication value
    {
        subject=s;
        publication=p;
    }
    void get_teacherdata() const
    {
        cout<<"\n\nAbout teacher : \n";
        cout << "\nname        code    subject                      publication\n\n";
        cout<<get_name()<<"       "<<get_code()<<"    "<<subject<<"          "<<publication;
    }
    void whoAmI()
    {
        Staff::whoAmI();
        cout<<"-teacher";
    }
};

//Class Officer is inheriting Staff Class (public inheritance)
class Officer:public Staff
{
private:
    string grade;

public:

    void set_officerdata(string g)//setting a value for grade
    {
        grade=g;
    }
    void get_officerdata() const
    {

         cout<<"\n\n\nAbout officer : \n";
        cout << "\nname                  code      Category\n\n";
        cout<<get_name()<<"             "<<get_code()<<"     "<<grade;
    }
    void whoAmI()
    {
        Staff::whoAmI();
        cout<<"-officer";
    }
};

//Class Typist is inheriting Staff Class (public inheritance)
class Typist:public Staff
{
private:
    double speed;

public:

    void set_typistdata(double sp)//setting speed
    {
        speed=sp;
    }
    double get_speed() const
    {
        return speed;
    }
    void whoAmI()
    {
        Staff::whoAmI();
        cout<<"-typist";
    }
};

//Class Regular is inheriting Typist Class (public inheritance)
class Regular:public Typist
{
private:
    double wage;

public:

    void set_regulardata(double w)//set wage
    {
        wage=w;
    }
    void get_regulardata() const
    {
         cout<<"\n\n\nAbout regular typist : \n";
        cout << "\nname                  code   speed   wage\n\n";
        cout<< get_name()<<"           "<<get_code()<<"    "<<get_speed()<<"     "<<wage;
    }
    void whoAmI()
    {
        Typist::whoAmI();
        cout<<"-regular";
    }
};

//Class Casual is inheriting Typist Class (public inheritance)
class Casual:public Typist
{
private:
    double wage;

public:

    void set_casualdata(double w)
    {
        wage=w;
    }
    void get_casualdata() const
    {

         cout<<"\n\n\nAbout casual typist : \n";
        cout << "\nname                   code   speed     wage\n\n";
     cout<<get_name()<<"           "<<get_code()<<"    "<<get_speed()<<"     "<<wage;
    }
    void whoAmI()
    {
        Typist::whoAmI();
        cout<<"-casual";
    }
};

int main()
{
    Teacher t1;
    Officer o1;
    Regular r1;
    Casual c1;
    t1.set_staffdata("Ataur",420);
    t1.set_teacherdata("programming with c++","Tata McGraw Hill");
    o1.set_staffdata("Md.Rashed",222);
    o1.set_officerdata("First class");
    r1.set_staffdata("Robiul Awal",333);
    r1.set_typistdata(85.5);
    r1.set_regulardata(15000);
    c1.set_staffdata("Kawsar Ahmed",333);
    c1.set_typistdata(78.900002);
    c1.set_casualdata(10000);
    t1.get_teacherdata();t1.whoAmI();
    o1.get_officerdata();o1.whoAmI();
    r1.get_regulardata();r1.whoAmI();
    c1.get_casualdata(); c1.whoAmI();

}

