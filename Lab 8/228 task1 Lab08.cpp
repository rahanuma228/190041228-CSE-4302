#include<bits/stdc++.h>
using namespace std;

class Seat
{
private:
    string comfort;
    string warm;
public:
    void set_seatdata(string c,string w)
    {
        comfort=c;
        warm=w;
    }
    void get_seatdata() const//displaying should not change any member function thats why it is constant
    {
        cout<<"\nThe seats are "<<comfort<<endl;
        cout<<"\nPresence of seat warmer : "<<warm<<endl;
    }
};
class Wheel
{
private:
    double radius;
public:
    void set_wheeldata(double r)
    {
        radius=r;
    }
    void get_wheeldata() const
    {
        cout<<"\nRadius of the wheel is : "<<radius<<endl;
    }
};
class Engine
{
private:
    double fuel;
    double energy;
    double rpm;
public:
    void set_enginedata(double f,double e,double rp)
    {
        fuel=f;
        energy=e;
        rpm=rp;
    }
    void get_enginedata() const
    {
        cout<<"\nMaximum Fuel Consumption Rate :  "<<fuel;
        cout<<"\nMaximum Energy Production Rate : "<<energy;
        cout<<"\nMaximum Energy Production Rate : "<<rpm;
    }

};

class Door
{
private:
    string mode;
public:
    void set_doordata(string m)
    {
        mode=m;
    }
    void get_doordata() const
    {
        cout<<"\nThe doors are : "<<mode<<endl;
    }
};
//Using composition
class Truck
{
private:
    double maximum_acceleration;
    double fuel_capacity;
    double load_capacity;
public:
    Seat s[2];
    Wheel w[6];
    Engine e1;
    Door d[2];
    void set_truckdata(double m,double f,double l)
    {
     maximum_acceleration=m;
     fuel_capacity=f;
     load_capacity=l;
    }

    void displaydata() const //display function to display all the information of truck
    {
        s[0].get_seatdata();
        w[0].get_wheeldata();
        e1.get_enginedata();
        d[0].get_doordata();
     cout<<"\nMaximum Acceleration :  "<<maximum_acceleration;
     cout<<"\nMaximum Fuel Capacity : "<<fuel_capacity;
     cout<<"\nMaximum Load Capacity : "<<load_capacity;
    }
};
int main()
{
    Truck t1;
    t1.s[0].set_seatdata("Pleasant","Yes");
    t1.w[0].set_wheeldata(15.87);
    t1.e1.set_enginedata(123.34,28.90,58);
    t1.d[0].set_doordata("upward ways");
    cout<<"\n\nInformation about the truck............\n";
    t1.set_truckdata(228.02,122.23,67.90);
    t1.displaydata();

}
